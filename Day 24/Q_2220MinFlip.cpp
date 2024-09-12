class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0; 
        int xoor = start ^ goal;

        while(xoor!=0){
            ans += xoor & 1;
            // Right-shift to check the next bit
            xoor >>=1;
        }
        return ans;
    }
};