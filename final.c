#include <stdio.h>
#include <pthread.h>

void* Printer(void* num)
{
	int n = *(int*)num;
	printf("\nthis is %d \n",n);
}

int main()
{
	int num;
	pthread_t thread[12];
	for (int i = 0; i < 12; i++)
	{
		pthread_create(&thread[i],NULL,Printer,&i);
		pthread_join(thread[i],NULL);
	}
	printf("\nthis is my end of Program\n");
}
