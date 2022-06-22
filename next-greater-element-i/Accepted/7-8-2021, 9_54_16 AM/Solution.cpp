// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int> st;
        unordered_map<int,int> map;
        vector<int> ans;
        int m=n2.size();
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && n2[i]>st.top()) st.pop();
            if(st.empty()){
                map[n2[i]]=-1;
            }
            else{
                map[n2[i]]=st.top();
            }
            st.push(n2[i]);
        }
        for(int i=0;i<n1.size();i++){
            ans.emplace_back(map[n1[i]]);
        }
        return ans;
    }
};