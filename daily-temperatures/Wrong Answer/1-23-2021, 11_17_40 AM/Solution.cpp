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
            if(num[i]>st.back().num){
                st.pop_back();
                i++;
            }
            else if(num[i]<st.back().num){
                ans[i]=st.back().rank-i;
                st.push_back(node{num[i],i});
            }
            else{
                int j;
                for(j=st.size()-1;j>=0 && st[j].num<=num[i];j--);
                if(j>=0)
                    ans[i]=st[j].rank-i;
                else{
                    ans[i]=0;
                }
            }
        }
        ans[ans.size()-1]=0;
        return ans;
    }
};