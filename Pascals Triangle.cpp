class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
    
//         if(numRows==1)
//             return {{1}};
//         result[0]={1};
//         result[1]={1,1};
//         if(numRows==2)
//             return result;
        
        
        for(int i=0;i<numRows;i++){
             //As each row has row+1 no of elements 
                                                // ij
                // 0th row has 0+1 = 1 elements ie 00
                // 1st row has 1+1 = 2 elements ie 10, 11
                // 2nd row has 2+1 = 3 elements ie 20, 21, 22
                // 3nd row has 3+1 = 3 elements ie 30, 31, 32, 33
                // 4th row has 4+1 = 4 elements ie 40, 41, 42, 43, 44
            result[i].resize(i+1);
            
            // first and last elements of array(pascal tr) will always be 1
            result[i][0]=result[i][i]=1;  // res[i][0] means 0th element of ith vector i.e 0th element of ith row. 
        
            //Now filling the elements in between first and last 
            for(int j=1;j<i;j++){
            result[i][j]= result[i-1][j-1]+result[i-1][j];
            }
        }
        
       return result;
    }
};












