// https://leetcode.com/problems/reformat-the-string

class Solution {
public:
    string reformat(string s) {
        vector<char> l;
        vector<char> d;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                d.emplace_back(s[i]);
            }
            else{
                l.emplace_back(s[i]);
            }
        }
        int m = d.size(),n = l.size();
        if(abs(m-n)>1){
            return "";
        }
        int i=0,j=0;
        if(d.size()>l.size()){
            while(j<l.size()){
                ans+=d[i];
                i++;
                ans+=l[j];
                j++;
            }
            ans+=d[i];
        }
        else if(d.size()<l.size()){
            while(i<d.size()){
                ans+=l[i];
                i++;
                ans+=d[j];
                j++;
            }
            ans+=l[j];
        }
        else{
             while(i<d.size()){
                ans+=l[i];
                i++;
                ans+=d[j];
                j++;
            }
        }
        return ans;
    }
};