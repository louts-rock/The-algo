//
//  main.c
//  ds
//
//  Created by Apple on 2020/8/18.
//  Copyright © 2020 louts. All rights reserved.
//

#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
#include "linklist.h"
#include "main.h"

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
    if(val > 0)
        return true;
    else
        return false;
        
}


#if 1
int main(int argc, const char * argv[]) {
    
    int a[11]={1,3,2,4,0,6,9,23,45,87,56};
    at_register(&i_sort_f);
    at_register(&b_sort_f);
    at_register(&s_sort_f);
    AlgorithmsType *p=at_find_by_name("s_select");
    p->version();
    sort_func sort =(sort_func)p->algorithm_mem_addr;
    sort(a,11,4,cmp);
    for (int i =0;i<11 ; i++) {
        printf(" %d ",a[i]);
    }
    printf("\n");
    return 0;
}
#endif
