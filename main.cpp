#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll n, m;
vvl adj;
vl ord;
vl ans;

void Solve() {
  auto visit = vb(n + 1, false);
  auto q = queue<ll>{};
  for (auto i = 1; i <= n; ++i) {
    if (0 == ord[i]) {
      q.push(i);
      visit[i] = true;
    }
  }

  while (!q.empty()) {
    auto f = q.front();
    q.pop();

    ans.push_back(f);

    for (const auto& y : adj[f]) {
      if (visit[y]) {
        continue;
      }

      --ord[y];
      if (0 == ord[y]) {
        q.push(y);
        visit[y] = true;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;

  adj = vvl(n + 1, vl{});
  ord = vl(n + 1, 0);

  while (0 < (m--)) {
    ll k;
    cin >> k;

    auto bf = 0LL;
    while (0 < (k--)) {
      ll x;
      cin >> x;

      if (0 < bf) {
        ++ord[x];
        adj[bf].push_back(x);
      }

      bf = x;
    }
  }

  ans = vl{};
  ans.reserve(n);
  Solve();

  if (n == ans.size()) {
    for (const auto& x : ans) {
      cout << x << '\n';
    }
    return 0;
  }

  cout << 0;

  return 0;
}