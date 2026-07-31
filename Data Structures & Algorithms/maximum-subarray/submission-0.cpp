class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxi = INT_MIN;
        for(int num : nums){
            curr += num;
            maxi = max(maxi, curr);
            if(curr < 0) curr = 0;
        }
        
        return maxi;
    }
};
