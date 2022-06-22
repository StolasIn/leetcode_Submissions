// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        stack<int> st;
        vector<int> ans(p.size());
        for(int i=p.size()-1;i>=0;i--){
            if(st.empty() || st.top()>p[i]){
                while(!st.empty() && st.top()>p[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = p[i] - st.top();
                }
                else{
                    ans[i] = p[i];
                }
                st.push(p[i]);
            }
            else{
                ans[i] = p[i]-st.top();
                st.push(p[i]);
            }
        }
        return ans;
    }
};