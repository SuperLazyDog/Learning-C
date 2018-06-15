//
//  a.c
//  School
//
//  Created by 徐伟达 on 2018/6/12.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>

int gcd(int a, int b) {
	int d = a%b;
	if (d == 0) {
		return b;
	} else {
		return gcd(b, d);
	}
}

int main_pk20180615(void)
{
	printf("%d\n", gcd(48, 24));
	printf("%d\n", gcd(36, 54));
	printf("%d\n", gcd(25, 15));
	printf("%d\n", gcd(54, 27));
	printf("%d\n", gcd(54, 48));
	printf("%d\n", gcd(64, 72));
	printf("%d\n", gcd(90, 80));
	printf("%d\n", gcd(12, 30));
	
	return 0;
}
