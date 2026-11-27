
class Solution {
private:

    // DFS to visit all connected 1s of an island
    void dfs(vector<vector<int>>& grid,
             vector<vector<int>>& vis,
             int row, int col,

             // Starting coordinates of the island
             int baseRow, int baseCol,

             // Stores relative coordinates of this island
             vector<pair<int,int>>& shape) {

        int n = grid.size();
        int m = grid[0].size();

        // Mark current cell as visited
        vis[row][col] = 1;

        // Calculate and store relative coordinates
        int r = row - baseRow;
        int c = col - baseCol;

        shape.push_back({r, c});

        // Up, Right, Down, Left
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check boundaries, land and visited status
            if(nrow >= 0 && ncol >= 0 &&
               nrow < n && ncol < m &&
               grid[nrow][ncol] == 1 &&
               vis[nrow][ncol] == 0) {

                dfs(grid, vis, nrow, ncol,
                    baseRow, baseCol, shape);
            }
        }
    }

public:

    int countDistinctIslands(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Stores unique island shapes
        set<vector<pair<int,int>>> s;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Found a new island
                if(grid[i][j] == 1 && vis[i][j] == 0) {

                    // Create a fresh vector for this island
                    vector<pair<int,int>> shape;

                    // (i,j) is both the starting point
                    // and the first DFS position
                    dfs(grid, vis, i, j, i, j, shape);

                    // Insert the complete island shape
                    // Duplicate shapes are automatically ignored
                    s.insert(shape);
                }
            }
        }

        // Number of unique island shapes
        return s.size();
    }
};
