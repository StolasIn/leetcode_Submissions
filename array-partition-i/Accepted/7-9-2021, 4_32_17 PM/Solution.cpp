// https://leetcode.com/problems/array-partition-i

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum=0;
        int a,b;
        int m=nums.size();
        for(int i=0;i<m;i++){
            pq.push(nums[i]);
        }
        while(!pq.empty()){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            sum+=min(a,b);
        }
        return sum;
    }
};