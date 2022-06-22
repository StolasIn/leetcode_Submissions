// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        unordered_map<int,int> map;
        int ma=-1;
        int p;
        int ans=0;
        for(auto& i : pos){
            map[i]++;
        }
        for(auto& i : map){
            if(ma<i.second){
                ma=i.second;
                p=i.first;
            }
        }
        for(int i=0;i<pos.size();i++){
            if((pos[i]-p)%2!=0){
                ans+=1;
            }
        }
        return ans;
    }
};