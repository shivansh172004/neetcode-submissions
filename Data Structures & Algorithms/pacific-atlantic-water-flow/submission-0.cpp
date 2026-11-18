
class Solution {
private:
    void bfs(vector<vector<int>>& heights,
             vector<vector<int>>& vis,
             queue<pair<int,int>>& q) {

        int m = heights.size();
        int n = heights[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nRow = r + delRow[k];
                int nCol = c + delCol[k];

                if(nRow >= 0 && nRow < m &&
                   nCol >= 0 && nCol < n &&
                   !vis[nRow][nCol] &&
                   heights[nRow][nCol] >= heights[r][c]) {

                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        queue<pair<int,int>> q1, q2;

        // Pacific: First row and first column
        for(int i = 0; i < m; i++) {
            pacific[i][0] = 1;
            q1.push({i, 0});
        }

        for(int j = 0; j < n; j++) {
            if(!pacific[0][j]) {
                pacific[0][j] = 1;
                q1.push({0, j});
            }
        }

        // Atlantic: Last row and last column
        for(int i = 0; i < m; i++) {
            atlantic[i][n-1] = 1;
            q2.push({i, n-1});
        }

        for(int j = 0; j < n; j++) {
            if(!atlantic[m-1][j]) {
                atlantic[m-1][j] = 1;
                q2.push({m-1, j});
            }
        }

        // Run both BFS traversals
        bfs(heights, pacific, q1);
        bfs(heights, atlantic, q2);

        // Find common cells
        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
