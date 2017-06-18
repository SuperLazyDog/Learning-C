//
//  AlgorithmSelector.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef AlgorithmSelector_h
#define AlgorithmSelector_h

#include <stdio.h>
#include "Search.h"
#include "List.h"

enum algorithm {//选择器的列举型
    search,
    list,
    other
};

//---------------------------------------------------------------------------
//                               选择器
//---------------------------------------------------------------------------
void algorithmSelector(int num);

#endif /* AlgorithmSelector_h */
