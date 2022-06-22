// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> num;
        if(x<0) return false;
        else{
            for(;x!=0;){
                num.push_back(x%10);
                x/=10;
            }
            for(int i=0,j=num.size()-1;i<num.size();i++,j--){
                if(num[i]!=num[j]) return false;
            }
            return true;
        }
    }
};