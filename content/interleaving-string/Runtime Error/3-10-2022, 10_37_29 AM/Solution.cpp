// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<char> v1(s1.begin(),s1.end());
        vector<char> v2(s2.begin(),s2.end());
        vector<char> v3(s3.begin(),s3.end());
        while(!v3.empty()){
            if(v3.back()==v1.back()){
                v1.pop_back();
                v3.pop_back();
            }
            else if(v3.back()==v2.back()){
                v2.pop_back();
                v3.pop_back();
            }
            else{
                return false;
            }
        }
        return true;
    }
};