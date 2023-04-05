#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
typedef int element;

typedef struct
{
	element data[MAX];
	int top;
} Stack;

void init_stack(Stack* s)
{
	for (int i = 0; i < MAX; i++)
		s->data[i] = 0;
	s->top = -1;
}

int is_empty(Stack* s)
{
	return (s->top == -1);
}

int is_full(Stack* s)
{
	return (s->top == (MAX - 1));
}

void push(Stack* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "Full error\n");
		return;
	}
	else
	{
		s->top++;
		s->data[s->top] = item;
	}
}

element pop(Stack* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "Empty error\n");
		return -1;
	}
	else
	{
		int data = s->data[s->top];
		s->top--;
		return data;
	}
}

int main()
{
	time_t t = time(NULL);
	unsigned int seed = (unsigned int)t;
	srand(seed);

	Stack s;
	init_stack(&s);

	for (int i = 0; i < 30; i++)
	{
		int rand_num = rand() % 100 + 1;

		if (rand_num % 2 == 0)
		{
			push(&s, rand_num);
			printf("push : %d\n", rand_num);
		}
		else
		{
			int popped = pop(&s);
			if (popped == -1)
				continue;
			else
			{
				pop(&s);
				printf("pop : %d\n", rand_num);
			}
		}

		printf("Struct stack : [ ");
		for (int i = 0; i < MAX; i++)
			printf("%d ", s.data[i]);
		printf("]\n");
	}
	return 0;
}
