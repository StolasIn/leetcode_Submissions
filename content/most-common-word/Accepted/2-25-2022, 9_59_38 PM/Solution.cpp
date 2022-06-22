// https://leetcode.com/problems/most-common-word

class Solution {
public:
    vector<string> split(const string& str, const string& delim) {
        vector<string> res;
        if("" == str) return res;
        char * strs = new char[str.length() + 1] ;
        strcpy(strs, str.c_str()); 
        char * d = new char[delim.length() + 1];
        strcpy(d, delim.c_str());
        char *p = strtok(strs, d);
        while(p) {
            string s = p;
            res.push_back(s);
            p = strtok(NULL, d);
        }
        return res;
    }
    string s2l(string& s){
        for(int i=0;i<s.size();i++){
            s[i] = tolower(s[i]);
        }
        return s;
    }
    string mostCommonWord(string p, vector<string>& b) {
        map<string,int> map;
        unordered_set<string> s;
        vector<string> ss = split(p," !?\',;.");
        int ma = -1;
        string ans;
        for(int i=0;i<ss.size();i++){
            map[s2l(ss[i])]++;
        }
        for(int i=0;i<b.size();i++){
            s.insert(b[i]);
        }
        for(auto i : map){
            if(i.second>ma && s.find(i.first)==s.end()){
                ma = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};