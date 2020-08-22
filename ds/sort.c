//
//  sort.c
//  ds
//
//  Created by Apple on 2020/8/22.
//  Copyright © 2020 louts. All rights reserved.
//

#include "sort.h"
bool cmp(elem_type a,elem_type b,char sym)
{
    if(sym ==  '>')
       return a>b ? true: false;
    if(sym ==  '<')
       return a<b ? true: false;
    return false;
}
void ble_sort(elem_type *arry ,uint8_t length,char symbol,bool (*cmp)(elem_type ,elem_type,char sym))
{
    uint8_t temp = 0,
            flag = 0,
            i = 0,
            j = 0,
            post = 0,
            t_length =length -1;
    
    if (!arry)
        return;
    for (i = 0; i < length-1; i++) {
        flag = 1;
        for (j = 0; j < t_length; j++) {
            if (cmp(arry[j],arry[j+1],symbol)) {
                temp = arry[j+1];
                arry[j+1] = arry[j];
                arry[j] = temp;
                flag = 0;
                post = j;
            }
        }
        t_length = post;
        if(flag)
            break;
    }
#define DUMP
#ifdef DUMP
    printf("data =");
    for (i =0; i<length; i++) {
        printf(" %d ",arry[i]);
    }
    printf("\n");
#endif
}
