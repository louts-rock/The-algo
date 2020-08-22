//
//  main.c
//  ds
//
//  Created by Apple on 2020/8/18.
//  Copyright © 2020 louts. All rights reserved.
//

#include <stdio.h>

void ble_sort(int *src ,uint32_t num,uint8_t direct)
{
    uint8_t i = 0,j = 0;
    uint8_t temp = 0,flag = 0;
    uint8_t len =num -1 ;
    uint8_t post = 0;
    if (!src)
        return;
    for (i = 0; i < num-1; i++) {
        flag = 1;
        for (j = 0; j < len; j++) {
            if(direct > 0){
                if(src[j] > src[j+1]){
                    temp = src[j+1];
                    src[j+1] = src[j];
                    src[j] = temp;
                    flag = 0;
                    post = j;
                }
            }else{
                if(src[j] < src[j+1]){
                    temp = src[j+1];
                    src[j+1] = src[j];
                    src[j] = temp;
                    flag = 0;
                    post = j;
                }
            }
        }
        len = post;
        if(flag)
            break;
    }
#define DUMP
#ifdef DUMP
    printf("data =");
    for (i =0; i<num; i++) {
        printf(" %d ",src[i]);
    }
    printf("\n");
#endif
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    return 0;
}
