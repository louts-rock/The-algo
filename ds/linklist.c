//
//  linklist.c
//  ds
//
//  Created by Apple on 2020/8/28.
//  Copyright © 2020 louts. All rights reserved.
//

#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
static inline void LIST_HEAD_INIT(struct list_head *list)
{
    list->next =list;
    list->prev =list;
}
static inline void __list_add(list_node *new,list_node *head,list_node *end)
{
    end->next = new;
    new->next = head;
    new->prev = end;
    head->prev = new;
}
static inline void list_add(list_node *new,struct list_head *head)
{
    __list_add(new,head,head->prev);
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









