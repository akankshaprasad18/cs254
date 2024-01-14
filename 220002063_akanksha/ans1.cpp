#include <iostream>
using namespace std;

int maxsum(int arr[], int n)
{
	int firstmax, secondmax;
	if (arr[0] > arr[1]) {
		firstmax = arr[0];
		secondmax = arr[1];
	}
	else {
		firstmax = arr[1];
		secondmax = arr[0];
	}

	for (int i = 2; i < n; i++) {
		if (arr[i] > firstmax) {
			secondmax = firstmax;
			firstmax = arr[i];
		}

		else if (arr[i] > secondmax && arr[i] != firstmax)
			secondmax = arr[i];
	}
	int ans;
	ans=firstmax+secondmax;
	return ans;
}


int main()
{
	int arr[] = {3,1,4,6,8,2,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<maxsum(arr, n);
	return 0;
}