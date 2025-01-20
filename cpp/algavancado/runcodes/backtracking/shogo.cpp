#include <bits/stdc++.h>
using namespace std;

bool visited[25][25];
vector<int> adj[25];
int max_path;

void solve(int u, int ct) {
    max_path = max(max_path, ct);
    for(int v : adj[u]) {
        if(!visited[u][v]) {
            visited[u][v] = true;
            visited[v][u] = true;
            
            solve(v, ct + 1);

            visited[u][v] = false;
            visited[v][u] = false;
        }
    }
}

int main() {
    int n, m;
    while (cin >> n) {
        if (!n) return 0;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        max_path = 0;
        for (int i = 0; i < n; i++) {
            memset(visited, false, sizeof(visited));
            solve(i, 0);
        }
        cout << max_path << endl;

        for (int i = 0; i < 25; i++) {
            adj[i].clear();
        }
    }
}