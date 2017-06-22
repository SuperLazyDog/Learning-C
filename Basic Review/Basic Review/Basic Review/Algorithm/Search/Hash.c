//
//  Hash.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/19.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Hash.h"

//---------------------------------------------------------------------------------------------------------
//                                      链式哈希表(chain hash)
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------


//-------------------------------------------------------
//                      共有变量
//-------------------------------------------------------



//---------------------------------------------------------------------------
//                           测试专用--自定义函数的实现
//---------------------------------------------------------------------------
//---------------------------------------------
//                获取哈希值的函数
//---------------------------------------------
ChainHash_Key getHashKey(const ChainHash_Data *data, int size) {
    return strlen(data->name) % size;
}
//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata) {
    if(strcmp(ldata->name, rdata->name) == 0) {
        return true;
    }else {
        return false;
    }
}
//---------------------------------------------
//                  输出格式
//---------------------------------------------
bool showNode(ChainHash_Data *data) {
    //printf("%s", data->name);
    printf("OK");
    return true;
}
//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------
//---------------------------------------------
//                设置哈希值的函数
//---------------------------------------------

//---------------------------------------------
//                设置数据对比函数
//---------------------------------------------

//---------------------------------------------
//                  设置节点
//---------------------------------------------
static bool setNode_ChainHash(ChainHash_Node *node, const ChainHash_Data *data, ChainHash_Node *next) {
    node->data = *data;
    node->next = next;
    
    return true;
}


//---------------------------------------------------------------------------
//                                共有变量
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//                                API函数
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void chainHashTest() {
    //-----------------------------------------
    //              创建样本数据
    //-----------------------------------------
    SPIRITLP spritit_p = createSpirit(char_shy);
    FLESHLP flesh_p = createFlesh(body_power);
    HUMANLP human_p = NULL;
    human_p = creatOneHuman(human_p, "WEIDA", flesh_p, spritit_p);
    //showHuman(human_p, false);
    //HUMANLP human1 = creatOneHuman(human_p, "1", flesh_p, spritit_p);
    
    
    //-----------------------------------------
    //              创建哈希表
    //-----------------------------------------
    ChainHash sample_chainHash;
    initialize_ChainHash(&sample_chainHash, 15);//初始化测试
    printf("size %d point %p", sample_chainHash.size, sample_chainHash.table);
    
    
    
    
    //bool result = Insert_Data_ChainHash(&sample_chainHash, human_p, chainHash_last);
    
    
    
    //printf("insert resert %d", result);
    //puts("start show node");
    //ChainHash_Key key = getHashKey(human_p, sample_chainHash.size);
    //printf("key: %d\n", key);
    //printf("%s", sample_chainHash.table[key]->data.name);
    //clear_ChainHash(&sample_chainHash);
    //dump_ChainHash(&sample_chainHash, showNode);
    
    
}

//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
bool initialize_ChainHash(ChainHash *hashTable, SIZE size) { // 初始化链式哈希表
    int i;
    hashTable->table = mallocPro(hashTable, sizeof(ChainHash_Node), GETSTR_MEMSET);
    // !! # TODO: 为什么不先判断hashTable是否存在
    if(hashTable == NULL) {
        hashTable->size = 0; //带入零，防止误操作
        return false;
    }
    hashTable->size = size;
    for(i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return true;
}

//-------------------------------------------------------
//                        检索
//-------------------------------------------------------
ChainHash_Node *search(const ChainHash *hashTable, const ChainHash_Data *data,
                       ChainHash_Key getHashKey(const ChainHash_Data *data, int size), //获取哈希表值的函数
                       bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata)) { //比较值大小的函数
    
    ChainHash_Key key = getHashKey(data, hashTable->size);//计算哈希值
    ChainHash_Node *temp = hashTable->table[key];//获取相应数据
    
    while (temp != NULL) {
        if(compareData_ChainHash(data, &temp->data)) {
            return temp;
        }
        temp = temp->next;
    }
    
    return NULL;
}
           
