// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int m=s.size();
        string ans;
        for(int i=0;i<m;i++){
            st.push(s[i]);
            if(s[i]==']'){
                st.pop();
                string str="";
                while(!st.empty() && isalpha(st.top())){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(str.begin(),str.end());
                string str1="";
                int pu;
                while(!st.empty() && isdigit(st.top())){
                    str1+=st.top();
                    st.pop();
                }
                reverse(str1.begin(),str1.end());
                pu=atoi(str1.c_str());
                for(int i=0;i<pu;i++){
                    for(int j=0;j<str.size();j++){
                        st.push(str[j]);
                    }
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};