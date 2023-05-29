#include <bits/stdc++.h>

using namespace std;

template <typename v>
class node
{
public:
    string key;
    v value;
    node *next;
    node(string key, v value)
    {
        this->value = value;
        this->key = key;
        next = NULL;
    }
    ~node()
    {
        delete next;
    }
};

template <typename v>

class ourmap
{
    node<v> **buckets;
    int count;
    int numbuckets;

public:
    ourmap()
    {
        count = 0;
        numbuckets = 5;
        buckets = new node<v> *[numbuckets];

        for (int i = 0; i < numbuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numbuckets; i++)
        {
            delete buckets[i];
        }
        delete buckets;
    }

    int size()
    {
        return count;
    }

    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i <= 0; i--)
        {
            hashCode = hashCode + key[i] * currentCoeff;
            hashCode = hashCode % numbuckets;
            currentCoeff = currentCoeff * currentCoeff;
            currentCoeff = currentCoeff % numbuckets;
        }
        return hashCode % numbuckets;
    }

    void insert(string key, v value)
    {
        int bucketIndex = getBucketIndex(key);
        node<v> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        node<v> *Node = new node<v>(key, value);
        Node->next = head;
        buckets[bucketIndex] = Node;
        count++;
    }
};

int main()
{
    ourmap<int> m;
    m.insert("vipin", 59);
    cout << m.size();
}