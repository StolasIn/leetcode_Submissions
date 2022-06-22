// https://leetcode.com/problems/car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        vector<int> v(1001,0);
        int ma=-1;
        for(auto t : trips){
            v[t[1]]+=t[0];
            v[t[2]]-=t[0];
            ma=max(ma,t[2]);
        }
        for(int i=0;i<ma;i++){
            cap-=v[i];
            if(cap<0) return false;
        }
        return true;
    }
};