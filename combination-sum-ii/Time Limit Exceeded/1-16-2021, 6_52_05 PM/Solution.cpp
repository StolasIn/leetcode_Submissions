// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> ans;
    void re(vector<int> now,vector<int>& candidates,int item,int remain){
        if(remain==0){
            ans.push_back(now);
            return;
        }
        else if(remain<0) return;
        if(item>=candidates.size()){
            return;
        }
        
        re(now,candidates,item+1,remain);
        now.push_back(candidates[item]);
        re(now,candidates,item+1,remain-candidates[item]);
        
    }
    bool equ(vector<int> a,vector<int> b){
        if(a.size()!=b.size()) return false;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    bool contain(vector<vector<int>>& a,vector<int> b){
        for(int i=0;i<a.size();i++){
            if(equ(a[i],b)){
                return true;
            }
        }
        return false;
    }
    void uni(vector<vector<int>>& an){
        vector<vector<int>> a;
        for(int i=0;i<an.size();i++){
            if(!contain(a,an[i])){
                a.push_back(an[i]);
            }
        }
        an.clear();
        for(int i=0;i<a.size();i++){
            an.push_back(a[i]);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> now;
        re(now,candidates,0,target);
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        for(int i=0;i<ans.size();i++){
            uni(ans);
        }
        return ans;
    }
};