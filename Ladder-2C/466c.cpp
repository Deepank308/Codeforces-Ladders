#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int sum = 0;
	int n;
	cin >> n;
	vector<long long int> array(n + 1, 0);
	int a;

	for(int i = 1; i < n + 1; i++)
	{
		cin >> a;
		array[i] = array[i - 1] + a;
	}
	if(array[n]%3 != 0)
	{
		cout << "0\n";
	}
	else
	{
		sum = array[n] / 3;
		long long int count_2sum = 0;
		vector<long long int> count_prefix_sum(n + 1, 0);
		for(int i = 1; i < n; i++)
		{
			count_prefix_sum[i] = count_prefix_sum[i - 1];
			if(array[i] == sum)
				count_prefix_sum[i]++;
			if(array[i] == 2*sum)
				count_2sum += count_prefix_sum[i - 1];
		}

		cout << count_2sum << "\n";
	}
	return 0;
}