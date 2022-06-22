// https://leetcode.com/problems/slowest-key

class Solution {
public:
    char slowestKey(vector<int>& r, string k) {
        int dur=r[0];
        char ans=k[0];
        for(int i=1;i<r.size();i++){
            if(dur<r[i]-r[i-1]){
                ans=k[i];
                dur=r[i]-r[i-1];
            }
            else if(dur==r[i]-r[i-1]){
                ans=max(ans,k[i]);
            }
        }
        return ans;
    }
};