//
//  main.c
//  School
//
//  Created by 徐伟达 on 2018/5/29.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGITS_LENGTH 4

int *getRandomNumQueue(int length); // 重複数字のないランダム数字を保持するqueueを取得
int buildNumBasedOnQueue(int *queue, int length); // queueから数字を取得
int *buildNumQueueBasedOnNum(int num, int length); // 数字からqueueを取得
void compareQueue(int *queueA, int *queueB, int length); // queueの比較


int main_20180529() {
	int *targetQueue = getRandomNumQueue(DIGITS_LENGTH), *inputQueue;
	int targetNum = buildNumBasedOnQueue(targetQueue, DIGITS_LENGTH);
	int inputNum, times = 0;
	do {
		printf("Please input number:");
		scanf("%d", &inputNum);
		inputQueue = buildNumQueueBasedOnNum(inputNum, DIGITS_LENGTH);
		compareQueue(inputQueue, targetQueue, DIGITS_LENGTH);
		free(inputQueue);
		times++;
	} while (inputNum != targetNum);
	puts("Congratulation!");
	printf("You found the number by %d questions.\n", times);
	free(targetQueue);
	
	return 0;
}

int *getRandomNumQueue(int length) {
	int n, i, count = 0, *array = (int *)malloc(sizeof(int) * length);
	srand((unsigned)time(NULL));
	while (count < DIGITS_LENGTH) {
		n = rand()%10;
		int isInclude = 0;
		for (i = 0; i < count; i++) {
			if (n == array[i]) {
				isInclude = 1;
				break;
			}
		}
		if (isInclude == 0) {
			array[count] = n;
			count++;
		}
	}
	return array;
}

int buildNumBasedOnQueue(int *queue, int length) {
	int n = 1, i, result = 0;
	if (length != DIGITS_LENGTH) {
		return 0;
	}
	for (i=0; i<length; i++) {
		result += queue[i]*n;
		n *= 10;
	}
//	printf("%d\n", result);
	return result;
}

int *buildNumQueueBasedOnNum(int num, int length) {
	int i, numTemp = num, operator=1;
	int *array = (int *)malloc(sizeof(int)*length);
	
	for (i=0; i<length; i++) {
		array[i] = (numTemp/operator) % 10;
		operator *= 10;
		
	}
	return array;
}

void compareQueue(int *queueA, int *queueB, int length) {
	int i, j, hintCount = 0, blowCount = 0;
	for (i = 0; i < length; i++) {
		for(j = 0; j < length; j++) {
			if (queueA[i] == queueB[j]) {
				if (i == j) {
					hintCount += 1;
				} else {
					blowCount += 1;
				}
			}
		}
	}
	printf("%dH%dB\n", hintCount, blowCount);
}
