// int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
//     vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));

//     // Distance from a node to itself is always 0
//     for (int i = 1; i <= n; i++) {
//         dist[i][i] = 0;
//     }

//     // Fill the distance matrix with the given edge weights
//     for (int i = 0; i < m; i++) {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         int w = edges[i][2];
//         dist[u][v] = w;
//     }

//     // Floyd-Warshall Algorithm
//     for (int via = 1; via <= n; via++) {
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 if (dist[i][via] != 1e9 && dist[via][j] != 1e9) {
//                     dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
//                 }
//             }
//         }
//     }

//     // If there is no path between src and dest, return 1e9 (infinity)
//     if (dist[src][dest] == 1e9) {
//         return 1e9;
//     }

//     return dist[src][dest];
// }