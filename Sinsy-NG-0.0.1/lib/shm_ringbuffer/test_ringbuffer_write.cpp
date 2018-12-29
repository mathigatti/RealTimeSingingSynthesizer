/* Created by Ghost Gloomy on 2018/11/8. */
#include "ringbuffer.h"
#include <stdio.h>
#include <string.h>

int main()
{
    RingBuffer rb((char*)"ringbuffer.data",5);
    char* data = (char*)"VOCALOID_MIKU_LUKA";
    rb.write(data,strlen(data));
    printf("written %i\n",strlen(data));
    fprintf(stderr,"userdata size %i\n",USERDATA_SIZE);
    int* tmp = (int*)rb.getUserdata();
    *tmp=2007;
}
