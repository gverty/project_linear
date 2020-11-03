int main()
{
	float x = 123;
	float y;
	if (x < -1)
	{
		y = -1 / x;
	}
	else if (x > -1 && x < 1)
	{
		y = x * x;
	}
	else if (x > 1)
	{
		y = 1;
	}
	return 0;
}
