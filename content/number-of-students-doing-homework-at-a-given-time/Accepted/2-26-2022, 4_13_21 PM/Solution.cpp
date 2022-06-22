// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time

class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int t) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]<=t && e[i]>=t){
                ans++;
            }
        }
        return ans;
    }
};