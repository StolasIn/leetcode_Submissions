// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& w) {
        if(w.size()<=1){
            return true;
        }
        vector<int> arr(26,0);
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w[i].size();j++){
                arr[w[i][j]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0 && arr[i]%w.size()!=0){
                return false;
            }
        }
        return true;
    }
};