// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& num, int k) {
        unordered_map<int,int> map;
        int m=num.size();
        for(int i=0;i<m;i++){
            if(map.find(num[i])!=map.end()){
                if(i-map[num[i]]<=k) return true;
                else map[num[i]]=i;
            }
            else{
                map[num[i]]=i;
            }
        }
        return false;
    }
};