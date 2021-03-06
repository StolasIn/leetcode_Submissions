// https://leetcode.com/problems/sort-even-and-odd-indices-independently

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int>odd,even;
        for(int i=0;i<n;i++){
            if(i%2!=0)odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());
        int i=0;
        for(auto x:even){
            nums[i]=x;
            i+=2;
        }
        i=1;
        for(auto x:odd){
            nums[i]=x;
            i+=2;
        }
        return nums;
    }
};