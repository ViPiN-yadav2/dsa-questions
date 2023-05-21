#include <iostream>
#include <vector>
#include <queue>

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

treenode<int> *takeinput()
{
    cout << "enter root data";
    cout << endl;
    int rootdata;
    cin >> rootdata;

    treenode<int> *root = new treenode<int>(rootdata);

    cout << "enter no. of children" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        treenode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

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

void print(treenode<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

void levelwishprint(treenode<int> *root)
{
    queue<treenode<int> *> q;
    q.push(root);
    cout << root->data << endl;
    while (q.empty() == 0)
    {
        treenode<int> *front = q.front();
        // cout << front->data << endl;
        q.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << endl;
            q.push(front->children[i]);
        }
    }
}

int main()
{
    // treenode<int> *root = new treenode<int>(1);
    // treenode<int> *node1 = new treenode<int>(2);
    // treenode<int> *node2 = new treenode<int>(3);

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // treenode<int> *root = takeinput();
    treenode<int> *root = takeinputlevelwish();

    levelwishprint(root);
}