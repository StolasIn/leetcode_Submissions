// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int find_fro(int a){
        return (a*(a-1))/4;
    }
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto i : map){
            if(i.second>=2){
                sum+=(i.second*(i.second-1))/2;
            }
        }
        return sum;
    }
};