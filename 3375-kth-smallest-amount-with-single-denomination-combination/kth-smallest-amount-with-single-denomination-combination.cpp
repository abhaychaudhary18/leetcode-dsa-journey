class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto lcm = [] (long long a, long long b){
            return a/gcd(a,b) *b;
        };
        auto count =[&](long long x){
            long long total =0;
            for(int mask =1;mask<(1<<n);mask++){
                long long L=1;
                int bits =0;
                for(int i=0;i<n;i++){
                    if(mask & (1<<i)){
                        bits++;
                        L=lcm(L,coins[i]);
                        if(L>x)
                        break;
                    }
                }
                if(L>x)
                continue;
                long long ways = x/L;
                if(bits %2==1)
                total += ways;
                else
                total -= ways;
            }
            return total;
        };
        long long low =1;
        long long high = 1LL*k*(*min_element(coins.begin(),coins.end()));
        while(low<high){
            long long mid = low+(high-low)/2;
            if(count(mid)>=k)
            high = mid;
            else
            low = mid+1;
        }
        return low;
        
    }
};