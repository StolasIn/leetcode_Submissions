// https://leetcode.com/problems/maximum-length-of-pair-chain

bool cmp(vector<int>& a,vector<int>& b){
    if(a!=b){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        if(p.size()==1) return 1;
        sort(p.begin(),p.end(),cmp);
        /*for(auto i : p){
            cout<<i[0]<<" "<<i[1]<<endl;
        }*/
        int cnt=1;
        for(int i=1;i<p.size();i++){
            if(p[i-1][1]>=p[i][0]){
                
            }
            else{
                cnt++;
            }
        }
        return cnt>=2? cnt:2;
    }
};