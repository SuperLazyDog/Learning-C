//
//  Basic.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/17.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Basic.h"

//---------------------------------------------------------------------------
//                               选择器
//---------------------------------------------------------------------------
void basicSelector(int a) {
    //a = 0  if, for, do...while
    int temp;
    //a = 1  getchar
    char charTemp;
    switch (a) {
        case 0:
            printf("input your num: ");
            scanf("%d", &temp);
            asIf(temp);
            asSwitch(temp);
            asFor(temp);
            asWhile(temp);
            asDoWhile(temp);
            break;
        case 1:
            printf("input your char: ");
            charTemp = getchar();
            printf("your char is %c\n", charTemp);
        case 2:
            scientificNotation();
        case 3:
            arrayTest();
        case 4:
            stringTest();
        case 5:
            pointTest();
        default:
            break;
    }
    
}
//---------------------------------------------------------------------------
//                          第二章，第三章  0，1
//---------------------------------------------------------------------------
//各种控制语句
//if
void asIf(int a) {
    puts("------------------------------");
    puts("        start if");
    puts("------------------------------");
    if (a > 0) {
        printf("a > 0\n");
    }else if (a == 0) {
        printf("a = 0\n");
    }else {
        printf("a < 0\n");
    }
}

//switch
void asSwitch(int a) {
    puts("------------------------------");
    puts("       start switch");
    puts("------------------------------");
    switch (a) {
        case 1:
            printf("a = 1\n");
            break;
        case 2:
            printf("a = 2\n");
            break;
        case 3:
            printf("a = 3\n");
            break;
        default:
            printf("a != 1, 2, 3\n");
            break;
    }
}

//for
void asFor(int a) {
    puts("------------------------------");
    puts("        start for");
    puts("------------------------------");
    int i;
    for(i = 0; i < a; i++) {
        printf("i = %d\n", i);
    }
}

void asWhile(int a) {
    puts("------------------------------");
    puts("        start while");
    puts("------------------------------");
    int i = 0;
    while (i < a) {
        printf("i = %d\n", i);
        i++;
    }
}

//do...while
void asDoWhile(int a) {
    puts("------------------------------");
    puts("      start do...while");
    puts("------------------------------");
    int i = 0;
    do {
        printf("i = %d\n", i);
        i++;
    }while(i < a);
}

//---------------------------------------------------------------------------
//                                 第四章  2
//---------------------------------------------------------------------------
//                       数据类型，声明与定义，类型转换
//double 科学计数法表达
void scientificNotation() {
    double a = 1.23123E2;
    double b = 1.23123e2;
    if(a == b) {
        printf("a == b\n");
        printf("a: %f, b: %f\n",a, b);
    }
}

//---------------------------------------------------------------------------
//                                 第五章  3,4
//---------------------------------------------------------------------------
//                              数组与字符串
void arrayTest() {
    int temp, i;
    int arrayTest[128];
    printf("input your num: ");
    scanf("%d", &temp);
    for(i = 0; i < sizeof(arrayTest)/sizeof(int); i++) {
        arrayTest[i] = temp;
        printf("arrayTest[%03d] = %d\n", i, arrayTest[i]);
    }
}

void stringTest() {
    //遍历字符串
    /*char temp[80];
    int i;
    printf("input your message: ");
    gets(temp);
    
    for(i = 0; temp[i]; i++) {
        printf("%c", temp[i]);
    }
    printf("\n");*/
    
    char str1[64] = "hello, i am ";
    char str2[64] = "hello, ";
    char str3[64] = "hello, i am ";
    printf("result: %s\n", strcmp(str1, str2) ? "不相同" : "相同");
    printf("out: %d\n", strcmp(str1, str2));
    puts("");
    printf("result: %s\n", strcmp(str1, str3) ? "不相同" : "相同");
    printf("out: %d\n", strcmp(str1, str3));
    
    printf("%d\n", atoi("100"));
}

//---------------------------------------------------------------------------
//                                 第六章  5
//---------------------------------------------------------------------------
//                                   指针
void pointTest() {
    //---------------------------------------------
    //               测试声明与使用
    //---------------------------------------------
    puts("//---------------------------------------------");
    puts("//               测试声明与使用");
    puts("//---------------------------------------------");
    int *a, b;
    b = 1;
    a = &b;
    printf("*a = %d\n", *a);
    printf("adress of a: %d\n", a);
    
    //---------------------------------------------
    //               测试声明与使用
    //---------------------------------------------
    puts("//---------------------------------------------");
    puts("//               测试声明与使用");
    puts("//---------------------------------------------");
    
}
