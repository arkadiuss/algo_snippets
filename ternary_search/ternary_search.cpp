double search() {
	double s = MIN;
	souble e = MAX;
	loop(t,0,100) {
		double x1 = (2.0*s+e)/3.0;
		double x2 = (s+2.0*e)/3.0;
		double y1 = forx(x1);
		double y2 = forx(x2);
		if(y1>y2) {
			s=x1;
		} else {
			e=x2;
		}
	}
	return forx(e);
}
