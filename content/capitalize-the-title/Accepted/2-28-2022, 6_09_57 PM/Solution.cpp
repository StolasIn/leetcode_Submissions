// https://leetcode.com/problems/capitalize-the-title

class Solution {
public:
    string str_to_lower(string word, bool cap) {
        for (auto& letter : word) letter = tolower(letter);
        if (cap) word[0] = toupper(word[0]);
        return word;
    }
    
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string word, res;
        
        while (ss >> word)
            res += str_to_lower(word, word.size() > 2) + " ";
        
        res.pop_back();
        return res;
    }
};