// https://leetcode.com/problems/find-right-interval

struct node{
    int id;
    int l,r;
};
bool cmp(node a,node b){
    if(a.l!=b.l){
        return a.l<b.l;
    }
    else{
        return a.r<b.r;
    }
}
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& in) {
        vector<node> arr(in.size());
        for(int i=0;i<in.size();i++){
            arr[i]=node{i,in[i][0],in[i][1]};
        }
        sort(arr.begin(),arr.end(),cmp);
        vector<int> v(in.size());
        arr.emplace_back(node{-1,-1,-1});
        for(int i=0;i<in.size();i++){
            if(arr[i].l<=arr[i+1].l && arr[i].r<=arr[i+1].r){
                v[arr[i].id]=arr[i+1].id;
            }
            else{
                v[arr[i].id]=-1;
            }
        }
        return v;
    }
};