#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 200010
#define MAXT (100 * MAXN)

#define lm ((l + r) >> 1)
#define rm (lm + 1)

static int N, Q, tr_tot, A[MAXN];
static int root[MAXN], lson[MAXT], rson[MAXT], size[MAXT];
static long long ans = 0;

void insert(int &n, int l, int r, int k, int d)
{
	if (!n) n = ++tr_tot;
	size[n] += d;
	if (l == r) return ;
	if (k <= lm)
		insert(lson[n], l, lm, k, d);
	else
		insert(rson[n], rm, r, k, d);
}

void modify(int p, int k, int d)
{
	for (int i = p; i <= N; i += i & (-i))
		insert(root[i], 1, N, k, d);
}

int query(int n, int l, int r, int k)
{
	if (l == r) return size[n];
	if (k <= lm)
		return query(lson[n], l, lm, k);
	else
		return query(rson[n], rm, r, k) + size[lson[n]];
}

int ask(int p, int k)
{
	int r = 0;
	for (int i = p; i; i -= i & (-i))
		r += query(root[i], 1, N, k);
	return r;
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) modify(i, A[i] = i, 1);
	while (Q--)
	{
		int l, r, k; scanf("%d%d", &l, &r);
		if (l != r)
		{
			ans += A[l] < A[r] ? 1 : -1;
			k = ask(r-1, A[r]) - ask(l, A[r]);
			ans += k - (r - l - k - 1);
			k = ask(r-1, A[l]) - ask(l, A[l]);
			ans -= k - (r - l - k - 1);
			modify(r, A[r], -1); modify(l, A[l], -1);
			k = A[l]; A[l] = A[r]; A[r] = k;
			modify(r, A[r], 1); modify(l, A[l], 1);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
