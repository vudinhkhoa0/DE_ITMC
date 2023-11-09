#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void load(ll &n)
{
    cin >> n; 
}
ll calculator(ll n)
{
    vector <ll> nagative_number(n + 1, 0);
    vector <ll> positive_number(n + 1, 0);
    ll tmax = -1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (x > 0) 
        {
            positive_number[i] =  max(positive_number[i-1], x);
            tmax = max(tmax, positive_number[i - 1] + x);
        }
        else positive_number[i] = positive_number[i-1];
        if (x < 0)
        {
            nagative_number[i] = min(nagative_number[i - 1], x);
            tmax = max(tmax, abs(nagative_number[i-1] + x));
        }
        else nagative_number[i] = nagative_number[i-1];
    }
    return tmax;
}
int main()
{
    ll n;
    load(n);
    cout << calculator(n);
    return 0;
}