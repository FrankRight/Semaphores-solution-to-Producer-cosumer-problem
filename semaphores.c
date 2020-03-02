/*Done By:-
    Frankline Bosire
//  Simeon Kengere
//  Iyvonne Bett
    Maluki Muthusi
    Gerry Kyalo    
*/

#include<stdio.h>
#include<stdlib.h>
 
//Initialize variables
int semaphore = 1, full = 0, empty = 0, x = 0, choice;

//Prototype functions
void producer();
void consumer();
int wait(int);
int signal(int);

//Driver Program
int main()
{
    printf("\nEnter the size of the buffer:");
	scanf("%d",&empty);
	printf("\n1.Produce\n2.Consume\n3.Set New Buffer\n4.Exit");
	while(1)
	{
		printf("\nChoice to do in 1, 2, 3 or 4 above): ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	if((semaphore == 1)&&(empty != 0))
						producer();
					else
						printf("%d items in the Buffer! The buffer is full!!\n", full);

					break;
			case 2:	if((semaphore == 1)&&(full != 0))
						consumer();
					else
						printf("You cannot consume... Buffer is empty!!");
					break;
            case 3: 
                    printf("\nEnter the size of the buffer:");
	                scanf("%d",&empty);
                    break;
			case 4:
					exit(0);
					break;
		}
	}
	
	return 0;
}

//define the functions
int wait(int s)
{
	return (--s);
}
 
int signal(int s)
{
	return(++s);
}
 
void producer()
{
	semaphore = wait(semaphore);
	full = signal(full);
	empty = wait(empty);
	x++;
	printf("\n1 Item Added\n%d items are in the buffer.\n",x);
	semaphore = signal(semaphore);
}
 
void consumer()
{
	semaphore = wait(semaphore);
	full = wait(full);
	empty = signal(empty);
	printf("\nConsumer consumes item %d",x);
	x--;
	semaphore = signal(semaphore);
}