
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        // STEP 1: Get the dimensions of the matrix
        int n = mat.size();       // Number of rows
        int m = mat[0].size();    // Number of columns

        // STEP 2: Create a queue for Multi-Source BFS
        // Each queue element stores:
        // {{row, col}, steps}
        // steps = distance from the nearest zero

        queue<pair<pair<int, int>, int>> q;

        // STEP 3: Create a visited matrix
        // Initially, no cell has been visited.
        // We use it to avoid visiting the same cell multiple times.
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // STEP 4: Create a distance matrix
        // dis[i][j] stores the shortest distance
        // of cell (i,j) from its nearest zero.
        vector<vector<int>> dis(n, vector<int>(m, 0));

        // STEP 5: Insert ALL zero cells into the queue.
        // Why all zeros?
        // Because every zero is a possible starting point.
        // We want to find the nearest zero for every cell.
        // This technique is called Multi-Source BFS.

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {

                    // Initially, distance of every zero is 0.
                    q.push({{i, j}, 0});

                    // Mark zero cells as visited.
                    // This prevents them from being inserted again.
                    vis[i][j] = 1;
                }
            }
        }

        // STEP 6: Define the four possible directions.
        // We can move UP, RIGHT, DOWN and LEFT.
        // We cannot move diagonally.

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        // STEP 7: Start BFS traversal.
        // BFS processes cells level by level.
        // Therefore, the first time we visit a cell,
        // we have found its shortest distance from a zero.

        while (!q.empty()) {

            // Get the front element from the queue.
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            // Remove the current cell from the queue.
            q.pop();

            // Store the shortest distance of this cell.
            dis[row][col] = steps;

            // STEP 8: Explore all four neighbouring cells.
            for (int i = 0; i < 4; i++) {

                // Calculate the coordinates of the neighbour.
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // STEP 9: Check three conditions:
                // 1. Neighbour must be inside the matrix.
                // 2. Neighbour must not have been visited.
                // If both conditions are satisfied, process it.

                if (nrow >= 0 && ncol >= 0 &&
                    nrow < n && ncol < m &&
                    vis[nrow][ncol] == 0) {

                    // Mark visited immediately when pushing.
                    // This prevents duplicate insertion into the queue.
                    vis[nrow][ncol] = 1;

                    // Distance of neighbour = current distance + 1.
                    // Every movement to an adjacent cell costs 1.
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        // STEP 10: Return the final distance matrix.
        return dis;
    }
};
