#include <iostream>
#include <cmath>
#include <exception>
#include <string>

class HeapException : public std::exception{
  private:
    std::string err_msg;
  public:
    HeapException(std::string s):err_msg(s){} 
    const char * what() {return err_msg.c_str();}
};

template<class DataType>
void swap(DataType* a, DataType* b){
  DataType t = *a;
  *a = *b;
  *b = t;
}

template<class DataType, int Size>
class MaxHeap{
  private:
    DataType heap[Size];
    int index = -1;

    int leftChild(int i) const{ return i * 2 + 1; }
    int rightChild(int i) const{ return i * 2 + 2; }
    int parentNode(int i) const{ return (i-1)/2; }
    int heightOfHeap() const{ return std::log2(index) + 1; }

    bool heapIsEmpty() const{ return index == -1; }
    bool heapIsFull() const{ return index == Size; }
    bool isLeaf(int i) const{ return index <= (2 * i +1) && i <= index; }

    void maxHeapify(int i){
      int newParent = i;
      if (leftChild(i) < Size && heap[leftChild(i)] > heap[newParent]) 
        newParent = leftChild(i);
      if (rightChild(i) < Size && heap[rightChild(i)] > heap[newParent])
        newParent = rightChild(i);

      if (newParent != i){
        swap(&heap[i], &heap[newParent]);
        maxHeapify(newParent);
      }
    }

  public:
    MaxHeap(){
      if (Size <= 0)
        throw HeapException("Enter a valid size for the heap!");
    }

    void insertItem(DataType data){
      if (heapIsFull()){
        throw HeapException("Heap is Full!");
      }

      if (heapIsEmpty()){
        index = 0;
        heap[index] = data;
        return;
      }

      heap[++index] = data; 

      int i = index;
      while (parentNode(i) >= 0 && heap[i] > heap[parentNode(i)]){
        swap(&heap[i], &heap[parentNode(i)]);
        i = parentNode(i);
      }
    }

    DataType returnMax(){
      DataType max = heap[0];
      heap[0] = heap[index];
      heap[index] = 0;
      index--;
      maxHeapify(0);
      return max;
    }

    void displayHeap () const{
      for (int i = 0; i <= index/2; i++){
        std::cout << " PARENT : " << heap[i] << " LEFT CHILD : "  
          << heap[leftChild(i)] << " RIGHT CHILD :" 
          << heap[rightChild(i)] << std::endl;
      }
      std::cout << std::endl;
    }
};


int main(){
  MaxHeap<int, 10> h1;
  try {
    h1.insertItem(10);
    h1.insertItem(5);
    h1.insertItem(5);
    h1.insertItem(5);
    h1.insertItem(5);
    h1.insertItem(4);
    h1.insertItem(8);
    h1.insertItem(7);

    h1.displayHeap();

    int max = h1.returnMax();
    std::cout << "The maximum value in the heap is : " << max << std::endl;
    h1.displayHeap();
  }
  catch (HeapException& e){
    std::cerr << e.what();
  }
}
