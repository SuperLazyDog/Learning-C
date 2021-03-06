//
//  Hash_OpenAdressing.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/26.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Hash_OpenAdressing.h"

//---------------------------------------------------------------------------------------------------------
//                                   开放寻址哈希表(open adressing hash)
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
OpenAdressingHash_Key getHashKey_OpenAdressingHash(const OpenAdressingHash_Data *data, SIZE size) {
	return (*data) % size;
}

//---------------------------------------------
//                再次哈希值的函数
//---------------------------------------------
OpenAdressingHash_Key getReHashKey_OpenAdressingHash(const OpenAdressingHash_Key key, SIZE size) {
	return ((key) + 1) % size;
}
//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
Bool compareData_OpenAdressingHash(const OpenAdressingHash_Data *ldata, const OpenAdressingHash_Data *rdata) {
	return *ldata == *rdata;
}
//---------------------------------------------
//                  输出格式
//---------------------------------------------
Bool showBucket_OpenAdressingHash(OpenAdressingHash_Data *data) {
	printf("%d ", *data);
	return false;
}

//-------------------------------------------------------
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
//                  设置节点
//---------------------------------------------
static Bool setNode_OpenAdressingHash(OpenAdressingHash_Bucket *bucket, const OpenAdressingHash_Data *data, Status_OpenAdressingHash status) {
    bucket->data = *data;
    //printf("test: %d\n", bucket->data);
	bucket->status = status;
    return true;
}


//---------------------------------------------------------------------------
//                                共有变量
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//                                API函数
//---------------------------------------------------------------------------
// # TODO: 返回结果不用Bool，改用enum D0159A0D-B4A7-43A4-8816-D59857D04B15
// # TODO: 改用函数指针     changed--------->  全部放弃函数指针  764E5771-5FAA-4354-8C11-E65640730C08
// # TODO: terminate要清楚哈希表管理器指向的内存  ChainHash  25E2CFFB-E347-4EED-8FE2-969990C64B1C
//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void OpenAdressingHashTest() {
    int i;
    OpenAdressingHash hash;
    initialize_OpenAdressingHash(&hash, 1000);
    
    for (i = 12345; i < 43215; i++) {
        insert_Data_OpenAdressingHash(&hash, &i);
    }
    
    dump_OpenAdressingHash(&hash, showBucket_OpenAdressingHash);
}

//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
Bool initialize_OpenAdressingHash(OpenAdressingHash *hashTable, SIZE size) {// 初始化开放寻址哈希表
	int i;
	if (hashTable == NULL) { //一开始为空指针
		hashTable = mallocPro(hashTable, sizeof(hashTable), GETSTR_MEMSET);
		if (hashTable == NULL) {
			return false;
		}
	}

	if ((hashTable->table = (OpenAdressingHash_Bucket *)callocPro(hashTable->table, size, sizeof(OpenAdressingHash_Bucket), GETSTR_MEMSET)) == NULL) { //　哈希表的内存初始化失败
		hashTable->size = 0;
		return false;
	}

	hashTable->size = size;
	for (i = 0;i < hashTable->size ; i++) {
        hashTable->table[i].status = empty;
	}
	return true;
}
//-------------------------------------------------------
//                        检索
//-------------------------------------------------------
//ChainHash_Node *search(const ChainHash *hashTable, const Data *data);
OpenAdressingHash_Bucket *search_OpenAdressingHash(const OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data) {
	int i;
	OpenAdressingHash_Key key = getHashKey_OpenAdressingHash(data, hashTable->size);
	OpenAdressingHash_Bucket *bucket = &hashTable->table[key];

	for (i = 0;((i < hashTable->size) && (bucket->status != empty)) ; i++) {
		if((bucket->status == occupied) && (compareData_OpenAdressingHash(data, &bucket->data)) == true) {
			return bucket;
		}
		key = getReHashKey_OpenAdressingHash(key , hashTable->size);
		bucket = &hashTable->table[key];
	}
	return NULL;
}

//-------------------------------------------------------
//                        追加
//-------------------------------------------------------
Bool insert_Data_OpenAdressingHash(OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data) {
	int i;
	OpenAdressingHash_Key key = getHashKey_OpenAdressingHash(data, hashTable->size);
    //printf("key: %d\n", key);
	OpenAdressingHash_Bucket *bucket = &hashTable->table[key];

	if(search_OpenAdressingHash(hashTable, data) != NULL) {
		return false;//　要插入的数据已存在
		// # TODO: 不用这个是否会更快  834BAD6D-E773-4F35-BC1F-CD01FD736179
	}

	for (i = 0; i < hashTable->size; i++) {
		if ((bucket->status == empty) || (bucket->status == deleted)) {
			setNode_OpenAdressingHash(bucket, data, occupied);
			return true;
		}
		key = getReHashKey_OpenAdressingHash(key, hashTable->size);
		bucket = &hashTable->table[key];
	}

	return false;//哈希表已满
}

//-------------------------------------------------------
//                        删除
//-------------------------------------------------------
Bool delete_Data_OpenAdressingHash(OpenAdressingHash *hashTable, const OpenAdressingHash_Data *data) {
	//int i;
	//OpenAdressingHash_key key = getHashKey_OpenAdressingHash(data, hashTable->size);
	OpenAdressingHash_Bucket *bucket = search_OpenAdressingHash(hashTable, data);

	if (bucket == NULL) {
		return false;//要删除的数据不存在
	}
	bucket->status = deleted;
	return true;
}

//-------------------------------------------------------
//                        Dump
//-------------------------------------------------------
void dump_OpenAdressingHash(const OpenAdressingHash *hashTable,
		Bool showBucket_OpenAdressingHash(OpenAdressingHash_Data *data)) {
	int i;
	for (i = 0; i < hashTable->size; i++) {
		printf("%d: ", i);
		switch (hashTable->table[i].status) {
			case occupied:
				showBucket_OpenAdressingHash(&(hashTable->table[i].data));//展示数据
				puts("");
				break;
			case empty:
				puts("--空--");
				break;
			case deleted:
				puts("--已删除--");
				break;
		}
	}
	
}

//-------------------------------------------------------
//                       全部删除
//-------------------------------------------------------
void clear_OpenAdressingHash(OpenAdressingHash *hashTable) {
	int i;
	for (i = 0; i < hashTable->size; i++) {
		hashTable->table[i].status = empty;
	}
}

//-------------------------------------------------------
//                      收尾（全删除）
//-------------------------------------------------------
void terminate_OpenAdressingHash(OpenAdressingHash *hashTable) {
	clear_OpenAdressingHash(hashTable);
	free(hashTable->table);
	hashTable->size = 0;
}
