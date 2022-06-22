// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int cnt=0;
        int l=0,r=0;
        int ans=-1;
        unordered_map<int,int> map;
        while(r<f.size()){
            if(cnt<=2){
                ans=max(ans,r-l);
                if(map[f[r]]==0){
                    cnt++;
                }
                map[f[r]]++;
                r++;
            }
            else{
                while(cnt>2){
                    if(map[f[l]]==1){
                        cnt--;
                    }
                    map[f[l]]--;
                    l++;
                }
            }
        }
        if(cnt<=2){
            ans=max(ans,r-l);
        }
        return ans;
    }
};