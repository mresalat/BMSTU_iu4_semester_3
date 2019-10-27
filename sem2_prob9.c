#include<bits/stdc++.h>
using namespace std;

int main(){
    system("color f0");
    ofstream filee;
    char path[16]="Graph.dot";
    filee.open(path, ios_base::trunc);

    cout<<"1-Directed\n2-Undirected \n\n";
    string G;
    cin>>G;

    if(G=="1"){
        filee<<"digraph G{\n";
    }
    else if(G=="2"){
        filee<<"graph G{\n";
    }
    cout<<"Number of vertices:";
    int V=0;
    cin>>V;
    int vertices[V+1][V+1];
    for(int i=0;i<V+1;i++){
        for(int l=0; l<V+1; l++){
            vertices[i][l]=0;
            if(i==0)
                vertices[i][l]=l;
            if(l==0)
                vertices[i][l]=i;
        }
    }
    cout<<"\nDirected graphs \"->\"\nUndirected Graphs \"--\"\nFinishing input\"-0\"\n\n";
    cout<<"Graphs dependencies separated by line break:\n";

    char temp[100];
    strcpy(temp,"\0");
    string Check="-0\0";
    char c[2];
    int A=0, B=0;
    bool key=false;
    c[1]='\0';
    int R=0;
    c[0]=getchar();
    while (temp!=Check){
        c[0]=getchar();
        while (c[0]!='\n'){
            strcat(temp,c);
            if(isdigit(c[0]) && key==false){
                A=atoi(c);
                key=true;
            }
            else if (isdigit(c[0]) && key==true){
                B=atoi(c);
                if (vertices[A][B]==0)
                    vertices[A][B]=1;
                else
                    vertices[B][A]=1;
                A=B;
            }
            else if(c[0]=='-'){
                R++;
                c[0]=getchar();
                strcat(temp,c);
            }
            c[0]=getchar();
        }
        key=false;
        if (temp!=Check){
            filee<<temp<<";\n";
            strcpy(temp,"\0");
        }
        else
            break;
    }
    R--;

    for(int i=0; i<V+1; i++){
        cout<<i;
        for(int l=1; l<V+1; l++){
            if (i==0)
                cout<<" "<<l;
            else{
                cout<<" "<<vertices[i][l];
            }
        }
        cout<<"\n";
    }
    int flag=0, k=0;
    bool endd=false;
    for(int i=1; i<V+1; i++){
        flag=0;
        for(int l=i; l<V+1; l++){
            if (vertices[i][l]==1){
                flag++;
                if(i==l){
                    k++;
                    cout<<"Loop found => This graphs a non-simple graph\n";
                    endd=true;
                    printf("%d\n", k);
                    break;
                }
                else if(vertices[i][l]==vertices[l][i]){

                    cout<<"Multiple edges found => This is a non-simple graph\n";
                    endd=true;
                    break;
                }
            }
        }
        if (flag==0 && i!=V){
            cout<<"Gap found => This This is a non-simple graph\n";
            endd=true;
            break;
        }
        if (endd==true)
            break;
    }

    if(endd==false){
        if (R>=(V-1)*(V-2)/2)
            cout<<"This is a connected graph\n";
        else
            cout<<"This is a disconnected graph\n";
    }
    else
        cout<<"This cannot be checked by theorem, since it is a non-simple graph\n";

    filee<<"}";
    filee.close();

    system("Graphviz\\bin\\gvedit.exe Graph.dot");
}

