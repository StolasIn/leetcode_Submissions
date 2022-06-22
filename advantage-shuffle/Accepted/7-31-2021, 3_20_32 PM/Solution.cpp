// https://leetcode.com/problems/advantage-shuffle

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        vector<int> ans(nums1.size());
        vector<bool> vis(nums1.size(),false);
        int beg=0;
        for(int i=0;i<nums2.size();i++){
            int tmp = upper_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
            if(tmp==nums1.size()){
                while(vis[beg] && beg<nums1.size()){
                    beg++;
                }
                vis[beg]=true;
                ans[i]=nums1[beg++];
                continue;
            }
            if(vis[tmp]==true){
                while(vis[tmp] && tmp<nums1.size()){
                    tmp++;
                }
                if(tmp==nums1.size()){
                    while(vis[beg] && beg<nums1.size()){
                        beg++;
                    }
                    vis[beg]=true;
                    ans[i]=nums1[beg++];
                    continue;
                }
                else if(vis[tmp]==false){
                    ans[i]=nums1[tmp];
                    vis[tmp]=true;
                }
            }
            else{
                ans[i]=nums1[tmp];
                vis[tmp]=true;
            }
        }
        return ans;
    }
};