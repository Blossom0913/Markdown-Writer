#include<iostream>
using namespace std;
int n,m,a[1005][1005];

// void add(int u,int v){
// 	edge[++top].to=v; //top表示第top条边，to表示第top条边的终点 
// 	edge[top].last=head[u]; //last表示第top条边的起点
// 	head[u]=top; //head数组记录每个点最后一次出现在第top条边
// }

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1; //根据题目可建反向边
        // add(x,y);
    }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<a[i][j];
		cout<<endl;
	}
    for(int i=1;i<=n;i++){
		cout<<i<<": ";
		for(int j=head[i];j;j=edge[j].last){ //从每个点的最后一条边往前推，所以是倒序输出的 
			int d=edge[j].to;
			cout<<d<<" ";
		}
		cout<<endl;
	}
	return 0;
}
