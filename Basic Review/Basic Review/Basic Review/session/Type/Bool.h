//
//  Bool.h
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/18.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#ifndef Bool_h
#define Bool_h

#include <stdio.h>

enum bools {
    true = 1,
    false = 0,
};
typedef enum bools bool;
#define BOOL_STR(b) ((b) ? "true":"false")

#endif /* Bool_h */
