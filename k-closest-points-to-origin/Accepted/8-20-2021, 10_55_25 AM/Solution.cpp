// https://leetcode.com/problems/k-closest-points-to-origin

struct node{
    double dis;
    vector<int> val;
    bool operator<(const node& a) const{
        return dis>a.dis;
    }
};
double d(vector<int> a){
    return a[0]*a[0]+a[1]*a[1];
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<node> pq;
        vector<vector<int>> v;
        for(int i=0;i<p.size();i++){
            pq.push(node{d(p[i]),p[i]});
        }
        for(int i=0;i<k;i++){
            v.emplace_back(pq.top().val);
            pq.pop();
        }   
        return v;
    }
};