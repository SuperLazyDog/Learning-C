//
//  S3_List.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/12/26.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "S3_List.h"

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
int listLength_Weida(struct listNode *head);
//------------------------------------------------
//                   基本运算
// 遍历， 插入元素， 删除元素
//------------------------------------------------
//遍历 p40
//获取长度 O(n)
int listLength_Weida(struct listNode *head) {
    struct listNode *current = head;
    int count = 0;
    while (current->next != NULL) {
        count++;
        current = current->next;
    }
    return ++count;
    //书上版本
//    while (current != NULL) {
//        count++;
//        current = current->next;
//    }
//    return ++count;
}


//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void listTester(void) {
    printf("hello\n");// TODO-PRO: 删除这行
    struct listNode sample;
    sample.data = 1;
    sample.next = NULL;
    printf("%d\n", listLength_Weida(&sample));
}
