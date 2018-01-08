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
void insertInLinkedList(struct listNode **head, int data, int position);
//------------------------------------------------
//                   基本运算
// 遍历， 插入元素， 删除元素
//------------------------------------------------
//------------------------
//         遍历 p40
//       获取长度 O(n)
//------------------------
int listLength(struct listNode *head) {
    struct listNode *current = head;
    int count = 0;
    while (current->next != NULL) { // 问题: 第一个可能是NULL所以这种有问题
        // TODO-PRO: weida fix here [上一行指出的问题]
        count++;
        current = current->next;
    }
    return ++count;
    // SHOW: SAMPLE [书上版本]
//    while (current != NULL) {
//        count++;
//        current = current->next;
//    }
//    return ++count;
}

//------------------------
// 插入: 开头, 末尾, 中间p41
//------------------------
// TODO-PRO: add [分别实现开头，末尾，中间三种 p43]
void insertInLinkedList(struct listNode **head, int data, int position) {
    // SHOW: SAMPLE [书上版本]
    int k = 1;
    struct listNode *p, *q, *newNode;
    newNode = (struct listNode *)malloc(sizeof(struct listNode));
    newNode->data = data;
    p = *head; // 直接改变head会使得外部的参数也变化，所以建一个指针来操作
    //插在开头
    if (position == 1) {
        newNode->next = p;
        *head = newNode;
    } else {
        q = NULL;
        position = abs(position);
        while ((k < position) && (p != NULL)) {
            q = p; // 保存当前的节点 例:插到第五个的话，要在第四个操作
            p = p->next;
            k++;
        }
        q->next = newNode;
        newNode->next = p;
    }
}

//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void listTester(void) {
    printf("hello\n");// TODO-PRO: 删除这行
    struct listNode sample;
    sample.data = 1;
    sample.next = NULL;
    printf("%d\n", listLength(&sample));
}
