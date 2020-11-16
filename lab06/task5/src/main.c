int main()
{
	const int N = 2;
	int massiv[N][N];

	int temp;
	for (int i = 0; i < N; i++) {         // цикл заполнения элементов двумерного массива размером N нa N
		for (int j = 0; j < N; j++) {
			massiv[i][j] = i * j;
		}
	}
	
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < N; j++) {
			temp = massiv[j][0];
			for (int g = 0; g < N - 1; g++)
				massiv[j][g] = massiv[j][g + 1];
			massiv[j][N - 1] = temp;
		}
	}
}
