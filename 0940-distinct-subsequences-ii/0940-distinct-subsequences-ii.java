class Solution {
    public int distinctSubseqII(String s) {
        long MOD = 1000000007;

        long[] dp = new long[26];
        long total = 0;

        for (char ch : s.toCharArray()) {

            int idx = ch - 'a';

            long newSubseq = (total + 1) % MOD;

            total = (total - dp[idx] + newSubseq + MOD) % MOD;

            dp[idx] = newSubseq;
        }

        return (int) total;
    }
}