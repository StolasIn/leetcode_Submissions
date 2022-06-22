// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int n) {
        int mod;
        deque<char> de;
        while(n!=0){
            mod=n%26;
            if(mod!=0){
                de.emplace_front(mod+64);
                n-=mod;
            }
            else{
                de.emplace_front('Z');
                n-=25;
            }
            n/=26;
        }
        string str="";
        for(int i=0;i<de.size();i++){
            str+=de[i];
        }
        return str;
    }
};