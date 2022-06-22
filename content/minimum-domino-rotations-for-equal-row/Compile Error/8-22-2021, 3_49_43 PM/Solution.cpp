// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        bool d[7];
        int cnt1[7];
        int cnt2[7];
        int ma=-1;
        vector<int> ans;
        for(int i=1;i<=6;i++){
            d[i]=true;
            cnt[i]=0;
        }
        int m=t.size();
        for(int i=0;i<m;i++){
            cnt1[t[i]]++;
            cnt2[b[i]]++;
            for(int j=1;j<=6;j++){
                if(j!=t[i] && j!=b[i]){
                    d[j]=false;
                }
            }
        }
        for(int i=1;i<=6;i++){
            if(d[i]){
                ma=max(ma,cnt1[i]);
                ma=max(ma,m-cnt1[i]);
                ma=max(ma,cnt2[i]);
                ma=max(ma,m-cnt2[i]);
            }
        }
        if(ma==-1) return -1;
        return m-ma;
    }
};