#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int item_gen[2];
char* item[3]={"pen","paper","question_paper"};
int i=0,j=0,k=0;
sem_t t;
void *agent()
	{

		sem_wait(&t);
		i=k;
		j=i+1;
		if(j==3)
			j=0;
		k=j;
		item_gen[0]=i;
		item_gen[1]=j;
		printf("teacher places %s and %s \n",item[i],item[j]);
		sem_post(&t);
		pthread_exit(NULL);
	}

void *smoker()
	{

		sem_wait(&t);
		int val=0;
		//printf("value is : %d \n",val);
		//if(item_gen[0]!=val && item_gen[1]!=val)
		//{
		printf("Student %d has completed his exam \n",val);
		//	}
		sem_post(&t);
		pthread_exit(NULL);
	}

int main()
	{
		pthread_t s1,s2,s0,agnt1,agnt2,agnt3;
		sem_init(&t,0,1);
		int m=0,n=1,o=2;
		printf("Student 0 has pen\n");
		printf("Student 1 has paper\n");
		printf("Student 2 has question_paper\n");
		for(int x=0;x<3;x++){
		pthread_create(&agnt1,NULL,agent,NULL);
		pthread_create(&s0,NULL,smoker,NULL);
		//printf("thread1 is created");
		pthread_create(&s1,NULL,smoker,NULL);
		pthread_create(&s2,NULL,smoker,NULL);
		pthread_join(agnt1,NULL);
		pthread_join(s0,NULL);
		pthread_join(s1,NULL);
		pthread_join(s2,NULL);
			}
	}
