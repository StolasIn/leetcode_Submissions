// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        char ma='0';
        for(int i=0;i<n.size();i++){
            ma=max(ma,n[i]);
        }
        return ma-'0';
    }
};