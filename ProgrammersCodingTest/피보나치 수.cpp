int solution(int n) {
	int fibo[100000 + 1] = { 0, };

	fibo[1] = 1;
	for (int i = 2; i <= 100000; i++)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1234567;

	return fibo[n];
}
