// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    struct node{
        int num,rank;
    };
    vector<int> dailyTemperatures(vector<int>& num) {
        stack<node> st;
        int n=num.size();
        vector<int> ans(n);
        if(n==0) return num;
        for(int i=0;i<n;i++){
            st.push(node{num[i],i});
        }
        print(st);
        for(int i=n-1;i>=0;i--){
            print(st);
            if(num[i]>st.top().num){
                st.pop();
                i++;
            }
            else if(num[i]<st.top().num){
                ans[i]=st.top().rank-i;
                st.push(node{num[i],i});
            }
            print(st);
        }
        return ans;
    }
};