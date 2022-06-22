// https://leetcode.com/problems/degree-of-an-array

struct node{
    int v,l,r;
};
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,node> map;
        int ma=0,mi=1e9;
        int tmp;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])==map.end()){
                map[nums[i]].l=i;
            }
            map[nums[i]].v++;
            map[nums[i]].r=i;
        }
        for(auto& i : map){
            if(ma<=i.second.v){
                ma=i.second.v;
            }
        }
        for(auto& i : map){
            if(ma==i.second.v){
                if((i.second.r-i.second.l+1)<mi){
                    mi=i.second.r-i.second.l+1;
                }
            }
        }
        return mi;
    }
};