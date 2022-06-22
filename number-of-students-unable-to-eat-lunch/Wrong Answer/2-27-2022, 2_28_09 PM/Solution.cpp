// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch

class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& w) {
        int c0 = 0;
        int c1 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==0){
                c0++;
            }
            else{
                c1++;
            }
        }
        for(int i=0;i<w.size();i++){
            if(w[i]==0){
                c0--;
            }
            else{
                c1--;
            }
            if(c0<0 || c1<0){
                return i;
                break;
            }
        }
        return 0;
    }
};