// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool cmp(string str,string str1,int arr[]){
        int m=min(str.size(),str1.size());
        for(int i=0;i<m;i++){
            if(arr[str[i]]>arr[str1[i]]){
                return false;
            }
        }
        if(str.size()>str1.size()) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int arr[129];
        int c=0;
        for(int i=0;i<order.size();i++){
            arr[order[i]]=c++;
        }
        for(int i=1;i<words.size();i++){
            if(cmp(words[i-1],words[i],arr)){
                return false;
            }
        }
        return true;
    }
};