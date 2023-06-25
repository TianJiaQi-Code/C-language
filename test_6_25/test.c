

//1.鸡兔同笼，鸡和兔共100只，共284只脚，求鸡和兔的个数。
#include <stdio.h>

int main()
{
	int chicken = 100;
	int rabbit = 0;
	while (chicken >= 0 && rabbit >= 0)
	{
		if (chicken * 2 + rabbit * 4 == 284)
		{
			printf("鸡有%d只,兔有%d只\n", chicken, rabbit);
			break;
		}
		chicken--;
		rabbit++;
	}
	return 0;
}