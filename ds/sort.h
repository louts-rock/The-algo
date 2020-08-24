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
typedef enum {
    ascend = '>',
    descend = '<',
}order;
#define elem_type int
void swap(elem_type *a,elem_type *b);
bool cmp(elem_type a,elem_type b,char sym);
void bubble_sort(elem_type *elem_arry ,uint8_t length,order symbol,bool (*cmp)(elem_type ,elem_type,char sym));
#endif /* sort_h */
