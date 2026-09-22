class Solution {
public:

    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b){

        long long ans = 1;

        while(b > 0){

            // If exponent is odd
            if(b % 2 == 1){

                ans = (ans * a) % MOD;
            }

            // Square the base
            a = (a * a) % MOD;

            // Divide exponent by 2
            b /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n){

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};