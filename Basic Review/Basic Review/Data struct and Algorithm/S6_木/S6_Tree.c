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
// 				  中序遍历 LDR
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
		temp = S6DeQueue(); // 处理当前node
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
//                       6.7 N叉树 p152
//---------------------------------------------------------------------
// N叉树数据结构
struct TreeNode {
	int data;
	struct TreeNode *firstChild; // 左侧子节点
	struct TreeNode *nextSibling; // 同层次右边一个节点
};

//---------------------------------------------------------------------
//                       6.8 线索二叉树
//---------------------------------------------------------------------
struct ThreadedBinaryTreeNode {
	struct ThreadedBinaryTreeNode *left;
	int LTag; // 0: 线索指针, 1: 子节点指针
	int data;
	int RTag;
	struct ThreadedBinaryTreeNode *right;
};
//------------------------------------------------
// 					中序遍历
//------------------------------------------------
// 搜索中序遍历的下一个节点
struct ThreadedBinaryTreeNode *inOrderSuccessor(struct ThreadedBinaryTreeNode *p) {
	struct ThreadedBinaryTreeNode *position;
	if (p->RTag == 0) { // 右子节点不存在, 返回上层节点
		return p->right;
	} else { // 右侧子节点存在
		position = p->right;
		while (position->LTag == 1) {
			position = position->left;
		}
		return position;
	}
}
// dummy节点: RTag恒为1, right指向自身
// 中序遍历
// 方法1
void inorderTraversal(struct ThreadedBinaryTreeNode *root) { // root是dummy节点
	struct ThreadedBinaryTreeNode *current = inOrderSuccessor(root);
	while (current != root) {
		current = inOrderSuccessor(current);
		printf("data: %d\n", current->data);
	}
}

// 方法2
void inorderTraversalV2(struct ThreadedBinaryTreeNode *root) {
	struct ThreadedBinaryTreeNode *current = root;
	while (1) {
		if (current == root) {
			return;
		}
		current = inOrderSuccessor(current);
		printf("data: %d\n", current->data);
	}
}
//------------------------------------------------
// 					前序遍历
//------------------------------------------------
// 搜索前序遍历的下一个节点
struct ThreadedBinaryTreeNode *preorderSuccessor(struct ThreadedBinaryTreeNode * p) {
	if (p->LTag == 1) { // 左侧存在返回左子节点
		return p->left;
	} else { // 不存在返回右边最近的
		return p->right;
	}
}
// 前序遍历
// 方法1
void preorderTravesal(struct ThreadedBinaryTreeNode *root) { // root是dummy节点
	struct ThreadedBinaryTreeNode *current = preorderSuccessor(root);
	while (current != root) {
		current = preorderSuccessor(current);
		printf("data: %d\n", current->data);
	}
}
// 方法2
void preorderTravesalV2(struct ThreadedBinaryTreeNode *root) { // root是dummy节点
	struct ThreadedBinaryTreeNode *current = root;
	while (1) {
		current = preorderSuccessor(current);
		if (current == root) {
			return;
		}
		printf("data: %d\n", current->data);
	}
}

//------------------------------------------------
// 			    插入节点(线索二叉树)
//------------------------------------------------
void insertRightInInorderThreadedBinaryTree(struct ThreadedBinaryTreeNode *location, struct ThreadedBinaryTreeNode *newNode) {
	// TODO-PRO: 感觉书上这个有错
	struct ThreadedBinaryTreeNode *temp;
	newNode->RTag = location->RTag;
	newNode->right = location->right;
	newNode->left = location;
	newNode->LTag = 0;
	location->right = newNode;
	location->RTag = 1;
	if (newNode->RTag == 1) {
		temp = newNode->right;
		while (temp->left) {
			temp = temp->left;
		}
		temp->left = newNode;
	}
}
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void treeTester(void) {
	
}
