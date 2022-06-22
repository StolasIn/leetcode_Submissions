// https://leetcode.com/problems/best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int val = -1e9,pos = -1e9;
        int ma = -1;
        int ans = 0;
        for(int i=0;i<v.size();i++){
            ans = max(ans,v[i]+val+pos-i);
            if(v[i]+i>ma){
                ma = v[i]+i;
                val = v[i];
                pos = i;
            }
        }
        return ans;
    }
};