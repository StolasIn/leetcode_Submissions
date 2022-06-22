// https://leetcode.com/problems/score-of-parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int m=s.size();
        for(int i=0;i<m;i++){
            if(s[i]=='('){
                st.push(-1);
            }
            else{
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int sum=0;
                    while(st.top()!=-1 && !st.empty()){
                        sum+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        if(st.size()>1){
            int sum=0;
            while(!st.empty()){
                sum+=st.top();
                st.pop();
            }
            return sum;
        }
        return st.top();
    }
};