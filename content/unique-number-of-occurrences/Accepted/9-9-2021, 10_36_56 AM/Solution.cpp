// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        unordered_set<int> ch;
        for(auto& i : arr){
            map[i]++;
        }
        for(auto& i : map){
            if(ch.find(i.second)!=ch.end()){
                return false;
            }
            else{
                ch.insert(i.second);
            }
        }
        return true;
    }
};