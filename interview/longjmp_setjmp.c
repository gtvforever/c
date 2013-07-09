#include <stdio.h>
#include <setjmp.h>

void s1(void);
void s2(void);

jmp_buf jumper;

void s1()
{
	longjmp(jumper, 1);
	return;
}

void s2()
{
	longjmp(jumper, 3);
	return;
}

main()
{
	int value = 0;
	int i = 0;

	value = setjmp(jumper);
	i++;
	printf("i = %d, value = %d\n", i, value);

	if(0 == value)
	{
		printf("initial setjmp call success %d\n", __LINE__);
		s1();
		printf("%d\n", __LINE__);
	}
	else if(1 == value)
	{

		printf("value = 1\n");
		s2();
		printf("%d\n", __LINE__);
	}
	else
	{

		printf("%d, value = %d\n", __LINE__, value);
	}

	return 0;
}
