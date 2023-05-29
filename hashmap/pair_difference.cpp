//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int TotalPairs(vector<int> nums, int k)
    {
        // Code here
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
            mpp[nums[i]]++;

        int cnt = 0;

        for (auto it : mpp)

        {

            if (mpp.find(it.first - k) != mpp.end() && k != 0)
                cnt++;

            if (k == 0 && it.second > 1)
                cnt++;
        }

        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.TotalPairs(nums, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends