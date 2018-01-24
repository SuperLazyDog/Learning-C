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
//typedef struct listNode {
//    int data;
//    struct listNode *next;
//} ListNode;
//------------------------------------------------
//                   函数声明
//------------------------------------------------
void listTester(void);
int listLength(struct listNode *head);
void insertInLinkedList(struct listNode **head, int data, int position);
void deleteNodeFromLinkedList(struct listNode **head, int position);
void deleteLinkedList(struct listNode **head);
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
    if (!newNode) {
        printf("MemoryError\n");
        return;
    }
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

//------------------------
// 删除: 开头, 末尾, 中间p44
//      全部删除 p46
//------------------------
void deleteNodeFromLinkedList(struct listNode **head, int position) {
    // SHOW: SAMPLE [书上版本]
    int k = 1;
    struct listNode *p, *q;
    if (!head) {
        printf("List Empty\n");
        return;
    }
    p = *head;
    if (position == 1) { // 删除开头节点
        *head = (*head)->next;
        free(p);
    }else {
        q = NULL; // 初始化
        while ((k < position) && (p != NULL)) {
            k++;
            q = p;
            p = p->next;
        }
        if (!p) {
            printf("Position does not exist.\n");
        }else {
            q->next = p->next;
            free(p);
        }
    }
}

void deleteLinkedList(struct listNode **head) { // 全删除
    // SHOW: SAMPLE [书上版本]
    
    // SHOW: SELF
    struct listNode *p, *q;
    p = *head;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    *head = NULL;// free()释放内存，不改变指针指向的地址
}

//---------------------------------------------------------------------
//                         3.7 双向链表 p47
//---------------------------------------------------------------------
//------------------------------------------------
//                  链表的型声明
//------------------------------------------------
//struct dllNode {
//    int data;
//    struct dllNode *next;
//    struct dllNode *prev;
//};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
void dllInsert(struct dllNode **head, int data, int position);
void dllDelete(struct dllNode **head, int position);
//------------------------------------------------
//                   基本运算
//        遍历， 插入元素， 删除元素
//------------------------------------------------
// TODO-PRO: add [双向链表的遍历, 书上省略了]
//------------------------
// 插入: 开头, 末尾, 中间p49
//------------------------
void dllInsert(struct dllNode **head, int data, int position) {
    // SHOW: SELF
    int k = 1;
    struct dllNode *p, *q, *newNode;
    newNode = (struct dllNode *)malloc(sizeof(struct dllNode));
    if (!head || !(*head)) {
        printf("Head is NULL\n");
    }
    if (!newNode) {
        printf("Memory Error\n");
               return;
    }
    newNode->data = data;
    p = *head;
    if (position == 1) {
        newNode->prev = NULL;
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    } else {
        q = NULL;
        while ((k < position) && p != NULL) {
            // 第一个条件为真才判断第二个，所以如果p为NULL则一定是指定位置超出长度
            q = p;
            p = p->next;
            k++;
        }
        if (k < position) { // 跳出仅因为第二个条件
            printf("指定的位置超过了当前链表长度\n");
            return;
        } else {
            if (p != NULL) { // 中间的插入
                newNode->next = p;
                newNode->prev = q;
                p->prev = newNode;
                q->next = newNode;
            } else { // 末尾
                newNode->next = NULL;
                newNode->prev = q;
                q->next = newNode;
            }
        }
    }
}
//------------------------
// 删除: 开头, 末尾, 中间p
//------------------------
void dllDelete(struct dllNode **head, int position) {
	// SHOW: SELF
	int k = 1;
	struct dllNode *p, *q;
	p = *head;
	if (position == 1) {
		(*head) = (*head)->next;
		if ((*head) != NULL) {
			(*head)->prev = NULL;
		}
		free(p);
		return;
	} else {
		q = NULL;
		while ((k < position) && p != NULL) {
			q = p;
			p = p->next;
			k++;
		}
		if (k < position) {
			printf("指定的位置超过了当前链表长度\n");
			return;
		} else {
			if (p == NULL) {
				q->next = NULL;
				free(p);
			} else {
				q->next = p->next;
				(q->next)->prev = q;
				free(p);
			}
		}
	}
}
//---------------------------------------------------------------------
//                         3.8 循环链表 p53
//---------------------------------------------------------------------
//------------------------------------------------
//                  链表的型声明
//------------------------------------------------
//struct cllNode { // circular list
//	int data;
//	struct cllNode *next;
//};
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
//------------------------------------------------
//                   基本运算
//        遍历， 插入元素， 删除元素
//------------------------------------------------
//------------------------
// 遍历, 打印 p55
//------------------------
int circularListLength(struct cllNode *head) {
	// SHOW: SELF
	struct cllNode *current = head;
	int count = 0;
	if (!head) {
		return 0;
	}
	do {
		current = current->next;
		count++;
	} while (current != head);
	return count;
}

