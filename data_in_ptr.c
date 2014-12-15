/*
* Copyright (C) 2014  Arjun Sreedharan
* License: GPL version 2 or higher http://www.gnu.org/licenses/gpl.html
*/

#include <stdio.h>
#include <assert.h>

void put_data(int*, unsigned int);
unsigned int get_data(unsigned int);
void cleanse_pointer(int*);

void put_data(int *p, unsigned int data)
{
	assert(data < 4);
	*p |= data;
}

unsigned int get_data(unsigned int p)
{
	return (p & 3);
}

void cleanse_pointer(int *p)
{
	*p &= ~3;
}

int main(void)
{
	assert(sizeof(int) == 4);
	assert(sizeof(void*) == 4);

	unsigned int x = 701;
	unsigned int p = (unsigned int) &x;

	printf("Original ptr: %u\n", p);

	put_data(&p, 3);

	printf("ptr with data: %u\n", p);
	printf("data stored in ptr: %u\n", get_data(p));

	cleanse_pointer(&p);

	printf("Cleansed ptr: %u\n", p);
	printf("Dereferencing cleansed ptr: %u\n", *(int*)p);

	return 0;
}
