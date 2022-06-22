// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int> st;
        int cnt=0;
        for(int i=0;i<pu.size();i++){
            st.push(pu[i]);
            if(st.top()==po[cnt]){
                st.pop();
                cnt++;
            }
        }
        while(cnt<po.size()){
            if(st.top()==po[cnt]){
                st.pop();
                cnt++;
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};