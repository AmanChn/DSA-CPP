
#include <bits/stdc++.h>

using namespace std;

int mySqrt(int x) {
        
        //using binary search
        long long int ans=0,mid,start,end; 
        //long long due to some of test cases overflows integer limit.
        start=0;end=x;
       
        while(start<=end){
            mid = (start+end)/2;
            if(mid*mid==x)
                return mid; 
            //if the 'mid' value gives the result, we return it.
            else if(mid*mid>x){
                end = mid-1; 
            //if 'mid' value gives greater result, we discard all the values greater than mid.
            }
            else{
                ans=mid;
                start=mid+1;  
                //if mid value gives lower result,discard all the values lower than mid.
            }      
        }
        return ans;
    }
    
double decimal(int n, int intPart, int precision ){
    
    double ans=intPart, factor=1;
    
    for(int i=0;i<precision;i++){
        
        factor=factor/10; // after every iteration it will divise by 10 to get to next decimal.
        
        for(double j=ans; j*j<n ; j=j+factor){ // initialize with ans, until it becomes > original no. , add the decimal part to the number.(eg 2.092) 
            ans=j;
        }
    }
    return ans;
}
    

int main()
{
    int x;
    cout<<"Enter the no.: ";
    cin>>x;
    
    // brute force
    // for(int i=0;i<x;i++){
    //     if(i*i==x){
    //     cout<<i<<endl;
    //     break;
    //     }
    //     else if (i*i>x){
    //         cout<<i-1<<endl;
    //         break;
    //     }
    // }
    
    int intPart = mySqrt(x);
    
    // to find the decinmal values ahead.
    
    
    cout<<"Answer is : "<<decimal(x,intPart,3);

    
    

    return 0;
}
