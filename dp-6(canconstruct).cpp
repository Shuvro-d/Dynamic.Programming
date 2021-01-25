#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
bool flag=false;
bool constructstring(string target,vector<string>v)
{
    if(target.size()==0)
    {
        flag=true;
        return true;
    }
    for(int i=0; i<v.size(); i++)
    {
        int found=target.find(v[i]);
        if(found==0)
        {
            string s;
            s=target;
            s.erase(0,v[i].size());
            if(constructstring(s,v)==true)return true;
        }
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        v.push_back(x);
    }
    constructstring(s,v);
    if(constructstring(s,v)==true)cout<<"Yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}

