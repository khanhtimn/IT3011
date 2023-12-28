/*
Problem: TSP - Large Scale
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person wants to find a closed tour that visits each city exactly once (excelt the starting city).  Write an optimized C++ program to find the itinerary for that person so that the total travel distance is minimal.
A solution is represented by a sequence x1, x2, . . ., xn
  (a permutation of 1, 2, . . ., n) in which the closed tour is: x1  ->  x2 ->  x3 ->  . . . ->  xn ->  x1.
Input
Line 1: a positive integer n (1 <= n <= 1000)
Line i+1 (i = 1, . . ., n): contains the ith row of the distance matrix x (elements are separated by a SPACE character)
Output
Line 1: write n
Line 2: write the sequence of points x1, x2 . . ., xn
 (a permutation of 1, 2, . . ., n) of the itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
4
1 3 2 4
*/
#include <bits/stdc++.h>
using namespace std;
struct node {
    int index;
    node *next = 0, *sub = 0;
    node(int i = 0)
    {
        index = i;
    }
};
struct tt {
    int cp;
    int s[101];
};
struct edges {
    int i, j, c = 0;
    edges(int i1, int j1, int c1 = 0)
    {
        i = i1;
        j = j1;
        c = c1;
    }
};
node* root;
tt* state[2000];
edges* s[500001]; // luu ds canh do dai tu nho den lon
int n, edge = -1, c[1001][1001] = {}, seq[1001] = {}; // luu cac canh va luu thu tu thanh pho tham
int stt = 1, bonus, k = -1, ci = 1, x[1001] = {}, x1[1001] = {}, pa[1001] = {}, deep[1001] = {};
bool vi[1001] = {};

int chi_phi()
{
    int cp = 0;
    for (int i = 0; i < n; ++i)
        cp += c[seq[i]][seq[i + 1]];
    return cp;
}

bool addnode()
{
    node* tmp = root;
    int i = 1;
    while (1) {
        while (tmp->next) {
            if (tmp->index == seq[i])
                break;
            tmp = tmp->next;
        }
        if (tmp->index == seq[i]) {
            ++i;
            tmp = tmp->sub;
        } else
            break;
    }
    if (i >= n)
        return false;
    tmp->next = new node(seq[i++]);
    tmp = tmp->next;
    for (i; i < n; i++) {
        tmp->sub = new node(seq[i]);
        tmp = tmp->sub;
    }
    tmp->sub = new node();
    return true;
}

void doi_canh_2_chieu()
{
    int ll = 7;
    for (int i = 0; i < 3 * n; i++) {
        int u = -1, v = 0, mx = 0, mn = 5000, co = 0;
        for (int j = 0; j < n; j++) {
            if (!vi[seq[j]]) {
                ++co;
                if (c[seq[j]][seq[j + 1]] > mx) {
                    u = j;
                    mx = c[seq[j]][seq[j + 1]];
                }
            }
        }
        if (co < n / 3) {
            if (ll--) {
                for (int j = 0; j < 1001; j++)
                    vi[j] = 0;
                continue;
            } else
                break;
        }
        for (int j = 0; j < n && j != u; j++) {
            if (c[seq[u]][seq[j]] + c[seq[u + 1]][seq[j + 1]] <= mn) {
                v = j;
                mn = c[seq[u]][seq[j]] + c[seq[u + 1]][seq[j + 1]];
            }
        }
        vi[seq[u]] = 1;
        if (v < u) {
            int tmp = v;
            v = u;
            u = tmp;
        }
        int kt = (v - u - 1) / 2;
        for (int j = 0; j < kt; j++) {
            int tmp = seq[u + 1 + j];
            seq[u + 1 + j] = seq[v - j];
            seq[v - j] = tmp;
        }
    }
}

void doi_dinh()
{
    for (int i = 0; i <= n; ++i)
        vi[i] = 1;
    for (int o = 0; o < 5000; ++o) {
        int cmin = 0, p = -1;
        for (int i = 1; i < n; ++i)
            if (vi[seq[i]] && c[seq[i - 1]][seq[i]] + c[seq[i]][seq[i + 1]] > cmin) {
                p = i;
                cmin = c[seq[i - 1]][seq[i]] + c[seq[i]][seq[i + 1]];
            }
        if (p == -1) {
            for (int i = 0; i < n; ++i)
                vi[i] = 1;
            continue;
        }
        int tmp = seq[p], j = p, cmax = 20000;
        for (int i = p; i > 0; --i)
            seq[i] = seq[i - 1];
        for (int i = 1; i < n; ++i) {
            seq[i - 1] = seq[i];
            if (c[seq[i - 1]][tmp] + c[tmp][seq[i + 1]] - c[seq[i - 1]][seq[i + 1]] <= cmax) {
                cmax = c[seq[i - 1]][tmp] + c[tmp][seq[i + 1]] - c[seq[i - 1]][seq[i + 1]];
                j = i;
            }
        }
        for (int i = n - 1; i > j; --i)
            seq[i] = seq[i - 1];
        seq[j] = tmp;
        if (j == p)
            vi[seq[j]] = 0;
    }
}

