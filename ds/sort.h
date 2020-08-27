//
//  sort.h
//  ds
//
//  Created by Apple on 2020/8/22.
//  Copyright © 2020 louts. All rights reserved.
//

#ifndef sort_h
#define sort_h
#include <stdbool.h>
#include <stdio.h>
#include "common.h"
#define SWAP(a, b, size) \
do{                            \
    size_t __size = (size);                \
    char *__a = (a), *__b = (b);        \
    do{                \
        char __tmp = *__a;                \
        *__a++ = *__b;                    \
        *__b++ = __tmp;                    \
    } while (--__size > 0);                \
} while (0)


typedef  bool (*cmp_func)(const void * ,const void *) ;
typedef  void (*sort_func)(void *base ,size_t length,size_t size,cmp_func) ;


#endif /* sort_h */
