struct BigNum{
	int n[N];
	BigNum(string s){
		for(int i=0;i<N;i++){
			n[i]=0;
		}
		for(int i=0;i<s.size();i++){
			n[i]=s[s.size()-1-i]-48;
		}
	};
	
	BigNum(){
		BigNum("0");
	};
	
	BigNum operator+(const BigNum & a){
		BigNum r("0");
		int d=0;
		for(int i=0;i<N;i++){
			r.n[i]=n[i]+a.n[i]+d;
			d=r.n[i]/10;
			r.n[i]%=10;
		}
		return r;
	}
	
	bool operator=(const BigNum & a){
		for(int i=0;i<N;i++){
			n[i]=a.n[i];
		}
		return 1;
	}
	
	BigNum operator*(const BigNum & a){
		BigNum r("0"), mr("0"), tr("0");
		for(int i=0;i<N;i++){
			int d=0;
			for(int j=0;j<N;j++){
				mr.n[i+j]=n[i]*a.n[j]+d;
				d=mr.n[i+j]/10;
				mr.n[i+j]%=10;
			}
			r=r+mr;
			mr=tr;
		}
		return r;
	}
	
	BigNum operator*(const int & a){
		BigNum r("0");
		int d=0;
		for(int i=0;i<N;i++){
			r.n[i]=n[i]*a+d;
			d=r.n[i]/10;
			r.n[i]%=10;
		}
		return r;
	}
};
