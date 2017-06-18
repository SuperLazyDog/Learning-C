//
//  Basic.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/17.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Basic.h"
#define GETSTR_MEMSET false
//---------------------------------------------------------------------------
//                               本地函数声明
//---------------------------------------------------------------------------
void recursive(int a);
void pointArguments(int *a, int *b);

//第十二章 动态分配内存
//bool mallocPro(void *p, long unsigned size);
//---------------------------------------------------------------------------
//                               选择器
//---------------------------------------------------------------------------
void basicSelector(int a) {
    //a = 0  if, for, do...while
    int temp;
    //a = 1  getchar
    char charTemp;
    puts("start basic review");
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
            break;
        case 2:
            scientificNotation();
            break;
        case 3:
            arrayTest();
            break;
        case 4:
            stringTest();
            break;
        case 5:
            pointTest();
            break;
        case 6:
            funcTest();
            break;
        case 7:
            IOTest();
            break;
        case 8:
            structTest();
            unionTest();
            break;
        case 10:
            highTopic();
            break;
        default:
             puts("nothing matches requirement");
            break;
    }
    puts("end basic review");
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
    int i;
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
    printf("adress of a: %p\n", a);
    
    //---------------------------------------------
    //                   测试
    //---------------------------------------------
    puts("//---------------------------------------------");
    puts("//                   测试");
    puts("//---------------------------------------------");
    int testA[128], testB[128];
    for(i = 0; i < sizeof(testB)/sizeof(int); i++) {
        testB[i] = i;
    }
    *testA = *testB;
    for(i = 0; i < sizeof(testA)/sizeof(int); i++) { //给testB赋值
        printf("testA[%d] = %d   ", i, testA[i]);
        printf("testB[%d] = %d\n", i, testB[i]);
    }//说明不可以直接把数组复制
    int *p;
    p = testB; //p指向testB的开头
    i = 0;
    while (i < sizeof(testB)/sizeof(int)) {//指针遍历数组
        printf("testB[%d] = %d\n", i, *(p++));
        //p++;
        i++;
    }
}

//---------------------------------------------------------------------------
//                                 第七章  6
//---------------------------------------------------------------------------
//                                   函数
void funcTest() {
    //递归
    recursive(0);
    int a = 10, b = 5;
    pointArguments(&a, &b);
}

void recursive(int a) {
    if(a < 20) {
        printf("a = %d\n", a);
        recursive(a+1);
    }else {
        printf("a == 20 : %s\n", a==20 ? "true":"false");
    }
}

void pointArguments(int *a, int *b) {
    int temp = *b;
    printf("a = %2d\tb = %2d\n", *a, *b);
    *b = *a;
    *a = temp;
    printf("a = %2d\tb = %2d\n", *a, *b);
}

//---------------------------------------------------------------------------
//                                 第八章  7
//---------------------------------------------------------------------------
//                                输入输出 I/O
void IOTest() {
    puts("//---------------------------------------------");
    puts("//                 gets测试");
    puts("//---------------------------------------------");
    /*printf("EOF = %d\n", EOF);
    puts("input your str");
    char *temp, temp1[128];
    temp = gets(temp1);
    printf("your str \"%s\"\n",temp);
    printf("your str \"%s\"\n",temp1);*/
    puts("//---------------------------------------------");
    puts("//                 scanf测试");
    puts("//---------------------------------------------");
    printf("input you num as 123.123: ");
    int a,b;//[a-ZA-Z0-9]
    scanf("%d %*f %d", &a, &b);
    printf("a: %d   b: %d\n", a, b);
    
}

//# TODO: 第九章 文件的输入输出暂时省略 440DF976-D4A2-4BFB-9AC8-82EC722C6959

//---------------------------------------------------------------------------
//                                 第十章  8
//---------------------------------------------------------------------------
//                               结构体和共用体
struct test {
    int a;
    int b;
};
typedef struct test Test;
bool structTest() {
    /*Test test[2] = {
        {.a = 1, .b = 2},
        {.a = 3, .b = 4}
    };*/
    Test test1 = {
        .a = 1,
        .b = 2
    }, *test2;
    test2 = &test1;
    if (test1.a == test2->a) {
        printf("test1.a = test2.a? : %s\n", BOOL_STR(test1.a == test2->a));
        return true;
    }
    return false;
}

void unionTest() {
}
//# TODO: 第十章后半部分(p307~)及第十一章十二章部分省略 C2237A39-AD6A-4AF4-8CEC-0D284B549543
//---------------------------------------------------------------------------
//                                 第十二章  10
//---------------------------------------------------------------------------
//                             暂时只看动态分配内存
void highTopic() {
    int i, *j = NULL;
    puts("------------");
    for(i = 0; i < 100; i++) {
        if(mallocPro(j, sizeof(int)*4, GETSTR_MEMSET)) {
            printf("mallocPro freed\n");
            free(j);
        }
        if(callocPro(j, 2, sizeof(int)*4, GETSTR_MEMSET)) {
            printf("callocPro freed\n");
            free(j);
        }
        puts("------------");
    }
}

/*bool mallocPro(void *p, long unsigned size) {
    p = malloc(size);
    if(!p) {
        printf("false\n");
        return false;
    }
    printf("true\n");
    return true;
}*/
