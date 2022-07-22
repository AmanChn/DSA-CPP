//to reverse thye elements of ana array
#include <iostream>

using namespace std;

void swapalternate(int arr[] , int size){
    int start=0,end=size-1;
    
    while(start<end){
        if(start+1<size){
            swap(arr[start],arr[start+1]);
            start=start+2;
        }
    }
}

void printarray(int arr[],int n){
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int brr[11]={0,1,2,3,4,5,6,7,8,9,10};

    swapalternate(arr,10);
    printarray(arr,10);
    
    swapalternate(arr,11);
    printarray(brr,11);
   
    
    return 0;
}
