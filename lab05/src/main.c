int main()
{
	int a = 6;
	int result = 0;
	for (int i = 1; i < a; i++)
	{
		if (a % i == 0)
		{
			result += i;
		}
		else
		{
			result += 0;
		}
	}
	return 0;
}
