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
#include "Tree.h"
#include "SampleDataStruct.h"
#include "Hash.h"
#include "Hash_OpenAdressing.h"
#include "Stack.h"
#include "Queue.h"
#include "Recurse.h"
#include "Sort.h"

// # TODO: list, hash等，进一步封装   F25CEB2E-B31D-4DB3-9600-A0390865832E
enum algorithm {//选择器的列举型
    search,
    list,
    tree,
    hash,
    sampleDataStruct,
    hash_OpenAdressing,
    stack,
    queue,
    recurse,
    sort,
    other
};

//---------------------------------------------------------------------------
//                               选择器
//---------------------------------------------------------------------------
void algorithmSelector(int num);

#endif /* AlgorithmSelector_h */
