// https://leetcode.com/problems/number-of-different-integers-in-a-string

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<int> s;  
        for (int i = 0; i < word.size(); i++) {
            if (isdigit(word[i])) {
			    string str;
                while (isdigit(word[i])){
                    str += word[i];
                    i++;
                }
                s.insert(atoi(str.c_str()));
            }
        }
        return s.size();
    }
};