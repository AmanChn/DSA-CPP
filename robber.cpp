int spaceOpt(vector<int> &nums){
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        int prev2 = 0;
        int prev1 = nums[0];
        
        for(int i=0; i<n ;i++){
            int include = nums[i] + prev2;
            int exclude = 0 + prev1;
            
            int ans = max(include,exclude);
            
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> first ,last;
        
        
        for(int i=0 ; i<n ; i++){
            if(i != (n-1))
                first.push_back(nums[i]);
            
            if(i != 0)
                last.push_back(nums[i]);
        }
        
        
        return max(spaceOpt(first) , spaceOpt(last));
    }