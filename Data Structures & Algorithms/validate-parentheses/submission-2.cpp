class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int index = 0;
        while(index < s.length()){
            if(s[index] == ')'){
                if(st.empty()) return false;
                if(st.top() == '(') st.pop();
                else return false;
            }
            else if(s[index] == '}'){
                if(st.empty()) return false;
                if(st.top() == '{') st.pop();
                else return false;
            }
            else if(s[index] == ']'){
                if(st.empty()) return false;
                if(st.top() == '[') st.pop();
                else return false;
            }
            else st.push(s[index]);
            index++;
        }
        return st.empty();
    }
};
