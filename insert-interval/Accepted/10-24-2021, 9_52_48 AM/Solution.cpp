// https://leetcode.com/problems/insert-interval

bool cmp(vector<int>& a,vector<int>& b){
    if(a[0]!=b[0]){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),cmp);
        vector<vector<int>> ans;
        for(int i=0;i<in.size();i++){
            if(ans.size()==0 || ans[ans.size()-1][1]<in[i][0]){
                ans.emplace_back(in[i]);
            }
            else{
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],in[i][1]);
            }
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& n) {
        in.emplace_back(n);
        return merge(in);
    }
};