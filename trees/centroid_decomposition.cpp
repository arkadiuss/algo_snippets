#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI; 
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
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

void printCT(vector<CTNode> &CT){
	loop(i,0,CT.size()){
		ps(i+1);ps(":");
		for(int e: CT[i].chl) {
			ps(e+1);
		}
		entr;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int m;
	cin>>n>>m;
	loop(i,0,n){
		tree.pb(TNode(i, i != 0));
	}
	int a,b;
	loop(i,0,n-1){
		cin>>a>>b;
		tree[a-1].ngh.pb(TEdge(b-1));
		tree[b-1].ngh.pb(TEdge(a-1));
	}
	vector<CTNode> CT = decompose(tree);
	printCT(CT); 	
}
