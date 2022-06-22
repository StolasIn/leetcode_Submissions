// https://leetcode.com/problems/fair-candy-swap

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int diff = 0;
        unordered_set<int> s;
        for(int i=0;i<a.size();i++){
            diff+=a[i];
            s.insert(a[i]);
        }
        for(int i=0;i<b.size();i++){
            diff-=b[i];
        }
        diff/=2;
        for(int i=0;i<b.size();i++){
            if(s.find(b[i]+diff)!=s.end()){
                return {b[i]+diff,b[i]};
            }
        }
        return {-1,-1};
    }
};