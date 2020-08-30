//
//  common.h
//  ds
//
//  Created by Apple on 2020/8/27.
//  Copyright © 2020 louts. All rights reserved.
//

#ifndef common_h
#define common_h
#include "linklist.h"
typedef struct  AlgorithmsType{
    const char *name ;
    int flag ;
    void *data;
    void (*version)(void);
    unsigned long algorithm_mem_addr;
    list_node list;
}AlgorithmsType;



#endif /* common_h */
