// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        unordered_map<int,int> map;
        int ma=-1;
        for(int i=0;i<arr.size();i++){
            if(map.find(arr[i]-dif)!=map.end()){
                map[arr[i]]=map[arr[i]-dif]+1;
                ma=max(ma,map[arr[i]]);
            }
            else{
                map[arr[i]]=1;
            }
        }
        return ma;
    }
};