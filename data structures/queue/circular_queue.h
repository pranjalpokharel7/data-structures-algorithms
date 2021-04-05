#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "queue.h"
#include <iostream>

template<class DataType, int Size>
void cqueue<DataType, Size>::enqueue(const DataType& item){
    if (queue_is_full()){
        std::cerr << "Overflow Error: Queue is Full\n"; 
        return; 
    } 

    if (queue_is_empty()) front = 0;
    rear = (rear + 1) % Size;
    cqueue_elements[rear] = item;
}

template<class DataType, int Size>
DataType cqueue<DataType, Size>::dequeue(){
   if (queue_is_empty()){
        std::cerr << "Underflow Error: Queue is Empty\n"; 
        return; 
   } 
   DataType element = cqueue_elements[front];
   if (front == rear) front = rear = -1;
   front = (front + 1)  % Size;
   return element;
}

template<class Datatype, int Size>
bool cqueue<Datatype, Size>::queue_is_empty(){
    return front == -1;
}

template<class Datatype, int Size>
bool cqueue<Datatype, Size>::queue_is_full(){
    return front == (rear + 1) % Size;
}

#endif
