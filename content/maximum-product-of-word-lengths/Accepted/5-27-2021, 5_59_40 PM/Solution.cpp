// https://leetcode.com/problems/maximum-product-of-word-lengths

class Solution {
public:
    vector<vector<bool>> v;
    bool cmp(string& a,string& b){
        return a.size()>b.size();
    }
    bool check(int a,int b){
        for(int i='a';i<='z';i++){
            if(v[a][i]==true && v[b][i]==true){
                return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& w){
        v.resize(w.size());
        //sort(w.begin(),w.end(),cmp);
        int m=w.size();
        for(int i=0;i<m;i++){
            v[i].assign(128,false);
        }
        for(int i=0;i<m;i++){
            for(auto j:w[i]){
                v[i][j]=true;
            }
        }
        int ma=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j) continue;
                if(check(i,j)){
                    int s=w[i].size()*w[j].size();
                    ma=max(ma,s);
                }
            }
        }
        return ma;
    }
};