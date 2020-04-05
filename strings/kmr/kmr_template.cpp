#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > kmr(const string & s) {
	int S=s.size();
	vector<vector<int> > kmr(1, vector<int>(S+1));
	int k=0;
	for(int i=0;i<S;i++) kmr[k][i] = s[i]-'a'+1;
	kmr[k][s.size()] = 0;
	while((1<<k)<S) {
		kmr.push_back(vector<int>(S+1));
		k++;
		vector<pair<int, int>> c;
		int K = 1<<(k-1);
		for(int i=0;i<S;i++) c.push_back({kmr[k-1][i], ((i+K > S) ? 0 : kmr[k-1][i+K])});
		sort(c.begin(), c.end());
		c.erase(unique(c.begin(), c.end()), c.end());
		map<pair<int, int>, int> cc;
		for(int i=0;i<(int)c.size();i++) cc[c[i]] = i+1;
		for(int i=0;i<S;i++) kmr[k][i]=cc[{kmr[k-1][i], ((i+K > S) ? 0 : kmr[k-1][i+K])}];
		kmr[k][S]=0;
	}
	return kmr;
}

int main() {
	auto res = kmr("azba");
	for(auto i:res) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}