void printCircularListData(struct cllNode *head) {
	// SHOW: SELF
	struct cllNode *current = head;
	int count = 0;
	if (!head) {
		puts("NULL");
		return;
	}
	do {
		printf("data[%d]: %d\n", count, current->data);
		current = current->next;
		count++;
	} while (current != head);
}

//------------------------
// 插入: 开头, 末尾 p55
//------------------------
//末尾
void insertAtEndInCll(struct cllNode *head, int data) {
	// SHOW: SELF [不用**head，用*head来尝试实现, 调整书上的循环执行位置]
	struct cllNode *current = head;
	struct cllNode *newNode = (struct cllNode*)(malloc(sizeof(struct cllNode)));
	if (!newNode) {
		puts("Memory Error\n");
	}
	newNode->data = data;
	newNode->next = NULL;
	if (!head) {
		head = newNode;
	} else {
		do {
			current = current->next;
		} while (current != head);
		current->next = newNode;
		newNode->next = head;
		
	}
}
void insertAtEndInCll_v2(struct cllNode **head, int data) { // 还是末尾
	// SHOW: SELF [用**head]
	struct cllNode *newNode, *current = *head, *preCurrent = *head;
	newNode = (struct cllNode*)malloc(sizeof(struct cllNode));
	if (!newNode) {
		puts("Memory Error\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	if (!(*head) || !head) {
		head = &newNode; // TODO-PRO: problem [head = &newNode和 *head = newNode有什么区别]
		return;
	}
	do {
		preCurrent = current;
		current = current->next;
	} while (current != *head);
	newNode->next = *head;
	preCurrent->next = newNode;
}
//开头
void insertAtBeginInCll(struct cllNode **head, int data) {
	// SHOW: SELF
	struct cllNode *current = NULL, *newNode;
	newNode = (struct cllNode*)malloc(sizeof(struct cllNode));
	if (!newNode) {
		puts("Memory Error\n");
		return;
	}
	newNode->data = data;
	if (!head || !(*head)) {
		head = &newNode;
		newNode->next = newNode;
		return;
	}
	current = *head;
	while (current->next != *head) {
		current = current->next;
	}
	current->next = newNode;
	newNode->next = *head;
}
//------------------------
// 删除: 开头, 末尾 p57
//------------------------
void deleteLastNodeFromCll(struct cllNode **head) { // 末尾
	// SHOW: SELF
	struct cllNode *current = *head, *preCurrent = *head;
	if (!head || !(*head)) {
		puts("List Empty\n");
			 return;
	}
	while (current->next != *head) {
		preCurrent = current;
		current = current->next;
	}
	preCurrent->next = *head;
	free(current);
}

void deleteFrontNodeFromCll(struct cllNode **head) { // 开头
	// SHOW: SELF
	struct cllNode *current = *head, *temp = *head;
	if (!head || !(*head)) {
		puts("List Empty\n");
		return;
	}
	while (current->next != *head) {
		current = current->next;
	}
	current->next = temp->next;
	free(temp);
	*head = current->next;
	
}
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void listTester(void) {
    printf("hello\n");// TODO-PRO: 删除这行
//    struct listNode sample;
//    sample.data = 1;
//    sample.next = NULL;
//    printf("%d\n", listLength(&sample));
	int *a, b = 1;
	a = &b;
	printf("*a: %d\na: %p\n&a: %p\n", *a, a, &a);
}
