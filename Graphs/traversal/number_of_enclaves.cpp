
class Solution {
private:

    // DFS function to visit all land cells
    // connected to the starting boundary cell
    void dfs(int row, int col,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        // Mark current cell as visited
        vis[row][col] = 1;

        // 4 possible directions:
        // Up, Right, Down, Left
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Explore all 4 neighbours
        for(int k = 0; k < 4; k++) {

            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            // Check if neighbour is inside the grid
            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m) {

                // Check if neighbour is land
                // and has not been visited yet
                if(grid[nrow][ncol] == 1 &&
                   vis[nrow][ncol] == 0) {

                    // Recursively visit the neighbour
                    dfs(nrow, ncol, grid, vis);
                }
            }
        }
    }

public:

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Initially all cells are unvisited
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // STEP 1: Traverse first and last columns
        for(int row = 0; row < n; row++) {

            // First column
            if(grid[row][0] == 1 && vis[row][0] == 0) {
                dfs(row, 0, grid, vis);
            }

            // Last column
            if(grid[row][m-1] == 1 && vis[row][m-1] == 0) {
                dfs(row, m-1, grid, vis);
            }
        }

        // STEP 2: Traverse first and last rows
        for(int col = 0; col < m; col++) {

            // First row
            if(grid[0][col] == 1 && vis[0][col] == 0) {
                dfs(0, col, grid, vis);
            }

            // Last row
            if(grid[n-1][col] == 1 && vis[n-1][col] == 0) {
                dfs(n-1, col, grid, vis);
            }
        }

        // STEP 3: Count remaining unvisited land cells
        int count = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                // Land that cannot reach the boundary
                if(grid[row][col] == 1 && vis[row][col] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
