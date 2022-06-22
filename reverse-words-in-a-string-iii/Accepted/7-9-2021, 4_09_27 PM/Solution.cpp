// https://leetcode.com/problems/reverse-words-in-a-string-iii

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
    string reverseWords(string s) {
        vector<string> str;
        string ans;
        string tok=" ";
        str=split(s,tok);
        for(int i=0;i<str.size();i++){
            reverse(str[i].begin(),str[i].end());
        }
        for(int i=0;i<str.size();i++){
            ans+=str[i];
            if(i!=str.size()-1) ans+=" ";
        }
        return ans;
    }
};