// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

struct node{
    char c;
    int f;
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<node> st;
        string ans="";
        int m = s.size();
        for(int i=0;i<m;i++){
            if(st.empty() || s[i]!=st.top().c){
                st.push(node{s[i],1});
            }
            else{
                st.push(node{s[i],st.top().f+1});
            }
            if(st.top().f>=k){
                for(int i=0;i<k;i++){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans+=st.top().c;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};