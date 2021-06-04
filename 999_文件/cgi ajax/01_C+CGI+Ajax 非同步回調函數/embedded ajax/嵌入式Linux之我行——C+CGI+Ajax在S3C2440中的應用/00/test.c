#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t current;
	struct tm *timeinfo;
	time(&current);
	timeinfo = localtime(&current);
	//這一句一定要加，否則非同步訪問會出現頁面異常
	printf("Content type: text/html\n\n");
	printf("%s", asctime(timeinfo));
}
