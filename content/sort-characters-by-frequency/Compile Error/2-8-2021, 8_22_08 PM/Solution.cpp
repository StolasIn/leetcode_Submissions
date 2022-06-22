// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        string s1="";
        vector<pair<char,int>> v;
        vector<int> ch(128,0);
        int m=s.size();
        for(int i=0;i<m;i++){
            ch[s[i]]++;
        }
        for(int i=0;i<m;i++){
            v.emplace_back(pair<char,int>(s[i],ch[s[i]]));
        }
        stable::sort(v.begin(),v.end(),[](pair<char,int> a, pair<char,int> b){
            return a.second>b.second;
        });
        for(int i=0;i<m;i++){
            s1+=v[i].first;
        }
        return s1;
    }
};