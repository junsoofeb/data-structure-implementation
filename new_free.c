#include <stdio.h>
#define POOL_SIZE 10

struct record  // record structure
{
	int item;
	struct record * next;
};

// pool of memory
struct record pool[POOL_SIZE];
struct record * top = pool;  // pool is constant.  top is pointer to stack top.

void init_pool();
struct record * new_node();
void free_node(struct record *r);

int main()
{
	init_pool();

	printf("Implemetation of new() and free() \n\n");

	return 0;
}

void init_pool() // Initialize the pool
{
	int i;
	struct record *q = pool;

	for (i = 0; i < POOL_SIZE - 1; i++) //첫 번째부터 마지막 전까지
	{
		q->next = q + POOL_SIZE;
		q = q + POOL_SIZE;
	}

	pool[POOL_SIZE - 1].next = NULL; //last block
	top = pool;
}

// Get a node from the pool. 
struct record * new_node()
{
	struct record * q;
	if (top == NULL)
	{
		printf("Pool is empty. Bye!\n");
		return;
	}
	q = top;
	top = q->next;

	return q;
}

// Push a node to the pool.
void free_node(struct record *r)
{
	r->next = top;
	top = r;
}