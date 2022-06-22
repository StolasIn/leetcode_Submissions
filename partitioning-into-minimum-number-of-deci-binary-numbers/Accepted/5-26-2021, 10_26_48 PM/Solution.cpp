// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
        for(char x:n){
            mx=max(mx,x-'0');
            if(mx==9)
                break;
        }
        return mx;
    }
};