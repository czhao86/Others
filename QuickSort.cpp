#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void quickSort(int l,int r,int a[])
{
	if (l<r)
		{
		    int pivot=a[r];
			int i=l,j=r-1;
			while (i<=j)
			{
				while (a[i]<pivot) i++;
				while (a[j]>pivot) j--;
                if (i<j) swap(a[i],a[j]);
			}
			swap(a[r],a[i]);
			for (int i=0;i<10;++i)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
			quickSort(l,i-1,a);
			quickSort(i+1,r,a);
		}
}

int main()
{
	int a[10]={3,5,2,4,8,13,1,6,9,7};
	quickSort(0,9,a);
	for (int i=0;i<10;++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
