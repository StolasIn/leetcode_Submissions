// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    set<vector<int>> s;
    void re(vector<int>& num,vector<int>& now,int idx){
        s.insert(now);
        if(idx>=num.size()) return;
        for(int i=idx+1;i<=num.size();i++){
            now.emplace_back(num[idx]);
            re(num,now,i);
            now.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& num) {
        vector<int> now;
        vector<vector<int>> ans;
        for(int i=0;i<num.size();i++)
            re(num,now,i);
        for(auto i : s){
            ans.emplace_back(i);
        }
        return ans;
    }
};