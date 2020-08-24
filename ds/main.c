//
//  main.c
//  ds
//
//  Created by Apple on 2020/8/18.
//  Copyright © 2020 louts. All rights reserved.
//

#include <stdio.h>
#include "sort.h"


int main(int argc, const char * argv[]) {
    int a[6]={1,3,2,4,0,6};
    bubble_sort(a, 6,descend, cmp);
    printf("Hello, World!\n");
    return 0;
}
