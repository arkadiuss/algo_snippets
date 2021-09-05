char M[MAX][MAX];

void rotate(int N) {
	for(int i=0;i<N/2;i++) {
		for(int j=i;j<N-i-1;j++) {
			int tmp = M[i][j];
			M[i][j] = M[j][N-i-1];
			M[j][N-i-1] = M[N-i-1][N-j-1];
			M[N-i-1][N-j-1] = M[N-j-1][i];
			M[N-j-1][i]=tmp;
		}
	}
}
