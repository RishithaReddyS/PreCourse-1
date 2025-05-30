#include <bits/stdc++.h> 
using namespace std; 
  
// A linked list node (changes) 
class Node  
{  
    public: 
    int data;  
    Node *next;  
};  
  
/* Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */
void push(Node** head_ref, int new_data)  
{  
    Node* newNode = new Node();     /* 1. allocate node */ 
    newNode->data = new_data;       /* 2. put in the data */  
    newNode->next = *head_ref;      /* 3. Make next of new node as head */  
    *head_ref = newNode;            /* 4. move the head to point to the new node */
}  
  
/* Given a node prev_node, insert a new node after the given  
prev_node */
void insertAfter(Node* prev_node, int new_data)  
{  
    if(prev_node == NULL){                      /*1. check if the given prev_node is NULL */ 
        cout<<"Given node is a NULL node\n";
        return;
    }
    Node* newNode = new Node();                 /* 2. allocate new node */ 
    newNode->data = new_data;                   /* 3. put in the data */ 
    newNode->next = prev_node->next;            /* 4. Make next of new node as next of prev_node */
    prev_node->next = newNode;                  /* 5. move the next of prev_node as new_node */ 
}  
  
/* Given a reference (pointer to pointer) to the head  
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)  
{  
    Node* newNode = new Node();     /* 1. allocate node */ 
    newNode -> data = new_data;     /* 2. put in the data */ 
    newNode->next = NULL;           /* 3. This new node is going to be 
                                           the last node, so make next of it as NULL*/  
    if(*head_ref == NULL){
        *head_ref = newNode;
        return;
    }                               /* 4. If the Linked List is empty, then make the new node as head */
  
    Node* ptr = *head_ref;
    while(ptr->next !=NULL){
        ptr = ptr -> next;
    }                               /* 5. Else traverse till the last node */
  
    ptr -> next = newNode;          /* 6. Change the next of last node */ 
}  
  
// This function prints contents of 
// linked list starting from head  
void printList(Node *node)  
{  
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}  
  
/* Driver code*/
int main()  
{  
    Node* head = NULL;   
    append(&head, 6);  
    push(&head, 7);  
    push(&head, 1);    
    append(&head, 4);    
    insertAfter(head->next, 8);  
    cout<<"Created Linked list is: ";  
    printList(head);  
    return 0;  
}  