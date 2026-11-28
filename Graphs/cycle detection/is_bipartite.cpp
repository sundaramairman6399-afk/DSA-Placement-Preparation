
class Solution {
public:

    // DFS function to check whether the graph can be
    // coloured using two different colours.
    bool dfs(int node, int col, vector<int>& color,
             vector<vector<int>>& graph) {

        // Assign the current node the given colour.
        color[node] = col;

        // Visit all neighbours of the current node.
        for (auto it : graph[node]) {

            // Case 1: Neighbour is not coloured yet.
            if (color[it] == -1) {

                // Assign the neighbour the opposite colour
                // and recursively check its neighbours.
                if (dfs(it, !col, color, graph) == false) {
                    return false;
                }
            }

            // Case 2: Neighbour is already coloured.
            // If both connected nodes have the same colour,
            // the graph is NOT bipartite.
            else if (color[it] == col) {
                return false;
            }
        }

        // No colour conflict found.
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // -1 means uncoloured.
        // 0 and 1 represent the two different colours.
        vector<int> color(n, -1);

        // Check every node because the graph may be disconnected.
        for (int i = 0; i < n; i++) {

            // If this node is not coloured, start a new DFS.
            if (color[i] == -1) {

                // Start with colour 0.
                if (dfs(i, 0, color, graph) == false) {
                    return false;
                }
            }
        }

        // Every component was successfully coloured.
        return true;
    }
};
