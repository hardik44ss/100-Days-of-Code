// 231. Power of Two
    bool isPowerOfTwo(int n,int i=0) {
            if(n<=0){
                return false;
            }
            if (n==1){
                return true;
            }
            if(n%2 !=0){
                return false;
            }
        return isPowerOfTwo(n/2);
    }
// 326. Power of Three
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n%3!=0){
            return false;
        }
        return isPowerOfThree(n/3);
    }
    