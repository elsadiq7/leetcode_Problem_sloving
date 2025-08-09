class Solution {
public:
    int mySqrt(int x) {
        long long  i=0;
        for( i=0;i*i<=x;i++)
        {
              continue;
        }
        return i-1;
        
    }
};