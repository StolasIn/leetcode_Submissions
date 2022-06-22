// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        deque<char> str;
        int lena=a.size()-1;
        int lenb=b.size()-1;
        char carry='0';
        string ans="";
        while(lena>=0 && lenb>=0){
            if(a[lena]+b[lenb]+carry==147){
                str.push_front('1');
                carry='1';
            }
            else if(a[lena]+b[lenb]+carry==146){
                str.push_front('0');
                carry='1';
            }
            else if(a[lena]+b[lenb]+carry==145){
                str.push_front('1');
                carry='0';
            }
            else{
                str.push_front('0');
                carry='0';
            }
            lena--;
            lenb--;
        }
        
        if(lena>=0){
            while(lena>=0){
                if(a[lena]+carry==98){
                    str.push_front('0');
                    carry='1';
                }
                else if(a[lena]+carry==97){
                    str.push_front('1');
                    carry='0';
                }
                else{
                    str.push_front('0');
                    carry='0';
                }
                lena--;
            }
        }
        if(lenb>=0){
            while(lenb>=0){
                if(b[lenb]+carry==98){
                    str.push_front('0');
                    carry='1';
                }
                else if(b[lenb]+carry==97){
                    str.push_front('1');
                    carry='0';
                }
                else{
                    str.push_front('0');
                    carry='0';
                }
                lenb--;
            }
        }
        if(carry=='1') str.push_front('1');
        for(int i=0;i<str.size();i++){
            ans+=str[i];
        }
        return ans;
    }
};