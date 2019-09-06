#include<bits/stdc++.h>

using namespace std;

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define v(d_type) vector<d_type>
#define loop(i, s, n) for(int i = s; i < n; i++)
#define print_vec(X) loop(i, 0, X.size()) cout << X[i] << "\n"
#define nl "\n"
#define fat 1000000007

void lay_tube(int *x, int *y, int n, int m, int len_1)
{
    cout << len_1 << " ";
    while(len_1--)
    {
        cout << *x << " " << *y << " ";
        if(*y < m && *y != 1)
        {
            if((*x)%2 == 1)
                (*y)++;
            else
                (*y)--;
        }
        else if(*y == m)
        {
            if((*x)%2 == 1)
                (*x)++;
            else
                (*y)--;
        }
        else if(*y == 1)
        {
            if((*x)%2 == 1)
                (*y)++;
            else
                (*x)++;
        }
        else if(*x > n || *y > m)
            break;
    }
    cout << nl;
}

int main()
{
    boost;
    int n, m, k;
    cin >> n >> m >> k;
    int len_1 = n*m - 2*(k - 1);
    int x = 1, y = 1;
    lay_tube(&x, &y, n, m, len_1);
    k--;
    while(k--)
        lay_tube(&x, &y, n, m, 2);
    return 0;
}