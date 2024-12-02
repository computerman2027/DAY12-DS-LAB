#include <stdio.h>
#define MAXSIZE 10

int heap[MAXSIZE];
int N=0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val)
{
	N=N+1;
	int pos=N,par;
	heap[N]=val;
	while(pos>1)
	{
		par=pos/2;
		if(heap[pos]<=heap[par])
		{
			return;
		}
		else
		{
			swap(&heap[pos],&heap[par]);
			pos=par;
		}
	}
}

void delete(int val)
{
	int last = heap[N];
	N=N-1
	int ptr =1,left=2,right=3;
	heap[ptr]=last;
	while(left<=N)
	{
		if(heap[ptr]>= heap[left] && heap[ptr]>=heap[right])
		{
			return;
		}
		if(heap[right]<=heap[left])
		{
			swap(&heap[ptr],&heap[left]);
			ptr=left;
		}
		else
		{
			swap(&heap[ptr],&heap[right]);
			ptr=right;
		}
		left=2*ptr;
		right=left+1;
		
	}
	return;
}

void heapsort()
{
	
}


int main()
{
	printf("ENTER NUMBER OF ELEMENTS\n");
    int n,i,j,val;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
    	printf("Enter value : ");
    	scanf("%d",&val);
    	insert(val);
    	printf("DISPLAYING ELEMENTS OF ARRAY\n"); 
    	for (j = 0; j <=i+1; j++)
        printf(j==i?"%d\n":"%d, ", heap[j]);
	}
	printf("DISPLAYING ELEMENTS OF ARRAY\n"); 
    for (i = 0; i < n+1; i++)
        printf(i==n-1?"%d\n":"%d, ", heap[i]);
    return 0;
}
