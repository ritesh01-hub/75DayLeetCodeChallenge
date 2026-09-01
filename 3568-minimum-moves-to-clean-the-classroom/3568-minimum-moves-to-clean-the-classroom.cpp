class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int litterCount = 0;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        
        vector<vector<int>> id(m, vector<int>(n, -1));

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int totalMasks = 1 << litterCount;
        int fullMask = totalMasks - 1;

        vector<vector<vector<short>>> maxEnergy(
            m,
            vector<vector<short>>(
                n,
                vector<short>(totalMasks, -1)
            )
        );

        struct State {
            int r;
            int c;
            int mask;
            int e;
        };

        queue<State> q;

        maxEnergy[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {
                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int e = cur.e;

                if (mask == fullMask)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                   
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                   
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                   
                    if (ne <= maxEnergy[nr][nc][nmask])
                        continue;

                    maxEnergy[nr][nc][nmask] = ne;

                    q.push({
                        nr,
                        nc,
                        nmask,
                        ne
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};