// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        for(auto i = map.rbegin();i!=map.rend();i++){
            if((*i).first == (*i).second){
                return (*i).first;
            }
        }
        return -1;
    }
};