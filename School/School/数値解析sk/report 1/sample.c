//
//  sample.c
//  School
//
//  Created by 徐伟达 on 2018/6/15.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//double **alloc_matrix(int n, int m)
//{
//	double **a;
//	int i;
//	
//	a = (double **)malloc(sizeof(double *) * n);
//	a[0] = (double *)malloc(sizeof(double) * n * m);
//	for (i=1; i<n; i++) {
//		a[i] = a[0] + i * m;
//	}
//	
//	return a;
//}
//
//void free_matrix(double **a)
//{
//	free(a[0]);
//	free(a);
//}
//
//// a: n x m, b: m x s, c: n x s
//void m_m_mul(double **a, double **b, double **c, int n, int m, int s)
//{
//	int i, j, k;
//	int i1, j1, k1;
//	
//	for (i=0; i<n; i++) {
//		for (j=0; j<s; j++) {
//			c[i][j] = 0.0;
//		}
//	}
//	
//	for (i=0; i<n; i++) {
//		for (k=0; k<m; k++) {
//			for (j=0; j<s; j++) {
//				c[i][j] += a[i][k] * b[k][j];
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int i, j, n;
//	double **a;
//	double **b;
//	double **c;
//	
//	clock_t start, end;
//	
//	scanf("%d", &n);
//	
//	a = alloc_matrix(n,n);
//	b = alloc_matrix(n,n);
//	c = alloc_matrix(n,n);
//	
//	for (i=0; i<n; i++) {
//		for (j=0; j<n; j++) {
//			a[i][j] = rand()/(double)RAND_MAX;
//			b[i][j] = rand()/(double)RAND_MAX;
//		}
//	}
//	
//	start = clock();
//	
//	m_m_mul(a, b, c, n, n, n);
//	
//	end = clock();
//	
//	printf("%g\n", (double)(end-start)/CLOCKS_PER_SEC);
//	
//	free_matrix(a);
//	free_matrix(b);
//	free_matrix(c);
//	
//	return 0;
//}
