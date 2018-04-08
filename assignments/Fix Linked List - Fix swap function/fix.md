``` cpp
// Anna Danh
// Fixed Linked List - Fix swap function

//assumptions are list is >= length(2);
  // swaps sets of neighbors
  // 1: head->A->B->C->D->E->NULL
  // 2: head->B->A->D->C->E->NULL
  void swapNeighbors(){
    node* prev = Head;
    node* temp = Head->next;
    int tempvar;
    
    while(temp->next){
      tempvar = temp->data;
      temp->data = prev->data;
      prev->data = tempvar;
      
      prev = temp->next;     // changed prev = prev->next that made 
                             // function terminate early
      temp = temp->next->next;
      }
    }
```
