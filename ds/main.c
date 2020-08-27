//
//  main.c
//  ds
//
//  Created by Apple on 2020/8/18.
//  Copyright © 2020 louts. All rights reserved.
//

#include <stdio.h>
#include "sort.h"

/**
* cmp compare values
* @a: value 1
* @b: value 2
* @sym: '>' or '<'
*compare the values a and b according to the symbol
 */
static bool cmp(const void *a,const void *b)
{
    int val =(*(int*)a) - (*(int*)b);
    if(val < 0)
        return true;
    else
        return false;
        
}

int main(int argc, const char * argv[]) {
    int a[6]={1,3,2,4,0,6};
    //select_sort(a, 6,sizeof(int),cmp);
    //bubble_sort(a, 6,sizeof(int),cmp);
    printf("data =");
    for (int i =0;i<6 ; i++) {
        printf(" %d ",a[i]);
    }
    printf("\n");
    return 0;
}
