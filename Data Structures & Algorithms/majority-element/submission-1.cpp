class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = 0;
        int count = 0;
        for(int n : nums){
            if(count == 0){
                can = n;
            }
            if(can == n) count++;
            else count--;
        }
        return can;

        
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n/2];
    }
};