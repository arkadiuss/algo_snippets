int col[26];

vector<int> Q;
bool dfs(int v) {
	col[v] = 1;
	loop(i,0,G[v].size()) {
		if(col[G[v][i]] == 1) {
			return false;
		}
		if(col[G[v][i]] == 0){
			if(!dfs(G[v][i])) return false;
		}
	}
	Q.pb(v);
	col[v] = 2;
	return true;
}
