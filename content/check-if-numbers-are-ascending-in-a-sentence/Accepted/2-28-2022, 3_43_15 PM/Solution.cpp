// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence

class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        int pre = -1;
        string tmp;
        while(ss>>tmp){
            if(isdigit(tmp[0])){
                int t = atoi(tmp.c_str());
                if(pre>=t){
                    return false;
                }
                pre = t;
            }
        }
        return true;
    }
};