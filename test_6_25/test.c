

//1.����ͬ���������ù�100ֻ����284ֻ�ţ��󼦺��õĸ�����
#include <stdio.h>

int main()
{
	int chicken = 100;
	int rabbit = 0;
	while (chicken >= 0 && rabbit >= 0)
	{
		if (chicken * 2 + rabbit * 4 == 284)
		{
			printf("����%dֻ,����%dֻ\n", chicken, rabbit);
			break;
		}
		chicken--;
		rabbit++;
	}
	return 0;
}