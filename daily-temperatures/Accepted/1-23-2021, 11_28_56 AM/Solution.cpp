// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    struct node{
        int num,rank;
    };
    vector<int> dailyTemperatures(vector<int>& num) {
        vector<node> st;
        int n=num.size();
        vector<int> ans(n,0);
        if(n==0) return num;
        for(int i=0;i<n;i++){
            st.push_back(node{num[i],i});
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && num[i]>=st.back().num){
                st.pop_back();
            }
            if(st.empty() || st.back().rank-i<0) ans[i]=0;
            else ans[i]=st.back().rank-i;
            st.push_back(node{num[i],i});
        }
        ans[ans.size()-1]=0;
        return ans;
    }
};