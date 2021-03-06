// https://leetcode.com/problems/count-integers-with-even-digit-sum

class Solution {
public:

    bool IsEven(int s)
    {
        int d=0;
        while(s!=0)
        {
            int rev=s%10;
            d=d+rev;
            s=s/10;
        }
        if(d%2==0)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int countEven(int num) {
        int count=0;
        for(int i=1;i<=num;i++)
        {
            if(IsEven(i))
            {
               // cout<<i<<" ";
                count++;
            }
        }
        return count;
    }
};