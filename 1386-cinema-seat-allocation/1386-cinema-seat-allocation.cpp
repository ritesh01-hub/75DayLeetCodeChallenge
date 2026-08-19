class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
         unordered_map<int, int> mp;
        
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            // Use bit (col - 1) for seat col
            mp[row] |= (1 << (col - 1));
        } // Every completely empty row can fit 2 families
        long long ans = 2LL * n;
        
        // Process only rows having reservations
        for (auto &[row, mask] : mp) {
            
            // We initially counted 2 families for this row.
            // Determine how many it can actually accommodate.
            
            bool left  = (mask & ((1 << 1) | (1 << 2) | (1 << 3) | (1 << 4))) == 0;
            bool right = (mask & ((1 << 5) | (1 << 6) | (1 << 7) | (1 << 8))) == 0;
            
            if (left && right) {
                // Both groups can sit
                continue;
            }
            
            // Remove the 2 we assumed for this row
            ans -= 2;
            
            // If either left or right block is available,
            // we can place one family.
            bool middle = (mask & ((1 << 3) | (1 << 4) | (1 << 5) | (1 << 6))) == 0;
            
            if (left || right || middle) {
                ans += 1;
            }
        }
        return int(ans);
    }
};