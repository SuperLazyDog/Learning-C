//
//  20181002.c
//  School
//
//  Created by 徐伟达 on 2018/10/2.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "20181002.h"


int card[10];
int flag[11];
int gsum = 0;

void solve(int n)
{
	int i;
	if (n == 10) {
		int sum = 0;
		for (i=1; i<10; i++) {
			sum += abs(card[i] - card[i+1]);
		}
		
		if (gsum < sum) {
			gsum = sum;
		}
		return;
	}
	
	for (i=1; i<=10; i++) {
		if (flag[i] == 1) continue;
		card[n] = i;
		flag[i] = 1;
		solve(n+1);
		flag[i] = 0;
	}
}

int main_20181002()
{
	int i;
	
	for (i=1; i<=10; i++) {
		flag[i] = 0;
	}
	
	solve(0);
	printf("sum: %d\n", gsum);
	return 0;
}
