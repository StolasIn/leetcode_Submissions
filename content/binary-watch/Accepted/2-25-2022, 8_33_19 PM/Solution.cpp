// https://leetcode.com/problems/binary-watch

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string> vec;
        
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<=59;j++)
            {
                if(__builtin_popcount(i) + __builtin_popcount(j) == turnedOn)
                {  string str;
                  str=to_string(i) + ':';
                 
                 
                 if(j<10)  str+='0';
                 
                 str+= to_string(j);
                 vec.push_back(str);
                        
                }
            }
        }
        
        
        return vec;
    }
};