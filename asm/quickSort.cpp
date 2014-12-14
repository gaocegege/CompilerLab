#include <iostream>
#define MAXSIZE 1000
int arr[MAXSIZE];

void swap(int a[],int x,int y)
{
		int tmp;
			tmp = a[x];
				a[x] = a[y];
					a[y] = tmp;
}
void quicksort(int array[], int left, int right)
{
	    if(left<right){
			        int pivot=left,j;
					        for(j=left+1;j<=right;j++)
								            if(array[j]<array[left])
												                swap(array,++pivot,j);
							        swap(array,pivot,left);
									        quicksort(array,left,pivot-1);
											        quicksort(array,pivot+1,right);
													    }
}
int main()
{
		int n,t;
			std::cout<<"input number of arr\n";
				std::cin>>n;

					for(int i = 0; i<n; i++)
							{
										std::cin>>t;
												arr[i] = t;
													}
						quicksort(arr,0,n-1);
							for(int i = 0; i<n; i++)
									{
												std::cout<<arr[i]<<" ";
													}
								return 0;
}
