class TEdge { 
	public:
		int v;
		TEdge(int _v): v(_v) {};
};

class TNode {
	public:
		int i; // number of the node
		int color; // blue = 0, red = 1
		int subtree_size; // -1 not yet determined
		bool blocked;
		vector<TEdge> ngh; //neighbours
		TNode(int _i, int _c): i(_i), color(_c), subtree_size(-1) {};
};

class CTNode {
	public:
		int i;
		int p; // parent
		vector<int> chl; // children
		CTNode(int _i, int _p): i(_i), p(_p) {}; 
};

int n;
vector<TNode> tree;

int count_subtrees_size(vector<TNode> &T, int i, int l){
	int sum = 0;
	for(TEdge e: T[i].ngh) {
		if(!T[e.v].blocked && e.v != l) {
			sum += count_subtrees_size(T, e.v, i);
		}
	}
	sum++;
	T[i].subtree_size = sum;
	return sum;
}

int check_centroid_condition(vector<TNode> &T, vector<CTNode> &CT, int i) {
	for(TEdge e: T[i].ngh) {
		if(!T[e.v].blocked && T[e.v].subtree_size > T[i].subtree_size/2){
			return e.v;
		}
	}
	return -1;
}

int find_centroid(vector<TNode> &T, vector<CTNode> &CT, int i){
	count_subtrees_size(T, i, -1);
	int prev = i;
	int nxt;
	while((nxt = check_centroid_condition(T, CT, prev)) != -1) {
		T[prev].subtree_size -= T[nxt].subtree_size;
		T[nxt].subtree_size += T[prev].subtree_size;
		prev = nxt;
	}
	return prev;
}

int decompose_subtree(vector<TNode> &T, vector<CTNode> &CT, int i){
	int centroid = find_centroid(T, CT, i);
	pln(centroid);
	T[centroid].blocked = true;
	for(TEdge e: T[centroid].ngh) {
		if(!T[e.v].blocked) {
			int nxt_centroid = decompose_subtree(T, CT, e.v);
			CT[nxt_centroid].p = centroid;
			CT[centroid].chl.pb(nxt_centroid);
		}
	}
	return centroid;
}

vector<CTNode> decompose(vector<TNode> &T) {
	vector<CTNode> CT;
	loop(i,0,T.size()){
		CT.pb(CTNode(i, -1));
	}
	decompose_subtree(T, CT, 0);
	return CT;
}
