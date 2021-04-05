#ifndef QUEUE_H
#define QUEUE_H

template<class DataType, int Size>
class cqueue {
    private:
        DataType cqueue_elements[Size];
        int front = -1, rear = -1;
    public:
        void enqueue(const DataType& item);
        DataType dequeue();

        bool queue_is_full();
        bool queue_is_empty();
};

#endif
