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
    printf("version: 1.0\n");
}
static void show_version_s(void){
    printf("version: 1.0\n");
}
static void show_version_b(void){
    printf("version 1.0\n");
}

#define ICMP(a,b) if(strcmp(a,b) == 0)
static void dump_data(void *base,size_t size,size_t len,...)
{
    int count =0;
    va_list pArgs;
    va_start(pArgs, len);
    char *par = va_arg(pArgs, char *);
    va_end(pArgs);
    ICMP(par,"%d"){
        for (count = 0; count<len; count ++) {
            printf(" %d ",*(int*)(base+count*size));
        }
    }
    ICMP(par,"%x"){
        printf("\n");
        for (count = 0; count<len; count ++) {
            printf(" %x ",*(int*)(base+count*size));
        }
        printf("\n");
    }
    ICMP(par,"%s"){
        printf("%s\n",base);
    }
}


AlgorithmsType s_sort_f ={
    .name = "SS",
    .long_name ="SS :(select sort).",
    .algorithm_mem_addr = (unsigned long)select_sort,
    .dump =dump_data,
    .version =show_version_s,
};
AlgorithmsType b_sort_f ={
    .name = "BS",
    .long_name ="BS :(bubble sort).",
    .algorithm_mem_addr = (unsigned long)bubble_sort,
    .dump =dump_data,
    .version =show_version_b,
};
AlgorithmsType i_sort_f ={
    .name = "IS",
    .long_name ="IS :(insert sort).",
    .algorithm_mem_addr = (unsigned long)insert_sort,
    .dump =dump_data,
    .version =show_version_i,
};



