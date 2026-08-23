class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int qDiff = 0;

        for (int i = 0; i < n; i++) {

            if (num[i] == '?') {
                if (i < half)
                    qDiff--;   // left ?
                else
                    qDiff++;   // right ?
            }
            else {
                int digit = num[i] - '0';

                if (i < half)
                    diff += digit;
                else
                    diff -= digit;
            }
        }

        
        if (abs(qDiff) % 2 == 1)
            return true;

        
        return diff != 9 * qDiff / 2;
    }
};