class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int i = 0;
        int j = n - 1;
        int iMax = 0;
        int jMax = 0;
        int ans = 0;
        while(i <= j){
            if(height[i] <= height[j]){
                if(height[i] >= iMax){
                    iMax = height[i];
                }
                else{
                    ans += iMax - height[i];
                }
                i++;
            }
            else{
                if(height[j] >= jMax){
                    jMax = height[j];
                }
                else{
                    ans += jMax - height[j];
                }
                j--;
            }
        }
    return ans;
    }
};
