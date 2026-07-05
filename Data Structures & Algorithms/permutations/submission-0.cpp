class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(auto num : nums){
            if(find(temp.begin(), temp.end(), num) != temp.end()) continue;
            temp.push_back(num);
            solve(ans, temp, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, nums);
        return ans;
    }
};
