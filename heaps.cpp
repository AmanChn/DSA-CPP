
#include <bits/stdc++.h>

using namespace std;

class heap {
    public:
    int arr[100];
    int size ;
    
    heap(){
        arr[0] = -1;
        size=0;
    }
    
    
    
    void insert(int val){
        size = size + 1; // we want to syore elements from 1 index;
        
        int index = size;
        
        arr[index] = val;
        
        while(index > 1){
            int parent = index/2;
            
            if(arr[index] > arr[parent]){
                swap(arr[index] , arr[parent]);
                index = parent;
            }
            else{
                return; // we are at right position come out of loop;
            }
            
        }
    }
    
    
    void print(){
        for(int i= 1 ; i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    
    void deletefromHeap(){
        if(size == 0){
            cout<<"nothing to delete in heap"<<endl;
        }
        
        // in heap always the root element will be deleted.
        
        
        // step 1 : move last element to root
        arr[1] = arr[size];
        
        //step 2 : remove the last element
        size--;
        
        
        // take root node to its correct position
        int i=1;
        
        while(i < size){
            int leftchild = 2*i;
            int rightchild = 2*i + 1;
            
            
            if(leftchild<size  &&  arr[leftchild] > arr[i]){  // if root is smaller than leftchild
                swap(arr[leftchild] , arr[i]);
            }
            else if(rightchild<size  &&  arr[rightchild] > arr[i]){ // if root is smaller than rightchild
                swap(arr[rightchild] , arr[i]);
            }
            else{
                return ;  // everuthing is at correct position
            }
            
        }
        
    }
    
};

// heapify function
void heapify(int arr[] , int n , int i){
    
    int largest = i;
    int leftchild = 2*i;
    int rightchild = 2*i + 1;
    
    
    if(leftchild <= n && arr[leftchild] > arr[largest]){
        largest  = leftchild;
    }
    
    if(rightchild <= n && arr[rightchild] > arr[largest]){
        largest = rightchild;
    }
    
    // if the largest element was not at correct position
    if(largest != i){   // agar largest ki value change hui hai matlab ki element ko sahi jagah lana padega
        swap(arr[largest] , arr[i]);
        heapify(arr, n , largest);  // check karo ki element aur kisi sahi jagah pe dala ja sakta hai kya aage ? 
    }

}


void heapsort(int arr[],int n){
    
    int size=n;
    
    while(size > 1){
        // step 1 : swap last and first element
        
        swap(arr[size] , arr[1]);
        size--;
        
        // heapify the first element ie place it at right position
        
        heapify(arr,size,1);  // exclude the last sorted item
    }

}




int main()
{
    heap h;
    
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    
    h.deletefromHeap();
    
    h.print();
    
    cout<<endl;
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    
    
    
    //in heap elements from index (n/2 + 1) to n are leaf nodes;
    // as leaf nodes are always heap so we dint have to heapify them
    
    // build heap function
    for(int i=n/2 ; i>0 ;i--){
        heapify(arr,n,i);
    }
    
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    cout<<"printing sorted array :"<<endl;
    heapsort(arr,n);
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    

    return 0;
}
