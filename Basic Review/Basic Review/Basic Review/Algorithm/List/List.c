//
//  List.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "List.h"


//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------
Node *createNode(void);
void setNode(Node *node, const type *data, Node *next);
void print(type data);

//-------------------------------------------------------
//                      共有变量
//-------------------------------------------------------

//---------------------------------------------------------------------------
//                                  链表
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void listTest() {
    
}

//-------------------------------------------------------
//                     生成节点
//-------------------------------------------------------
Node *createNode(void) {//本地函数
    Node *temp = NULL;
    if((temp =  mallocPro(temp, sizeof(Node)))) {
        return temp;
    }
    puts("wrong, can't create Node");
    return NULL;
    
}

//-------------------------------------------------------
//                      设置节点
//-------------------------------------------------------
void setNode(Node *node, const type *data, Node *next) {//本地函数
    node->data = *data;
    node->next = next;
}

//-------------------------------------------------------
//                        初始化
//-------------------------------------------------------
void initialize(List *list) {
    list->head = NULL;
    list->crnt = NULL;
}

//-------------------------------------------------------
//                        搜索
//-------------------------------------------------------
Node *searchNode(List *list, const type *data, bool compare(const type *left, const type *right)) {
    Node *temp = list->head;//从开头开始检索
    while (temp) {
        if((*compare)(data, &temp->data)) {
            list->crnt = temp;
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//-------------------------------------------------------
//                        开头插入
//-------------------------------------------------------
bool insertInHead(List *list, const type *data) {
    Node *temp = list->head;
    list->head = createNode();
    list->crnt = list->head;
    setNode(list->head, data, temp);
    return true;
}

//-------------------------------------------------------
//                        末尾插入
//-------------------------------------------------------
bool insertInTail(List *list, const type *data) {
    Node *temp = list->head;
    if(!temp) { //链表为空
        insertInHead(list, data);
    }else {
        while(temp) { //一直走到末尾的下一个
            temp = temp->next;
        }
        temp = createNode();//最新的末尾
        list->crnt = temp;
        setNode(temp, data, NULL);
        
    }
    return true;
}

//-------------------------------------------------------
//                      删除头节点
//-------------------------------------------------------
bool deleteHead(List *list) {
    if(list->head){
        Node *temp = list->head;
        list->head = list->crnt = temp->next;
        free(temp);
    }
    
    return true;
}

//-------------------------------------------------------
//                      删除尾节点
//-------------------------------------------------------
bool deleteTail(List *list) {
    Node *temp = list->head;
    Node *pre = NULL;
    
    if(temp) {//不是空链表
        if(temp->next == NULL) { //只有一个元素
            deleteHead(list);
        }else {
            while(temp->next) {
                pre = temp;
                temp = temp->next;
            }
            pre->next = NULL;
            free(temp);
            list->crnt = pre;
        }
    }
    
    return true;
}
//-------------------------------------------------------
//                    删除当前所在节点
//-------------------------------------------------------
bool deleteCurrent(List *list) {
    if(list->head) {
        if(!list->head->next) {
            deleteHead(list);
        }else {
            Node *temp = list->head;//一直检索到当前的前一个
            Node *after = list->crnt->next;//当前的后一个
            while(temp->next != list->crnt) {
                temp = temp->next;
            }
            free(list->crnt);
            list->crnt = temp;
            list->crnt->next = after;
            
        }
    }
    
    return true;
}

//-------------------------------------------------------
//                      删除所有节点
//-------------------------------------------------------
bool clearAll(List *list) {
    while (list->head) {
        deleteHead(list);
    }
    list->crnt = NULL;
    return true;
}

//-------------------------------------------------------
//                      表示当前节点
//-------------------------------------------------------
bool showCurrent(List *list, void print(type data), bool needNewLine) {
    if (!list->crnt) {
        puts("the current item of list does not exit!");
    }else {
        print(list->crnt->data);
        if(needNewLine) {
            puts("");
        }
    }
    return true;
}
//-------------------------------------------------------
//                      表示所有节点
//-------------------------------------------------------
bool showAll(List *list, void print(type data)) {
    if(!list->head) {
        puts("the list does not exit!");
    }else {
        Node *temp = list->head;
        while(temp) {
            print(temp->data);
            puts("");
            temp = temp->next;
        }
    }
    return true;
}

//-------------------------------------------------------
//                         扫尾
//-------------------------------------------------------
bool terminate(List *list) {
    clearAll(list);
    return true;
}

//-------------------------------------------------------
//                         打印函数
//-------------------------------------------------------
void print(type data) {
    printf("your num is %d", data);
}
//# TODO: p354~383 其他形式的链表
//---------------------------------------------------------------------------
//                                  笔记
//---------------------------------------------------------------------------
/*                   判断
    list->head == NULL; //判断是不是空链表
    list->head->next == NULL; //判断是不是只有一个元素
    list->head->next->next == NULL; //判断是不是只有两个元素
    p == list->head; //判断当前变量是不是头节点
    p->next == NULL; //判断当前变量是不是尾节点
 */


