// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mi = 1e9;
        int ma = -1e9;
        int diff = 1e9;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                nums[i] *= 2;
            }
            mi = min(mi,nums[i]);
            ma = max(ma,nums[i]);
            s.insert(nums[i]);
        }
        diff = min(diff,ma-mi);
        while((*s.rbegin())%2==0){
            int t = (*s.rbegin()) / 2;
            s.erase(--s.end());
            s.insert(t);
            mi = min(mi,t);
            diff = min(diff,(*s.rbegin()) - mi);
        }
        return diff;
    }
};