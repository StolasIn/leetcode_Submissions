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
        bool flag;
        vector<node> arr(in.size());
        for(int i=0;i<in.size();i++){
            arr[i]=node{i,in[i][0],in[i][1]};
        }
        sort(arr.begin(),arr.end(),cmp);
        vector<int> v(in.size());
        arr.emplace_back(node{-1,-1,-1});
        for(int i=0;i<in.size();i++){
            if(arr[i].l==arr[i].r){
                v[arr[i].id]=arr[i].id;
                continue;
            }
            flag=false;
            for(int j=i+1;j<in.size();j++){
                if(arr[i].r<=arr[j].l){
                    v[arr[i].id]=arr[j].id;
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                v[arr[i].id]=-1;
            }
        }
        return v;
    }
};