// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> ne(10010,0);
        vector<vector<int>> ans;
        vector<int> error;
        int m=intervals.size();
        for(int i=0;i<m;i++){
            if(intervals[i][0]==intervals[i][1]) error.push_back(intervals[i][0]);
            for(int j=intervals[i][0];j<intervals[i][1];j++){
                ne[j]=1;
            }
        }
        for(int i=0;i<error.size();i++) if(ne[error[i]]!=1) ans.push_back(vector<int>{error[i],error[i]});
        for(int i=0;i<10010;i++){
            if(ne[i]>=1){
                for(int j=i+1;j<10010;j++){
                    if(ne[j]<1){
                        ans.push_back(vector<int>{i,j});
                        i=j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};