
class Solution {
private:

    // DFS function to visit all connected land cells
    void dfs(vector<vector<char>>& grid,
             vector<vector<char>>& vis,
             int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        // Mark the current cell as visited
        vis[i][j] = 1;

        // Arrays to represent 4 directions:
        // Up, Left, Down, Right
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        // Explore all 4 neighbouring cells
        for(int k = 0; k < 4; k++) {

            // Calculate the neighbouring cell coordinates
            int row = i + delrow[k];
            int col = j + delcol[k];

            // Check whether the neighbour is inside the grid,
            // contains land ('1'), and has not been visited
            if(row >= 0 && col >= 0 &&
               row < n && col < m &&
               grid[row][col] == '1' &&
               vis[row][col] == 0) {

                // Recursively explore the neighbouring land cell
                dfs(grid, vis, row, col);
            }
        }
    }

public:

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Create a visited matrix initialized with 0
        // 0 = Not visited, 1 = Visited
        vector<vector<char>> vis(n, vector<char>(m, 0));

        // Stores the total number of islands
        int cnt = 0;

        // Traverse every cell of the grid
        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {

                // If we find unvisited land, we found a new island
                if(grid[row][col] == '1' && vis[row][col] == 0) {

                    // Increase island count only once per island
                    cnt++;

                    // Explore the entire connected island
                    dfs(grid, vis, row, col);
                }
            }
        }

        // Return the total number of islands
        return cnt;
    }
};
