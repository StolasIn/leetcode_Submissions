// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int now=0;
        int ans=0;
        for(int i=0;i<t.size();i++){
            ans+=(t[i]+d-max(now,t[i]));
            now=t[i]+d;
        }
        return ans;
    }
};