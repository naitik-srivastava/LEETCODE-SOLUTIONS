class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; // Handle 0 and 1 cases
        
        int left = 1, right = x;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // To avoid overflow, compare mid with x/mid instead of mid*mid with x
            if (mid <= x / mid) {
                left = mid + 1;
                result = mid; // This could be our answer
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};
