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
void bubble_sort(void *base ,size_t length, size_t width,bool (*cmp)(const void * ,const void *))
{
    uint8_t flag = 0,
            i = 0,
            j = 0,
            post = 0,
            t_length =length -1;
    #define DUMP
       #ifdef DUMP
           printf("data =");
           for (i =0; i<length; i++) {
               printf(" %d ",*(int*)(base+i*width));
           }
           printf("\n");
       #endif
    if (!base)
        return;
    for (i = 0; i < length-1; i++) {
        flag = 1;
        for (j = 0; j < t_length; j++) {
            if (cmp(base+j*width,base+(j+1)*width)) {
                SWAP(base+j*width,base+(j+1)*width,width);
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
               printf(" %d ",*(int*)(base+i*width));
           }
           printf("\n");
       #endif
}
void select_sort(int arr[], int length)
{
    for (int i = 0; i < length; i++){
        int index = i;
        for (int j = i+1; j < length; j++){
            if (arr[j] < arr[index]){
                index = j;
            }
        }
        if (index == i)
            continue;
        else{
            int temp;
            temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
           }
    }
    #define DUMP
    #ifdef DUMP
        printf("data =");
        for (int i =0; i<length; i++) {
            printf(" %d ",arr[i]);
        }
        printf("\n");
    #endif

}
