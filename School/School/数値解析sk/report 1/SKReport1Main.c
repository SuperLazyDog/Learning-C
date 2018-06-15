//
//  SKReport1Main.c
//  School
//
//  Created by 徐伟达 on 2018/6/15.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "Matricx.h"

#define TIMES 1
//plot "data.txt" using 1:2 title "mm-multi1" with lines,"data.txt" using 1:3 title "mm-multi2" with lines,"data.txt" using 1:4 title "mm-multi3" with lines

void test(int n);
//int main_SK20180612() {
int main(void) {
	puts("formatter: n time1 time 2 time3");
	int n[] = {10, 50, 100, 200, 400, 600, 1200, 2400};
	for (int i = 0; i<sizeof(n)/sizeof(int); i++) {
		test(n[i]);
	}
	return 0;
}

void test(int n) {
	int i, j;
	double **a;
	double **b;
	double **c;
	double sum1=0, sum2=0, sum3=0;
	
	clock_t start, end;
	
//	scanf("%d", &n);
	
	a = alloc_matrix(n,n);
	b = alloc_matrix(n,n);
	c = alloc_matrix(n,n);
	
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			a[i][j] = rand()/(double)RAND_MAX;
			b[i][j] = rand()/(double)RAND_MAX;
		}
	}
//	puts("--------------------------------------------");
//	puts("				   test");
//	puts("--------------------------------------------");
	// test 1
	for (int i = 0; i<TIMES; i++) {
		start = clock();
		m_m_mul1(a, b, c, n, n, n);
		end = clock();
		sum1 += (double)(end-start);
		
		start = clock();
		m_m_mul2(a, b, c, n, n, n);
		end = clock();
		sum2 += (double)(end-start);
		
		start = clock();
		m_m_mul3(a, b, c, n, n, n, n/10);
		end = clock();
		sum3 += (double)(end-start);
		
	}
	sum1 /= TIMES*CLOCKS_PER_SEC;sum2 /= TIMES*CLOCKS_PER_SEC;sum3 /= TIMES*CLOCKS_PER_SEC;
	printf("n=%d %g %g %g\n", n, sum1, sum2, sum3);
//	printf("n=%d\n", n);
//	printf("time1: %g\n", sum1);
//	printf("time2: %g\n", sum2);
//	printf("time3: %g\n", sum3);
	
	free_matrix(a);
	free_matrix(b);
	free_matrix(c);
}
