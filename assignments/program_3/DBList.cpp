#include <iostream>
#include <string>
#include <fstream>
#include "DBList.h"

using namespace std;

//Public 
////////////////////////////////////////////

DBList::DBList(){
  Head = NULL;
  Tail = NULL;
  Current = NULL;
}

/**
 * InsertFront - 
 *     Inserts a value at the front of the list by calling 
 *     actual insert with a node.
 * Params:
 *     string : data element to be inserted
 */
void DBList::InsertFront(string Data){
  Node* Temp = new Node(Data);
  InsertFront(Temp);

}

/**
 * InsertFront - 
 *     Inserts a value at the front of the list
 * Params:
 *     Node*& : node to be appended to front
 */
void DBList::InsertFront(Node* &Temp){
  
  if(!Head){
    Head = Temp;
    Tail = Temp;
    Tail->Next = Head;
    Current = Temp;
    Head->Prev = Tail;
    // cout << Current-> Data << endl;
  }else{
    Temp->Next = Head;
    Temp->Prev = Tail;
    Head->Prev = Temp;
    Tail->Next = Temp;
    Head = Temp;
    Current = Head;
    // cout << Current-> Data<< endl;
  }
}


void DBList::InsertRear(Node* &Temp){

  if(!Head){
    DBList::InsertFront(Temp);
  }else{
    
    Tail->Next = Temp;
    Temp->Prev = Tail;
    Tail=Temp;
    Temp->Next = Head;
    Head->Prev = Tail;
    Current = Tail;
  }
}

/**
 * InsertRear - 
 *     Inserts a value at the rear of the list by calling 
 *     actual insert with a node.
 * Params:
 *     string : data element to be inserted
 */
void DBList::InsertRear(string Data){
  if(!Head){
    DBList::InsertFront(Data);
  }else{
    Node* Temp = new Node(Data);
    InsertRear(Temp);
    //cout << Temp->Data<< endl;
  }
}

void DBList::InsertInOrder(string Data){
  if(!Head){
    DBList::InsertFront(Data);
  }else{
    Node* Temp = new Node(Data);
    //Node* Location = DBList::_Find(Data);
    
  }
}

/**
 * Delete - 
 *     deletes an item from the list
 * Params:
 *     string : data element to be inserted
 */

bool DBList::Delete(string x){
  //One node 
  if(Head == Tail && Head->Data==x){
    delete Head;
    Head = NULL;
    Tail = NULL;
    Current = NULL;
    return true;
  //Beginning of list
  }else if(Head->Data == x){
    Head = Head->Next;
    Current = Head;
    delete Head->Prev;
    Head->Prev = Tail;
    return true;
  //End of list
  }else if(Tail->Data == x){
    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = Head;
    Current = Tail;
    return true;
  //Middle of list
  }else{
    Node* Location = DBList::_Find(x);
    if(Location){
      Location->Prev->Next = Location->Next;
      Location->Next->Prev = Location->Prev;
     // cout << Location->Data << endl;
      Current = Location->Next;
      delete Location;
      return true;
    }
  }
  return false; 
}

bool DBList::Find(string x){
  return false;
}

bool DBList::Update(string x,string y){
  return false;
}

void DBList::Print(int columns){
  Node *Temp = Head;
  int count = 1;
  
  while(Temp != Tail){
    cout<<Temp->Data<<" ";
    Temp = Temp->Next;
    if(columns && count % columns == 0)
      cout<<endl;
    count++;
  }
  cout << Tail->Data << " ";
}

void DBList::Print(){
  DBList::Print(0);
}


void DBList::rPrint(){
  DBList::rPrint1(Tail);
}
//Private 
////////////////////////////////////////////

void DBList::rPrint(Node* Head){
  if(Head == Tail){
    return;
  }else{
    
    DBList::rPrint(Head->Next);
    cout<<Head->Data<<" ";
  }
}

void DBList::rPrint1(Node* Tail){
  if(Tail == Head){
    return;
  }else{
    cout<<Tail->Data<<" ";
    DBList::rPrint1(Tail->Prev);
  }
}



Node* DBList::_Find(string key){
  Node* Temp = Head;
  
  while(Temp){
    if (Temp->Data == key){
      return Temp;
    }
    Temp = Temp->Next;
  }
  return NULL;
}
/**
 * Traverse - 
 *     traverses the list to find animal name and delete it
 * Params:
 *     int : multiplier that traverses the list
 */
string DBList::Traverse(int mult){
  Node *temp = Current;  
  string tdata;
  if(mult%2==0)
  {
    for(int i=0; i<mult; i++)
    {
      Current = Current->Next;
    }
    tdata = Current->Data;
    Delete(Current->Data);
    return tdata;
  }
  else
  {
    for(int i =0; i<mult;i++)
    {
      Current = Current->Prev;
    }
    tdata = Current->Data;
    Delete(Current->Data);
    return tdata;
  }
  
}
