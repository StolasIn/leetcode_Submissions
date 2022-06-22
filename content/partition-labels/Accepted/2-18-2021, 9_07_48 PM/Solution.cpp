// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> map(128,vector<int>(2,-1));
        vector<int> uni;
        int m=s.size();
        bool flag=0;
        for(int i=0;i<m;i++){
            if(map[s[i]][0]==-1){
                map[s[i]][0]=i;
                map[s[i]][1]=i;
            }
            else{
                map[s[i]][1]=i;
            }
        }
        for(int i=0;i<m;i++){
            if(uni.empty()){
                uni.emplace_back(map[s[i]][1]);
            }
            else{
                flag=0;
                for(int j=0;j<uni.size();j++){
                    if(map[s[i]][0]<=uni[j]){
                        uni[j]=max(uni[j],map[s[i]][1]);
                        flag=1;
                    }
                }
                if(flag==false){
                    uni.emplace_back(map[s[i]][1]);
                }
            }
        }
        int y=uni.size();
        for(int i=y-1;i>0;i--) uni[i]-=uni[i-1];
        uni[0]++;
        return uni;
    }
};