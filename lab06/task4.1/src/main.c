int main()
{
	const char mas[] = { " Hi     Gitler    xxx x x x0 0" };
	int result=0;
	int len = 0;
	int found = 0;
	while (mas[len] != 0)
	{
		if (mas[len] != ' ')
		{
			if (found == 0) {
				result++;
			}
			found = 1;
		}
		else {
			found = 0;
		}
		len++;
	}
}
	
