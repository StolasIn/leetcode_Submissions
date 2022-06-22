// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> ans;
        vector<string> str;
        int n=str.size();
        str.assign(strs.begin(),strs.end());
        for(int i=0;i<n;i++){
            sort(str[i].begin(),str[i].end());
        }
        for(int i=0;i<n;i++){
            map[str[i]].push_back(strs[i]);
        }
        for(auto i : map){
            ans.push_back(i.second);
        }
        return ans;
    }
};