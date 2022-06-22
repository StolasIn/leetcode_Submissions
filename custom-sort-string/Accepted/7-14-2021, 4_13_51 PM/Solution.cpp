// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string str) {
        unordered_set<char> c;
        int m=str.size();
        string ans;
        int arr[128];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<m;i++){
            arr[str[i]]++;
            c.insert(str[i]);
        }
        for(int i=0;i<order.size();i++){
            c.erase(order[i]);
            for(int j=0;j<arr[order[i]];j++){
                ans+=order[i];
            }
        }
        for(auto i : c){
            for(int j=0;j<arr[i];j++){
                ans+=i;
            }
        }
        return ans;
    }
};