#include<bits/stdc++.h>

using namespace std;

const int ALPHABET = 26;
const int FAIL = -1;
// goto function
vector<vector<int> > g;
// failure function
vector<int> f;
// output function
map<int, string> o;

// maps char a into int <0..ALPHABET)
int mp(char a) {
	return a-'a';
}
// backward map
char mpb(int a) {
	return a+'a';
}

int new_state() {
	int ind = g.size();
	g.push_back(vector<int>(ALPHABET, FAIL));
	f.push_back(FAIL);
	return ind;
}

void init() {
	new_state();
}

void add(string s) {
	int st=0;
	for(char a : s) {
		if(g[st][mp(a)] == FAIL) {
			st = g[st][mp(a)] = new_state();
		} else {
			st = g[st][mp(a)];
		}
	}
	o[st]=s;
}

void construct() {
	for(int i=0;i<(int)g[0].size();i++) if(g[0][i]==FAIL) g[0][i]=0;
	
	queue<int> Q;
	for(auto s:g[0]) if(s != 0) {
		f[s]=0;
		Q.push(s);
	} 
	
	while(!Q.empty()){
		int r = Q.front();
		Q.pop();
		int s;
		for(int a=0;a<(int)g[r].size();a++) if((s = g[r][a]) != FAIL) {
			Q.push(s);
			int state = f[r];
			while(g[state][a]==FAIL) state=f[state];
			f[s]=g[state][a];
		}
	}
}

void output(int st) {
	while(st != 0) {
		if(o.find(st) != o.end()) cout<<o[st]<<" ";
		st=f[st];
	}
	cout<<"\n";
}

void match(string s) {
	int st = 0;
	for(auto a : s) {
		while(g[st][mp(a)]==FAIL) st=f[st];
		st=g[st][mp(a)];
		output(st);
	}
}

void printG() {
	cout<<"GoTo:\n";
	for(int i=0;i<(int)g.size();i++) {
		cout<<i<<": ";
		for(int j=0;j<(int)g[i].size();j++) if(g[i][j] != FAIL) cout<<mpb(j)<<"->"<<g[i][j]<<" ";
		cout<<"\n";
	}
}

void printF(){
	cout<<"Failure:\n";
	for(int i=0;i<(int)f.size();i++) cout<<i<<" "<<f[i]<<"\n";
}

void printO() {
	cout<<"Output:\n";
	for(int i=0;i<(int)g.size();i++) {
		cout<<i<<": ";
		if(o.find(i) != o.end()) cout<<o[i]<<" ";
		cout<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	init();
	string K[] = {"he", "she", "his", "hers"};
	for(auto s : K) add(s);
	construct();
	printG();
	printF();
	printO();
	match("mama tatshers");
}
