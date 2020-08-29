//
//  linklist.h
//  ds
//
//  Created by Apple on 2020/8/28.
//  Copyright © 2020 louts. All rights reserved.
//

#ifndef linklist_h
#define linklist_h

typedef struct list_head{
    struct list_head *prev,*next;
}list_node;

#define INIT_LIST_HEAD(name) { &(name),&(name)}

#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)
#define list_for_each(pos,head) \
    for(pos = (head)->next;pos->next,pos != head;\
            pos= pos->next)

#endif /* linklist_h */
