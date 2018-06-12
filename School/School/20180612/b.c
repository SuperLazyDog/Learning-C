//
//  b.c
//  School
//
//  Created by 徐伟达 on 2018/6/12.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>

int gcd_(int a, int b) {
	int d = a%b;
	if (d == 0) {
		return b;
	} else {
		return gcd(b, d);
	}
}

struct rational {
	int num;
	int den;
};

struct rational rational_add(struct rational a, struct rational b)
{
	struct rational c;
	int tmp;
	c.num = a.num * b.den + b.num * a.den;
	c.den = a.den * b.den;
	
	tmp = gcd(c.num, c.den);
	c.num /= tmp;
	c.den /= tmp;
	
	return c;
}

struct rational rational_sub(struct rational a, struct rational b)
{
	struct rational c = b;
	c.num *= -1;
	return rational_add(a, c);
}

struct rational rational_mul(struct rational a, struct rational b)
{
	// m/n * s/t = ms/nt
	struct rational c;
	int tmp;
	c.num = a.num * b.num;
	c.den = a.den * b.den;
	tmp = gcd(c.num, c.den);
	
	c.num /= tmp;
	c.den /= tmp;
	
	return c;
}

struct rational rational_div(struct rational a, struct rational b)
{
	// m/n / s/t = m/n * t/s
	struct rational c;
	c.num = b.den;
	c.den = b.num;
	
	return rational_mul(a, c);
}

void rational_print(struct rational a)
{
	if (a.den > 0) {
		printf("%d/%d\n", a.num, a.den);
	} else {
		printf("%d/%d\n", -a.num, -a.den);
	}
}

int main_20180612_b(void)
{
	struct rational x, y, z;
	
	x.num = 1; x.den = 3;
	y.num = 1; y.den = 2;
	z = rational_add(x, y);
	rational_print(z);
	z = rational_sub(x, y);
	rational_print(z);
	z = rational_mul(x, y);
	rational_print(z);
	z = rational_div(x, y);
	rational_print(z);
	
	return 0;
}
