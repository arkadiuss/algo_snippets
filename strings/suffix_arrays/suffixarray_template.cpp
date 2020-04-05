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

vector<int> suffix_array(const string & s) {
	auto k = kmr(s);
	int ks = k.size()-1;
	vector<int> sarr(s.size());
	for(int i=0;i<(int)s.size();i++) sarr[k[ks][i]-1]=i;
	return sarr;
}

vector<int> lcp(const string & s, const vector<int> & suffix_array) {
	int n = suffix_array.size();
	vector<int> lcp(n, 0);
	vector<int> R(n+1);
	for(int i=0;i<n;i++) R[suffix_array[i]]=i;
	int l=0;
	for(int i=0;i<n;i++) {
		if(R[i] == n-1) {
			l=0;
			continue;
		}	
		int j = suffix_array[R[i]+1];
		while(l + i < n && l + j < n && s[l+i] == s[l+j]) l++;
		lcp[R[i]]=l;		
		l = max(0,l-1);
	}
	return lcp;
}

int main() {
	//string s = "babaabababba";
	// string s = "abaabbaa";
	//string s = "abaab";
	string s = "abaabaa";
	cout<<s<<"\n";
	auto res = suffix_array(s);
	for(auto i:res) {
		cout<<s.substr(i)<<"\n";		
	}
	cout<<"\n";
	auto res2  = lcp(s, res);
	for(auto i:res2) {
		cout<<i<<" ";		
	}
	cout<<"\n";
}