//-------------------------------------------------------
//                        追加
//-------------------------------------------------------
bool Insert_Data_ChainHash(ChainHash *hashTable, const ChainHash_Data *data, ChainHash_InsertLocation where) {
    ChainHash_Key key = getHashKey(data, hashTable->size); //获取key
    ChainHash_Node *item = hashTable->table[key]; //读取key所在位置
    ChainHash_Node *temp = NULL;//加在开头时候用来暂存新的开头
    
    while (item != NULL) {
        if (compareData_ChainHash(data, &item->data)) {
            return false; // 要插入的数据已经存在
        }
        item = item->next;
    }

    switch (where) {
        case chainHash_First:
            //---------------------------------------
            //               加在开头
            //---------------------------------------
            if ((temp = (ChainHash_Node *)mallocPro(temp, sizeof(ChainHash_Node), GETSTR_MEMSET)) == NULL) {
                return false; // 初始化内存失败
            }
            setNode_ChainHash(temp, data, hashTable->table[key]);
            hashTable->table[key] = temp;
            printf("data: %s", data->name);
            return true;
            break;
        case chainHash_last:
            //---------------------------------------
            //               加在最后
            //---------------------------------------
            if ((item = (ChainHash_Node *)mallocPro(item, sizeof(ChainHash_Node), GETSTR_MEMSET)) == NULL) {
                return false; // 初始化内存失败
            }
            setNode_ChainHash(item, data, NULL);//最新节点后面跟空指针
            printf("data: %s", data->name);
            return true;
        default:
            return false;//不存在的位置枚举
    }
}

//-------------------------------------------------------
//                        删除
//-------------------------------------------------------
bool delete_Data_ChainHash(ChainHash *hashTable, const ChainHash_Data *data) {
    ChainHash_Key key = getHashKey(data, hashTable->size);
    ChainHash_Node *item = hashTable->table[key];//指向目标桶
    ChainHash_Node **table = &hashTable->table[key];//指向整个哈希表的目标列的指针 也可以写成*item;
//# TODO: 多重指针
    while (item != NULL) {//开始寻找目标
        if (compareData_ChainHash(data, &item->data)) {//找到目标
            *table = item->next;
            free(item);
        }
        item = item->next;
        table = &item->next;
    }
    
    return false;//要删除的值不存在
    
    /*ChainHash_Key key = getHashKey(data, hashTable->size);
    ChainHash_Node *item = hashTable->table[key];
    ChainHash_Node **row = &item;
    while (item != NULL) {
        if (compareData_ChainHash(data, &item->data)) {
            *row = item->next;
            free(item);
            return true;
        }
        
        item = item->next;
        row = &item->next;
    }
    return false;//要删除的值不存在*/
}

//-------------------------------------------------------
//                        Dump
//-------------------------------------------------------
void dump_ChainHash(const ChainHash *hashTable, bool showNode(ChainHash_Data *data)) {
    int i;
    //ChainHash_Node *temp = NULL;
    
    for (i = 0; i < hashTable->size; i++) { //每一个node
        ChainHash_Node *temp = hashTable->table[i];
        
        while (temp != NULL) {
            showNode(&temp->data);
            temp = temp->next;
            //if (temp->next != NULL) {
                printf(" -> ");
            //}
        }
        putchar('\n');
    }
    
    return;
}

//-------------------------------------------------------
//                       全部删除
//-------------------------------------------------------
void clear_ChainHash(ChainHash *hashTable) {
    int i;
    
    for (i = 0; i < hashTable->size; i++) {
        ChainHash_Node *temp = hashTable->table[i];
        
        while (temp != NULL) {
            ChainHash_Node *next = temp->next;
            free(temp);
            temp = next;
        }
        hashTable->table[i] = NULL; //前面是释放指针指着的数组，现在把这个指针释放了
    }
    return;
}

//-------------------------------------------------------
//                      收尾（全删除）
//-------------------------------------------------------
void terminate_ChainHash(ChainHash *hashTable) {
    clear_ChainHash(hashTable);
}

/*//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void hashTest_chain();

//-------------------------------------------------------
//                        初始化
//-------------------------------------------------------
bool Initialize(ChainHash *h, int size);

//-------------------------------------------------------
//                         检索
//-------------------------------------------------------
Node_ChainHash *search_ChainHash(const ChainHash *h, const int size);
//-------------------------------------------------------
//                        插入数据
//-------------------------------------------------------
int InsertInChainHash(ChainHash *h, const CHAINHASHDATALP member);

//-------------------------------------------------------
//                        删除数据
//-------------------------------------------------------
int Delete(ChainHash *h, const CHAINHASHDATALP member);

//-------------------------------------------------------
//                      删除全部数据
//-------------------------------------------------------
bool dump(const ChainHash *h);
//-------------------------------------------------------
//                         收尾
//-------------------------------------------------------
bool Dump(const ChainHash *h);*/
