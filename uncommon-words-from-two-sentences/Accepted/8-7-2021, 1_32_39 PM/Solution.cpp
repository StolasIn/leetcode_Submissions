// https://leetcode.com/problems/uncommon-words-from-two-sentences

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
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> map1;
        unordered_map<string,int> map2;
        vector<string> str1;
        vector<string> str2;
        vector<string> ans;
        string d=" ";
        str1=split(s1,d);
        str2=split(s2,d);
        for(int i=0;i<str1.size();i++){
            map1[str1[i]]++;
        }
        for(int i=0;i<str2.size();i++){
            map2[str2[i]]++;
        }
        for(auto i : map1){
            if(i.second==1 && map2.find(i.first)==map2.end()){
                ans.emplace_back(i.first);
            }
        }
        for(auto i : map2){
            if(i.second==1 && map1.find(i.first)==map1.end()){
                ans.emplace_back(i.first);
            }
        }
        return ans;
    }
};