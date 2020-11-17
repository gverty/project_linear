int func(const int len, int massiv[])
{
	int last = 0;
	int founder = 1;
	int temps = 0;
	while (temps < len)
	{
		for (int i = last + 1; i < 1000; i++)
		{
			founder = 1;
			for (int j = 2; j < i / 2; j++)
			{
				if (i % j == 0)
				{
					founder = 0;
					break;
				}
			}
			if (founder != 0)
			{
				massiv[temps] = i;
				last = i;
				break;
			}
		}
		temps++;
	}
	return 0;
}



int main()
{
	const int length = 30;
	int mas[length];

	mas[length] = func(length, mas);
	return 0;


}
