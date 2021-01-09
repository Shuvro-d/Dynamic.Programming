#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
int check[10000];
stack<int>s;             //this stack is used to save the sum combination.
vector<int>save;         // this vector is used to save the smallest combination.
bool flag=false;
bool bestsum(int n,int m,int a[])
{
    if(n==0)
    {
        //cout<<"Hurrah"<<endl;
        flag=true;
        stack<int>s2;       //this stack s2 helps to copy the values of s into the vector.
        vector<int>vec;
        s2=s;
        while(s2.size()>0)       //if stack s has smaller combination than vector then 
        {                            // we replace the values of vector with stack's value
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
            bestsum(r,m,a);
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
    bestsum(n,m,a);
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

