long long fastPower(long long n, long long p){
	if(p==0) 
		return 1;
	else if(p==1) 
		return n;
	else if(p%2==0){
		n=fastPower(n,p/2);
		return n*n;
	}else 
		return n*fastPower(n,p-1);
}

long long fastPowerMOD(long long n, long long p, long long* MOD){
	if(p==0) 
		return 1;
	else if(p==1) 
		return n%(*MOD);
	else if(p%2==0){
		n=fastPowerMOD(n,p/2,MOD);
		return (n*n)%(*MOD);
	}else 
		return (n*fastPowerMOD(n,p-1,MOD))%(*MOD);
}

long long max2Div(long long n){
	long long k=0;
	long long p=1;
	while(n%p==0){
		k++;
		p=p*2;
	}
	return --k; 
}

bool MillerRabin(long long n, long long k){
	if(n<2) return false;
	else if(n==2) return true;
	else if(n%2==0) return false;
	srand(time(NULL));
	long long s = max2Div(n-1);
	long long d = (n-1)/fastPower(2,s);
	bool result=1;
	while(k--){
		long long a = rand()%(n-1)+1;
		result=0;
		for(int r=0;r<s;r++){
			if(fastPowerMOD(a,d,&n)==1||fastPowerMOD(a,fastPower(2,r)*d,&n)==n-1)
				result=1;
		}
		if(!result) return false;
	}
	return true;
	
}
