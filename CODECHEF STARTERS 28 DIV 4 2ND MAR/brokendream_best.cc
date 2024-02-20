#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;

class Solution {
public:
    string solve(string& s, int K) {
        int n = s.length();

        if (K == 1) {
            return s;
        }
        const int A = 26;
        vector<vector<int>> pos(A);
        for (int i = 0; i < n; ++i) {
            int x = s[i] - 'a';
            pos[x].push_back(i);
        }

        {
            int cnt = 0;
            for (auto& V : pos) {
                if (V.size() > 0) {
                    ++cnt;
                }
            }
            if (cnt <= K) {
                sort(s.begin(), s.end());
                return s;
            }
        }

        int rem = K;

        string res;
        int last = -1;
        vector<char> used(n, false);

        vector<int> seqs;
        seqs.push_back(-1);
        for (int i = 0; i < A && rem > 2; ++i) {
            auto& V = pos[i];
            if (V.empty()) {
                continue;
            }
            if (V[0] < seqs.back()) {
                int cnt = 0;
                int last = seqs.back();
                while (!V.empty() && V.back() > last) {
                    used[V.back()] = true;
                    seqs.push_back(V.back());
                    V.pop_back();
                    ++cnt;
                }
                if (cnt > 0) {
                    int sz = seqs.size();
                    reverse(seqs.begin() + sz - cnt, seqs.end());
                }
                --rem;
                if (rem == 2) {
                    break;
                }
            } 
            for (auto x : V) {
                seqs.push_back(x);
                used[x] = true;
            }
            V.clear();
        }


        for (int i = 0, last = -1; i < A; ++i) {
            if (pos[i].empty()) {
                continue;
            }
            auto& V = pos[i];
            for (auto x : V) {
                if (x > last) {
                    used[x] = true;
                    seqs.push_back(x);
                    // cout << x << " " << s[x] << endl;
                    last = x;
                }
            }
        }

        int mn = '~';
        for (int i = 0; i < n && mn == '~'; ++i) {
            if (!used[i]) {
                mn = s[i];

                for (int j = i + 1; j < n; ++j) {
                    if (!used[j] && s[j] != mn) {
                        if (s[j] < mn) {
                            --mn;
                        } else {
                        }
                        break;
                    }
                }
            }
        }
        while (!seqs.empty()) {
            int x = seqs.back();
            if (s[x] > mn) {
                used[x] = false;
                seqs.pop_back();
            } else {
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                used[i] = true;
                seqs.push_back(i);
            }
        }

        for (auto x : seqs) {
            if (x >= 0) {
                res += s[x];
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution sol;

    int t;
    cin >> t;
    while (t-- > 0) {
        int n, K;
        cin >> n >> K;
        string s;
        cin >> s;

        cout << sol.solve(s, K) << '\n';
    }

    return 0;
}