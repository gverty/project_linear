int main()
{
	char *massivThousands[10] = {"dont","Одна тисяча","Дві тисячі","Три тисячі","Чотири тисячі","П ять тисяч","Шість тисяч","Сім тисячі","Вісім тисячі","Дев ять тисяч"};
	char *massivHundreds[10]  = {"dont","Сто","двісті","триста","чотириста","п ятсот","шістсот","сімсот","вісімсот","дев ятсот"};
	char *massivTens[10]  = {"dont","десять","двадцять","тридцять","сорок","п ятдесят","шістдесят","сімдесят","вісімдесят","дев яносто"};
	char *massivDecimal[10]  = {"ZERO","один","два","три","чотири","п ять","шість","сім","вісім","дев ять"};
	char *massivAny[10] = {"dont","одинадцять","дванадцять","тринадцять","чотирнадцять","п ятнадцять","шістнадцять","сімнадцять","вісімнадцять","дев ятнадцять"};
	int number = 1631;
	char *result[4];
	if (number != 0 && number < 10000 ){
	if ((number % 100) > 19){
		if (number >=1 && number % 10 != 0)
		{	
			result[3] = massivDecimal[(number % 10)];
		}
	
		if ((( number % 100 ) / 10)>0)
		{
			result[2] = massivTens[(( number % 100 ) / 10)];
		}
		}
	if ((number % 100) < 10)
	{
		result[3] = massivDecimal[(( number % 100) % 10)];
	}
	if ((number % 100) > 10 && (number % 100) < 20){
		result[3] = massivAny[(( number % 100 ) / 10)];
		}
	if ((( number / 100 ) % 10) > 0)
	{
		result[1] = massivHundreds[(( number / 100 ) % 10)];
	}
	if ( (number / 1000) > 0)
	{
		result[0] = massivThousands[(number / 1000)];
	}
	}
	else if(number==0){
		result[3]= massivDecimal[0];
	}
	return 0;	
}

