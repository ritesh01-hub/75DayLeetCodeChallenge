class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();


        vector<int> suff(n+1, 0);
        for(int i = n-1;i>=0;i--){
            suff[i] = suff[i+1]+piles[i];
        } 
        vector<vector<int>> dp(n+1, vector<int>(n+1 , 0));

        for(int i = n-1;i>=0;i--){

            for(int  M  = n;M>=1;M--){

                if(2*M >= n-i){
                    dp[i][M] = suff[i];
                    continue;
                }
                int best =  0;
                for (int x = 1; x <= 2 * M; x++) {
                    int opponent = dp[i + x][max(M, x)];

                    int current = suff[i] - opponent;

                    best = max(best, current);
                }
                    dp[i][M] = best;

            }
        }
        return dp[0][1];
    }
};