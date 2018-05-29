//
//  main.c
//  School
//
//  Created by 徐伟达 on 2018/5/29.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>

int main() {
	int target, i;
	scanf("%d", &target);
	
	for (i = 10; target/10 > 0; i *=10) {
		printf("%d\n", target%10);
		target /= 10;
	}
	printf("%d\n", target%10);
	return 0;
}
