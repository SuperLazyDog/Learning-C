//
//  S6_Tree.c
//  Basic Review
//
//  Created by 徐伟达 on 2018/4/13.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "S6_Tree.h"
#include <sys/queue.h>
//---------------------------------------------------------------------
//                            树   p123~208
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//                       6.5.1 二叉树的构造 p127
//---------------------------------------------------------------------
//------------------------------------------------
//                  树的型声明
//------------------------------------------------
struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};
//------------------------------------------------
//                   函数声明
//------------------------------------------------
//------------------------------------------------
//                   函数实现
//------------------------------------------------
// TODO-PRO:  fix here [书上树的性质看不懂 p127]

//---------------------------------------------------------------------
//                       6.6 遍历二叉树 p129
//---------------------------------------------------------------------
// TODO-PRO: 为树设计合适的stack并实现
//------------------------------------------------
//                  前序遍历 DLR
//------------------------------------------------
// 递归版
void preOrder(struct BinaryTreeNode *root) {
	if (root) {
		printf("处理%d\n中", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

// 非递归版 stack不兼容, 测试一定报错
void preOrderNonRecursive(struct BinaryTreeNode *root) {
	struct arrayStack *stack = createStack();
	while (1) {
		while (root) {
			printf("处理%d\n中", root->data);
			push(stack, root);
			root = root->left;
		}
		if (isEmptyStack(stack)) {
			break;
		}
		root = root->right;
	}
	deleteStack(stack);
}

//------------------------------------------------
// 					　中序遍历 LDR
//------------------------------------------------
// 递归版
void inOrder(struct BinaryTreeNode *root) {
	if (root) {
		inOrder(root->left);
		printf("处理%d\n中", root->data);
		inOrder(root->right);
	}
}
// 非递归版 stack不兼容, 测试一定报错
void inOrderNonRecursive(struct BinaryTreeNode *root) {
	struct arrayStack *stack = createStack();
	while (1) {
		while (root) {
			push(stack, root);
			root = root->left;
		}
		if (isEmptyStack(stack)) { // 树的深度为0
			break;
		}
		root = pop(stack);
		printf("处理%d\n中", root->data);
		root = root->right;
	}
	deleteStack(stack);
	
}

//------------------------------------------------
// 					后序遍历 LRD
//------------------------------------------------
// 递归版
void postOrder(struct BinaryTreeNode *root) {
	if (root) {
		postOrder(root->left);
		postOrder(root->right);
		printf("处理%d\n中", root->data);
	}
}
// 非递归版 stack不兼容, 测试一定报错
// TODO-PRO: 搞懂这里
void postOrderNonRecursive(struct BinaryTreeNode *root) {
	struct arrayStack *stack = createStack();
	while (1) {
		if (root) {
			push(stack, root);
			root = root->left;
		} else {
			if (isEmptyStack(stack)) {
				break;
			} else if (stack->array[0] == NULL) { //stack->array[0]->right top(stack)->right
				root = pop(stack);
				printf("处理%d\n中", root->data);
				if (root == stack->array[0]) { //stack->array[0]->right top(stack)->right
					printf("处理%d\n中", root->data);
					pop(stack);
				}
			}
			if (!isEmptyStack(stack)) {
				root = stack->array[0]; ////stack->array[0]->right top(stack)->right
			} else {
				root = NULL;
			}
		}
		deleteStack(stack);
	}
}

//------------------------------------------------
// 					  层次遍历
//------------------------------------------------
// 层次遍历使用的queue
struct S6_Queue {
	int front, rear;
	int capacity;
	int *array;
};
struct S6_Queue *S6CreateQueue() {return NULL;}
int S6IsEmptyQueue(struct S6_Queue *queue) { return rand()%2;}
void S6EnQueue(struct BinaryTreeNode *data, struct S6_Queue *queue) {}
struct BinaryTreeNode *S6DeQueue() { return NULL; }
void S6DeleteQueue(struct S6_Queue *queue) {};
// 层次遍历
void levelOrder(struct BinaryTreeNode *root) {
	struct S6_Queue *queue = S6CreateQueue();
	struct BinaryTreeNode *temp;
	if (root == NULL) {
		return;
	}
	S6EnQueue(root, queue);
	while (!S6IsEmptyQueue(queue)) {
		temp = S6DeQueue();
		// 处理当前node
		if (temp->left) {
			S6EnQueue(temp->left, queue);
		}
		if (temp->right) {
			S6EnQueue(temp->right, queue);
		}
	}
	S6DeleteQueue(queue);
	
}
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void treeTester(void) {
	
}
