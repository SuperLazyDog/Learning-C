//
//  CBD.h
//  Basic Review
//
//  Created by 徐伟达 on 2018/1/17.
//  Copyright © 2018年 徐伟达. All rights reserved.
//
/*---------------------------------------------------------------------------
							       任务表
 ----------------------------------------------------------------------------
 
 ---------------------------------------------------------------------------*/
#ifndef CBD_h
#define CBD_h

#include <stdio.h>
//#include "AlgorithmSelector.h"
#include "Sort.h"

//---------------------------------------------------------------------------
//                                数据定义
//---------------------------------------------------------------------------
enum CBDItem {
	max,
	middle,
	small
};
//---------------------------------------------------------------------------
//                               选择器
//---------------------------------------------------------------------------
void CBDTestSelector(enum CBDItem selector);

#endif /* CBD_h */
