// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> map(26,vector<int>(2,-1));
        vector<int> uni;
        int m=s.size(),n;
        bool flag=0;
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
            flag=0;
            n=uni.size();
            for(int j=0;j<n;j++){
                if(map[s[i]-'a'][0]<=uni[j]){
                    uni[j]=max(uni[j],map[s[i]-'a'][1]);
                    flag=1;
                    break;
                }
            }
            if(flag==false){
                uni.emplace_back(map[s[i]-'a'][1]);
            }
        }
        int y=uni.size();
        for(int i=y-1;i>0;i--) uni[i]-=uni[i-1];
        uni[0]++;
        return uni;
    }
};