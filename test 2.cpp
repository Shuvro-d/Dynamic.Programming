#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int check[10000];
stack<int>s;
vector<int>save;
bool flag=false;
bool howsum(int n,int m,int a[])
{
    if(n==0)
    {
        cout<<"Hurrah"<<endl;
        flag=true;
        stack<int>s2;
        vector<int>vec;
        s2=s;
        while(s2.size()>0)
        {
            int x=s2.top();
            vec.push_back(x);
            s2.pop();
        }
         if(save.size()>0 and vec.size()<save.size()){
            save=vec;
            vec.clear();
         }
         if(save.size()==0){
            save=vec;
             vec.clear();
         }
         s.pop();
        return true;
    }

    for(int i=0; i<m; i++)
    {
        int r=n-a[i];
        if(r>=0)
        {
            s.push(a[i]);
            howsum(r,m,a);
        }
    }
    s.pop();
    return false;
}

//driver code
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
    howsum(n,m,a);
    if(flag==true)
    {
        cout<<"yes"<<endl;
        for(int i=0;i<save.size();i++){
            cout<<save[i]<<endl;
        }
    }
    else
        cout<<"no ans"<<endl;
    return 0;
}

