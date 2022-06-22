// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& c) {
        unordered_set<int> s;
        int m=c.size();
        for(int i=0;i<m;i++){
            s.insert(c[i]);
        }
        return max(c.size()/2,s.size());
    }
};