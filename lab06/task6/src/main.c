// task6lab06.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
int main()
{
	const int N = 3;
	int matrixA[N][N];
	int matrixB[N][N];
	int result[N][N];

	for (int i = 0; i < N; i++) {         // цикл заполнения элементов матрицы 
		for (int j = 0; j < N; j++) {
			matrixA[i][j] = i * j;
			matrixB[i][j] = i * j;
			
		}
	}
	for (int x = 0; x < N; x++) // цикл умножения
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				result[x][i] += matrixA[x][j] * matrixB[j][i];

				
			}
		}
	}
}


