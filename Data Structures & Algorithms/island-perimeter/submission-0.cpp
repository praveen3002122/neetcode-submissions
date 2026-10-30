class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        long long len = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool found = false;
        
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < m && !found; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    found = true;
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0) {
                    len = len + 1;
                } 
                else if (grid[nx][ny] == 1 && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return len;
    }
};