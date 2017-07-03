//
//  Tree.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"
#include "MemorySet.h"

//---------------------------------------------------------------------------
//                                  树
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------
typedef int BinType; //处理的数据类型

typedef struct __BinNode { //二叉树
    BinType data;
    struct __BinNode *left;
    struct __BinNode *right;
} BinNode;

typedef enum {//比较结果
    bigger = 1,
    smaller = -1,
    equal = 0,
} Compare;

typedef enum { preOrder, inOrder, postOrder } Order; //遍历的顺序
//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void treeTest();

//-------------------------------------------------------
//                        初始化
//-------------------------------------------------------
void initializeBin(BinNode *p);

//-------------------------------------------------------
//                        检索
//-------------------------------------------------------
BinNode *searchBinTree(BinNode *p, const BinType *data, int compare(const BinType *key, const BinType *val));

//-------------------------------------------------------
//                       插入节点
//-------------------------------------------------------
BinNode *insertNode(BinNode *p, const BinType *data, int compare(const BinType *key, const BinType *val));

//-------------------------------------------------------
//                       删除节点
//-------------------------------------------------------
int deleteBinNode(BinNode **root, const BinType *data, int compare(const BinType *key, const BinType *val));

//-------------------------------------------------------
//                        求深度
//-------------------------------------------------------
int getTreeHeight(BinNode *p);

//-------------------------------------------------------
//                        统计个数
//-------------------------------------------------------
int getTreeCount(BinNode *p);

//-------------------------------------------------------
//                      表示全部节点
//-------------------------------------------------------
Bool showAllBinNodePreOrder(const BinNode *p, void printBin(const BinType *data));//前序
Bool showAllBinNodeInOrder(const BinNode *p, void printBin(const BinType *data));//中序
Bool showAllBinNodePostOrder(const BinNode *p, void printBin(const BinType *data));//后序

//-------------------------------------------------------
//                      删除全部节点
//-------------------------------------------------------
Bool clearAllBinNode(BinNode *p);

#endif /* Tree_h */
