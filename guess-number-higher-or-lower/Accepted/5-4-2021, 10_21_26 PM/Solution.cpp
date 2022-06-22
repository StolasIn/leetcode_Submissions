// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int tmp;
        int g;
        int l=1,r=n;
        while(r>=l){
            g=(r-l)/2+l;
            tmp=guess(g);
            if(tmp==-1){
                r=g-1;
            }
            else if(tmp==0){
                return g;
            }
            else{
                l=g+1;
            }
        }
        return 0;
    }
};