
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // {maximum elevation, row, column}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {

            auto [time, r, c] = pq.top();
            pq.pop();

            if(r == m-1 && c == n-1) {
                return time;
            }

            if(time > dist[r][c]) continue;

            for(int k = 0; k < 4; k++) {

                int nRow = r + delRow[k];
                int nCol = c + delCol[k];

                if(nRow >= 0 && nRow < m &&
                   nCol >= 0 && nCol < n) {

                    int newTime = max(time, grid[nRow][nCol]);

                    if(newTime < dist[nRow][nCol]) {

                        dist[nRow][nCol] = newTime;

                        pq.push({newTime, nRow, nCol});
                    }
                }
            }
        }

        return -1;
    }
};
