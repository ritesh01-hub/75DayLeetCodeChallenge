class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countAmounts(long long x, vector<int>& coins) {

        int n = coins.size();
        long long ans = 0;

        // Enumerate every subset
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    L = lcm(L, coins[i]);

                    // L is already greater than x
                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long cnt = x / L;

            // Odd number of elements -> add
            if (bits % 2 == 1)
                ans += cnt;

            // Even number -> subtract
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {

        long long low = 1;

        long long minCoin = *min_element(coins.begin(), coins.end());

        long long high = minCoin * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};