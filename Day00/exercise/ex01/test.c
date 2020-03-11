#include <stdio.h>

int main(){
	int arr[] = {7,2,3,5,4,1,9,8,1};
	int n = 9;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n - 1; ++j)
			if (arr[j+1] < arr[j])
			{
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}



}
