#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll C = 12;
const ll O = 16;
const ll H = 1;
void calculator(string s)
{
    vector <ll> sum(s.length() + 2, 0);
    vector <int> v;
    s = ' ' + s;
    for (int i = 1; i <= s.length() - 1; i++)
    {
        if (s[i] == 'C') sum[i] = sum[i-1] + C;
        else if (s[i] == 'H') sum[i] = sum[i-1] + H;
        else if (s[i] == 'O') sum[i] = sum[i-1] + O;
        else 
        {
            if (s[i] == '(') 
            {
                sum[i] = sum[i-1];
                v.push_back(i);
            }
            else if (s[i] >= '0' && s[i] <= '9' ) 
            {
                int x = (int) s[i] - 48;
                if (s[i-1] != ')') sum[i] = (sum[i-1] - sum[i-2]) * x + sum[i-2];
                else sum[i] = sum[i-1];
            }
            else
            {
                int vitri = v[v.size() - 1];
                v.pop_back();
                if (s[i+1] >= '0' && s[i+1] <= '9') 
                    {
                        int x = (int) s[i+1] - 48;
                        sum[i] = ((sum[i-1] - sum[vitri]) * x) + sum[vitri];
                    }
                else sum[i] = sum[i-1];
            }
            
        }
    }
    cout << sum[sum.size() - 2] << endl;
}
int main()
{
    int test;
    cin >> test;
    for (int t = 1; t <= test; t ++)
    {
        string s;
        cin >> s;
        calculator(s);
    }
    return 0;
}