//
//  other.c
//  ds
//
//  Created by Apple on 2020/11/23.
//  Copyright © 2020 louts. All rights reserved.
//

#include "other.h"
int llsubstr(const char * s)
{
    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[(int)*(s+start)] = 1;
    while( *(s+end) != 0 ){
        maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
        ++end;
        while( 0 != map[ (int)*(s+end) ] ){
            map[ (int)*(s+start) ] = 0;
               ++start;
        }
        map[(int)*(s+end)] = 1;
    }
    return maxlen;
}
