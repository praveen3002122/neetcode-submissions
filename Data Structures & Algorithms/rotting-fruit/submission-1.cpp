class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int cnt = 0;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int freshcount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshcount++;
                }
            }
        }

        if (freshcount == 0) return 0;

        while (!q.empty()) {
            int size = q.size();
            bool rottedAny = false; 

            for (int k = 0; k < size; k++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        freshcount--;
                        rottedAny = true;
                    }
                }
            }
            
            if (rottedAny) {
                cnt++;
            }
        }

        if (freshcount > 0) return -1;
        else return cnt;
    }
};