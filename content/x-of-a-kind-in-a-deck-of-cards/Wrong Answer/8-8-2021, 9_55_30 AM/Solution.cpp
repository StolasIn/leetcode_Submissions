// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> map;
        for(int i=0;i<deck.size();i++){
            map[deck[i]]++;
        }
        int now=map.begin()->second;
        for(auto i : map){
            if(now!=i.second){
                return false;
            }
        }
        return true;
    }
};