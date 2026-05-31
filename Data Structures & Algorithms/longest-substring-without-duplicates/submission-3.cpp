class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLen = 0;
        for(int right=0;right<s.length();right++){
            if(charSet.count(s[right]) == 0){
                charSet.insert(s[left]);
                maxLen = max(maxLen, right - left + 1);
            }
            else{
                while(charSet.count(s[right])){
                charSet.erase(s[left]);
                left++;
            }
            }
            charSet.insert(s[right]);
        }
        return maxLen;
    }
};
