//
//  Tree.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Tree.h"

//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------
BinNode *createBinNode(void);
void setBinNode(BinNode *binNode, const BinType *data, BinNode *left, BinNode *right);
void printBin(BinType *data, void printBin(const BinType *data));//带换行

//-------------------------------------------------------
//                      共有变量
//-------------------------------------------------------

//---------------------------------------------------------------------------
//                                  树
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void treeTest() {
    
}

//-------------------------------------------------------
//                        初始化
//-------------------------------------------------------
void initializeBin(BinNode *p) {
    p->data = 0;
    p->left = NULL;
    p->right = NULL;
}
//-------------------------------------------------------
//                     生成节点
//-------------------------------------------------------
BinNode *createBinNode(void) {//本地函数
    BinNode *binTree = NULL;
    if((binTree = mallocPro(binTree, sizeof(BinNode)))) {
        return binTree;
    }
    puts("wrong, can't create Node");
    return NULL;
}

//-------------------------------------------------------
//                     设置节点
//-------------------------------------------------------
void setBinNode(BinNode *binNode, const BinType *data, BinNode *left, BinNode *right) {//本地函数
    binNode->data = *data;
    binNode->left = left;
    binNode->right =right;
}

//-------------------------------------------------------
//                        检索
//-------------------------------------------------------
//int compare(a, b)
//a > b > 0
//a = b = 0
//a < b < 0
BinNode *searchBinTree(BinNode *p, const BinType *data, int compare(const BinType *key, const BinType *val)) {
    int temp;
    if(!p) {
        return NULL;
    }else if((temp = compare(data, &p->data)) == equal) {
        return p;
    }else if(temp == bigger) {
        searchBinTree(p->right, data, compare);
        
    }else if(temp == smaller) {
        searchBinTree(p->left, data, compare);
    }
    return NULL;
}

//-------------------------------------------------------
//                       插入节点
//-------------------------------------------------------
BinNode *insertNode(BinNode *p, const BinType *data, int compare(const BinType *key, const BinType *val)){
    int temp;
    if(!p) {
        p = createBinNode();
        setBinNode(p, data, NULL, NULL);
    }else if((temp = compare(data, &p->data)) == equal) {
        puts("すでに挿入された。");
    }else if(temp == bigger) {
        insertNode(p->right, data, compare);
    }else if(temp == smaller) {
        insertNode(p->left, data, compare);
    }
    return NULL;
}

//-------------------------------------------------------
//                       删除节点
//-------------------------------------------------------
//# TODO: 理解二叉树节点删除的原理   EC2912DE-2120-4FAB-ABD8-1EC873CFE2C7
//# TODO: 递归   0096FF87-E0E6-4B0F-8C74-B8875832B4C0
int deleteBinNode(BinNode **root, const BinType *data, int compare(const BinType *key, const BinType *val)) {
    BinNode *next, *temp;
    BinNode **left;
    BinNode **p = root;
    
    while (true) {//寻找目标
        int outTemp;
        if(!p) {
            puts("p doesn't exist");
            return -1;
        } else if((outTemp = compare(data, (&(*p)->data))) == equal) {
            break;
        }else if(outTemp < 0) {
            p = &((*p)->left);
        }else if(outTemp > 0) {
            p = &((*p)->right);
        }
    }
    
    if (!((*p)->left)) {
        next = (*p)->right;
    }else {
        left = &((*p)->left);
        while ((*left)->right != NULL) {
            left = &(*left)->right;
        }
        next = *left;
        *left = (*left)->left;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }
    
    temp = *p;
    *p = next;
    free(temp);
    return 0;
}

//-------------------------------------------------------
//                      表示全部节点
//-------------------------------------------------------
bool showAllBinNode(const BinNode *p, void printBin(const BinType *data)) {
    if(p) {
        showAllBinNode(p->left, printBin);
        printBin(&(p->data));
        showAllBinNode(p->right, printBin);
        
    }
    return true;
}

//-------------------------------------------------------
//                      删除全部节点
//-------------------------------------------------------
bool clearAllBinNode(BinNode *p) {
    if(p) {
        clearAllBinNode(p->left);
        clearAllBinNode(p->right);
        free(p);
    }
    return true;
}

