#include<bits/stdc++.h>

using namespace std;

vector<int> prefix_function(const string & s) {
	vector<int> pref(s.size() + 1);
	pref[0]=-1;
	int k=-1;
	for(int i=0;i<(int)s.size();i++) {
		while(k != -1 && s[i]!=s[k]) k=pref[k];
		pref[i+1]=++k;
	}
	return pref;
}

int main() {
	//string s = "babaabababba";
	// string s = "abaabbaa";
	//string s = "abaab";
	string s = "aaa";
	auto res = prefix_function(s);
	for(auto i:res) {
		cout<<i<<" ";		
	}
	cout<<"\n";
}
