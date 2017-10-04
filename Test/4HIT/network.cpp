#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#define MOD 1000000007
using namespace std;
struct node_t{
    int dat/*,len*/;
    double len;
    node_t* nxt;
}p[600007],np[600007];//出边
int n,tp,tq,e[300007],top,ntop;
double s[300007],z[300007];
map<pair<int,int>,node_t*> ind,nind; 
void ExGCD(int a,int b,int d,int &x,int &y){//扩展欧几里德
    if(!b)d=a,x=1,y=0;
    else ExGCD(b,a%b,d,y,x),y-=x*(a/b);
}
inline int inv(int a,int b){//求模b意义下逆元
    int x,y,d;
    ExGCD(a,b,d,x,y);
    return (x%b+b)%b;
}
inline void add_edge(int x,int y,/*int*/double l){//From X to Y
    p[++top].dat=y,p[top].len=l;
    p[top].nxt=p[x].nxt,p[x].nxt=&p[top];
}
inline void add_nedge(int x,int y,/*int*/double l){//From Y to X
    np[++ntop].dat=y,np[ntop].len=l;
    np[ntop].nxt=np[x].nxt,np[x].nxt=&np[ntop];
}
inline void solve(){
    for(int i=1;i<=n;i++){
        for(node_t* k=p[i].nxt;k!=NULL;k=k->nxt){//i的出边
            s[k->dat]-=(k->len*s[i]);
            if(ind.find(make_pair(k->dat,i))!=ind.end())
               z[k->dat]-=(ind[make_pair(k->dat,i)]->len*k->len);
            for(node_t* l=np[i].nxt;l!=NULL;l=l->nxt){//i的入边
                if(l->dat==k->dat)continue;
                if(ind.find(make_pair(l->dat,k->dat))==ind.end()){
                    add_edge(l->dat,k->dat,-1*(l->len*k->len));
                    add_nedge(k->dat,l->dat,-1*(l->len*k->len));
                    ind[make_pair(l->dat,k->dat)]=&p[top];
                    nind[make_pair(l->dat,k->dat)]=&np[ntop];
                }
                else{
                    ind[make_pair(l->dat,k->dat)]->len-=(l->len*k->len);
                    nind[make_pair(l->dat,k->dat)]->len-=(l->len*k->len);
                }
                
            }
            ind.erase(make_pair(i,k->dat));
            nind.erase(make_pair(i,k->dat));
        }
    }
}
int main(){
    scanf("%d",&n);
    top=n;
    for(int i=1;i<=n;i++)
        scanf("%d",&e[i]),z[i]=1.0; 
    for(int i=1;i<=n;i++){
        scanf("%d%d",&tp,&tq);
        add_edge(i,e[i],/*-1*tp*inv(tq,MOD)*/(double)-1*tp/tq);
        add_nedge(e[i],i,/*-1*tp*inv(tq,MOD)*/(double)-1*tp/tq);
        ind[make_pair(i,e[i])]=&p[top];
        nind[make_pair(i,e[i])]=&np[ntop];
    }
    for(int i=1;i<=n;i++)
        scanf("%lf",&s[i]);
    solve();
    for(int i=1;i<=n;i++)
        printf("%.3lf\n",s[i]/z[i]);
    system("pause");
    return 0;
}