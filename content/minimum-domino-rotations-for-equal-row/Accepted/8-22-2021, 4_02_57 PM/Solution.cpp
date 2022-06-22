// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int t1[7];
        int b1[7];
        int both[7];
        int m=t.size();
        for(int i=1;i<=6;i++){
            t1[i]=0;
            b1[i]=0;
            both[i]=0;
        }
        for(int i=0;i<m;i++){
            if(t[i]==b[i]){
                both[t[i]]++;
            }
            else{
                t1[t[i]]++;
                b1[b[i]]++;   
            }
        }
        for(int i=1;i<=6;i++){
            if(t1[i]+b1[i]+both[i]==m){
                return min(t1[i],b1[i]);
            }
        }
        return -1;
    }
};