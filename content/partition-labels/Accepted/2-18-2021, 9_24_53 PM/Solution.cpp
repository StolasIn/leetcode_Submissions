// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> map(26,vector<int>(2,-1));
        vector<int> uni;
        int m=s.size(),n;
        for(int i=0;i<m;i++){
            if(map[s[i]-'a'][0]==-1){
                map[s[i]-'a'][0]=i;
                map[s[i]-'a'][1]=i;
            }
            else{
                map[s[i]-'a'][1]=i;
            }
        }
        uni.emplace_back(map[s[0]-'a'][1]);
        for(int i=0;i<m;i++){
            n=uni.size();
            if(map[s[i]-'a'][0]<=uni[n-1]){
                uni[n-1]=max(uni[n-1],map[s[i]-'a'][1]);
            }
            else{
                uni.emplace_back(map[s[i]-'a'][1]);
            }
        }
        int y=uni.size();
        for(int i=y-1;i>0;i--) uni[i]-=uni[i-1];
        uni[0]++;
        return uni;
    }
};