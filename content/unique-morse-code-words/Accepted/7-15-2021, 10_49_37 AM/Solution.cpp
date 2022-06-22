// https://leetcode.com/problems/unique-morse-code-words

class Solution {
public:
    vector<string> ch={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string change(string& str){
        int m=str.size();
        string ans;
        for(int i=0;i<str.size();i++){
            ans+=ch[str[i]-'a'];
        }
        return ans;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;
        for(int i=0;i<words.size();i++){
            s.insert(change(words[i]));
        }
        return s.size();
    }
};