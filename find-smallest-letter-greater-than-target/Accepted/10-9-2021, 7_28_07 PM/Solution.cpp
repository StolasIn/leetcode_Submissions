// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[letters.size()-1]<=target){
            return letters[0];
        }
        return *upper_bound(letters.begin(),letters.end(),target);
    }
};