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
//                       6.8 线索二叉树 p160
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
//                       6.9 表达式木 p168
//---------------------------------------------------------------------
// 为了表现算法的虚构函数
//struct S9Stack {
//	int top; //开头的索引
//	int capacity; // 容量
//	struct BinaryTreeNode **data;
//};
//struct S9Stack *S9CreateStack(void);// 创建堆
//int S9IsEmptyStack(struct S9Stack *s); // 判断是否为空
//int S9IsFullStack(struct S9Stack *s);// 判断是否已满
//void S9Push(struct S9Stack *s, struct BinaryTreeNode *data); // push
//struct BinaryTreeNode *S9Pop(struct S9Stack *s); //pop
//void S9DeleteStack(struct S9Stack *s); // 删除堆
//// 判断是否是运算符
//int isOperater(char chr);
//// 表示式木
//struct BinaryTreeNode *buildExpressionTree(char postfixExpression[], int size) {
//	struct S9Stack *stack = S9CreateStack();
//	for (int i = 0; i < size; i++) {
//		if (!isOperater(postfixExpression[i])) {
//			struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
//			if (!newNode) {
//				printf("memory error\n");
//				return NULL;
//			}
//			newNode->data = (int)postfixExpression[i]; // 为了不改变这个模板其他地方用到的BinaryTreeNode, 实际不用转换
//			newNode->left = newNode->right = NULL;
//			S9Push(stack, newNode);
//		} else {
//			struct BinaryTreeNode *t2 = S9Pop(stack), *t1 = S9Pop(stack);
//			struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
//			if (!newNode) {
//				printf("memory error\n");
//				return NULL;
//			}
//			newNode->left = t1;
//			newNode->right = t2;
//			newNode->data = (int)postfixExpression[i];
//			S9Push(stack, newNode);
//		}
//	}
//	return stack;
//}

//---------------------------------------------------------------------
//                       6.11 二叉搜索树 p172
//---------------------------------------------------------------------
//------------------------------------------------
// 			    二叉搜索树节点声明
//------------------------------------------------
// 和普通二叉树没有区别
struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};
//------------------------------------------------
// 			        搜索元素
//------------------------------------------------
// 方法1
struct BinarySearchTreeNode *find(struct BinarySearchTreeNode *root, int data) {
	if (root == NULL) {
		return NULL;
	}
	if (data < root->data) {
		return find(root->left, data);
	} else if (data > root->data) {
		return find(root->right, data);
	} else {
		return root;
	}
}

// 方法2
struct BinarySearchTreeNode *findV2(struct BinarySearchTreeNode *root, int data) {
	while (root) {
		if (data == root->data) {
			return root;
		} else if (data > root->data) {
			root = root->right;
		} else {
			root = root->left;
		}
	}
	return NULL;
}

// 个人方法
struct BinarySearchTreeNode *findV3(struct BinarySearchTreeNode *root, int data) {
	struct BinarySearchTreeNode *current = root;
	if (root == NULL) {
		return NULL;
	}
	while (1) {
		if (data == current->data) {
			return current;
		} else if (data > current->data) {
			current = current->right;
		} else {
			current = current->left;
		}
		if (current == NULL) {
			return NULL;
		}
	}
}

//------------------------------------------------
// 			        搜索最小元素
//------------------------------------------------
// 递归版
struct BinarySearchTreeNode *findMin(struct BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->left) {
		return findMin(root->left);
	} else {
		return root;
	}
}
// 非递归版
struct BinarySearchTreeNode *findMinV2(struct BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	}
	while (root->left) {
		root = root->left;
	}
	return root;
}

struct BinarySearchTreeNode *findMinV3(struct BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	}
	while (1) {
		if (root->left) {
			root = root->left;
		} else {
			break;
		}
	}
	return root;
}

//------------------------------------------------
// 			        搜索最大元素
//------------------------------------------------
// 递归版
struct BinarySearchTreeNode *findMax(struct BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->right == NULL) {
		return root;
	} else {
		return findMax(root->right);
	}
}
// 非递归版
struct BinarySearchTreeNode *findMaxV2(struct BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	}
	while (root->right) {
		root = root->right;
	}
	return root;
}

struct BinarySearchTreeNode *findMaxV3(struct BinarySearchTreeNode *root) {
	if (root == NULL) {
		return NULL;
	}
	while (1) {
		if (root->right) {
			root = root->right;
		} else {
			return root;
		}
	}
}

//------------------------------------------------
// 			        插入元素
//------------------------------------------------
// 递归版
struct BinarySearchTreeNode *insert(struct BinarySearchTreeNode *root, int data) {
	if (root == NULL) { // 树不存在则新建树
		root = (struct BinarySearchTreeNode *)malloc(sizeof(struct BinarySearchTreeNode));
		if (root == NULL) { // 生成树失败
			return NULL;
		}
		root->data = data;
		root->left = root->right = NULL;
		return root;
	} else {
		if (data < root->data) {
			root->left = insert(root->left, data);
		} else if (data > root->data) {
			root->right = insert(root->right, data);
		}
	}
	return root;
}

// 非递归版
struct BinarySearchTreeNode *insertV2(struct BinarySearchTreeNode *root, int data) {
	if (root == NULL) {
		root = (struct BinarySearchTreeNode *)malloc(sizeof(struct BinarySearchTreeNode));
		if (root == NULL) {
			return NULL;
		}
		root->data = data;
		root->left = root->right = NULL;
		return root;
	} else {
		struct BinarySearchTreeNode *current = root;
		while (1) {
			if (data > current->data) {
				if (current->right) {
					current = current->right;
				} else {
					current->right = (struct BinarySearchTreeNode *)malloc(sizeof(struct BinarySearchTreeNode));
					current->right->data = data;
					current->right->left = current->right->right = NULL;
					return root;
				}
			} else if (data < current->data) {
				if (current->left) {
					current = current->left;
				} else {
					current->left = (struct BinarySearchTreeNode *)malloc(sizeof(struct BinarySearchTreeNode));
					current->left->data = data;
					current->left->left = current->left->right = NULL;
					return root;
				}
			}
		}
	}
}
//------------------------------------------------
// 			       删除元素
//------------------------------------------------
// 递归版
struct BinarySearchTreeNode *delete(struct BinarySearchTreeNode *root, int data) {
	struct BinarySearchTreeNode *temp;
	if (root == NULL) {
		return NULL;
	}
	if (data < root->data) {
		root->left = delete(root->left, data);
	} else if (data > root->data) {
		root->right = delete(root->right, data);
	} else { // 找到了需要删除的元素
		if (root->left && root->right) { // 子节点有两个
			//可以把用左侧最大或右侧最小替代当前元素
			temp = findMax(root);
			root->data = temp -> data;
			root->left = delete(root->left, root->data);
		} else if (!root->left && !root->right) { // 子节点0个
			temp = root;
			free(temp);
		} else { // 子节点1个
			if (root->left == NULL) {
				root = root->right;
			} else if (root->right == NULL) {
				root = root->left;
			}
			temp = root;
			free(temp);
		}
	}
	return root;
}
//---------------------------------------------------------------------
//                             测试函数
//---------------------------------------------------------------------
void treeTester(void) {
	
}
