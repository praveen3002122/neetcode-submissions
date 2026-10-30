class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        stack<pair<int,int>>st;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int mx =0;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    int cnt =0;
                    st.push({i,j});
                    vis[i][j]=1;

                    while(!st.empty()){
                        cnt++;
                        int x = st.top().first;
                        int y = st.top().second;
                        st.pop();

                        for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && vis[nx][ny]==0) {
                            vis[nx][ny]=1;
                            st.push({nx, ny});
                        }
                    }
                }
                mx = max(mx,cnt);

                }
            }
        }
        return mx;
    }
};