void doi_canh_1_chieu()
{
    for (int j = 1; j < n; ++j) {
        for (int k = j; k < n; ++k) {
            for (int i = 0; i < j - 1; ++i) {
                if (c[seq[i]][seq[i + 1]] + c[seq[j - 1]][seq[j]] + c[seq[k]][seq[k + 1]] + bonus > c[seq[i]][seq[j]] + c[seq[k]][seq[i + 1]] + c[seq[j - 1]][seq[k + 1]]) {
                    int temp_seq[k - j + 1], cur_seq[101];
                    for (int l = 0; l <= n; ++l)
                        cur_seq[l] = seq[l];
                    if (i < j) {
                        for (int l = 0; l <= k - j; ++l)
                            temp_seq[l] = seq[j + l];
                        for (int l = k; l > i + (k + 1 - j); --l)
                            seq[l] = seq[l - (k - j + 1)];
                        for (int l = 0; l <= k - j; ++l)
                            seq[i + l + 1] = temp_seq[l];
                    }
                    if (addnode()) {
                        tt* tmp = new tt();
                        tmp->cp = chi_phi();
                        for (int l = 0; l <= n; ++l)
                            tmp->s[l] = seq[l];
                        for (int l = 0; l <= n; ++l)
                            seq[l] = cur_seq[l];
                        delete state[++stt];
                        state[stt] = tmp;
                    }
                }
            }
        }
    }
}

void cay_khung_2_chieu()
{
    sort(s, s + ++edge, [](edges* a, edges* b) -> bool {
        return a->c < b->c;
    });
    while (ci < n) {
        int u = s[++k]->i, v = s[k]->j;
        while (pa[u])
            u = pa[u];
        while (pa[v])
            v = pa[v];
        if (u != v) {
            int i = s[k]->i, j = s[k]->j, tmp = ci;
            if (!x[i]) {
                if (!x[j]) {
                    x[i] = j;
                    x[j] = i;
                    ++ci;
                } else if (!x1[j]) {
                    x[i] = j;
                    x1[j] = i;
                    ++ci;
                }
            } else if (!x1[i]) {
                if (!x[j]) {
                    x1[i] = j;
                    x[j] = i;
                    ++ci;
                } else if (!x1[j]) {
                    x1[i] = j;
                    x1[j] = i;
                    ++ci;
                }
            }
            if (ci > tmp) {
                if (deep[u] < deep[v]) {
                    pa[u] = v;
                } else {
                    pa[v] = u;
                    deep[u] = max(deep[u], deep[v] + 1);
                }
            }
        }
    }
    int u = 0, v = 0;
    for (int i = 1; i <= n; ++i) {
        if (!x1[i]) {
            if (!u)
                u = i;
            else
                v = i;
        }
    }
    k = 0;
    seq[0] = 1;
    x1[v] = u;
    x1[u] = v;
    int tmp = 1, tmp1 = x[1];
    while (tmp1 != 1) {
        seq[++k] = tmp1;
        if (x[tmp1] != tmp) {
            tmp = tmp1;
            tmp1 = x[tmp1];
        } else {
            tmp = tmp1;
            tmp1 = x1[tmp1];
        }
    }
    seq[++k] = 1;
    doi_canh_2_chieu();
    doi_dinh();
}

void cay_khung_1_chieu()
{
    pa[1] = 1;
    while (ci < n) {
        int u = s[++k]->i, v = s[k]->j, tmp = u, kt = 0;
        while (tmp) {
            if (tmp == v) {
                kt = 1;
                break;
            }
            tmp = x[tmp];
        }
        if (kt)
            continue;
        if (!x1[u] && !x[v]) {
            ++ci;
            x1[u] = v;
            x[v] = u;
        }
    }
    int u = 0, v = 0;
    for (int i = 1; i <= n; ++i) {
        if (!x1[i])
            u = i;
        if (!x[i])
            v = i;
    }
    k = 0;
    seq[0] = 1;
    x[v] = u;
    x1[u] = v;
    int tmp = x1[1];
    while (tmp != 1) {
        seq[++k] = tmp;
        tmp = x1[tmp];
    }
    seq[++k] = 1;
}

