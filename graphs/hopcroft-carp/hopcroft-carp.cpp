/*
*G - bipartite graph where first n nodes is from first part and next m from the second
*/
typedef vector<int> VI;
typedef vector<vector<int> > VVI;

void extend_path(VI & match, VI & p, int v) {
	while(v != -1) {
		match[v] = p[v];
		match[p[v]] = v;
		v = p[p[v]];
	}
}

bool extend_matching(VVI & G, VI & match, int n, int m){
	queue<int> Q;
	vector<bool> visited(n+m);
	VI p(n+m);
	for(int i = 0; i<n; i++) {
		if(match[i] == -1) {
			Q.push(i);
			p[i] = -1;
			visited[i] = false;
		}
	}
	bool extended = false;
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		if(v < n) {
			for(int i = 0; i < G[v].size(); i++){
				if(!visited[G[v][i]]){
					visited[G[v][i]] = true;
					p[G[v][i]] = v;
					Q.push(G[v][i]);
				}
			}
		} else {
			if(match[v] != -1) {
				p[match[v]] = v;
				visited[match[v]] = true;
				Q.push(match[v]);
			} else {
				extend_path(match, p, v);
				extended = true;
				break;
			}
		}
	}
	return extended;
}

VI hopcroft_karp(VVI & G, int n, int m) {
	VI match(n+m);
	for(int i = 0; i<n+m; i++) match[i] = -1;
	
	while(extend_matching(G,match,n,m));
	
	return match;	
}

//-------------------
