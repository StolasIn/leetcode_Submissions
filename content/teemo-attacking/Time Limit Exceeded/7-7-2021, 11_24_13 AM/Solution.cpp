// https://leetcode.com/problems/teemo-attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int d) {
        unordered_set<int> s;
        int m=time.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<d;j++){
                s.insert(time[i]+j);
            }
        }
        return s.size();
    }
};