#include<iostream>
#include<vector>
using namespace std;

vector<int> arr[51];

int low[51],in[51],vis[51];

int timer,r;

void DFS(int node,int par){
    int nchild=0;
   vis[node]=1;
   in[node]=low[node]=timer;
   timer++;

   for(int child:arr[node]){

    if(child==par){
        continue;
    }
    if(vis[child]==1){

        low[node]=min(low[node],in[child]);

    }
    else{
        DFS(child ,node);
        low[node]=min(low[node],low[child]);
        if(low[child]>=in[node] && par!=-1){
                cout<<node<<endl;
                r++;//for counting
        }
        nchild++;

    }
   }
   if(par==-1 && nchild>1){
    cout<<node<<endl;
    r++;
   }
}
int main(){

    int n,m,x,y;

    cout<<"Enter number of vertex and number of edge"<<endl;
    cin>>n>>m;
    while(m--){
        cout<<"enter vertex having edge"<<endl;
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    DFS(0,-1);
    cout<<"Number of cut vertex =" <<r<<endl;

    return 0;


}
