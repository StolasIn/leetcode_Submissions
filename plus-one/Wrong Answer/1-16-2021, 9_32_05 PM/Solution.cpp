// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        vector<int> aon;
        for(int i=digits.size()-1;i>0;i--){
            if(digits[i]>=10){
                digits[i-1]++;
            }
        }
        if(digits[0]>=10){
            aon.push_back(1);
            for(int i=0;i<digits.size();i++){
                aon.push_back(digits[i]);
            }
            return aon;
        }
        return digits;
    }
};