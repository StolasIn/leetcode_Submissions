// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

class Solution {
public:
    bool check(unordered_map<char,int>& map,string& str){
        unordered_map<char,int> tmp;
        for(auto& t : str){
            tmp[t]++;
        }
        for(auto& i : tmp){
            if(map.find(i.first)==map.end() || map[i.first]<i.second){
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string s) {
        unordered_map<char,int> map;
        int ans=0;
        for(auto& t : s){
            map[t]++;
        }   
        for(auto& str : words){
            if(check(map,str)){
                ans+=str.size();
            }
        }
        return ans;
    }
};