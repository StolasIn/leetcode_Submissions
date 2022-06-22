// https://leetcode.com/problems/goat-latin

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
    bool isv(char& c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        else if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        return false;
    }
    void change(string& s,int ind){
        if(!isv(s[0])){
            char c=s[0];
            for(int i=1;i<s.size();i++){
                s[i-1]=s[i];
            }
            s[s.size()-1]=c;
        }
        s+="ma";
        for(int i=0;i<=ind;i++) s+='a';
    }
    string toGoatLatin(string& s) {
        string d=" ";
        vector<string> str;
        str=split(s,d);
        string ans;
        for(int i=0;i<str.size();i++){
            change(str[i],i);
            ans+=str[i];
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};