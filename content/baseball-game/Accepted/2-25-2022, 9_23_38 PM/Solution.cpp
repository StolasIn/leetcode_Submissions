// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<int> st;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=="C"){
                st.pop();
            }
            else if(s[i]=="D"){
                int t = st.top();
                st.pop();
                st.push(t);
                st.push(t*2);
            }
            else if(s[i]=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            else{
                st.push(atoi(s[i].c_str()));
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};