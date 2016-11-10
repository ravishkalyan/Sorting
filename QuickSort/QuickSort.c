#include<stdio.h>
#include<stdlib.h>

void display(int *ar,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",ar[i]);
	printf("\n");
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a,*a=*b,*b=temp;
}

void quicksort(int *ar,int p,int q)
{
	int i,j,pivot;
	if(p<q)
	{
		pivot=ar[p];
		printf("\npivot is %d",pivot);
		i=p,j=q;
		printf("\ni: %d,j: %d",i,j);
		while(i<j)
		{
			while(ar[i]<=pivot && i<q)
				i++;
			while(ar[j]>pivot)
				j--;
			if(i<j)
			{
				swap(&ar[i],&ar[j]);
			}
		}
		swap(&ar[j],&ar[p]);
		quicksort(ar,p,j-1);
		quicksort(ar,j+1,q);
	}
}

int main ()
{
	int n,i,*ar;
	printf("\nenter size of array");
	scanf("%d",&n);
	ar=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("\nenter %d element",i+1);
		scanf("%d",&ar[i]);
	}
	display(ar,n);
	quicksort(ar,0,n-1);
	printf("\nafter sorting ");
	display(ar,n);
	return 0;
}