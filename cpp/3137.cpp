#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define EL printf("\n")
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define faster ios_base::sync_with_stdio(false) && cin.tie(NULL)

// #define debug 1

#define e(a) a[sz(a) - 1]

struct dta {
    int l, r;
    int lshift, rshift;
};

char shift_left(string &s) {
    char c = s[0];
    FOR(i, 1, sz(s) - 1) s[i - 1] = s[i];
    s.pop_back();
    return c;
}

char shift_right(string &s) {
    char c = s[sz(s) - 1];
    s.pop_back();
    return c;
}

void receive_left(string &s, char c) {
    s.push_back(c);
    FOD(i, sz(s) - 1, 1) s[i] = s[i - 1];
    s[0] = c;
}

void receive_right(string &s, char c) {
    s.push_back(c);
}

bool obtainPalindromicArray(vector<string> a) {
    int n = sz(a);
    if (n <= 1)
        return n;

#ifdef debug
    for (string x : a) cout << x << " ";
    EL;
#endif

    stack<dta> st;
    st.push({0, n - 1, 0, 0});
    while (!st.empty()) {
        dta u = st.top();
        st.pop();

        int l = u.l, r = u.r;
        if (l >= r)
            return true;

        // recover state of 2 strings
        string sl = a[l];
        if (u.lshift < 0) {
            shift_left(sl);
        } else if (u.lshift > 0) {
            receive_left(sl, e(a[l - 1]));
        }

        string sr = a[r];
        if (u.rshift < 0) {
            shift_right(sr);
        } else if (u.rshift > 0) {
            receive_right(sr, a[r + 1][0]);
        }

#ifdef debug
        EL;
        printf("%d %d %d %d\n", l, r, u.lshift, u.rshift);
        cout << l << " : " << sl << endl;
        cout << r << " : " << sr << endl;
#endif

        if (l == r - 1) {
            if (sl == sr)
                return true;
        }

        int szl = sz(sl), szr = sz(sr);
        if (abs(szl - szr) > 2)
            continue;

        if (szl == szr) {
            if (sl == sr) {
                st.push({l + 1, r - 1, 0, 0});
            }
            if (l == r - 1)
                continue;

            // both receive
            string ssl = sl;
            string ssr = sr;
            receive_right(ssl, a[l + 1][0]);
            receive_left(ssr, e(a[r - 1]));
            if (ssl == ssr) {
                st.push({l + 1, r - 1, -1, -1});
            }

            // both shift
            shift_right(sl);
            shift_left(sr);
            if (sl == sr) {
                st.push({l + 1, r - 1, 1, 1});
            }
            continue;
        }

        if (szl - 1 == szr + 1) {
            shift_right(sl);
            receive_left(sr, e(a[r - 1]));
            if (sl == sr) {
                st.push({l + 1, r - 1, 1, -1});
            }
            continue;
        }

        if (szl + 1 == szr - 1) {
            receive_right(sl, a[l + 1][0]);
            shift_left(sr);
            if (sl == sr) {
                st.push({l + 1, r - 1, -1, 1});
            }
            continue;
        }

        if (szl - 1 == szr) {
            if (l == r - 1)
                continue;
            // left shift
            string ssl = sl;
            shift_right(ssl);
            if (ssl == sr) {
                st.push({l + 1, r - 1, 1, 0});
            }
            // right receive
            string ssr = sr;
            receive_left(ssr, e(a[r - 1]));
            if (sl == ssr) {
                st.push({l + 1, r - 1, 0, -1});
            }
            continue;
        }

        if (szl + 1 == szr) {
            if (l == r - 1)
                continue;
            // left receive
            string ssl = sl;
            receive_right(ssl, a[l + 1][0]);
            if (ssl == sr) {
                st.push({l + 1, r - 1, -1, 0});
            }
            // right shift
            shift_left(sr);
            if (sl == sr) {
                st.push({l + 1, r - 1, 0, 1});
            }
            continue;
        }
    }
    return false;
}

#ifdef debug
int main() {
    // cout << obtainPalindromicArray(
    //     vector<string>({"aa", "bab", "cde", "aba", "ab"}));
    // cout << obtainPalindromicArray(
    //     vector<string>({"ab", "aabba", "bb", "aba"}));

    EL;
    return 0;
}
#endif
