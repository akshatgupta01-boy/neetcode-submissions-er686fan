class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i=0;i<nums.size();i++){
            ans ^= i;
            ans ^= nums[i];
        }
        return ans;
        // int n = nums.size();
        // int expected = n * (n + 1) / 2;
        // int actual = 0;
        // for(int num : nums){
        //     actual += num;
        // }
        // return expected - actual;
    }
};
