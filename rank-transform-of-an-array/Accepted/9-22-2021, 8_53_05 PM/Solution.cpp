// https://leetcode.com/problems/rank-transform-of-an-array

struct node{
    int val,id;
    bool operator<(const node a) const {
        return a.val>val;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<node> v;
        int cnt=1;
        for(int i=0;i<arr.size();i++){
            v.emplace_back(node{arr[i],i});
        }
        sort(v.begin(),v.end());
        arr[v[0].id]=cnt;
        for(int i=1;i<v.size();i++){
            if(v[i].val!=v[i-1].val) cnt++;
            arr[v[i].id]=cnt;
        }
        return arr;
    }
};