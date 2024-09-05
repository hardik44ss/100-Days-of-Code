// Solving number of way to climb stairs without TLE 
// --- By recursion it gives TLE 
// --- use Extra space to solve the problem


class Solution {
    public int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        int[] res =  new int[n+1];
        res[0]=res[1]=1;
        for(int i =2 ; i<=n ;i++ ){
            res[i]=res[i-1]+res[i-2];
        }
        return res[n];
    }
}