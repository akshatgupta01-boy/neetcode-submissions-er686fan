class Solution {
private:
    int robHelper(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, 0);
        if(n < 2) return nums[0];
        ans[0] = nums[0];
        ans[1] = max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            ans[i] = max(ans[i - 2] + nums[i], ans[i - 1]);
        }
        return ans[n - 1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums[0];
        vector<int> skipFirst(n - 1, 0);
        vector<int> skipLast(n - 1, 0);
        
        for(int i=0;i<n-1;i++){
            skipLast[i] = nums[i];
            skipFirst[i] = nums[i + 1];
            
        }
        int skippingFirst = robHelper(skipFirst);
        int skippingLast = robHelper(skipLast);
        return max(skippingFirst, skippingLast);
        
    }
};
