pair<ll, VI> kruskal(int n, int m) {
	init_fu(n);
	sort(ALL(es));
	ll cost = 0;
	VI res;
	for(auto e : es) {
		int tu = fu_find(e.u);
		int tv = fu_find(e.v);
		if(tu != tv) {
			if(tv == e.v){
				T[e.v] = tu;
				res.pb(e.i);
				cost += e.c;
			}
		}
	}
	return {cost, res};
}

