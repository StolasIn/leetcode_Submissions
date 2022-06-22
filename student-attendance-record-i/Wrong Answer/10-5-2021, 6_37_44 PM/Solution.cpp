// https://leetcode.com/problems/student-attendance-record-i

class Solution {
public:
    bool checkRecord(string s) {
        if(s.find("AA")!=string::npos){
            return false;
        }
        if(s.find("LLL")!=string::npos){
            return false;
        }
        return true;
    }
};