#include<iostream>

using namespace std;

int possible(int m, int s)
{
        return (s >= 0) && (s <= 9*m);
}

int main()
{
        int m, s;
        cin >> m >> s;
        string max, min;

        if((s == 0 && m > 1) || !possible(m, s))
        {
                cout << "-1 -1\n";
                return 0;
        }

        if(s == 0 && m == 1)
        {
                cout << "0 0\n";
                return 0;
        }


        int sum = s;
        for(int pos = 0; pos < m; pos++)
        {
                for(int dig = 0; dig <= 9; dig++)
                {
                        if(pos == 0 && dig == 0) continue;
                        if(possible(m - pos - 1, sum - dig))
                        {
                                min += '0' + dig;
                                sum = sum - dig;
                                break;
                        }
                }
        }

        sum = s;
        for(int pos = 0; pos < m; pos++)
        {
                for(int dig = 9; dig >= 0; dig--)
                {
                        if(possible(m - pos - 1, sum - dig))
                        {
                                max += '0' + dig;
                                sum = sum - dig;
                                break;
                        }
                }
        }
        cout << min << " " << max << "\n";
        return 0;
}
