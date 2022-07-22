//to reverse thye elements of ana array
#include <iostream>

using namespace std;

void reverse(int arr[] , int size){
    int start=0,end=size-1;
    
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int arr[9]={0,1,2,3,4,5,6,7,8};

    reverse(arr,9);
    
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
