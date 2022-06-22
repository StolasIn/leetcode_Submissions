// https://leetcode.com/problems/license-key-formatting

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        if(s.size()==1){
            return s;
        }
        string ans;
        string tmp;
        for(int i=0;i<s.size();i++){
            if(s[i]!='-'){
                tmp+=toupper(s[i]);
            }
        }
        int cnt=tmp.size()%k;
        if(cnt!=0){
            for(int i=0;i<cnt;i++){
                ans+=tmp[i];
            }
            ans+='-';
        }
        for(int i=cnt;i<tmp.size();i+=k){
            for(int j=0;j<k;j++){
                ans+=tmp[i+j];
            }
            if(i+k<tmp.size())ans+='-';
        }
        return ans;
    }
};