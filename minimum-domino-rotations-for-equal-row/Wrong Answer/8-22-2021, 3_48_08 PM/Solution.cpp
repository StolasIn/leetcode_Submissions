// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        bool d[7];
        int cnt[7];
        int ma=-1;
        vector<int> ans;
        for(int i=1;i<=6;i++){
            d[i]=true;
            cnt[i]=0;
        }
        int m=t.size();
        for(int i=0;i<m;i++){
            cnt[t[i]]++;
            for(int j=1;j<=6;j++){
                if(j!=t[i] && j!=b[i]){
                    d[j]=false;
                }
            }
        }
        for(int i=1;i<=6;i++){
            if(d[i]){
                ma=max(ma,cnt[i]);
                ma=max(ma,m-cnt[i]);
            }
        }
        return m-ma;
    }
};