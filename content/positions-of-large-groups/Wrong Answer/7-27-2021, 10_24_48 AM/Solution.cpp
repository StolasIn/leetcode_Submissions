// https://leetcode.com/problems/positions-of-large-groups

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int cnt=1;
        int f=INT_MAX;
        vector<vector<int>> ans;
        int m=s.size();
        for(int i=1;i<m;i++){
            if(s[i]==s[i-1]){
                f=min(f,i);
                cnt++;
            }
            else{
                if(cnt>=3){
                    ans.emplace_back(vector<int>{f,i-1});
                }
                f=i;
                cnt=1;
            }
        }
        if(cnt>=3){
            ans.emplace_back(vector<int>{f,m-1});
        }
        return ans;
    }
};