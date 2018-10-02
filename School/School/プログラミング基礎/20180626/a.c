//
//  a.c
//  School
//
//  Created by 徐伟达 on 2018/6/26.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main_20180626(void)
{
	int a[10000];
	int n, i, j, carry, tmp;
	
	a[0] = 1;
	n = 1;
	for (i=2; i<=1000; i++) {
		carry = 0;
		tmp = 0;
		for (j=0; j<n; j++) {
			carry = a[j]*i;
			a[j] = carry%10000 + tmp;
			if (carry>=10000) {
				tmp = carry/10000;
				if (j+1<=n-1) {
					carry =  tmp + a[j+1]*i;
				} else {
					carry = tmp;
				}
			} else {
				carry = 0;
				tmp = 0;
			}
			
		}
		if (carry != 0) {
			a[n] = carry;
			n++;
		}
	}
	
	for (j=n-1; j>=0; j--) {
		printf("%04d", a[j]);
	}
	printf("\n");
	
	return 0;
}
