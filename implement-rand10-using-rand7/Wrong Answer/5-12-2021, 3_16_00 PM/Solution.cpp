// https://leetcode.com/problems/implement-rand10-using-rand7

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        return (rand7()*2)%10+1;
    }
};