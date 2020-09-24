int solution(int n, int a, int b) {
	for (int answer = 1; true; answer++, a = (a + 1) / 2, b = (b + 1) / 2)
		if (a % 2 == 0 ? a - 1 == b : a + 1 == b)
			return answer;
}
