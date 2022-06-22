// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        string tmp = "";
        for(int i = 0; i < s.length(); i++){
            tmp+=s[i];
            if((i+1)%k==0){
                v.push_back(tmp);
                tmp="";
            }
        }
        if(tmp.length()!=0){
            while(tmp.length()!=k){
                tmp+=fill;
            }
            v.push_back(tmp);
        }
        return v;
    }
};