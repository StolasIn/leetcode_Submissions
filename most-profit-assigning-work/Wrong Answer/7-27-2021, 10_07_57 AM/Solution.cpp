// https://leetcode.com/problems/most-profit-assigning-work

struct node{
    int d,p;
};
bool cmp(node a,node b){
    return a.d<b.d;
}
class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<node> v;
        for(int i=0;i<d.size();i++){
            v.emplace_back(node{d[i],p[i]});
        }
        sort(v.begin(),v.end(),cmp);
        sort(w.begin(),w.end());
        int ma=0,cnt=0,ans=0;
        for(int i=0;i<v.size();i++){
            if(cnt>=w.size()) break;
            if(w[cnt]>=v[i].d){
                ma=max(ma,v[i].p);
            }
            else{
                ans+=ma;
                cnt++;
                i--;
            }
        }
        return ans;
    }
};