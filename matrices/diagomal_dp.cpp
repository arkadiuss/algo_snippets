int dp[2*MAX][MAX][MAX];
int a[MAX][MAX];
int n;

int rdp(int k, int i, int j) {
	if(i<0) return -INFTY;
	if(j<0) return -INFTY;
	if(k<n && (i > k || j> k)) return -INFTY;
	if(k>=n && (i < k-n+1 || j < k-n+1)) return -INFTY;
	return dp[k][i][j];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n) loop(j,0,n) cin>>a[i][j];
	
	dp[0][0][0] = a[0][0];
	loop(k,1,2*n-1) {
		int s = (k < n ? 0 : k-n+1);
		int e = (k < n ? k+1 : n);
		loop(i, s, e) {
			loop(j,s, e) {
				int yj = k-j;
				int yi = k-i;
				dp[k][i][j] = max(max(rdp(k-1, i, j), rdp(k-1, i-1, j)), max(rdp(k-1, i, j-1),rdp(k-1, i-1, j-1))) + a[i][yi] + ( i != j ? a[j][yj] : 0);
				//ps(k);ps(i);ps(j);pln(dp[k][i][j]);
			}
		}
	}
	pln(dp[2*n-2][n-1][n-1]);
}
