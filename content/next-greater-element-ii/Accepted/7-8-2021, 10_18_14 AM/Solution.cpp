// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int m=nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        stack<int> st;
        vector<int> ans(m);
        for(int i=m*2-1;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(i<m) ans[i]=st.empty()? -1:st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};