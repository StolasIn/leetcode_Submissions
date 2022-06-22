// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        for(auto i : arr){
            if(i>0){
                if(map[i]>=1){
                    if(map.find(2*i)==map.end()){
                        return false;
                    }
                    else{
                        if(map[2*i]<map[i]){
                            return false;
                        }
                        else{
                            map[2*i]-=map[i];
                        }
                    }
                }
            }
            else{
                if(i%2!=0) return false;
                if(map[i]>=1){
                    if(map.find(i/2)==map.end()){
                        return false;
                    }
                    else{
                        if(map[i/2]<map[i]){
                            return false;
                        }
                        else{
                            map[i/2]-=map[i];
                        }
                    }
                }
            }
        }
        return true;
    }
};