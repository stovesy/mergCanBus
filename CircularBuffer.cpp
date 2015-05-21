#include "CircularBuffer.h"

CircularBuffer::CircularBuffer()
{
    tail=0;
    op=0;
    pos=0;
}

CircularBuffer::~CircularBuffer()
{
    //dtor
}

bool CircularBuffer::put(byte* buffer){
    if (op==0){
        op=1;//writing
    }
    else{
        return false;
    }
    if (tail>=CIRCULARBUFFER_SIZE){
        tail=0;
    }
    if (tail){
    }
    for (int i=0;i<_msgSize;i++){
        _buf[tail]=buffer[i];
        tail++;
    }
    op=0;
    return true;
}

bool CircularBuffer::get(byte* buffer){
    if (op==0){
        op=1;//reading
    }
    else{
        return false;
    }
    if (pos>=CIRCULARBUFFER_SIZE){
        pos=0;
    }
    if ((pos+1)>=tail){
        return false;//nothing to read.
    }
    for (int i=0;i<_msgSize;i++){
        buffer[i]=_buf[pos];
        pos++;
    }
    op=0;
    return true;
}