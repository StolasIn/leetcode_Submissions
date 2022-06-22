// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int,int> map;
        int ans=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                map[a[i]+b[j]]++;
            }
        }
        for(int i=0;i<c.size();i++){
            for(int j=0;j<d.size();j++){
                if(map.find(-c[i]-d[j])!=map.end()){
                    ans+=map[-c[i]-d[j]];
                }
            }
        }
        return ans;
    }
};