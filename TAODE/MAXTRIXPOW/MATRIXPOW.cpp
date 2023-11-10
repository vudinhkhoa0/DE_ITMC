#include <bits/stdc++.h>
using namespace std;
const int N = 150;
typedef long long ll;
const ll MOD = 1000000000 + 7;
ll a[N][N];
ll result[N][N];
ll base[N][N];
void OutPut(ll a[][N], ll m) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
        cout << endl;
    }
}
void get(ll x[][N], ll y[][N], ll m) {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) x[i][j] = y[i][j];
}
void multiplication(ll x[][N], ll y[][N], ll m) {
    ll tmp[N][N];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++) tmp[i][j] = (tmp[i][j] + (x[i][k] * y[k][j]) % MOD) % MOD;
    get(x, tmp, m);
}

void POWMATRIX(ll m, ll power) {
    for (int i = 1; i <= m; i++) result[i][i] = 1;

    get(base, a, m);

    while (power > 0) {
        if (power % 2 == 1)
            multiplication(result, base, m);
        multiplication(base, base, m);
        power /= 2;
    }
    OutPut(result, m);
}
int main() {
    ll m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    POWMATRIX(m, n);
    return 0;
}