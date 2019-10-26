struct TNode{
	int val,mod,size;
};
int countD(int n){
	int i=1;
	while(i<n){
		i*=2;
	}
	return i;
}
void init(TNode * tree, int * A,vector<Vertex> & G, int D,int n){
	loop(i,D,2*D){
		if(i-D<n){
			tree[G[i-D].pre_i+D].val = A[i-D];
			tree[i].size = 1;
		}else
			tree[i].val=0;
		tree[i].mod=1;		
	}
	loopback(i,D-1,1){
		tree[i].mod=1;
		tree[i].size=tree[2*i].size+tree[2*i+1].size;
		tree[i].val=tree[2*i].val+tree[2*i+1].val;
	}
}
void update(TNode * tree,int l, int r, int a, int b,int D){
	int rp = (b+D)/(b-a+1); //range point
	if(l>b||r<a) return;
	else if(l<=a&&b<=r){
		tree[rp].mod *= -1;
		tree[rp].val = tree[rp].size-tree[rp].val;
	}else{
		if(tree[rp].mod==-1){
			tree[2*rp].mod *= -1;
			tree[2*rp].val = tree[2*rp].size-tree[2*rp].val;
			tree[2*rp+1].mod *= -1;
			tree[2*rp+1].val = tree[2*rp+1].size-tree[2*rp+1].val;
			tree[rp].mod=1;
		}
		update(tree,l,r,a,(a+b)/2,D);
		update(tree,l,r,(a+b)/2+1,b,D);
		tree[rp].val = tree[2*rp].val + tree[2*rp+1].val;
	}
}
int query(TNode * tree,int l,int r,int a,int b,int D){
	int rp = (b+D)/(b-a+1); //range point
	//ps(l);ps(r);ps(a);ps(b);pln(rp);
	if(l>b||r<a) return 0;
	else if(l<=a&&b<=r){
		return tree[rp].val;
	}else{
		if(tree[rp].mod==-1){
			tree[2*rp].mod *= -1;
			tree[2*rp].val = tree[2*rp].size-tree[2*rp].val;
			tree[2*rp+1].mod *= -1;
			tree[2*rp+1].val = tree[2*rp+1].size-tree[2*rp+1].val;
			tree[rp].mod=1;
		}
		return query(tree,l,r,a,(a+b)/2,D)+query(tree,l,r,(a+b)/2+1,b,D);
	}
}
