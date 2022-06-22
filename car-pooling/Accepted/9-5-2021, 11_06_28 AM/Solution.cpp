// https://leetcode.com/problems/car-pooling

struct node{
    int p;
    int n;
    bool flag;
};
int cnt=0;
bool cmp(node a,node b){
    if(a.n==b.n){
        return a.flag>b.flag;
    }
    return a.n<b.n;
}
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        vector<node> v;
        for(auto t : trips){
            v.emplace_back(node{t[0],t[1],false});
            v.emplace_back(node{t[0],t[2],true});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto i : v){
            if(i.flag==false){
                cap-=i.p;
            }
            else{
                cap+=i.p;
            }
            if(cap<0) return false;
        }
        return true;
    }
};