//
//  sort.c
//  ds
//
//  Created by Apple on 2020/8/22.
//  Copyright © 2020 louts. All rights reserved.
//

#include "sort.h"


/**
* swap values
* @a: value 1
* @b: value 2
* swap a and b
 */
void swap(elem_type *a,elem_type *b)
{
    elem_type temp = *a;
    *a = *b;
    *b = temp;
}

/**
* cmp compare values
* @a: value 1
* @b: value 2
* @sym: '>' or '<'
*compare the values a and b according to the symbol
 */
bool cmp(elem_type a,elem_type b,char sym)
{
    if(sym ==  '>')
       return a>b ? true: false;
    if(sym ==  '<')
       return a<b ? true: false;
    return false;
}
/**
* bubble_sort - bubble sort function.
* @elem_elem_arry: Collection of all elements
* @length: collection of all elements length
* @symbol: '>' or '<'  ascending or descending order
*complete the data ascending and descending sorting
*/
void bubble_sort(elem_type *elem_arry ,uint8_t length,order symbol,bool (*cmp)(elem_type ,elem_type,char sym))
{
    uint8_t flag = 0,
            i = 0,
            j = 0,
            post = 0,
            t_length =length -1;
    
    if (!elem_arry)
        return;
    for (i = 0; i < length-1; i++) {
        flag = 1;
        for (j = 0; j < t_length; j++) {
            if (cmp(elem_arry[j],elem_arry[j+1],symbol)) {
                swap(&elem_arry[j],&elem_arry[j+1]);
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
        printf(" %d ",elem_arry[i]);
    }
    printf("\n");
#endif
}
