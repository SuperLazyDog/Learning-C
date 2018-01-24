//
//  S3_List.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/12/26.
//  Copyright © 2017年 徐伟达. All rights reserved.
//
/*---------------------------------------------------------------------
							第三章 任务表
-----------------------------------------------------------------------
 ● TODO-PRO-GLO: 动态数组(p38) s4, s5, s14
 ● TODO-PRO-GLO: 内存高效的双向链表(p60) 因为XOR(排他的逻辑和)还不会暂时放一下
---------------------------------------------------------------------*/
#ifndef S3_List_h
#define S3_List_h

#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------------------------------
//                         3.6 单向链表 p40
//---------------------------------------------------------------------
//------------------------------------------------
//                  链表的型声明
//------------------------------------------------
typedef struct listNode {
	int data;
	struct listNode *next;
} ListNode;
//------------------------------------------------
//                   函数声明
//------------------------------------------------
void listTester(void);
int listLength(struct listNode *head);
void insertInLinkedList(struct listNode **head, int data, int position);
void deleteNodeFromLinkedList(struct listNode **head, int position);
void deleteLinkedList(struct listNode **head);
//---------------------------------------------------------------------
//                         3.7 双向链表 p47
//---------------------------------------------------------------------
//------------------------------------------------
//                  链表的型声明
//------------------------------------------------
struct dllNode {
	int data;
	struct dllNode *next;
	struct dllNode *prev;
};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
void dllInsert(struct dllNode **head, int data, int position);
void dllDelete(struct dllNode **head, int position);
//---------------------------------------------------------------------
//                         3.8 循环链表 p53
//---------------------------------------------------------------------
//------------------------------------------------
//                  链表的型声明
//------------------------------------------------
struct cllNode { // circular list
	int data;
	struct cllNode *next;
};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
int circularListLength(struct cllNode *head);
void printCircularListData(struct cllNode *head);
void insertAtEndInCll(struct cllNode *head, int data);
void insertAtEndInCll_v2(struct cllNode **head, int data);
void insertAtBeginInCll(struct cllNode **head, int data);
void deleteLastNodeFromCll(struct cllNode **head);
void deleteFrontNodeFromCll(struct cllNode **head);
//---------------------------------------------------------------------
//                    数据结构与算法 第三章 链表   p37~80
//---------------------------------------------------------------------
void listTester(void);

#endif /* S3_List_h */
