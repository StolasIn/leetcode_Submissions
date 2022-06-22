// https://leetcode.com/problems/reorder-data-in-log-files

bool cmp(string& s1,string& s2){
    string g1 = "";
    string g2 = "";
    bool flag = false;
    for(int i=0;i<s1.size();i++){
        if(flag==true){
            g1+=s1[i];
        }
        if(s1[i]==' '){
            flag = true;
        }
    }
    flag = false;
    for(int i=0;i<s2.size();i++){
        if(flag==true){
            g2+=s2[i];
        }
        if(s2[i]==' '){
            flag = true;
        }
    }
    return g1<g2;
}
class Solution {
public:
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> l;
        vector<string> d;
        for(int i=0;i<logs.size();i++){
            if(logs[i][0]=='l'){
                l.emplace_back(logs[i]);
            }
            else{
                d.emplace_back(logs[i]);
            }
        }
        sort(l.begin(),l.end(),cmp);
        l.insert(l.end(),d.begin(),d.end());
        return l;
    }
};