/*
* G - graph given as list of neighbours
* C - capacity (matrix)
*/
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<vector<int> > VVI;
vector<PII > ek_bfs(VVI & G, VVI & capacity, VVI & flow, int n, int source, int sink) {
	vector<PII > p(n);
	vector<int> visited(n);
	loop(i,0,n){ 
		visited[i] = false;
		p[i] = {-1, -1};
	}
	queue<int> Q;
	Q.push(source);
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		loop(i,0,G[v].size()) {
			if(!visited[G[v][i]]){
				if(capacity[v][G[v][i]] - flow[v][G[v][i]] > 0) {
					visited[G[v][i]] = true;
					p[G[v][i]] = {v, capacity[v][G[v][i]] - flow[v][G[v][i]]};
					Q.push(G[v][i]);
				} else if(flow[G[v][i]][v] > 0) {
					visited[G[v][i]] = true;
					p[G[v][i]] = {v, flow[G[v][i]][v]};
					Q.push(G[v][i]);
				}
			}
		}
	}
	vector<PII> path;
	path.pb({sink, 0});
	PII v = p[sink];
	while(v.ff != -1){
		path.pb(v);
		v = p[v.ff];
	}
	reverse(ALL(path));
	return path;
}

int find_min(vector<PII > path) {
	int mini = INFTY;
	loop(i,0,path.size()-1) {
		mini = min(mini, path[i].ss);
	}
	return mini;
} 


VVI edmonds_karp(VVI & G, VVI & capacity, int n, int source, int sink) {
	VVI flow(n, VI(n));
	loop(i,0,n) {
		loop(j,0,n) {
			flow[i][j] = 0;
		}
	}
	vector<PII> path;
	while((path = ek_bfs(G,capacity,flow,n, source,sink)).size() > 1) {
		int mini = find_min(path);
		loop(i,0,path.size() - 1) {
			int v = path[i].ff;
			int u = path[i+1].ff;
			flow[v][u] += mini;
		}
	}
	return flow;
}
