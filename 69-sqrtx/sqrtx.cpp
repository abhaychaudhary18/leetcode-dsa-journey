// class Solution {
// public:
//     int mySqrt(int x) {
//         long long i=0;
//         while(i*i<=x){
//             i++;
//         }
//         return i-1;
        
//     }
// };

class Solution{
    public:
    int mySqrt(int x){
        int low =1;
        int high =x;
        long long mid;
        int ans=0;
        while(low<=high){
            mid = (high-low)/2+low;
            if(mid*mid<=x){
                ans = mid;
                low = mid + 1;
            }else {
                high = mid-1;
            }
        }
        return ans ;
    }
};