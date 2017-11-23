#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 8;

int cal(int a[], int n)
{
	int i, result = 0;

	for (i = 1; i < n; i++)
	{
		result += abs(a[i] - a[i - 1]);
	}

	return result;
}

int main(void)
{
	int n, a[MAX];
	int i, min = 0, result = 0;

	cin>>n;

	for (i = 0; i<n; i++)
	{
		cin>>a[i];
	}

	sort(a, a+n);

	result = cal(a, n);

	while (next_permutation(a, a+n))
	{
		if (result < cal(a, n))
			result = cal(a, n);
	}

	cout<<result;

	return 0;

}