int T[MAX];
int R[MAX];

void init_fu(int n) {
	loop(i,0,n) {
		R[i] = 0;
		T[i] = i;
	}
}

int fu_find(int v) {
	if(T[v] == v) return v;
	T[v] = fu_find(T[v]);
	return T[v];
}

void fu_union(int u, int v) {
	int tu = fu_find(u);
	int tv = fu_find(v);
	if(R[tu] < R[tv]) {
		T[tu] = tv;
	} else {
		T[tv] = tu;
		if(R[tu] == R[tv]) {
			R[tu]++;
		}
	} 
}
