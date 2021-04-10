#ifndef SINGLY_LINKED_LIST_H 
#define SINGLY_LINKED_LIST_H

#include "linked-list.h"
#include <stdexcept>
#include <iostream>

template <class DataType>
list<DataType>::~list(){
   Node *current = head;
   while(current->next != nullptr){
      Node *temp = current->next;
      delete current;
      current = temp;
   }
   delete tail;
}

template<class DataType>
void list<DataType>::insert(DataType value){
   Node* current = new Node;
   current->data = value;
   current->next = nullptr;

   if (list_is_empty()) head = current; 
   else tail->next = current;

   tail = current;
   max_index_count++;
}

template<class DataType>
void list<DataType>::delete_by_index(int index){
   if (index > max_index_count || index < 0){
      throw std::out_of_range("Provided index does not exist!\n");
   }

   if (index == 0){
      delete_head();
      return;
   }

   Node* current = head;
   Node* previous = current;
   for (int i = 0; i < index; i++){
      previous = current;
      current = current->next;
   }
   previous->next = current->next;
   delete current;
   max_index_count--;
}

template<class DataType>
void list<DataType>::delete_by_value(DataType value){
   if (list_is_empty()){
      throw std::underflow_error("No element to delete!\n");
   }

   if (head->data == value){
      delete_head();
      return;
   }

   Node* current = head;
   Node* previous = current;
   while(current != nullptr){
      previous = current;
      current = current->next;
      if (current->data == value) break;
   }
   previous->next = current->next;
   delete current;
   max_index_count--;
}

template<class DataType>
void list<DataType>::delete_head(){
   if (list_is_empty()){
      throw std::underflow_error("No element to delete!\n");
   }

   Node *temp = head;
   head = head->next;
   delete temp;
   max_index_count--;
}

template<class DataType>
DataType& list<DataType>::operator [](int index){
   if (index > max_index_count || index < 0){
      throw std::out_of_range("Provided index does not exist!\n");
   }

   Node* current = head;   
   for (int i = 0; i < index; i++){
      current = current->next; 
   }
   return current->data;
}

template<class DataType>
bool list<DataType>::list_is_empty(){ return head == nullptr ? true : false; }

template<class DataType>
void list<DataType>::print(){
   for (Node* current = head; current != nullptr; current = current->next){
      std::cout << current->data << " ";
   }
   std::cout << std::endl;
}

#endif
