#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t current;
	struct tm *timeinfo;
	time(&current);
	timeinfo = localtime(&current);
	//�o�@�y�@�w�n�[�A�_�h�D�P�B�X�ݷ|�X�{�������`
	printf("Content type: text/html\n\n");
	printf("%s", asctime(timeinfo));
}
