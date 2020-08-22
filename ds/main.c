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
    int temp[5]={2,1,4,7,3};
    ble_sort(temp,5,'<',cmp);
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    return 0;
}
