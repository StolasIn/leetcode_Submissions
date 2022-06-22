// https://leetcode.com/problems/shortest-completing-word

bool cmp(string s1,string s2){
    return s1.size()<s2.size();
}
class Solution {
public:
    bool check(unordered_map<char,int>& map,string& str){
        int cnt=map.size();
        for(int i=0;i<str.size();i++){
            map[str[i]]--;
            if(map[str[i]]==0) cnt--;
        }
        return cnt==0? true : false;
    }
    string shortestCompletingWord(string plate, vector<string>& words) {
        std::stable_sort(words.begin(),words.end(),cmp);
        unordered_map<char,int> map;
        for(int i=0;i<plate.size();i++){
            if(isalpha(plate[i])) map[tolower(plate[i])]++;
        }
        unordered_map<char,int> copy(map.begin(),map.end());
        for(int i=0;i<words.size();i++){
            if(check(map,words[i])){
                return words[i];
            }
            else{
                map=copy;
            }
        }
        return "";
    }
};