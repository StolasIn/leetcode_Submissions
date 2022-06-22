// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int,int> map;
        nums.insert(nums.end(),nums.begin(),nums.end());
        int m=nums.size();
        stack<int> st;
        vector<int> ans;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(map.find(nums[i])!=map.end()){
                if(map[nums[i]]==-1){
                    map[nums[i]]=st.empty()? -1:st.top();
                }
            }
            else if(map.find(nums[i])==map.end()){
                map[nums[i]]=st.empty()? -1:st.top();
            }
            st.push(nums[i]);
        }
        m/=2;
        for(int i=0;i<m;i++){
            ans.emplace_back(map[nums[i]]);
        }
        return ans;
    }
};