//
//  20180605_01.c
//  School
//
//  Created by 徐伟达 on 2018/6/5.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char fname[128];
	FILE *fp;
	int chr, count[52], i;
	char path[128] = "/Users/xuweida/Desktop/github/Learning-C/School/School/20180605/";
	scanf("%s", fname);
	fp = fopen(strcat(path, fname), "r");
	if (fp == NULL) {
		fprintf(stderr, "cannot open %s\n", fname);
	}
	for (i=0; i<52; i++) {
		count[i] = 0;
 	}
	while ((chr = getc(fp)) != EOF) {
		if (chr >=97 && chr <= 121) {
			count[chr-97]++;
		} else if (chr >=65 && chr <= 90) {
			count[chr-39]++;
		}
	}
	fclose(fp);
	for (i = 0; i < 52; i++) {
		if (i<=25) {
			printf("%c  %d\n", i+97, count[i]);
		} else {
			printf("%c  %d\n", i+39, count[i]);
		}
	}
	
}
