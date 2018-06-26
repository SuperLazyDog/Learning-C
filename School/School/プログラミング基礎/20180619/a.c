//
//  a.c
//  School
//
//  Created by 徐伟达 on 2018/6/19.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>

int main_20180619(int argc, char *argv[])
{
	FILE *fp;
	int i, n;
	double x, y, a, b;
	double sumX, sumY, sumXY, sumX2;
	sumX = sumY = sumXY = sumX2 = 0;
	
	if (argc != 2) {
		fprintf(stderr, "file name needed\n");
		return 1;
	}
	
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", argv[1]);
		return 1;
	}
	
	fscanf(fp, "%d", &n);
	
	for (i=0; i<n; i++) {
		fscanf(fp, "%lf", &x);
		fscanf(fp, "%lf", &y);
		sumX += x;
		sumY += y;
		sumXY += x*y;
		sumX2 += x*x;
	}
	
	fclose(fp);
	
	a = (n*sumXY-sumX*sumY)/(n*sumX2 - sumX*sumX);
	b = (sumX2*sumY- sumXY*sumX)/(n*sumX2 - sumX*sumX);
	printf("a: %f, b: %f\n", a, b);
	
	return 0;
}
