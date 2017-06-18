//
//  main.c
//  Robot
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------
//                              比赛专用定义
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------
typedef struct {
    int numOfRobot;
    int numOfWorkDown;
    int time;
    int internal;
    int type;
} BinType; //处理的数据类型

typedef enum {
    work,
    creatRobot,
    rest
} WorkType;

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

int compareBinTree(const BinType *key, const BinType *val) {
    //工作往右，造机器人往左
    if(key->type == work) {
        return bigger;
    }else if(key->type == creatRobot) {
        return smaller;
    }else {
        return equal;
    }
}
//测试专用打印函数
void printBin(const BinType *data) {//带换行, 要自己定义
    if(data) {
        printf("time: %d\n", data->time);
    }
}

//---------------------------------------------------------------------------
//                               bool
//---------------------------------------------------------------------------
typedef enum { false, true } bool;
#define BOOL_STR(b) ((b) ? "true":"false")

//---------------------------------------------------------------------------
//                               memset
//---------------------------------------------------------------------------
void *mallocPro(void *p, long unsigned size);
void *callocPro(void *p, long unsigned n, long unsigned size);

//---------------------------------------------------------------------------
//                                  树
//---------------------------------------------------------------------------

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
bool showAllBinNodePreOrder(const BinNode *p, void printBin(const BinType *data));//前序
bool showAllBinNodeInOrder(const BinNode *p, void printBin(const BinType *data));//中序
bool showAllBinNodePostOrder(const BinNode *p, void printBin(const BinType *data));//后序

//-------------------------------------------------------
//                      删除全部节点
//-------------------------------------------------------
bool clearAllBinNode(BinNode *p);



//---------------------------------------------------------------------------
//                                 main
//---------------------------------------------------------------------------
int workTest, costOfRobotTest;

BinNode *conductMission(BinNode *p) {
    //默认都gotoWork
    if(p->data.time < workTest) {
        //gotoWork
        BinNode gotoWork = *p;
        gotoWork.data.type = work;
        gotoWork.data.numOfWorkDown += gotoWork.data.internal;
        gotoWork.data.time += 1;
        p = insertNode(p, &gotoWork.data, compareBinTree);
        conductMission(&gotoWork);
        
        
        //gotoCreatRobot
        BinNode gotoCreatRobot = *p;
        gotoCreatRobot.data.numOfRobot++;
        gotoCreatRobot.data.type = creatRobot;
        gotoCreatRobot.data.internal += 1;
        gotoCreatRobot.data.time += costOfRobotTest;
        p = insertNode(p, &gotoCreatRobot.data, compareBinTree);
        conductMission(&gotoCreatRobot);
        
    }
    return p;
    
}
int main(int argc, const char * argv[]) {
    
    int i;
    BinNode *root = NULL;
    BinType rootData;
    rootData.internal = 1;
    rootData.numOfRobot = 1;
    rootData.numOfWorkDown = 0;
    rootData.time = 0;
    rootData.type = rest;
    root = insertNode(root, &rootData, compareBinTree);
    /*while(scanf("%d%d", &workTest, &costOfRobotTest) != EOF) {
        printf("work: %d costOfRobot: %d\n", workTest,  costOfRobotTest);
    }*/
    scanf("%d%d", &workTest, &costOfRobotTest);
    printf("work: %d costOfRobot: %d\n", workTest,  costOfRobotTest);
    conductMission(root);
    printf("height: %d, count: %d\n", getTreeHeight(root), getTreeCount(root));
    showAllBinNodeInOrder(root, printBin);
    return 0;
}

//---------------------------------------------------------------------------
//                              memset
//---------------------------------------------------------------------------
//-------------------------------------------------------
void *mallocPro(void *p, long unsigned size) {
    p = malloc(size);
    if(!p) {
        //printf("false\n");
        return NULL;
    }
    //printf("true\n");
    return p;
}

void *callocPro(void *p, long unsigned n, long unsigned size) {
    p = calloc(n, size);
    if(!p) {
        printf("false\n");
        return NULL;
    }
    printf("true\n");
    return p;
}
//---------------------------------------------------------------------------
//                              tree
//---------------------------------------------------------------------------
#define BINTREE_COUNT 10
//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------
BinNode *createBinNode(void);
void setBinNode(BinNode *binNode, const BinType *data, BinNode *left, BinNode *right);
//int compareBinTree(const BinType *key, const BinType *val)  比较函数
int compareBinTreeBinTree(const BinType *key, const BinType *val);  //比较函数
void printBin(const BinType *data);//带换行, 要自己定义
//-------------------------------------------------------
//                      共有变量
//-------------------------------------------------------

//---------------------------------------------------------------------------
//                                  树
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------

/*void treeTest() {//注: 根节点要自己创建
    int i;
    int tst = 2007237709;
    int *array = (int *)malloc(sizeof(int)*BINTREE_COUNT);
    //int array[BINTREE_COUNT];
    BinNode *root = NULL;//(BinNode *)malloc(sizeof(BinNode));
    //生成
    for(i = 0; i < BINTREE_COUNT; i++) {
        array[i] = rand();
        //printf("%d\n", array[i]);
        root = insertNode(root, &array[i], compareBinTree);
        //showAllBinNodePreOrder(root, printBin);
        //printf("root = %p\n", root);
        //printf("root->left = %p\n", root->left);
        //printf("root->right = %p\n", root->right);
        puts("-------------------------------------------------------");
    }
    showAllBinNodePreOrder(root, printBin);puts("-------------------------------------------------------");
    //删除
    deleteBinNode(&root, &tst, compareBinTree);
    showAllBinNodePreOrder(root, printBin);puts("-------------------------------------------------------");
    
    printf("count: %d\n", getTreeCount(root));
    printf("height: %d\n", getTreeHeight(root));
}*/

