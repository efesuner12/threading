#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


typedef struct Compound{
	int *a, *b;	
}Compound;

void do_one_thing();
void do_another_thing();
int* do_sum_wrapped(void *d);

int main(void)
{
	pthread_t thread1, thread2;
	pthread_t  thread3;

	Compound *c;
	*c->a = 10;
	*c->b = 11;

	pthread_create(&thread1,
		NULL,
		(void*) do_one_thing,
		NULL
	);

	pthread_create(&thread2,
		NULL,
		(void*) do_another_thing,
		NULL
	);

	pthread_create(&thread3,
		NULL,
		(void *) do_sum_wrapped,
		(void *) c
	);	

	sleep(1);

	return 0;
}

void do_one_thing()
{
	int i,j,x;

	for(i=0; i<200; i++)
		printf("doing one thing\n");
}

void do_another_thing()
{
	int i,j,x;

	for(i=0; i<200; i++)
		printf("doing another thing\n");
}


int* do_sum(int *x, int *y)
{
	int *sum;
	*sum = *x + *y;

	return sum; 
}

int* do_sum_wrapper(Compound *c)
{
	int *d;
	d = do_sum(c->a, c->b); 

	return d;
}
