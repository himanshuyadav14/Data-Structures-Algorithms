// vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
 
//     vector<int> d(n + 1, 1e8);
//     // Distance of source to source is 0.
//     d[src] = 0;

//     // Apply bellmonford algorithm.
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int u = edges[j][0];
//             int v = edges[j][1];
//             int w = edges[j][2];

//             if (d[u] != 1e9 && d[v] > (d[u] + w)) {
//                 d[v] = d[u] + w;
//             }
//         }
//     }

//     // Return the distance of destination.
//     return d;
    
// }