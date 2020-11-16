int main()
{
	const int len = 15;
	char mas[len] = { "Ivanov        " };
	char zapol = '_';
	int countprobel = 0;
	int countivanov = 0;
	char mas2[len];
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (mas[i] == ' ')
		{
			countprobel++;
		}
	}

	for (int i = 0; i < len; i++)
	{
		if (mas[i] != ' ' && mas[i] != '\0')
		{
			countivanov++;
			mas2[i] = mas[i];
		}
	}
	int formula = (len - 1 - countivanov) / 2;

	for (int i = (formula); i < (countivanov+formula); i++)
	{
		mas[i] = mas2[j];
		j++;
	}

	for (int i = 0; i < formula ; i++)
	{
		mas[i] = zapol;
	}
	for (int i = formula + countivanov; i < len; i++)
	{
		mas[i] = zapol;
	}
}