//-------------------------------------------------------
//                        初始化
//-------------------------------------------------------
//void initializeBin(BinNode *p)
//# TODO: 指针里的结构体怎么初始化
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
    //printBin(&binNode->data);
    binNode->left = left;
    binNode->right = right;
}

//-------------------------------------------------------
//                        检索
//-------------------------------------------------------
//int compareBinTree(a, b)
//a > b > 0
//a = b = 0
//a < b < 0
BinNode *searchBinTree(BinNode *p, const BinType *data, int compareBinTree(const BinType *key, const BinType *val)) {
    int temp;
    if(!p) {
        return NULL;
    }else if((temp = compareBinTree(data, &p->data)) == equal) {
        return p;
    }else if(temp == bigger) {
        searchBinTree(p->right, data, compareBinTree);
        
    }else if(temp == smaller) {
        searchBinTree(p->left, data, compareBinTree);
    }
    return NULL;
}

//-------------------------------------------------------
//                       插入节点
//-------------------------------------------------------
BinNode *insertNode(BinNode *p, const BinType *data, int compareBinTree(const BinType *key, const BinType *val)){
    int temp;
    //puts("start");
    if(p == NULL) {
        p = createBinNode();
        setBinNode(p, data, NULL, NULL);
        //printf("p = %p\n", p);
    }else if((temp = compareBinTree(data, &p->data)) == equal) {
        puts("已经有了");
    }else if(temp == bigger) {
        //printf("p->right = %p\n", p->right);
        p->right = insertNode(p->right, data, compareBinTree);
    }else if(temp == smaller) {
        p->left = insertNode(p->left, data, compareBinTree);
    }
    return p;
}

//-------------------------------------------------------
//                       删除节点
//-------------------------------------------------------
//# TODO: 理解二叉树节点删除的原理   EC2912DE-2120-4FAB-ABD8-1EC873CFE2C7
//# TODO: 递归   0096FF87-E0E6-4B0F-8C74-B8875832B4C0
/*-------------------------------------------------------
 笔记
 ①没有子节点: 直接删除
 ②有一个子节点: 左对左，右対右
 ③有两个子节点: 只看左节点的子孙 ---> 搜索最大值(越往右越大) ---> 把这个移到删除处
 
 删除含有目标数据的节点
 int deleteBinNode(BinNode **root, const BinType *data, int compareBinTree(const BinType *key, const BinType *val))
 BinNode **root  根节点
 BinType *data   目标数据
 int compareBinTree(const BinType *key, const BinType *val)  比较函数
 -------------------------------------------------------*/
int deleteBinNode(BinNode **root, const BinType *data, int compareBinTree(const BinType *key, const BinType *val)) {
    BinNode *next, *temp;
    BinNode **left;//接上的节点
    BinNode **p = root;//**root ---> * root[]
    
    while (true) {//寻找目标
        int outTemp;
        if(*p == NULL) {//根不存在或者没有相同的
            puts("p doesn't exist or doesn't match anyone");
            return -1;
        }else if ((outTemp = compareBinTree(data, (&((*p)->data)))) == equal) {
            break;
        }else if (outTemp == smaller) {
            p = &((*p)->left);
        }else if (outTemp == bigger) {
            p = &((*p)->right);
        }
        //puts("searching");
    }
    
    if (!((*p)->left)) { //只有右节点，直接把右节点接上
        next = (*p)->right;
    }else {
        left = &((*p)->left); //有左节点: 前进到左节点(原来的节点要被删除)
        while ((*left)->right != NULL) {
            left = &((*left)->right);//获取目标节点的最大子孙
        }
        next = *left;//最大左子孙
        *left = (*left)->left; //把最大的左子孙的左节点连接上(因为最大的要拿出去)
        next->left = (*p)->left;//连接上删除处的左右子节点
        next->right = (*p)->right;
    }
    
    temp = *p;
    *p = next;
    free(temp);
    return 0;
}

//-------------------------------------------------------
//                        求深度
//-------------------------------------------------------
int getTreeHeight(BinNode *p) {
    int h,left,right;
    if(!p){
        return 0;
    }
    left = getTreeHeight(p->left);
    right = getTreeHeight(p->right);
    h = (left > right ? left : right) + 1;
    return h;
}

//-------------------------------------------------------
//                        统计个数
//-------------------------------------------------------
int getTreeCount(BinNode *p) {
    if(p){
        return (getTreeCount(p->left) + getTreeCount(p->right) + 1);
    }
    return 0;
}
//-------------------------------------------------------
//                      表示全部节点
//-------------------------------------------------------
//前序
bool showAllBinNodePreOrder(const BinNode *p, void printBin(const BinType *data)) { //前序
    if(p != NULL) {
        //puts("printBin");
        printBin((&p->data));
        showAllBinNodePreOrder(p->left, printBin);
        showAllBinNodePreOrder(p->right, printBin);
    }
    return true;
}

//中序
bool showAllBinNodeInOrder(const BinNode *p, void printBin(const BinType *data)) { //中序
    if(p) {
        showAllBinNodeInOrder(p->left, printBin);
        printBin(&(p->data));
        showAllBinNodeInOrder(p->right, printBin);
        
    }
    return true;
}
//后序
bool showAllBinNodePostOrder(const BinNode *p, void printBin(const BinType *data)) { //后序
    if(p) {
        showAllBinNodePostOrder(p->left, printBin);
        showAllBinNodePostOrder(p->right, printBin);
        printBin(&(p->data));
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
