#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define EL printf("\n")
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

#define x first
#define y second

std::vector<std::vector<int>> treasureLocating(std::vector<std::vector<int>> _points) {
    vector<ii> points;
    for (auto p : _points) points.push_back({p[0], p[1]});
    map<ii, int> mp;
    for (ii p : points) mp[p] = 1;
    vector<ii> f;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            for (int k = j + 1; k < points.size(); k++) {
                ii a = points[i];
                ii b = points[j];
                ii c = points[k];
                if ((b.x - a.x) * (c.y - a.y) == (c.x - a.x) * (b.y - a.y))
                    continue;
                ii g = {a.x + b.x + c.x, a.y + b.y + c.y};
                if (g.x % 3 || g.y % 3)
                    continue;
                g.x /= 3;
                g.y /= 3;
                if (mp[g] == 1) {
                    f.push_back(g);
                    mp.erase(g);
                }
            }
        }
    }
    sort(f.begin(), f.end());

    vector<vi> res;
    for (ii p : f) res.push_back({p.x, p.y});
    return res;
}