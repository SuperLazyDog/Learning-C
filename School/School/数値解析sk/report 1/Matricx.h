//
//  Matricx.h
//  School
//
//  Created by 徐伟达 on 2018/6/15.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#ifndef Matricx_h
#define Matricx_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double **alloc_matrix(int n, int m);
void free_matrix(double **a);
void m_m_mul1(double **a, double **b, double **c, int n, int m, int s);
void m_m_mul2(double **a, double **b, double **c, int n, int m, int s);
void m_m_mul3(double **a, double **b, double **c, int n, int m, int s, int l);
#endif /* Matricx_h */
