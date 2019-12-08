#include<bits/stdc++.h>
using namespace std;
int main(){
    system("color f0");
    cout<<"Number of vertices: ";
    int n;
    cin>>n;
    int degree[n+1];
    memset(degree ,0,sizeof degree);
    cout<<"Number of edges: ";
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        degree[a]++;
        degree[b]++;
    }
    vector<pair<int,int> >v;
    for(int i=1;i<=n;i++){
        if(degree[i]%2==1)v.push_back(make_pair(degree[i],i));
    }
    sort(v.begin(),v.end());
    cout<<"vertices having odd degree(vertices->degree): "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].second<<"->"<<v[i].first<<endl;
    }
}
