class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> ans(n + 1);
        if(s[0] == '0') return 0;
        ans[0] = 1;
        ans[1] = 1;
        for(int i=2;i<n+1;i++){
            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigit = stoi(s.substr(i - 2, 2));
            if(oneDigit >= 1){
                ans[i] += ans[i-1];
            }
            if(twoDigit >= 10 && twoDigit <= 26){
                ans[i] += ans[i-2];
            }
        }
        return ans[n];
    }
};
