// ringbuffer.h
//
// A lock-free ring buffer.
//
//   (C) Copyright 2000 Paul Davis
//   (C) Copyright 2003 Rohan Drape
//   (C) Copyright 2002 Fred Gleason <fredg@paravelsystems.com>
//
//    $Id: ringbuffer.h,v 1.1 2007/12/19 20:22:23 fredg Exp $
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

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <sys/types.h>

typedef struct  
{
  char *buf;
  size_t len;
} 
ringbuffer_data_t ;

typedef struct
{
  char typesig[4];
  volatile size_t write_ptr;
  volatile size_t read_ptr;
  size_t size;
  size_t size_mask;
} 
ringbuffer_t ;

class RingBuffer
{
 public:
  RingBuffer(char* shmfile,int pages);
  ~RingBuffer();
  void* getUserdata();
  void reset();
  void writeAdvance(size_t cnt);
  void readAdvance(size_t cnt);
  size_t writeSpace() const;
  size_t readSpace() const;
  size_t read(char *dest,size_t cnt);
  size_t write(char *src,size_t cnt);
  void getReadVector(ringbuffer_data_t *vec);
  void getWriteVector(ringbuffer_data_t *vec);

 private:
  ringbuffer_t *rb;
  int fd;
  char* rb_buf;
  int data_size;
};

#define USERDATA_SIZE (4096-sizeof(ringbuffer_t))


#endif  // RINGBUFFER_H

