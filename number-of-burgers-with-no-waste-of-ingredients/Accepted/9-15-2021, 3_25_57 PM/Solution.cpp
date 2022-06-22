// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients

class Solution {
public:
    vector<int> numOfBurgers(int a, int b) {
        if((a-2*b)%2!=0 or (4*b-a)%2!=0 or (a-2*b)<0 or (4*b-a)<0){
            return {};
        }
        return {(a-2*b)/2,(4*b-a)/2};
    }
};