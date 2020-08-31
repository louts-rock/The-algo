//
//  main.h
//  ds
//
//  Created by Apple on 2020/8/30.
//  Copyright © 2020 louts. All rights reserved.
//

#ifndef main_h
#define main_h
#include <stdlib.h>
#include <string.h>
struct list_head at_head = INIT_LIST_HEAD(at_head);
extern AlgorithmsType b_sort_f;
extern AlgorithmsType i_sort_f;
extern AlgorithmsType s_sort_f;

static inline void  at_register_onec(AlgorithmsType *Algorithms){
        if(!Algorithms)
            return;
        list_add(&Algorithms->list,&at_head);
}

static inline AlgorithmsType *  at_find_by_name(char *name){
    list_node *p;
    list_for_each(p, &at_head){
        AlgorithmsType *at_p =container_of(p,AlgorithmsType,list);
        if (strcmp(at_p->name,name) == 0) {
            return at_p;
        }
    }
    return NULL;
}




#endif /* main_h */
