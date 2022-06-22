// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int> ans;
        for(int i=1;i<arr.size();i++){
            arr[i]^=arr[i-1];
        }
        for(int i=0;i<q.size();i++){
            if(q[i][0]==0){
                ans.emplace_back(arr[q[i][1]]);
            }
            else{
                ans.emplace_back(arr[q[i][1]]^arr[q[i][0]-1]);
            }
        }
        return ans;
    }
};