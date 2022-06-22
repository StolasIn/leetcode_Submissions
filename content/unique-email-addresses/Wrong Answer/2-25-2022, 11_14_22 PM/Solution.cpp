// https://leetcode.com/problems/unique-email-addresses

class Solution {
public:
    string trans(string& s){
        string ans="";
        bool flag = false;
        for(int i=0;i<s.size();i++){
            if(flag==false){
                if(s[i]=='.'){
                    continue;
                }
                else if(s[i]=='+'){
                    while(s[i]!='@'){
                        i++;
                    }
                    ans+='@';
                    flag = true;
                }
                else{
                    ans+=s[i];
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
    int numUniqueEmails(vector<string>& es) {
        unordered_set<string> s;
        for(int i=0;i<es.size();i++){
            cout<<trans(es[i])<<endl;
            s.insert(trans(es[i]));
        }
        return s.size();
    }
};