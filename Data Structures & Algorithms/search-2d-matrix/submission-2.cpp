// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int start = 0;
//         int end = m+n-1;
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(matrix[i][j] == target)
//                 return true;
                
//             }
//         }
//         // queue<pair<pair<int, int>, bool>>q;
//         // q.push({{0,0}, false});
//         // while(!q.empty()){
//         //     int r = q.front().first.first;
//         //     int c = q.front().first.second;
//         //     bool x = q.front().second;
//         //     q.pop();
//         //    int delRow[] = {-1, 0, 1, 0};
//         // int delCol[] = {0, 1, 0, -1};
//         //     for(int i=0; i<4; i++){
//         //         int nRow = r + delRow[i];
//         //         int nCol = c + delCol[i];
//         //         if(nRow<=0 && nRow>m && nCol<=0 && nCol>n ){
//         //             q.push({{nRow, nCol}, true});
//         //         }
//         // }
    
//     return false;
//     }
// };


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m * n - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) {
                return true;
            }

            else if(matrix[row][col] < target) {
                l = mid + 1;
            }

            else {
                r = mid - 1;
            }
        }

        return false;
    }
};

