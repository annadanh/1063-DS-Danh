```
///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Priority Queue
// Files:            input_data.txt
// Semester:         CMPS 1063 Spring 2018
//
// Author:           Anna Danh
// Email:            anna.danh@yahoo.com
// Description:
//       This program reads in push and pop commands from an  
//       input file. It adds the names of animals to a list
//       based queue in order based on name length, where names
//       of shorter lengths have a higher priority. If the names
//       are of equal length, priority is then handled based on 
//       alphabetical order. The program then prints out all the 
//       names that were popped off of the list, followed by the
//       remaining names on the queue according to priority.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// creates node with next as a pointer
struct Node
{
    string val;
    Node *next;
    // node constructor
    Node()
    {
        val = " ";
        next = NULL;
    }
    // constructor with animal's name passed in for parameter
    Node(string v)
    {
        val = v;
        next = NULL;
    }
};

/**
* class Queue:
* a list based priority queue that holds animal names. Names will based
* ordered from shortest to longest, words that are of equal length will
* be ordered alphabetically
*     
* Methods:
*  - Queue()       : constructor
*  - string pop()  : returns the name that is currently at the front of the list
*  - void push(string): adds the animal name (passed in as a parameter) to the list
*  - bool empty(): returns if status of list is empty or not
*  - void print(): prints items that are still on the queue
*  - bool pop(string): pops a name of the queue
*  - string First(): returns the name at the front of the list
*  - void bubbleSort(): sorts the names based on length. If lengths are equal, names        sorted alphabetically
*  - void Remain(outfile): prints the names that were not popped off
*/
class Queue
{
  private:
    Node *Front;
    Node *Rear;

  public:
    /**
   * Queue
   * constructor
   * 
   * params:
   *     - none
   */
    Queue()
    {
        Front = Rear = NULL;
    }

    /**
   * Function: 
   *  pop()
   * Description:
   *  returns name currently at front off list. Prints error message if list is empty
   * Params: 
   *  none
   * Returns:
   *  string
   * 
   */
    string pop()
    {
        if (!empty())
        {
            Node *temp = Front;   // temp pointer so we can delete node
            string v = temp->val; // grab value out of node
            Front = Front->next;  // move pointer to next node
            delete temp;          // give mem back to system
            return v;
        }
        else
        {
            cout << "error: cannot pop off empty queue." << endl;
            return " ";
        }
    }
    
    /**
   * Function: 
   *  push(string)
   * Description:
   *  adds an animal name to the list
   * Params: 
   *  string
   * Returns:
   *  none
   */
    void push(string v)
    {
        Node *n = new Node(v);

        // handle the empty case
        if (empty())
        {
            Front = n;
            Rear = n;
        }
        else
        {
            // not empty add to rear
            Rear->next = n;
            Rear = n;
        }
    }
    
     /**
   * Function: 
   *  empty()
   * Description:
   *  returns wether list is empty or not
   * Params: 
   *  none
   * Returns:
   *  boolean
   * 
   */
    bool empty()
    {
        return (Front == NULL);
    }

     /**
   * Function: 
   *  print()
   * Description:
   *  prints items still on the queue
   * Params: 
   *  none
   * Returns:
   *  none
   * 
   */
    void print()
    {
        Node *temp = Front;
        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << endl;
    }
  
     /**
   * Function:
   *  pop(string)
   * Description:
   *  pops an item off the que
   * Params: 
   *  string
   * Returns:
   *  boolean
   * 
   */
    bool pop(string &v)
    {
        if (!empty())
        {
            Node *temp = Front;   // temp pointer so we can delete node
            string t = temp->val; // grab value out of node
            Front = Front->next;  // move pointer to next node
            delete temp;          // give mem back to system
            v = t;
            return true;
        }
        else
        {
            cout << "error: cannot pop off empty queue." << endl;
            return false;
        }
    }
    
     /**
   * Function:
   *  First()
   * Description:
   *  returns front name off the list
   * Params: 
   *  none
   * Returns:
   *  string
   * 
   */
    string First(){
      while(!empty()){
        return Front->val;
      }
      return "";
    }
    
     /**
   * Function:
   *  bubbleSort()
   * Description:
   *  sorts the names in the list from shortest to longest. Ties are ordered alphabetically
   * Params: 
   *  none
   * Returns:
   *  none
   * 
   */
    void bubbleSort(){
      Node* t1 = Front;
      Node* t2 = Front;
      
      string temp = "";
      
      bool swapped = false;
      
      while(t1){
        swapped = false;
        t2 = t1->next;
        while(t2){
          if(t1->val.length() > t2->val.length()){
            swapped = true;
            temp = t1->val;
            t1->val = t2->val;
            t2->val = temp;
          }
          else if(t1->val.length() == t2->val.length()){
              if(t1->val > t2->val){
                temp = t1->val;
                t1->val = t2->val;
                t2->val = temp;
              }
            }
          
          t2 = t2->next;
          }
        t1 = t1->next;
        }
      if(!swapped){
        return;
      }
    }
    
     /**
   * Function:
   *  Reamin()
   * Description:
   *  writes remaing names on queue to priority_out.txt
   * Params: 
   *  access to write fill to outifile remaining names on queue
   * Returns:
   *  none
   * 
   */
    void Remain(ofstream &outfile){
      int itemNum = 1;
      Node* temp = Front;
      while (temp)
    		{	outfile << itemNum << " " << temp->val << '\n';
    		  itemNum++;
    			temp = temp->next;
    		}
    		return;
    }
};

int main()
{
    Queue Q;
    string animal, command;
    int animalCount = 0; // keeps track of animals pushed onto queue
    int itemNum = 1; // keeps track of num of popped items
    
    ifstream infile;
    infile.open("input_data.txt");
    ofstream outfile;
    outfile.open("priority_out.txt");
    
    outfile << "Animals Popped off the Queue: \n\n";
    
    while(!infile.eof()){
      infile >> command;
      if(command == "push"){
        infile >> animal;
        Q.push(animal);
        animalCount++;
      }
      else if(command == "pop"){
        if(Q.First() != ""){
          outfile << itemNum << " " << Q.First() << '\n';
          itemNum++;
        }
        Q.pop(animal);
        animalCount--;
        if(animalCount < 0){ // prevent animalCount being negative in for loop
          animalCount = 0;
        }
      }
      if(animalCount > 1){
      for(int i = 0; i < animalCount - i; i++){ // loops sort fuction enough times so shortest name is at front of queue
        Q.bubbleSort();
      }
     }
    }
    
    outfile << "\nAnimals Remaining on the Queue (in order of priority): \n\n";
    
    Q.Remain(outfile);
}
```
