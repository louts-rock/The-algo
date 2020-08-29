//
//  sort.c
//  ds
//
//  Created by Apple on 2020/8/22.
//  Copyright © 2020 louts. All rights reserved.
//

#include "sort.h"
/**
* bubble_sort - bubble sort function.
* @elem_elem_arry: Collection of all elements
* @length: collection of all elements length
* @symbol: '>' or '<'  ascending or descending order
*complete the data ascending and descending sorting
*/
static void bubble_sort(void *base ,size_t length, size_t size,cmp_func cmp)
{
    uint8_t flag = 0,
            i = 0,
            j = 0,
            post = 0,
            t_length =length -1;
    if (!base)
        return;
    for (i = 0; i < length-1; i++) {
        flag = 1;
        for (j = 0; j < t_length; j++) {
            if (cmp(base + j * size, base + (j + 1) * size)) {
                SWAP(base + j * size, base + (j+1) * size, size);
                flag = 0;
                post = j;
            }
        }
        t_length = post;
        if(flag)
            break;
    }
  
}
static void select_sort(void *base ,size_t length,size_t size,cmp_func cmp)
{
    uint8_t i ,j ;
    for ( i = 0; i < length; i++){
        uint8_t index = i;
        for (j = i+1; j < length; j++){
            if (cmp(base + j * size , base + index * size)){
                index = j;
            }
        }
        if (index == i)
            continue;
        else{
            SWAP(base + index* size, base + i * size, size);
        }
    }
}

AlgorithmsType s_sort_f ={
    .name = "s_select",
    .algorithm_mem_addr = (unsigned long)select_sort,
};
AlgorithmsType b_sort_f ={
    .name = "s_bubble",
    .algorithm_mem_addr = (unsigned long)bubble_sort,
};



