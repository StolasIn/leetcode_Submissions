// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& w) {
        int ch[128]={0};
        int ans[128];
        vector<string> res;
        for(int i='a';i<='z';i++){
            ans[i]=1e9;
        }
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w[i].size();j++){
                ch[w[i][j]]++;
            }
            for(int k='a';k<='z';k++){
                ans[k]=min(ans[k],ch[k]);
                ch[k]=0;
            }
        }
        string str;
        for(int i='a';i<='z';i++){
            str+=(char)i;
            for(int j=0;j<ans[i];j++){
                res.emplace_back(str);
            }
            str.pop_back();
        }
        return res;
    }
};