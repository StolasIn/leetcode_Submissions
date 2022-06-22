// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

struct node{
    int val,id;
    bool operator<(const node& a) const {
        if(a.val==val){
            return a.id<id;
        }
        return a.val<val;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<node> pq;
        vector<int> ans;
        int c;
        for(int i=0;i<mat.size();i++){
            c=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) c++;
                else break;
            }
            pq.push(node{c,i});
        }
        for(int i=0;i<k;i++){
            ans.emplace_back(pq.top().id);
            pq.pop();
        }
        return ans;
    }
};