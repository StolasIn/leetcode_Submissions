// https://leetcode.com/problems/compare-version-numbers

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
    int compareVersion(string& s1, string& s2) {
        vector<string> v1;
        vector<string> v2;
        string d=".";
        v1=split(s1,d);
        v2=split(s2,d);
        int i=0,j=0;
        while(i<v1.size() || j<v2.size()){
            if(i<v1.size() && j<v2.size()){
                if(atoi(v1[i].c_str())>atoi(v2[j].c_str())){
                    return 1;
                }
                else if(atoi(v1[i].c_str())<atoi(v2[j].c_str())){
                    return -1;
                }
                else{
                    i++;
                    j++;
                }
            }
            else if(i>=v1.size()){
                if(atoi(v2[j].c_str())>0){
                    return -1;
                }
                else{
                    j++;
                }
            }
            else{
                if(atoi(v1[i].c_str())>0){
                    return 1;
                }
                else{
                    i++;
                }
            }
        }
        return 0;
    }
};