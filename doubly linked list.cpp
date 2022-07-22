
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int value){
        this -> data = value;
        this -> next = NULL;
        this -> prev = NULL;
    }
    
    // destructor to free memory
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"the memory of node is free having data: "<<value<<endl;
    }

    
};
    //      h    
    //      1->2->3->4->Null
    //          t
    void insertAtHead(Node* &head, Node* & tail , int data){
        //if empty list
        if(head == NULL){
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        }
        
        else{
            Node* temp =  new Node(data);
            temp -> next = head;
            head -> prev = temp;
            head = temp;
        }
    }
    
    void insertAtTail(Node* &head ,Node* &tail, int data){
        //if empty list
        if(tail == NULL){
            Node* temp = new Node(data);
            tail = temp;
            head = temp;
        }
        else{
            Node* temp = new Node(data);
            tail->next = temp;
            temp -> prev = tail;
            tail = temp;
        }
    }
    
    void insertAtPosition(Node* &head, Node* &tail, int position , int data ){
        Node* curr = head;
        
        if(position == 1){
            insertAtHead(head,tail,data);
            return;
        }
        
        int cnt = 1;
        while( cnt < position-1){
            curr = curr->next;
            cnt++;
        }
        
        // insert at end
        if(curr->next == NULL){
            insertAtTail(head,tail,data);
		return;
        }
        
        Node* temp = new Node(data);

        temp->next = curr->next;
        curr->next->prev = temp;

        temp->prev = curr;
        curr->next =temp;

    }
    
    
    void deleteNode(int position , Node* &head,Node* &tail ){
        //starting node
        if(position == 1){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            head->next->prev = NULL;
            
            delete temp;
        }
        
        
        else{
            Node* curr = head;
            Node* previous = NULL;

            int cnt = 1;
            while(cnt < position ){
                previous = curr;
                curr = curr->next;
                cnt++;
            }
        
            if(curr->next == NULL){
                tail=previous;
            }
            
            curr->prev = NULL;
            previous->next = curr->next;
            curr->next = NULL;
    
            
            delete curr;
            
        }
        
    }
    
    
    
    void printList(Node* &head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }


int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    insertAtHead(head,tail,1);
    printList(head);
    
    insertAtHead(head,tail,2);
    printList(head);
    
    
    insertAtTail(head,tail,11);
    printList(head);
    
    insertAtPosition(head,tail,4,3);
    printList(head);
    
    insertAtPosition(head,tail,5,20);
    printList(head);
    
    deleteNode(3,head,tail);
    printList(head);
    
    deleteNode(5,head,tail);
    printList(head);
    
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    


    return 0;
}
