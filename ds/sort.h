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

#define elem_type int
void bubble_sort(void *base ,size_t length,size_t width,bool (*cmp)(const void * ,const void *));
void select_sort(int arr[], int length);
#endif /* sort_h */
