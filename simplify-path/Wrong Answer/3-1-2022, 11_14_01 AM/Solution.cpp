// https://leetcode.com/problems/simplify-path

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
    string simplifyPath(string path) {
        string d = "/.";
        vector<string> v = split(path,d);
        string ans = "/";
        for(int i=0;i<v.size();i++){
            ans+=v[i];
            if(i!=v.size()-1){
                ans+='/';
            }
        }
        return ans;
    }
};