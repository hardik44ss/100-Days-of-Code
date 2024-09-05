class Solution {
    public boolean isPowerOfFour(int n) {
        // while(n>0){
        // if(n==1){
        // return true;
        // }
        // n=n>>2;
        // }
        // return false;
        if(n<=0){
        return false;
        }
        while(n%4 == 0){
        n/=4;
        }
        return n==1;
        // return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
    }
};