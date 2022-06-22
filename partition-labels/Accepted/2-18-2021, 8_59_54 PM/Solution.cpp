// https://leetcode.com/problems/partition-labels

class Solution {
public:
    struct node{
        int f,l;  
    };
    vector<int> partitionLabels(string s) {
        vector<vector<int>> map(128,vector<int>(2,-1));
        vector<node> uni;
        vector<int> ans;
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
                uni.emplace_back(node{map[s[i]][0],map[s[i]][1]});
            }
            else{
                flag=0;
                for(int j=0;j<uni.size();j++){
                    if(map[s[i]][0]>=uni[j].f && map[s[i]][0]<=uni[j].l){
                        uni[j].l=max(uni[j].l,map[s[i]][1]);
                        flag=1;
                    }
                }
                if(flag==false){
                    uni.emplace_back(node{map[s[i]][0],map[s[i]][1]});
                }
            }
        }
        ans.emplace_back(uni[0].l+1);
        for(int i=1;i<uni.size();i++){
            ans.emplace_back(uni[i].l-uni[i-1].l);
        }
        return ans;
    }
};