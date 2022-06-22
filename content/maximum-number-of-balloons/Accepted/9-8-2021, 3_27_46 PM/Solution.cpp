// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[128];
        int mi=INT_MAX;
        unordered_map<char,int> map;
        string str = "balloon";
        memset(arr,0,sizeof(arr));
        for(auto i : str){
            map[i]++;
        }
        for(auto& i : text){
            arr[i]++;
        }
        for(auto& i : map){
            mi=min(mi,arr[i.first]/i.second);
        }
        return mi;
    }
};