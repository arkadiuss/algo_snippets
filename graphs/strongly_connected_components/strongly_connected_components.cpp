VVI G(MAX);
VVI GT(MAX);
VVI SCC(MAX);
 
int order[MAX];
bool visited[MAX];
 
void dfs1(int v){
	visited[v] = 1;
	static int ord_i = 0;
	loop(i,0,G[v].size()) {
		if(!visited[G[v][i]]) {
			dfs1(G[v][i]);
		}
	}
	order[ord_i++] = v;
}
int cc_i = 0;
void dfs2(int v){
	visited[v] = 1; 
	SCC[cc_i].pb(v);
	loop(i,0,GT[v].size()) {
		if(!visited[GT[v][i]]) {
			dfs2(GT[v][i]);
		}
	}
}

loop(i,0,n){
	if(!visited[i]) dfs1(i);
}
reverse(order, order+n);
loop(i,0,n) visited[i] = false;
loop(i,0,n){
	if(!visited[order[i]]){
		dfs2(order[i]);
		cc_i++;
	}
	
}
