//
//  sort.c
//  ds
//
//  Created by Apple on 2020/8/22.
//  Copyright © 2020 louts. All rights reserved.
//

#include "sort.h"

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
    if(!base)
        return;
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

static void insert_sort(void *base,size_t length,size_t size,cmp_func cmp)
{
    char i,j;
    void *cur = malloc(size);
    if(!base)
        return;
    for(i =1 ; i<length;i++){
        VOL(cur, base+i*(size), size);
        for(j = i - 1;j>=0&& cmp(base+(j*size),cur);j--){
            VOL(base+(j+1)*size, base+(j*size),size);
        }
        VOL(base+(j+1)*size,cur,size);
    }
}

static void show_version_i(void){
    printf("s_insert 1.0\n");
}
static void show_version_s(void){
    printf("s_select 1.0\n");
}
static void show_version_b(void){
    printf("s_select 1.0\n");
}


AlgorithmsType s_sort_f ={
    .name = "s_select",
    .algorithm_mem_addr = (unsigned long)select_sort,
    .version =show_version_s,
};
AlgorithmsType b_sort_f ={
    .name = "s_bubble",
    .algorithm_mem_addr = (unsigned long)bubble_sort,
    .version =show_version_b,
};
AlgorithmsType i_sort_f ={
    .name = "s_insert",
    .algorithm_mem_addr = (unsigned long)insert_sort,
    .version =show_version_i,
};



