//
//  main.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/17.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include <stdio.h>

#include "test.h"
//#define INCLUDE_TEST_H

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
#ifdef INCLUDE_TEST_H
    printA(a);
#endif
    return 0;
}
