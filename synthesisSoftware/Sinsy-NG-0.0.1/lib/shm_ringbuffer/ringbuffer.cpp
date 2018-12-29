// ringbuffer.cpp
//
// A lock-free ring buffer.
//
//   (C) Copyright 2000 Paul Davis
//   (C) Copyright 2003 Rohan Drape
//   (C) Copyright 2003 Fred Gleason <fredg@paravelsystems.com>
//
//    $Id: ringbuffer.cpp,v 1.1 2007/12/19 20:22:23 fredg Exp $
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU Library General Public License 
//   version 2 as published by the Free Software Foundation.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public
//   License along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//   Adapted from code by Paul Davis and Rohan Drape in 
//   'example-clients/ringbuffer.ch' in the Jack Audio Connection Kit.
//

#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ringbuffer.h"


RingBuffer::RingBuffer(char* shmfile,int pages)
{
    int tmp=0;
    char* data=nullptr;
    if(pages)
    {
        int power_of_two;
        for (power_of_two = 1; 1 << power_of_two < pages; power_of_two++);
        pages = 1 << power_of_two;
        
        unlink(shmfile);
        fd = open(shmfile, O_RDWR|O_CREAT, 0666);
        void* zeropage = calloc (4096,1);
        for(int i=0;i<pages+1;i++) ::write(fd, zeropage, 4096);
        free(zeropage);
        data_size = 4096*(pages+1);
        
        
    }
    else
    {
        fd = open(shmfile, O_RDWR, 0);
        ringbuffer_t hdr;
        ::read(fd,&hdr,sizeof(hdr));
        if(memcmp(&hdr,"RING",4)!=0)
        {
            fprintf(stderr,"Ringbuffer: invalid typesig\n");
            abort();
        }
        tmp = hdr.size/4096;
        data_size = 4096*(tmp+1);
        
        
    }
    
    lseek(fd,0,SEEK_SET);
    
    data = (char*)mmap(NULL, data_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    
    if(!data) {
        fprintf(stderr,"Ringbuffer: mmap failed\n");
        abort();
    }
    
    rb = (ringbuffer_t*)data;
    rb_buf = data+4096;
    
    if(pages)
    {
        memcpy(rb->typesig,"RING",4);
        rb->size = pages*4096;
        rb->size_mask = rb->size;
        rb->size_mask -= 1;
        rb->write_ptr = 0;
        rb->read_ptr = 0;
    }
}


RingBuffer::~RingBuffer()
{
  close(fd);
  munmap((void*)rb,data_size);
 
}

void RingBuffer::reset()
{
  rb->read_ptr = 0;
  rb->write_ptr = 0;
}


void RingBuffer::writeAdvance(size_t cnt)
{
  rb->write_ptr += cnt;
  rb->write_ptr &= rb->size_mask;
}


void RingBuffer::readAdvance(size_t cnt)
{
  rb->read_ptr += cnt;
  rb->read_ptr &= rb->size_mask;
}


size_t RingBuffer::writeSpace() const
{
  size_t w, r;

  w = rb->write_ptr;
  r = rb->read_ptr;

  if (w > r) {
    return ((r - w + rb->size) & rb->size_mask) - 1;
  } else if (w < r) {
    return (r - w) - 1;
  }
  return rb->size - 1;
}


size_t RingBuffer::readSpace() const
{
  size_t w, r;

  w = rb->write_ptr;
  r = rb->read_ptr;

  if (w > r) {
    return w - r;
  }
  return (w - r + rb->size) & rb->size_mask;
}


size_t RingBuffer::read(char *dest,size_t cnt)
{
  size_t free_cnt;
  size_t cnt2;
  size_t to_read;
  size_t n1, n2;

  if ((free_cnt = readSpace()) == 0) {
    return 0;
  }

  to_read = cnt > free_cnt ? free_cnt : cnt;

  cnt2 = rb->read_ptr + to_read;

  if (cnt2 > rb->size) {
    n1 = rb->size - rb->read_ptr;
    n2 = cnt2 & rb->size_mask;
  } else {
    n1 = to_read;
    n2 = 0;
  }

  memcpy (dest, &(rb_buf[rb->read_ptr]), n1);
  rb->read_ptr += n1;
  rb->read_ptr &= rb->size_mask;

  if (n2) {
    memcpy (dest + n1, &(rb_buf[rb->read_ptr]), n2);
    rb->read_ptr += n2;
    rb->read_ptr &= rb->size_mask;
  }

  return to_read;
}


size_t RingBuffer::write(char *src,size_t cnt)
{
  size_t free_cnt;
  size_t cnt2;
  size_t to_write;
  size_t n1, n2;

  if ((free_cnt = writeSpace()) == 0) {
    return 0;
  }

  to_write = cnt > free_cnt ? free_cnt : cnt;

  cnt2 = rb->write_ptr + to_write;

  if (cnt2 > rb->size) {
    n1 = rb->size - rb->write_ptr;
    n2 = cnt2 & rb->size_mask;
  } else {
    n1 = to_write;
    n2 = 0;
  }

  memcpy (&(rb_buf[rb->write_ptr]), src, n1);
  rb->write_ptr += n1;
  rb->write_ptr &= rb->size_mask;

  if (n2) {
    memcpy (&(rb_buf[rb->write_ptr]), src + n1, n2);
    rb->write_ptr += n2;
    rb->write_ptr &= rb->size_mask;
  }

  return to_write;
}


void RingBuffer::getReadVector(ringbuffer_data_t *vec)
{
  size_t free_cnt;
  size_t cnt2;
  size_t w, r;

  w = rb->write_ptr;
  r = rb->read_ptr;

  if (w > r) {
    free_cnt = w - r;
  } else {
    free_cnt = (w - r + rb->size) & rb->size_mask;
  }

  cnt2 = r + free_cnt;

  if (cnt2 > rb->size) {

    /* Two part vector: the rest of the buffer after the current write
       ptr, plus some from the start of the buffer. */

    vec[0].buf = &(rb_buf[r]);
    vec[0].len = rb->size - r;
    vec[1].buf = rb_buf;
    vec[1].len = cnt2 & rb->size_mask;

  } else {

    /* Single part vector: just the rest of the buffer */

    vec[0].buf = &(rb_buf[r]);
    vec[0].len = free_cnt;
    vec[1].len = 0;
  }
}


void RingBuffer::getWriteVector(ringbuffer_data_t *vec)
{
  size_t free_cnt;
  size_t cnt2;
  size_t w, r;

  w = rb->write_ptr;
  r = rb->read_ptr;

  if (w > r) {
    free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
  } else if (w < r) {
    free_cnt = (r - w) - 1;
  } else {
    free_cnt = rb->size - 1;
  }

  cnt2 = w + free_cnt;

  if (cnt2 > rb->size) {

    /* Two part vector: the rest of the buffer after the current write
       ptr, plus some from the start of the buffer. */

    vec[0].buf = &(rb_buf[w]);
    vec[0].len = rb->size - w;
    vec[1].buf = rb_buf;
    vec[1].len = cnt2 & rb->size_mask;
  } else {
    vec[0].buf = &(rb_buf[w]);
    vec[0].len = free_cnt;
    vec[1].len = 0;
  }
}

void* RingBuffer::getUserdata()
{
    return (char*)rb+sizeof(rb);
}
