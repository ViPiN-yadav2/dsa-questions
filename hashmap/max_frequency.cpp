#include <bits/stdc++.h>

using namespace std;

void solve(int *a, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]] = m[a[i]] + 1;
    }
    int max = m[a[0]];
    int num = a[0];
    for (int i = 1; i < m.size(); i++)
    {
        if (max < m[a[i]])
        {
            max = m[a[i]];
            num = a[i];
        }
    }
    cout << num;
}

int main()
{
    int a[] = {2, 12, 2, 11, 12, 2, 1, 2, 2, 11, 12, 2, 6};
    solve(a, 13);
    return 0;
}