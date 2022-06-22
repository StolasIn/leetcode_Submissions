// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    struct node{
        int num,rank;
    };
    vector<int> dailyTemperatures(vector<int>& num) {
        vector<node> st;
        int n=num.size();
        vector<int> ans(n);
        if(n==0) return num;
        for(int i=0;i<n;i++){
            st.push_back(node{num[i],i});
        }
        for(int i=n-1;i>=0;i--){
            while(num[i]>st.back().num && !st.empty()){
                st.pop_back();
            }
            ans[i]=st.back().rank-i;
            st.push_back(node{num[i],i});
        }
        return ans;
    }
};