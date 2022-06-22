// https://leetcode.com/problems/number-of-equivalent-domino-pairs

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        unordered_map<string,int> map;
        int ans=0;
        int l,r;
        for(int i=0;i<dom.size();i++){
            l=min(dom[i][0],dom[i][1]);
            r=max(dom[i][0],dom[i][1]);
            map[to_string(l)+to_string(r)]++;
        }
        for(auto i : map){
            ans+=((i.second*(i.second-1)))/2;
        }
        return ans;
    }
};