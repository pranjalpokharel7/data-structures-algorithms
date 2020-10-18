#include <iostream>
#include <exception>
using namespace std;

class ListException:public exception{
   private:
      string err_msg;
   public:
      ListException(string s):err_msg(s){}
      const char * what() { return err_msg.c_str();}
};

template<class T>
class DLL{
   private:
      struct Node{
         T data;
         Node* next;
         Node* previous;
      } *head, *tail;
      int index = -1;

   public:
      DLL(){
         head = nullptr;
         tail = nullptr;
      }
      ~DLL(){
         if(!isEmpty()){
            Node *toDelete = head;
            while(toDelete!= nullptr){
               Node* next = toDelete->next;
               delete toDelete;
               toDelete = next;
            }
         }
      }
      void insertAtBegin(T data){
         cout << "Inserting " << data << " at the beginning of the list!\n";
         Node* np = new Node;
         np->data = data;
         np->previous = nullptr;
         if (isEmpty()){
            np->next = nullptr;
            tail = np;
         }
         else {
            head->previous = np;
            np->next = head;
         }
         head = np;
         index++;
      }
      void insertAtEnd(T data){
         cout << "Inserting " << data << " at the end of the list!\n";
         Node* np = new Node;
         np->data = data;
         np->next = nullptr;
         if (isEmpty()){
            head = np;
            np->previous = nullptr;
         }
         else {
            tail->next = np;
            np->previous = tail;
         }
         tail = np;
         index++;
      }
      void insertBeforeNode(T data, int x){
         if (isEmpty()){
            insertAtBegin(data);
            return;
         }
         Node* current = tail;
         for (int i=index; i > x; i--){
            current = current->previous;
         } 
         Node *prev = current->previous;
         if (prev == nullptr){
            insertAtBegin(data);
            return;
         } 
         cout << "Inserting " << data << " delete node number " << x << "\n";
         Node* np = new Node;   
         np->data = data;
         np->next = current;
         np->previous = prev; 
         current->previous = np;
         prev->next = np;

         index++;
      }
      void insertAfterNode(T data, int x){
         if (isEmpty()){
            insertAtBegin(data);
            return;
         } 
         Node* current = head; 
         for (int i=0; i<x; i++){
            current = current->next; 
         }
         Node *next = current->next;
         if (next == nullptr){
            insertAtEnd(data);   
            return;
         }
         cout << "Inserting " << data << " after node number " << x << "\n";
         Node* np = new Node;
         np->data = data;
         np->next = next;
         np->previous = current;
         current->next = np;
         next->previous = np;

         index++;
      }
      void delFromBeg(){
         cout << "Deleting " << head->data << " from the beginning of the list!\n";
         Node* delNode = head;
         head = head->next;
         head->previous =  nullptr;
         index--;
         delete delNode;
      }
      void delFromEnd(){
         cout << "Deleting " << tail->data << " from the end of the list!\n";
         Node* delNode = tail;
         tail = tail->previous;
         tail->next = nullptr;
         index--;
         delete delNode;
      }
      void deleteAfterNode(int n){
         if (n >= index || n < 0){
            throw ListException("Out of bound deletion attempt!"); 
            return;
         }
         if (n == index-1){
            delFromEnd();
            return;
         }
         Node* current = head;
         for(int i=0;i<n;i++){
            current = current->next;
         }
         Node* delNode = current->next; 
         cout << "Deleting " << delNode->data << " after " << n << " position of the list!\n";
         Node* newNext = delNode->next; 
         current->next = newNext;
         newNext->previous = current;
         index--;
         delete delNode;
      }
      void deleteBeforeNode(int n){
         if (n > index || n <= 0){
            throw ListException("Out of bound deletion attempt!"); 
            return;
         }
         if (n == 1){
            delFromBeg();
            return;
         }
         
         Node* current = tail;
         for(int i=index;i>n;i--){
            current = current->previous;
         }
         printIndex();
         Node* delNode = current->previous; 
         cout << "Deleting " << delNode->data << " before " << n << " position of the list!\n";
         Node* newNext = delNode->previous; 

         current->previous= newNext;
         newNext->next= current;
         index--;
         delete delNode;
      }
      void printList(){
         Node* np = head;
         while (np->next!= nullptr){
            cout << np->data << "<=>"; 
            np = np->next; 
         }
         cout << tail->data << "\n"; 
         np = nullptr; 
      }
      bool isEmpty(){
         return head == nullptr;
      } 
      void printIndex(){
         cout << index << "\n";
      }
};

int main(){
   DLL<int> d1;
   d1.insertAtBegin(43);
   d1.insertAtBegin(82);
   d1.insertAtBegin(99);
   d1.insertAtEnd(100);
   d1.printList();
   d1.delFromEnd();
   d1.printList();
   d1.insertAfterNode(25,0);
   d1.printList();
   d1.insertBeforeNode(52, 2);
   d1.printList();
   d1.deleteAfterNode(0);
   d1.printList();
   d1.deleteBeforeNode(1);
   d1.printList();
}
