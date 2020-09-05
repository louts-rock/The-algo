//
//  queue.h
//  ds
//
//  Created by Apple on 2020/9/5.
//  Copyright © 2020 louts. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ufifo {
    void  *buffer;
    unsigned int size;
    unsigned int in;
    unsigned int out;
}ufifo_t;

#define __ufifo_initializer(s,b) \
    (struct ufifo) { \
            .size   = s,\
            .in   = 0,\
            .out  = 0,\
            .buffer = b,\
    }
#define DEFINE_UFIFO(name, size) \
unsigned char name##ufifo_buffer[size]; \
struct kfifo name = __ufifo_initializer(size, name##kfifo_buffer)

#define min(x, y) ({                        \
typeof(x) _min1 = (x);          \
typeof(y) _min2 = (y);          \
(void) (&_min1 == &_min2);      \
_min1 < _min2 ? _min1 : _min2; })

static void inline init_ufifo(ufifo_t *fifo,void *buffer,unsigned int size)
{
    fifo->buffer = buffer;
    fifo->size =size;
    fifo->in=fifo->out =0;
}
static int inline ufifo_in(ufifo_t *fifo,void *buf,unsigned int len)
{
    unsigned int l;
    len = min(len,(fifo->size - fifo->in +fifo->out));
    l = min(len,fifo->size-(fifo->in));
    memcpy(fifo->buffer+(fifo->in), buf, l);
    memcpy(fifo->buffer,buf+l,len-l);
    fifo->in =(fifo->in+len)%fifo->size;
    return len;

}
static int inline ufifo_out(ufifo_t *fifo,void *buf,unsigned int len)
{
    unsigned int l;
    len =min(len,fifo->in-fifo->out);
    l = min(len,fifo->size - fifo->out);
    memcpy(buf,fifo->buffer+fifo->out,l);
    memcpy(buf+l,fifo->buffer, len-l);
    fifo->out = (fifo->out+len)%fifo->size;
    return len;
}
#endif /* queue_h */
