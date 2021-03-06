//
//  Hash.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/19.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef Hash_h
#define Hash_h

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"
#include "MemorySet.h"
#include "SampleDataStruct.h"
#include <string.h>
#define nil	NULL
// !! #  alloc, malloc, calloc, realloc总结 13E98FED-1B4A-4023-BA3E-B91C1F3DFA00
//---------------------------------------------------------------------------
//                                  笔记
//---------------------------------------------------------------------------
/*---------------------------------------------------------------------------
    散式哈希表：每一个哈希值对应的桶为链表的头节点
              重复哈希值在桶里往后走
 
    双重指针：指向地址的指针
            注意： 指针是一种独特的数据类型，不能直接和int划等号。
            指针不初始化不能用
            例： int a, *b, **c;
            　　　　　　　　a = 1;
            b = &a;
            错: *c = b;//　c是指针的指针，还没初始化不能直接用
            对: c = (int *)malloc(sizeof(int));
            *c = b; //　注意，这时候c指向的是b的位置，也就是a的地址。对b运算或者对*c的运算实际上实在向a旁的地址移动
            //对c的操作是在b的地址附近移动，而b是a的地址，本身就是指针。换句话说，操作c实在操作a的数组的开头附近的地址
            int a[] = [1, 2, 3];
            int *b = a + 1;
            int *c = a -1;
            int **d = &a;// d + 1 = b; d - 1 = c;
   
    释放内存: 释放具体数据， free(p);
             释放指针: p = NULL;
 ---------------------------------------------------------------------------*/



//---------------------------------------------------------------------------
//                                 哈希表
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------
//------------------------------
//实际使用时候改变这个定义     散式哈希表处理的数据类型
//typedef Human ChainHash_Data;
typedef int ChainHash_Data;
//------------------------------
typedef int INT;
typedef INT SIZE, LENGTH;
typedef SIZE Size;
typedef LENGTH Length;
typedef INT ChainHash_Key;//对哈希值的定义
typedef struct __chainHash_Node { // 哈希表的节点
    ChainHash_Data data; // 存放的数据
    struct __chainHash_Node *next; // 同一哈希值的下一个节点的指针
} ChainHash_Node;

typedef struct { // 哈希表
    int size; // 容量
    ChainHash_Node **table; // 哈希表开头的指针的指针
} ChainHash;

typedef enum {//新元素的插入位置
    chainHash_First,
    chainHash_last
} ChainHash_InsertLocation;

//-------------------------------------------------------
//                     需要自定义的函数
//-------------------------------------------------------
//---------------------------------------------
//                获取哈希值的函数
//---------------------------------------------
ChainHash_Key getHashKey(const ChainHash_Data *data, SIZE size); // 测试专用
//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
Bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata);//测试专用
//---------------------------------------------
//                  输出格式
//---------------------------------------------
Bool showNode(ChainHash_Data *data);

//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void chainHashTest(void);

//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
Bool initialize_ChainHash(ChainHash *hashTable, SIZE size); // 初始化链式哈希表

//-------------------------------------------------------
//                        检索
//-------------------------------------------------------
//ChainHash_Node *search(const ChainHash *hashTable, const Data *data);
ChainHash_Node *search_ChainHash(const ChainHash *hashTable, const ChainHash_Data *data, ChainHash_Key getHashKey(const ChainHash_Data *data, int size), Bool compareData_HashChain(const ChainHash_Data *ldata, const ChainHash_Data *rdata));

//-------------------------------------------------------
//                        追加
//-------------------------------------------------------
ChainHash_Node *insert_Data_ChainHash(ChainHash *hashTable, const ChainHash_Data *data, ChainHash_InsertLocation where, Bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata));

//-------------------------------------------------------
//                        删除
//-------------------------------------------------------
Bool delete_Data_ChainHash(ChainHash *hashTable, const ChainHash_Data *data, Bool compareData_ChainHash(const ChainHash_Data *ldata, const ChainHash_Data *rdata));

//-------------------------------------------------------
//                     全部表示(dump)
//-------------------------------------------------------
void dump_ChainHash(const ChainHash *hashTable, Bool showNode(ChainHash_Data *data));

//-------------------------------------------------------
//                       全部删除
//-------------------------------------------------------
void clear_ChainHash(ChainHash *hashTable);

//-------------------------------------------------------
//                      收尾（全删除）
//-------------------------------------------------------
void terminate_ChainHash(ChainHash *hashTable);

#endif /* Hash_h */
