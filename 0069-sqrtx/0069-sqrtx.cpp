class Solution {
public:
    long long mySqrt(long long x) {
        if(x==1)return 1;
 for(long long i=0;i<x+1;i++)
 {
    if(i*i > x)return i-1;
 }


  return 0;
    }
};
