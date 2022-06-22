// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<deque<char>,int> map;
        vector<string> ans;
        deque<char> dq(s.begin(),s.begin()+10);
        for(int i=10;i<s.size();i++){
            map[dq]++;
            dq.pop_front();
            dq.push_back(s[i]);
        }
        map[dq]++;
        for(auto i : map){
            if(i.second>1){
                ans.emplace_back(string(i.first.begin(),i.first.end()));
            }
        }
        return ans;
    }
};