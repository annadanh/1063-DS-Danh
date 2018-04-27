#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node{
  string Data;

  Node *Prev;
  Node *Next;
  Node(string x){
      Data = x;
      Prev = NULL;
      Next = NULL;
  }
};

struct DBList{

    Node *Head;
    Node *Tail;
    Node *Current;
    Node* _Find(string);
    void rPrint(Node*);
    void rPrint1(Node*);

    DBList();
    void InsertFront(string);
    void InsertFront(Node*&);
    void InsertRear(string);// inserts animal names into the list in
                            // alphabetical order
    void InsertRear(Node*&);
    void InsertInOrder(string);
    void PriorityInsert(string Data);
    bool Delete(string);   //Removes item from list
    bool Find(string);     //Locate and see if exists
    bool Update(string,string);   //Change existing value
    void Print();
    void Print(int);
    void rPrint();
    string Traverse(int); // Traverses list
    

};
