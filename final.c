#include <stdio.h>
#include <pthread.h>

void *print_numbers(void *arg)
{
	int *num = (int *)arg;
	for(int i = 0; i < 5; i++ )
	{
		printf("Thread %d: %d\n", *num,i);
	}
	return NULL;
}
int main()
{
	pthread_t thread1, thread2;
	int num1 = 1, num2 = 2;
	pthread_create(&thread1, NULL, print_numbers, &num1);
	pthread_create(&thread2, NULL, print_numbers, &num2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	return 0;
}

