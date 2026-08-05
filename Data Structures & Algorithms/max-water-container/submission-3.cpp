class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftPole = 0;
        int rightPole = height.size() - 1;
        int maximumArea = 0;
        while(leftPole < rightPole){
            int currArea = min(height[leftPole], height[rightPole]) * (rightPole - leftPole);
            maximumArea = max(maximumArea, currArea);
            if(height[leftPole] < height[rightPole]){
                leftPole++;
            }else{
                rightPole--;
            }
        }
        return maximumArea;
    }
};
