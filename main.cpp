vector < vector<int> > g; // graf
int n; // number of nodes
int s; // start node (node are numbered from zero everywhere)

// 
// read graf to g
//

//bfs
queue<int> q;
q.push (s);
vector<bool> used (n);
vector<int> d (n), p (n);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
	int v = q.front();
	q.pop();
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			used[to] = true;
			q.push (to);
			d[to] = d[v] + 1;
			p[to] = v;
		}
	}
}

// If now you need to restore and output the shortest path to some node, it can be done as follows:
if (!used[to])
	cout << "No path!";
else {
	vector<int> path;
	for (int v=to; v!=-1; v=p[v])
		path.push_back (v);
	reverse (path.begin(), path.end());
	cout << "Path: ";
	for (size_t i=0; i<path.size(); ++i)
		cout << path[i] + 1 << " ";
}