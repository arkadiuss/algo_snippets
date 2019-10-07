vector<ll> dijkstra(int v){
	ll * d=new ll[n];
	loop(i,0,n) d[i]=INFTY;
	d[v]=0;
	priority_queue<Ver> Q;
	Q.push(Ver(v,0));
	while(!Q.empty()){
		int w = Q.top().v;
		Q.pop();
		loop(i,0,SIZE(G[w])){
			if(d[w]+G[w][i].d<d[G[w][i].v]){
				d[G[w][i].v]=d[w]+G[w][i].d;
				Q.push(Ver(G[w][i].v,d[G[w][i].v]));
			}
		}
	}
	vector<ll> res(d,d+n);
	delete [] d;
	return res;
}
