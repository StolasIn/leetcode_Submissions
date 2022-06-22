// https://leetcode.com/problems/count-items-matching-a-rule

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string key, string value) {
        int m=items.size();
        int cnt=0;
        int flag;
        if(key=="type"){
            flag=0;
        }
        else if(key=="color"){
            flag=1;
        }
        else if(key=="name"){
            flag=2;
        }
        for(int i=0;i<m;i++){
            if(items[i][flag]==value) cnt++;
        }
        return cnt;
    }
};