
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int value){
        this -> data = value;
        this -> next = NULL;
    }
    
    // destructor to free memory
    ~Node(){
        int value = this->data;
        if(this-> next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data : "<<this->data<<endl;
    }
    
};
    // h    
    // 1->2->3->4->Null
    //          t
    void insertAtHead(Node* & head , int data){
        
        // create new node
        Node* temp = new Node(data);
        
        temp->next = head;
        head = temp;
        
    }
    
    void insertAtTail(Node* &tail, int data){
            // creating new node
            Node* temp =new Node(data);
            
            tail->next = temp;
            tail = temp;
    }
    
    void insertAtPosition(Node* &head, Node* &tail, int position , int data ){
            Node* temp =head;
            
            int count = 1;
            
            while(count < position -1 ){
                temp = temp->next;
                count++;
            }
            
            // new node to insert
            Node* newNodeToInsert = new Node(data);
            
            // if insertion at start
            if(position == 1){
                insertAtHead(head,data);
                return;
            }
            
            // insertion at end
            // if temp->next ==null it means we are insetting at tail.
            // so we will have to update the tail als0.
            if(temp->next == NULL){ 
                insertAtTail(tail,data);
                return;
            }
            
            
            // at any Position
            newNodeToInsert->next = temp->next;
            temp->next = newNodeToInsert;
    }
    
    
    void deleteNode(int position , Node* &head){
        
        if(position == 1){
            Node* temp = head;
        
            head = head->next;
            
            temp->next = NULL;
            delete temp;

            
        }
        
        else{
            Node* current = head;
            Node* previous = NULL;
            
            int cnt = 1;
            
            while(cnt < position){
                previous = current;
                current = current ->next;
                cnt++;
            }
            
            previous -> next = current -> next;
            
            current -> next = NULL;
            delete current;
            
        }
        
        
        
    }
    
    
    
    void printList(Node* &head){
        Node* temp = head;
        
        while(temp!= NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }


int main()
{
    // crating first node
    Node* node1 = new Node(10);
    
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    
    // the head and tail pointers are both on node1
    Node* head = node1;
    Node* tail = node1;
    
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);

    printList(head);
    
    insertAtTail(tail,11);
    insertAtTail(tail,12);
        
    printList(head);
    
    insertAtPosition(head,tail,3,100);
    insertAtPosition(head,tail,8,400);

    printList(head);

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    
    
    deleteNode(1,head);
    deleteNode(7,head);
    
    printList(head);


    return 0;
}
