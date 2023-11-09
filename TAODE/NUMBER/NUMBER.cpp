#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000000 + 5;
vector<bool> prime(N, true);
vector<ll> a(N, 0);
void sive() {
    prime[1] = prime[0] = false;
    for (int i = 2; i <= sqrt(N - 5); i++)
        if (prime[i])
            for (int j = i * 2; j <= N - 5; j += i) prime[j] = false;
    prime[3] = false;
    for (int i = 1; i <= N - 5; i++)
        if (prime[i])
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
}
int main() {
    ll test;
    cin >> test;
    sive();
    for (int t = 1; t <= test; t++) {
        ll x, y;
        cin >> x >> y;
        ll x1 = x, y1 = y;
        x = ceil(sqrt(x / 9));
        y = floor(sqrt(y / 9));
        if (x * x * 9 < x1)
            x++;
        if (y * y * 9 > y1)
            y--;

        if (x == 0)
            cout << a[y];
        else
            cout << a[y] - a[x - 1];
        cout << endl;
    }
    return 0;
}