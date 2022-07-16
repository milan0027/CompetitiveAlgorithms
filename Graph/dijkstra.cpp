void dijkstra(int src, vi &d, vi &p, vvi &adj) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, src});
    while (!q.empty()) {
        auto u=q.top();
        q.pop();
        int v = u.se;
        if (u.fi > d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}