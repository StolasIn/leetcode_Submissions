// https://leetcode.com/problems/student-attendance-record-i

class Solution {
public:
    bool checkRecord(string s) {
        int cnt=0;
        if(s.find("LLL")!=string::npos){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'){
                cnt++;
                if(cnt>=2) return false;
            }
        }
        return true;
    }
};