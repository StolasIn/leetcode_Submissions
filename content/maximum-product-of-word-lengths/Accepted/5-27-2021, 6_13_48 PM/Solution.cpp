// https://leetcode.com/problems/maximum-product-of-word-lengths

class Solution {
public:
    int encode(string& s){
        int m=s.size();
        int ans=0;
        for(auto i : s){
            ans|=(1<<(i-'a'));
        }
        return ans;
    }
    int maxProduct(vector<string>& w){
        int m=w.size();
        int arr[m];
        vector<int> v;
        for(int i=0;i<m;i++){
            v.emplace_back(encode(w[i]));
        }
        int ma=0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(i==j) continue;
                if((v[i] & v[j])==0){
                    int s=w[i].size()*w[j].size();
                    ma=max(ma,s);
                }
            }
        }
        return ma;
    }
};