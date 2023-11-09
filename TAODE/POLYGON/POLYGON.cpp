#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;
typedef double db;
ll n;
struct point {
    db x, y;
};
vector<point> p;

ll cross(const point &A, const point &B, const point &C) {
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}
int CCW(const point &A, const point &B, const point &C) {
    ll S = cross(A, B, C);
    if (S < 0)
        return -1;
    if (S == 0)
        return 0;
    return 1;
}
vector<point> ConvexHull(vector<point> p, ll n) {
    for (int i = 1; i < n; i++) {
        if (p[0].y > p[i].y || (p[0].y == p[i].y && p[0].x > p[i].x))
            swap(p[0], p[i]);
    }

    sort(p.begin() + 1, p.end(), [&p](const point &A, const point &B) {
        ll c = CCW(p[0], A, B);
        if (c > 0)
            return true;
        if (c < 0)
            return false;
        return A.x < B.x || (A.x == B.x && A.y < B.y);
    });

    vector<point> hull;
    hull.push_back(p[0]);

    for (int i = 1; i < n; i++) {
        while (hull.size() >= 2 && CCW(hull[hull.size() - 2], hull.back(), p[i]) < 0) hull.pop_back();
        hull.push_back(p[i]);
    }
    return hull;
}
db calculateAreaTriangle(point A, point B, point C) {
    db c1, c2, c3;
    c1 = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    c2 = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
    c3 = sqrt(pow(B.x - C.x, 2) + pow(B.y - C.y, 2));
    db p = (c1 + c2 + c3) / 2;
    db s = sqrt(p * (p - c1) * (p - c2) * (p - c3));
    return s;
}
void find() {
    n = p.size() + 2;
    p.push_back(p[0]);
    p.push_back(p[1]);
    for (int i = 0; i < p.size() - 2; i++) {
        if (CCW(p[i], p[i + 1], p[i + 2]) == 0)
            n--;
    }
    p.pop_back();
    p.pop_back();
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        db xx, xy;
        cin >> xx >> xy;
        p.push_back({ xx, xy });
    }
    p = ConvexHull(p, n);
    find();
    if (n == 2) {
        cout << 2 << " "
             << "0.00";
        return 0;
    } else
        cout << n - 2 << " ";
    db area = 0;
    for (int i = 1; i < p.size() - 1; i++) area += calculateAreaTriangle(p[0], p[i], p[i + 1]);
    if (area <= 1000000)
        cout << setprecision(2) << fixed << area;
    else
        cout << setprecision(0) << fixed << area;
    return 0;
}