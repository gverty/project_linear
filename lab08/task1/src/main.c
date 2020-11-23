int func(const int len,int arr[])		// Головна функція, призначення якої підрахувати результат
{						// за умови, якщо попередній елемент массиву меньше наступного,
	int res = 0;				// то до кінцевого результату додається 1
	for (int i = 0; i < len; i++)		
	{
		if (arr[i] < arr[i+1])
		{
			res++;
		}
	}
	return res;
}

void func2(int len,int mass[])
{
	for (int i = 0; i < len; i++)    // Псевдовипадковий генератор чисел rand()
	{				  // заповнює масив довжиною length
		mass[i] = rand();
	}


}


int main()
{
	const int length = 4;
	int massiv[length];
	int RESULT;
	
	
	
	RESULT = func(length,massiv);	  // Кінцевий результат, обичислений за допомогою звернення 	
}					  // До функції , яка використовує довжину массиву, 	
					  // та массив,для обчислення RESULT
