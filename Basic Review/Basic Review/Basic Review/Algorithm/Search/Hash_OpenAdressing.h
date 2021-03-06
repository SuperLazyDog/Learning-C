//
//  Hash_OpenAdressing.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/26.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef Hash_OpenAdressing_h
#define Hash_OpenAdressing_h

#include "Hash_OpenAdressing.h"
#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"
#include "MemorySet.h"
#include <string.h>

// # TODO: Hash.h改名---> Hash_Chain.h  77020035-AA17-4021-9216-DC673A915FB7
// # TODO: 增加备注: Hash_Chain 拉链法   Hash_OpenAdressing 开放寻址法  如这里的线性探测再散列法 F588E20F-371D-443F-9677-0190F449DC07

//---------------------------------------------------------------------------
//                                  笔记
//---------------------------------------------------------------------------
/*---------------------------------------------------------------------------
*/

//---------------------------------------------------------------------------
//                              开放寻址哈希表
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                       类型定义
//-------------------------------------------------------
//------------------------------
//实际使用时候改变这个定义     散式哈希表处理的数据类型
typedef int OpenAdressingHash_Data;
//------------------------------
typedef int INT;
typedef INT SIZE, LENGTH;
typedef SIZE Size;
typedef LENGTH Length;

typedef enum {
	occupied,
	empty,
	deleted
} Status_OpenAdressingHash;

typedef int OpenAdressingHash_Key;//对哈希值的定义

typedef struct __OpenAdressingHash_Node { // 开放寻址哈希表的桶
	OpenAdressingHash_Data data; // 存放的数据
	Status_OpenAdressingHash status;// 桶的状态
} OpenAdressingHash_Bucket;

typedef struct { // 开放寻址哈希表
	Size size; // 容量
	OpenAdressingHash_Bucket *table; // 开放寻址哈希表开头的指针
} OpenAdressingHash;

//-------------------------------------------------------
//                     需要自定义的函数
//-------------------------------------------------------
//---------------------------------------------
//                获取哈希值的函数
//---------------------------------------------
OpenAdressingHash_Key getHashKey_OpenAdressingHash(const OpenAdressingHash_Data *data, SIZE size); // 测试专用
//---------------------------------------------
//                再次哈希值的函数
//---------------------------------------------
OpenAdressingHash_Key getReHashKey_OpenAdressingHash(const OpenAdressingHash_Key key, SIZE size);
//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
Bool compareData_OpenAdressingHash(const OpenAdressingHash_Data *ldata, const OpenAdressingHash_Data *rdata);//测试专用
//---------------------------------------------
//                  输出格式
//---------------------------------------------
Bool showBucket_OpenAdressingHash(OpenAdressingHash_Data *data);

//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void OpenAdressingHashTest(void);

//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
Bool initialize_OpenAdressingHash(OpenAdressingHash *hashTable, SIZE size); // 初始化链式哈希表

//-------------------------------------------------------
//                        检索
//-------------------------------------------------------
OpenAdressingHash_Bucket *search_OpenAdressingHash(const OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data);
//ChainHash_Node *search(const ChainHash *hashTable, const Data *data);
/*OpenAdressingHash_Bucket *search_OpenAdressingHash(const OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data, 
		OpenAdressingHash_Key getHashKey_OpenAdressingHash(const OpenAdressingHash_Data *data, SIZE size), 
		OpenAdressingHash_Key getReHashKey_OpenAdressingHash(const OpenAdressingHash_Key key, SIZE size)
		Bool compareData_OpenAdressingHash(const OpenAdressingHash_Data *ldata, const OpenAdressingHash_Data *rdata));*/

//-------------------------------------------------------
//                        追加
//-------------------------------------------------------
Bool insert_Data_OpenAdressingHash(OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data);
/*Bool insert_Data_OpenAdressingHash(OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data,
		OpenAdressingHash_Key getHashKey_OpenAdressingHash(const OpenAdressingHash_Data *data, SIZE size), 
		OpenAdressingHash_Key getReHashKey_OpenAdressingHash(const OpenAdressingHash_Key key, SIZE size), 
		Bool compareData_OpenAdressingHash(const OpenAdressingHash_Data *ldata, const OpenAdressingHash_Data *rdata));*/

//-------------------------------------------------------
//                        删除
//-------------------------------------------------------
Bool delete_Data_OpenAdressingHash(OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data);
/*Bool delete_Data_OpenAdressingHash(OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data,
		OpenAdressingHash_Key getHashKey_OpenAdressingHash(const OpenAdressingHash_Data *data, SIZE size), 
		OpenAdressingHash_Key getReHashKey_OpenAdressingHash(const OpenAdressingHash_Key key, SIZE size), 
		Bool compareData_OpenAdressingHash(const OpenAdressingHash_Data *ldata, const OpenAdressingHash_Data *rdata));*/
//-------------------------------------------------------
//                        Dump
//-------------------------------------------------------
//void dump_OpenAdressingHash(const OpenAdressingHash *hashTable);
void dump_OpenAdressingHash(const OpenAdressingHash *hashTable,
		Bool showBucket_OpenAdressingHash(OpenAdressingHash_Data *data));

//-------------------------------------------------------
//                       全部删除
//-------------------------------------------------------
void clear_OpenAdressingHash(OpenAdressingHash *hashTable);

//-------------------------------------------------------
//                      收尾（全删除）
//-------------------------------------------------------
void terminate_OpenAdressingHash(OpenAdressingHash *hashTable);
#endif
