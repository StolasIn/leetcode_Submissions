// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int odd=0;
        int m = pos.size();
        for(int i=0;i<m;i++){
            if(pos[i]%2!=0){
                odd++;
            }
        }
        return min(odd,m-odd);
    }
};