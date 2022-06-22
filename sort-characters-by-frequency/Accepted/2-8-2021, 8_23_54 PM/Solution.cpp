// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(const string& s) {
        vector<string> v(127);
        for(auto i:s) v[i]+=i;
        sort(v.begin(),v.end(),[](const string& s1,const string& s2){return s1.size()>s2.size();});
        string res;
        for(auto i:v) res+=i;
        return res;
    }
};