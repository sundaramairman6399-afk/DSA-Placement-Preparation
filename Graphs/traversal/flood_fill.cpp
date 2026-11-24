
class Solution {
private:

    // DFS function:
    // i, j       = current pixel coordinates
    // color      = new colour to apply
    // initialColor = original colour of the starting pixel

    void dfs(vector<vector<int>>& image,
             vector<vector<int>>& vis,
             int i, int j,
             int color, int initialColor) {

        int n = image.size();
        int m = image[0].size();

        // Mark the current pixel as visited.
        // This prevents DFS from visiting it again.
        vis[i][j] = 1;

        // Change the current pixel to the new colour.
        image[i][j] = color;

        // These arrays represent 4 possible directions:
        // k = 0 -> UP
        // k = 1 -> DOWN
        // k = 2 -> LEFT
        // k = 3 -> RIGHT

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        // Explore all 4 neighbours of the current pixel.
        for(int k = 0; k < 4; k++) {

            int row = i + delrow[k];
            int col = j + delcol[k];

            // Check 1: row and column must be inside the image.
            // Check 2: the neighbour must not be visited.
            // Check 3: the neighbour must have the ORIGINAL colour.

            if(row >= 0 && col >= 0 &&
               row < n && col < m &&
               vis[row][col] == 0 &&
               image[row][col] == initialColor) {

                // Recursively visit the valid neighbour.
                // DFS will change this pixel and explore its neighbours.
                dfs(image, vis, row, col, color, initialColor);
            }
        }
    }

public:

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr, int sc, int color) {

        // Get the number of rows and columns.
        int n = image.size();
        int m = image[0].size();

        // STEP 1: Store the original colour of the starting pixel.
        // We need this to identify which pixels belong to
        // the same connected region.
        int initialColor = image[sr][sc];

        // STEP 2: If the original colour and new colour are equal,
        // no modification is required.
        // This also avoids unnecessary DFS traversal.
        if(initialColor == color) {
            return image;
        }

        // STEP 3: Create a visited matrix.
        // Initially, no pixel has been visited.
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // STEP 4: Start DFS from the given starting pixel.
        // DFS will visit only connected neighbours having
        // the same original colour.
        dfs(image, vis, sr, sc, color, initialColor);

        // STEP 5: Return the modified image.
        return image;
    }
};
