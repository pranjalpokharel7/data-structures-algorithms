#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class DataType>
class list {
   protected:
      struct Node {
         DataType data;
         Node* next;
      } *head = nullptr, *tail = nullptr;
      int max_index_count = -1;
      bool list_is_empty();

   public:
      virtual ~list();
      void insert(DataType value);
      void delete_by_value(DataType value);
      void delete_by_index(int index);
      void delete_head();
      void print();

      DataType& operator [](int index);
};

#endif