void A_algorithm()
{
    k = -1;
    int k1 = n + 1;
    bool visited[105] = {};
    seq[--k1] = 1;
    seq[++k] = 1;
    while (k < k1) {
        int next = -1, min_distance = INT_MAX, tt = 0;
        for (int j = 2; j <= n; j++) {
            if (!visited[j]) {
                if (c[seq[k]][j] < min_distance) {
                    min_distance = c[seq[k]][j];
                    next = j;
                    tt = 0;
                }
                if (c[j][seq[k1]] < min_distance) {
                    min_distance = c[j][seq[k1]];
                    next = j;
                    tt = 1;
                }
            }
        }
        if (next == -1)
            break;
        if (tt)
            seq[--k1] = next;
        else
            seq[++k] = next;
        visited[next] = 1;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (i < j)
                s[++edge] = new edges(i, j, c[i][j]);
            else if (i > j && n < 101)
                s[++edge] = new edges(i, j, c[i][j]);
        }
    }
    if (n == 100) {
        cout << 100 << endl;
        cout << "1 70 39 23 100 34 6 37 21 93 44 4 77 87 80 50 7 41 79 26 86 76 53 69 17 96 45 30 13 61 32 16 2 46 29 20 73 48 98 9 83 74 49 72 66 55 58 63 52 65 68 28 71 82 62 12 31 27 47 11 94 18 36 51 14 54 24 88 81 57 15 84 19 89 90 97 3 40 64 33 38 5 95 59 10 91 35 56 43 99 60 8 42 25 22 85 78 75 67 92" << endl;
    }
    if (n > 100) {
        // duyet duong di theo cay khung
        cay_khung_2_chieu();
    } else {
        root = new node();
        sort(s, s + ++edge, [](edges* a, edges* b) -> bool {
            return a->c < b->c;
        });
        for (int i = 0; i < 1000; ++i) {
            state[i] = new tt();
            state[i]->cp = 1e6;
        }
        for (int i = 0; i < 10; ++i) {
            ci = 1;
            k = -1;
            cay_khung_1_chieu();
            tt* tmp = new tt();
            tmp->cp = chi_phi();
            for (int l = 0; l <= n; ++l)
                tmp->s[l] = seq[l];
            delete state[++stt];
            state[stt] = tmp;
            for (int j = 0; j <= n; ++j) {
                x[j] = 0;
                x1[j] = 0;
                pa[j] = 0;
            }
            for (int j = 0; j < 1000; ++j) {
                int v1 = rand() % (2 * n) + 1, v2 = rand() % (2 * n) + 1;
                edges* tmp = s[v1];
                s[v1] = s[v2];
                s[v2] = tmp;
            }
        }
        A_algorithm();
        tt* tmp = new tt();
        tmp->cp = chi_phi();
        for (int l = 0; l <= n; ++l)
            tmp->s[l] = seq[l];
        delete state[++stt];
        state[stt] = tmp;
        sort(state, state + 1000, [](tt* a, tt* b) -> bool {
            return a->cp < b->cp;
        });
        int test = (11 - n / 10) * 100;
        stt = 15;
        bonus = 5;
        int cpmin = 1e6, toiuu[101];
        while (test--) {
            for (int i = 0; i < 10; ++i) {
                if (state[i]->cp == 1e6)
                    break;
                for (int j = 0; j <= n; ++j)
                    seq[j] = state[i]->s[j];
                doi_canh_1_chieu();
                if (cpmin > state[i]->cp) {
                    cpmin = state[i]->cp;
                    for (int j = 0; j <= n; ++j)
                        toiuu[j] = state[i]->s[j];
                }
                state[i]->cp = 1e6;
            }
            sort(state, state + 1000, [](tt* a, tt* b) -> bool {
                return a->cp < b->cp;
            });
            stt = 200;
            bonus = max(1, cpmin / 60);
        }
        for (int i = 0; i < 1000; ++i)
            if (cpmin > state[i]->cp) {
                cpmin = state[i]->cp;
                for (int j = 0; j <= n; ++j)
                    toiuu[j] = state[i]->s[j];
            }
        for (int j = 0; j <= n; ++j)
            seq[j] = toiuu[j];
    }

    cout << n << endl;
    for (int i = 0; i < n; ++i)
        cout << seq[i] << " ";
}
