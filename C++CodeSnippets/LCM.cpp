int gcd(int a, int b) {
	while (b > 0) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

int lcm(int a, int b) {
	int temp = gcd(a, b);

	return ((a / temp) * b);
}