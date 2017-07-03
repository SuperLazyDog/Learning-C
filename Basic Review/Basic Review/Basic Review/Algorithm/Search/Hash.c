
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
ChainHash_Key getHashKey(const ChainHash_Data *data, SIZE size) {// 测试专用
    return (*(data)) % size;
}
//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
Bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata) {//测试专用
    return *ldata == *rdata;
}
//---------------------------------------------
//                  输出格式
//---------------------------------------------
Bool showNode(ChainHash_Data *data) {
    printf("%d", *data);
    return true;
}
//---------------------------------------------
//                获取哈希值的函数
//---------------------------------------------
/*ChainHash_Key getHashKey(const ChainHash_Data *data, int size) {
    //return strlen(data->name) % size;
    if (!strcmp(data->name, "")) {
        return 0;
    }else {
        return data->name[0] % size;
    }
}
//---------------------------------------------
//                  对比函数
//---------------------------------------------
Bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata) {
    if(strcmp(ldata->name, rdata->name) == 0) {
        return true;
    }else {
        return false;
    }
}
//---------------------------------------------
//                  输出格式
//---------------------------------------------
Bool showNode(ChainHash_Data *data) {
    printf("%s", data->name);
    //printf("OK");
    return true;
}*/
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
static Bool setNode_ChainHash(ChainHash_Node *node, const ChainHash_Data *data, ChainHash_Node *next) {
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
#define SIZE_CHAINHASH 15
void chainHashTest() {
    /*//-----------------------------------------
    //              创建样本数据
    //-----------------------------------------
    SPIRITLP spritit_p = createSpirit(char_shy);
    FLESHLP flesh_p = createFlesh(body_power);
    HUMANLP human_p, human_p1, human_p2, human_p3, human_p4;
    human_p = human_p1 = human_p2 = human_p3 = human_p4 = NULL;
    human_p = creatOneHuman(human_p, "WEIDA", flesh_p, spritit_p);
    human_p1 = creatOneHuman(human_p1, "Zhang", flesh_p, spritit_p);
    human_p2 = creatOneHuman(human_p2, "HuangAA", flesh_p, spritit_p);
    human_p3 = creatOneHuman(human_p3, "Wu", flesh_p, spritit_p);
    human_p4 = creatOneHuman(human_p4, "Yddasdasasdas", flesh_p, spritit_p);
    
    
    //-----------------------------------------
    //              创建哈希表
    //-----------------------------------------
    ChainHash *sample_chainHash = NULL;
    sample_chainHash = (ChainHash *)mallocPro(sample_chainHash, sizeof(ChainHash *), GETSTR_MEMSET);
    Bool result = initialize_ChainHash(sample_chainHash, SIZE_CHAINHASH);//初始化测试
    printf("result %s\n", Bool_STR(result));
    dump_ChainHash(sample_chainHash, showNode);
    //printf("size %d point %p\n", sample_chainHash.size, sample_chainHash.table);
    
    //插入数据
    //puts("||||||||||||||||||||||||||||||||||");
    insert_Data_ChainHash(sample_chainHash, human_p, chainHash_First, compareData_ChainHash);
    insert_Data_ChainHash(sample_chainHash, human_p1, chainHash_First, compareData_ChainHash);
    insert_Data_ChainHash(sample_chainHash, human_p2, chainHash_First, compareData_ChainHash);
    insert_Data_ChainHash(sample_chainHash, human_p3, chainHash_First, compareData_ChainHash);
    insert_Data_ChainHash(sample_chainHash, human_p4, chainHash_First, compareData_ChainHash);
    //insert_Data_ChainHash(sample_chainHash, human_p1, chainHash_First);
    int i;
    char store[8][8] = { "ahgfg", "bxcvxfd", "cerasf", "dbcht", "etercx", "adfsjhk", "hgdfs", "#$%&'()0"};
    for(i = 0; i < 100; i++) {
        HUMANLP tempHuman = NULL;
        tempHuman = creatOneHuman(tempHuman , store[i%8], flesh_p, spritit_p);
        insert_Data_ChainHash(sample_chainHash, tempHuman, chainHash_First, compareData_ChainHash);
        
    }
    //检索
    puts("----------------------------------");
    printf("your search result: \n");
    showHuman(&search_ChainHash(sample_chainHash, human_p3, getHashKey, compareData_ChainHash)->data, true);puts("");
    puts("----------------------------------");
    //显示
    dump_ChainHash(sample_chainHash, showNode);
    delete_Data_ChainHash(sample_chainHash, human_p3, compareData_ChainHash);//删一个
    dump_ChainHash(sample_chainHash, showNode);
    clear_ChainHash(sample_chainHash);//全删
    dump_ChainHash(sample_chainHash, showNode);*/
}

//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
// # TODO: malloc, alloc, calloc, realloc   1F916BF4-7F64-4EAE-B9B1-7ECD00EFF5B2
// # TODO: 修改mallocPro, 增加初始化memsetPro D7B1391A-13C6-441B-8069-D027F1856FBE
Bool initialize_ChainHash(ChainHash *hashTable, SIZE size) { // 初始化链式哈希表
    int i;
    if(hashTable == NULL) {
        return false;
    }
    //指针也好，数据也好，占用的内存是实际数据内存大小
    hashTable->table = NULL;//calloc(size, sizeof(ChainHash_Node));//mallocPro(hashTable, sizeof(ChainHash_Node **), GETSTR_MEMSET);
    hashTable->table = (ChainHash_Node **)callocPro(hashTable->table, size, sizeof(ChainHash_Node *), GETSTR_MEMSET);
    // !! # TODO: 为什么不先判断hashTable是否存在
    if(hashTable->table == NULL) {
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
ChainHash_Node *search_ChainHash(const ChainHash *hashTable, const ChainHash_Data *data,
                       ChainHash_Key getHashKey(const ChainHash_Data *data, int size), //获取哈希表值的函数
                       Bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata)) { //比较值大小的函数
    
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
ChainHash_Node *insert_Data_ChainHash(ChainHash *hashTable, const ChainHash_Data *data, ChainHash_InsertLocation where,
                                    Bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata)) {
    //puts("|||||||||||||||||||||\n");
    //puts("before insert");
    //showHuman((HUMANLP)data, true);
    ChainHash_Key key = getHashKey(data, hashTable->size); //获取key
    ChainHash_Node *item = hashTable->table[key]; //读取key所在位置
    ChainHash_Node *temp = NULL;//加在开头时候用来暂存新的开头
    //puts("prepare for insert");
    //ChainHash_Node **row = &hashTable->table[key]; //双重指针定位周边
    ChainHash_Node *pre = item;
    
    int count = -1; //chainHash_lase专用, 捕捉前一个的双重指针
    while (item != NULL) {
        //showHuman((HUMANLP)data, false);
        if (compareData_ChainHash(data, &item->data)) {
            //puts("already exits|||||||||");
            return NULL; // 要插入的数据已经存在
        }
        item = item->next;
        if(where == chainHash_last) {
            if (count >= 0) {
                //(*row) = (*row)->next;
                pre = pre->next;
            }
            count++;
        }
    }
    //puts("start inseart");
    switch (where) {
        case chainHash_First:
            //---------------------------------------
            //               加在开头
            //---------------------------------------
            if ((temp = (ChainHash_Node *)callocPro(temp, 1, sizeof(ChainHash_Node), GETSTR_MEMSET)) == NULL) {//(ChainHash_Node *)mallocPro(temp, sizeof(ChainHash_Node *), GETSTR_MEMSET)) == NULL) {
                return NULL; // 初始化内存失败
            }
            //temp->next = NULL;
            setNode_ChainHash(temp, data, hashTable->table[key]);
            //temp->data = *data;
            //temp->next = hashTable->table[key];
            //printf("%s\n", temp->next->data.name);
            //printf("%s\n", hashTable->table[key]->data.name);
            hashTable->table[key] = temp;
            //printf("data: %s\n", hashTable[key].table[key]->data.name);
            //puts("insert successfully");
            return temp;
            break;
        case chainHash_last:
            //---------------------------------------
            //               加在最后
            //---------------------------------------
            if ((item = (ChainHash_Node *)callocPro(item, 1, sizeof(ChainHash_Node), GETSTR_MEMSET)) == NULL) {
                return NULL; // 初始化内存失败
            }
            //temp->next = NULL;
            setNode_ChainHash(item, data, NULL);//最新节点后面跟空指针
            printf("count: %d\n", count);
            if (count >= 0) {
                //(*row)->next = item;
                pre->next = item;
            }else {
                hashTable->table[key] = item;
            }
            //printf("data: %s\n", data->name);
            //puts("insert successfully");
            return temp;
        default:
            return NULL;//不存在的位置枚举
    }
}

//-------------------------------------------------------
//                        删除
//-------------------------------------------------------
Bool delete_Data_ChainHash(ChainHash *hashTable, const ChainHash_Data *data,
                           Bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata)) {
    ChainHash_Key key = getHashKey(data, hashTable->size);
    ChainHash_Node *item = hashTable->table[key];//指向目标桶
    ChainHash_Node **table = &hashTable->table[key];//指向整个哈希表的目标列的指针 也可以写成*item;
// # TODO: 多重指针   C26DB890-B0BF-4EE1-BAE8-2A3E64DA48DC
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
void dump_ChainHash(const ChainHash *hashTable, Bool showNode(ChainHash_Data *data)) {
    int i;
    //ChainHash_Node *temp = NULL;
    
    for (i = 0; i < hashTable->size; i++) { //每一个node
        printf("hashTable[%d]: ", i);
        ChainHash_Node *temp = hashTable->table[i];
        
        while (temp != NULL) {
            printf("data:");
            showNode(&temp->data);
            temp = temp->next;
            if (temp != NULL) {
                printf(" -> ");
            }
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
Bool Initialize(ChainHash *h, int size);

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
Bool dump(const ChainHash *h);
//-------------------------------------------------------
//                         收尾
//-------------------------------------------------------
Bool Dump(const ChainHash *h);*/
