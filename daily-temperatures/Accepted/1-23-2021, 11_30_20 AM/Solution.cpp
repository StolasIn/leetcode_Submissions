// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& num) {
        vector<int> st;
        int n=num.size();
        vector<int> ans(n,0);
        if(n==0) return num;
        for(int i=0;i<n;i++){
            st.push_back(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && num[i]>=num[st.back()]){
                st.pop_back();
            }
            if(st.empty() || st.back()-i<0) ans[i]=0;
            else ans[i]=st.back()-i;
            st.push_back(i);
        }
        ans[ans.size()-1]=0;
        return ans;
    }
};