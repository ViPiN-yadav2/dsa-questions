#include <bits/stdc++.h>

using namespace std;

template <typename t>

class treenode
{
public:
    t data;
    vector<treenode<t> *> children;
    treenode(t data)
    {
        this->data = data;
    }
};

treenode<int> *takeinputlevelwish()
{
    cout << "enter data for root" << endl;
    int rootdata;
    cin >> rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    queue<treenode<int> *> q;
    q.push(root);
    while (q.empty() == 0)
    {
        treenode<int> *front = q.front();
        q.pop();
        cout << "enter no. of children of" << front->data << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childdata;
            cout << "enter the " << i << " th child" << front->data << endl;
            cin >> childdata;
            treenode<int> *node = new treenode<int>(childdata);
            front->children.push_back(node);
            q.push(node);
        }
    }
    return root;
}

void solve(treenode<int> *root, int &largest, int &sec_largest)
{
    if (largest == 0)
    {
        largest = root->data;
    }

    if (root->data > largest)
    {
        sec_largest = largest;
        largest = root->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        solve(root->children[i], largest, sec_largest);
    }
}

int main()
{
    treenode<int> *root = takeinputlevelwish();
    int largest = 0;
    int sec_largest = 0;
    solve(root, largest, sec_largest);
    cout << sec_largest;
}