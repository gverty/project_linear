#include <iostream>
int main()
{
	const char mas[] = { "   Hi     Gitler    xxx x x x0 0   " };
	int Words=0;
	int len = 0;
	int temp=0;
	int temp2=0;
	while (mas[len] != 0)
	{
		len++;
	}
	for (int i = 0; i < len; i++)
	{
		if (mas[i] != ' ')
		{
			temp = i;
			
			for (int j = i; j < len; j++) 
			{
				
				if (mas[j] == ' ')
				{
					temp2 = j;
					break;
				}
				if (mas[j + 1] == '\0') {
					temp2 = j + 1;
				}
				i = j;
			}
			if (temp2 - temp > 0 )
			{
				Words++;
			}
		}
		
		
	}
}
