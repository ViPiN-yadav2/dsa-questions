#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 9, 8, 7, 6};

    unordered_map<int, bool> m;

    for (int i = 0; i < 7; i++)
    {
        m[arr[i]] = true;
    }

    int len = 0;

    for (int i = 0; i < 7; i++)
    {
        if (m.at(arr[i]) == false)
            continue;
        cout << arr[i] << endl;
        int temp_len = 1;
        int j = 1;
        int k = 1;
        int temp = arr[i];
        while (1)
        {
            int less = temp - k;
            int great = temp + j;
            if (m.count(great) > 0)
            {
                j++;
                temp_len++;
                cout << "this is great" << great << endl;
                m[great] = false;
            }
            if (m.count(less) > 0)
            {
                k++;
                temp_len++;
                m[less] = false;
                cout << "this is less" << less << endl;
            }
            if (m.count(less) == 0 && m.count(great) == 0)
                break;
        }
        m[arr[i]] = false;
        if (len <= temp_len)
        {
            len = temp_len;
        }
    }

    cout << len;
}