// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mi = 1e9;
        int diff = 1e9;
        int t;
        set<int> s;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                nums[i] *= 2;
            }
            mi = min(mi,nums[i]);
            s.insert(nums[i]);
        }
        for(int i : s){
            pq.push(i);
        }
        while(pq.top()%2==0){
            t = pq.top()/2;
            mi = min(mi,t);
            pq.pop();
            pq.push(t);
            diff = min(diff,pq.top()-mi);
        }
        return diff;
    }
};