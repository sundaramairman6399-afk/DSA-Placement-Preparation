
// 4. Important difference between DFS and BFS
// DFS	                     BFS
// Goes deep first	   Explores level by level
// Uses recursion/stack	    Uses queue
// Does not guarantee shortest distance	  Finds shortest distance in an unweighted graph
// Not suitable for this time simulation	Suitable for Rotting Oranges

// Remember this DSA pattern:

// Whenever a problem says:
// - Spread simultaneously.
// - Minimum time to reach.
// - Minimum distance from multiple starting points.
// - Infection spreading level by level.
// Think about Multi-Source BFS.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Queue stores coordinates of rotten oranges.
        queue<pair<int,int>> q;

        // Count the total number of fresh oranges.
        int fresh = 0;

        // Insert ALL initially rotten oranges into queue.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i,j});
                }

                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Four possible directions.
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int minutes = 0;

        // BFS traversal.
        while(!q.empty() && fresh > 0) {

            // Number of oranges at the current level.
            int size = q.size();

            // Process all oranges that were rotten
            // at the beginning of this minute.
            for(int i = 0; i < size; i++) {

                auto [row, col] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {

                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];

                    // Check boundaries and fresh orange.
                    if(newRow >= 0 && newRow < n &&
                       newCol >= 0 && newCol < m &&
                       grid[newRow][newCol] == 1) {

                        // Make the fresh orange rotten.
                        grid[newRow][newCol] = 2;

                        // Decrease fresh orange count.
                        fresh--;

                        // Add newly rotten orange to queue.
                        q.push({newRow, newCol});
                    }
                }
            }

            // One complete BFS level = one minute.
            minutes++;
        }

        // If fresh oranges remain, they cannot rot.
        if(fresh > 0) {
            return -1;
        }

        return minutes;
    }
};
