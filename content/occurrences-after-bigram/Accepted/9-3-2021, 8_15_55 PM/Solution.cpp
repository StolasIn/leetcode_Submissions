// https://leetcode.com/problems/occurrences-after-bigram

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
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> word;
        string dim=" ";
        word=split(text,dim);
        vector<string> ans;
        for(int i=0;i<word.size()-2;i++){
            if(word[i]==first && word[i+1]==second){
                ans.emplace_back(word[i+2]);
            }
        }
        return ans;
    }
};