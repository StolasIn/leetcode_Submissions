// https://leetcode.com/problems/remove-covered-intervals

bool cmp(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        vector<int> tmp=v[0];
        int ans=1;
        for(int i=1;i<v.size();i++){
            if(tmp[0]<=v[i][0] && tmp[1]>=v[i][1]){
                
            }
            else{
                ans++;
                tmp=v[i];
            }
        }
        return ans;
    }
};