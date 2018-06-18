//
//  Matricx.c
//  School
//
//  Created by 徐伟达 on 2018/6/15.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include "Matricx.h"

double **alloc_matrix(int n, int m)
{
	double **a;
	int i;
	
	a = (double **)malloc(sizeof(double *) * n);
	a[0] = (double *)malloc(sizeof(double) * n * m);
	for (i=1; i<n; i++) {
		a[i] = a[0] + i * m;
	}
	
	return a;
}

void free_matrix(double **a)
{
	free(a[0]);
	free(a);
}

// a: n x m, b: m x s, c: n x s
void m_m_mul1(double **a, double **b, double **c, int n, int m, int s)
{
	int i, j, k;
	int i1, j1, k1;
	
	for (i=0; i<n; i++) {
		for (j=0; j<s; j++) {
			c[i][j] = 0.0;
		}
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<s; j++) {
			for (k=0; k<m; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

// a: n x m, b: m x s, c: n x s
void m_m_mul2(double **a, double **b, double **c, int n, int m, int s)
{
	int i, j, k;
	int i1, j1, k1;
	
	for (i=0; i<n; i++) {
		for (j=0; j<s; j++) {
			c[i][j] = 0.0;
		}
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			for (k=0; k<s; k++) {
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}
}

// a: n x m, b: m x s, c: n x s, l: block size
void m_m_mul3(double **a, double **b, double **c, int n, int m, int s, int l)
{
	int i, j, k;
	int i1, j1, k1;
	
	for (i=0; i<n; i++) {
		for (j=0; j<s; j++) {
			c[i][j] = 0.0;
		}
	}
	
	for (i=0; i<n/l; i++) {
		for (j=0; j<s/l; j++) {
			for (k=0; k<m/l; k++) {
				for (i1=0; i1<l; i1++) {
					for (j1=0; j1<l; j1++) {
						for (k1=0; k1<l; k1++) {
							c[i*l+i1][j*l+j1] += a[i*l+i1][k*l+k1] * b[k*l+k1][j*l+j1];
						}
					}
				}
			}
		}
	}
}
