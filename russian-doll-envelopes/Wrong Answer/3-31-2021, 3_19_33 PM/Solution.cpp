// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]<b[0]){
            return true;
        }
        else if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),cmp);
        int m=e.size();
        int cnt=0;
        auto tmp=e[0];
        for(int i=0;i<m;i++){
            if(tmp[0]<e[i][0] && tmp[1]<e[i][0]){
                cnt++;
                tmp=e[i];
            }
        }
        //cout<<cnt<<endl;
        return cnt+1;
    }
};