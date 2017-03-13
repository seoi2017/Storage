#include <algorithm>
#include <iostream> 
#include <cstdio> 
#include <string> 
#include <cstring> 
#include <cstdlib> 
#include <set> 
#include <stack> 
#include <queue> 
#include <cmath>
#include <iomanip>
#include <list>
using namespace std; 

const int MAXN=100;
int M,n;

struct Node{
	int to,dis;
	Node* next;
	Node():to(-1),dis(0),next(NULL){
	}
}a[MAXN+5];
int p[MAXN+5],l[MAXN+5],x[MAXN+5];
int t,v;
//debug
void OutMap(){
	Node* f;
	for(int i=0;i<=n;i++){
		cout<<"point"<<i;
		for(f=a[i].next;f!=NULL;f=f->next){
			cout<<"-"<<f->dis<<"->"<<f->to<<' ';
		}
		cout<<endl;
	}
}
void OutQueue(queue<int> q){
	cout<<"the queue is:";
	while(!q.empty()){
		cout<<q.front()<<' ';
		q.pop();
	}
	cout<<endl;
}




void Insert(int from,int to,int dis){
	Node* p=new Node;
	p->dis=dis;
	p->to=to;
	p->next=a[from].next;
	a[from].next=p;
}
int SPFA(int s,int e,int n){
	bool vis[MAXN+5];
	int ans[MAXN+5];
	memset(vis,0,sizeof(vis));
	memset(ans,0x3f3f3f3f,sizeof(ans));
	ans[s]=0;
	vis[s]=true;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int tmp=q.front();
cout<<"now the front of queue is "<<tmp<<endl<<endl;		
		for(Node* f=a[tmp].next;f!=NULL;f=f->next){
cout<<"now the f is pointing an edge from "<<tmp<<" to "<<f->to<<endl
	<<"the ans of "<<f->to<<" is "<<ans[f->to]
	<<"and throug tmp to "<<f->to<<" is "<<f->dis+ans[tmp]<<endl;
			if(f->dis+ans[tmp]<=ans[f->to]){
cout<<"the ans of "<<f->to<<" change as "<<ans[f->to]+ans[tmp]<<endl<<endl;
				ans[f->to]=f->dis+ans[tmp];
				if(!vis[f->to]){
					q.push(f->to);
cout<<"push "<<f->to<<" into the queue"<<endl;
					vis[f->to]=true;
					n--;
				}
			}
			else continue;
		}
		q.pop();vis[tmp]=false;
OutQueue(q);
	}
	return ans[e];
}
int main(){
	cin>>M>>n;
	cin>>p[1]>>l[1]>>x[1];
	Insert(0,1,p[1]);
	for(int j=1;j<=x[1];j++){
		cin>>t>>v;
		Insert(t,1,v);
	}
	for(int i=2;i<=n;i++){
		cin>>p[i]>>l[i]>>x[i];
		if(l[1]-l[i]>M) continue;
		else{
			Insert(0,i,p[i]);
			for(int j=1;j<=x[i];j++){
				cin>>t>>v;
				Insert(t,i,v);
			}	
		}
	}
//	OutMap();
	cout<<SPFA(0,1,n);
	system("pause");
	return 0;
}






