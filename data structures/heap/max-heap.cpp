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

class MaxHeap{
  private:
    int* heap;
    int index;
    int size;

    int leftChild(int i){
      return i * 2 + 1;
    }

    int rightChild(int i){
      return i * 2 + 2;
    }

    int parentNode(int i){
      return (i-1)/2;
    }

    int heightOfHeap(){
      return std::log2(index) + 1; 
    }
    void swap(int* a, int* b){
      int t = *a;
      *a = *b;
      *b = t;
    }

    bool heapIsEmpty(){
      return index == -1;
    }

    bool heapIsFull(){
      return index == size;
    }

    bool isLeaf(int i){
      return index <= (2 * i +1) && i <= index;
    }

    void maxHeapify(int i){
      int newParent = i;
      if (leftChild(i) < size && heap[leftChild(i)] > heap[newParent]) 
        newParent = leftChild(i);
      if (rightChild(i) < size && heap[rightChild(i)] > heap[newParent])
        newParent = rightChild(i);

      if (newParent != i){
        swap(&heap[i], &heap[newParent]);
        maxHeapify(newParent);
      }
    }

  public:
    MaxHeap(int s):size(s){
      heap = new int[size]; 
      index = -1;
    }

    ~MaxHeap(){
      delete [] heap;
    }

    void insertItem(int data){
      if (heapIsFull()){
        throw HeapException("Heap is Full!");
      }

      if (heapIsEmpty()){
        index = 0;
        heap[index] = data;
        return;
      }

      index++;
      heap[index] = data; 

      int i = index;
      while (parentNode(i) >= 0 && heap[i] > heap[parentNode(i)]){
        swap(&heap[i], &heap[parentNode(i)]);
        i = parentNode(i);
      }
    }

    int returnMax(){
      int max = heap[0];
      heap[0] = heap[index];
      heap[index] = 0;
      index--;
      maxHeapify(0);
      return max;
    }

    void displayHeap(){
      for (int i = 0; i <= index/2; i++){
        std::cout << " PARENT : " << heap[i] << " LEFT CHILD : "  
          << heap[leftChild(i)] << " RIGHT CHILD :" 
          << heap[rightChild(i)] << "\n";
      }
      std::cout << "\n";
    }
};

int main(){
  MaxHeap h1(10);
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
  std::cout << "The maximum value in the heap is : " << max << "\n";
  h1.displayHeap();
}
