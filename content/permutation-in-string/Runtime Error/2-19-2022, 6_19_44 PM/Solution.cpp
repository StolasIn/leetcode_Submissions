// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(128,0);
        int cnt = 0;
        int l=-1,r=-1;
        for(int i=0;i<s1.size();i++){
            v[s1[i]]++;
        }
        auto v_tmp = v;
        int m = s2.size();
        int n = s1.size();
        while(r-1<m){
            r++;
            if(v[s2[r]]==0){
                v = v_tmp;
                cnt = 0;
            }
            else{
                v[s2[r]]--;
                cnt++;
            }
            if(cnt==s1.size()){
                return true;
            }
        }
        return false;
    }
};