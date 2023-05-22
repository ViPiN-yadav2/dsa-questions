#include <iostream>

using namespace std;
void solve(int n,char a,char b, char c)
{
    if(n==1)
    {
        cout<<"moving 1 from "<<a<<" to "<<c<<endl;
        return;
    }
    solve(n-1,a,c,b);
    cout<<"moving "<<n<<" from "<<a<<" to "<<c<<endl;
    solve(n-1,b,a,c);
    return;
}

int main()
{
    solve(4,'s','h','d');
    return 0;
}
