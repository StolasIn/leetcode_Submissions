// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string s1, string s2) {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        vector<int> v(s1.size()+s2.size(),0);
        int c=0;
        string s;
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s2.size();j++){
                v[i+j]+=((s1[i]-'0')*(s2[j]-'0'));
            }
        }
        
        for(int i=0;i<v.size()-1;i++){
            c=v[i]/10;
            v[i]%=10;
            v[i+1]+=c;
        }
        if(v.back()==0) v.pop_back();
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            s+=(char)(v[i]+'0');
        }
        return s;
    }
};