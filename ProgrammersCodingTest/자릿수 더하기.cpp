int solution(int n) {
	int answer = 0;
	for (; n > 0; n /= 10)
		answer += n % 10;

	return answer;
}

int main()
{
	solution(100200507);

	return 0;
}
