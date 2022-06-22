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
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                v[i] = -1;
            }
        }
        auto v_tmp = v;
        int m = s2.size();
        int n = s1.size();
        while(r+1<m){
            r++;
            cout<<l<<' '<<r<<' '<<cnt<<endl;
            if(v[s2[r]]==-1){
                v = v_tmp;
                l = r;
                cnt = 0;
            }
            else if(v[s2[r]]==0){
                while(s2[++l]!=s2[r]){
                    v[s2[l]]++;
                    cnt--;
                }
                v[s2[l]]++;
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