class Solution {
public:
    int subsetSum(vector<int>& arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
        for(int i=0;i<n+1;i++) dp[i][0] = 1;
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums) sum += num;
        if(sum < abs(target)) return 0;
        if((sum + target) % 2 != 0) return 0;
        int targets = (sum + target) / 2;
        return subsetSum(nums, targets); 
    }
};
