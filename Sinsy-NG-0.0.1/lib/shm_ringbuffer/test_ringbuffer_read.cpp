/* Created by Ghost Gloomy on 2018/11/8. */

#include "ringbuffer.h"
#include <stdio.h>
#include <string.h>

int main()
{
    RingBuffer rb((char*)"ringbuffer.data",0);
    
    char data[1024]={0};
    int count = rb.read(data,sizeof(data));
    fprintf(stderr,"data %i [%s]\n",count,data);
    fprintf(stderr,"userdata size %i\n",USERDATA_SIZE);
    int* tmp = (int*)rb.getUserdata();
    fprintf(stderr,"hatsune miku was released in %i\n",*tmp);
}
