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
    const char *long_name;
    int flag ;
    void *data;
    void (*version)(void);
    void (*dump)(void *base,size_t size,size_t len,...);
    unsigned long algorithm_mem_addr;
    list_node list;
}AlgorithmsType;



#endif /* common_h */
