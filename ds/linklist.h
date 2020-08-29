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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static inline void LIST_HEAD_INIT(struct list_head *list)
{
    list->next =list;
    list->prev =list;
}
static inline void __list_add(list_node *new,list_node *prev,list_node *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}
static inline void list_add(list_node *new,struct list_head *head)
{
    __list_add(new,head,head->next);
}
static inline void list_add_tail(list_node *new,struct list_head *head)
{
    __list_add(new,head->prev,head);
}

static inline bool __list_add_valid(list_node *new,list_node *prev,list_node *next)
{
    return true;
}

static inline void list_insert(list_node *pos,list_node *new)
{
    list_node *prev = pos->prev;
    prev->next = new;
    new->prev  = prev;
    new->next  = pos;
    pos->prev  = new;
}
static inline void list_delete(list_node *pos)
{
    list_node  *prev,*next;
    if(pos->next == pos)
        return;
    prev = pos->prev;
    next = pos->next;
    prev->next =  next;
    next->prev = prev;
    pos->next = NULL;
    pos->prev = NULL;
    
}


#endif /* linklist_h */
