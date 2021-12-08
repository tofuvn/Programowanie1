bool expval(unsigned int n, const double  *x, const double  *p, double (*f) (double), double &r) {
	
	double cumSum = 0;
	
	for (int i = 0; i < n; i++) {
		if (p[i] < 0) {
			return false;
		}
		
		cumSum += p[i];
	}	
	
	if (cumSum >= 1) {
		return false;
	}
	
	double lastPn = 1;
	
	for (int i = 0; i < n; i++) {
		r += f(x[i]) * p[i];
		lastPn -= p[i];
	}
	
	r += f(x[n]) * lastPn;
	
	return true;
}
