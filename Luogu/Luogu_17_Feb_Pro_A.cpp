#include<cstdio>//Divide into Blocks
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#define INF 1000000010
#define N4 800010
#define N 200010
using namespace std;
struct dan{
    int r;
    int flag;//1->zeng,0->jian.
    dan(int r=-1,int f=-1){
        this->r=r;
        this->flag=f;
    }
};
dan q[N];
int n,m,a[N]={0};
void build(){
    int l=1,r=1,tag=-1;//1->zeng,0->jian.
    if(a[2]>=a[1])tag=1,l=1,r=2;
    else tag=0,l=1,r=2;
    for(int i=3;i<n;i++){
        if(a[i]<a[i-1]){//jian
            if(tag==1){
                q[l].r=r,q[l].flag=tag;
                
                tag=0;
                l=r,r=i;
            }
            else{
                r++;
            }
        }
        else if(a[i]>=a[i-1]){//zeng
            if(tag==0){
                q[l].r=r,q[l].flag=tag;
                
                tag=1;
                l=r,r=i;
            }
            else{
                r++;
            }
        }
    }
    if(a[n]<a[n-1]){
        if(tag==1){
            q[l].r=r,q[l].flag=tag;
            
            l=r,r=n;tag=0;
            q[l].r=r,q[l].flag=tag;
            
        }
        else{
            r++;
            q[l].r=r,q[l].flag=tag;
            
        }
    }
    else if(a[n]>=a[n-1]){
        if(tag==0){
            q[l].r=r,q[l].flag=tag;
            
            l=r,r=n;tag=1;
            q[l].r=r,q[l].flag=tag;
            
        }
        else{
            r++;
            q[l].r=r,q[l].flag=tag;
            
        }
    }
}
int work(int x){
    int now=0,ans=0;
    for(int i=1;i<=n;i++){
        if(q[i].flag==1){//zeng
            if(a[q[i].r]>=x){
                if(now==0){
                    now=1,ans++;
                    i=q[i].r;
                }
                else i=q[i].r;
            }
            else if(a[q[i].r]<x){
                i=q[i].r;
            }
        }
        else if(q[i].flag==0){//jian
            if(a[q[i].r]<x && a[i]>=x){
                if(now==0)ans++;
                else i=q[i].r;
            }
            else if(a[q[i].r]>=x){
                if(now==0){
                    now=1,ans++;
                }
                else i=q[i].r;
            }
            else if(a[q[i].r]<x){
                if(now==1){
                    now=0;
                }
                else i=q[i].r;
            }
        }
    }
    return ans;
}
void debug_out(){
    int tot=0;
    int i=1;
    while(i<n){
        printf("%d:[%d->%d|%d]\n",++tot,i,q[i].r,q[i].flag);
        //i=q[i].r;
        i++;
    }
}
void change(int x,int s){
    a[x]=s;
    int nl,nr;
    for(int i=x-1;i>=1;i--){
        if(q[i].r!=-1){
            nl=i,nr=q[i].r;
            break;
        }
    }
    int l,r,tag;
    if(a[nl+1]>=a[nl])tag=1,l=nl+1,r=nl;
    else tag=0,l=nl+1,r=nl;
    for(int i=nl+1;i<=nr;i++){
        if(a[i]<a[i-1]){//jian
            if(tag==1){
                q[l].r=r,q[l].flag=tag;           
                tag=0;
                l=r,r=i;
            }
            else{
                r++;
            }
        }
        else if(a[i]>=a[i-1]){//zeng
            if(tag==0){
                q[l].r=r,q[l].flag=tag;               
                tag=1;
                l=r,r=i;
            }
            else{
                r++;
            }
        }
    }
    if(a[nl+1]<a[nl]){
        if(tag==1){
            q[l].r=r,q[l].flag=tag;            
            l=r,r=nl+1;tag=0;
            q[l].r=r,q[l].flag=tag;
        }
        else{
            r++;
            q[l].r=r,q[l].flag=tag;            
        }
    }
    else if(a[nl+1]>=a[nl]){
        if(tag==0){
            q[l].r=r,q[l].flag=tag;           
            l=r,r=nl+1;tag=1;
            q[l].r=r,q[l].flag=tag;            
        }
        else{
            r++;
            q[l].r=r,q[l].flag=tag;          
        }
    }
}
int init(){
    //q[0].l=0,q[0].r=0,q[0].flag=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build();
    debug_out();
    for(int i=1;i<=m;i++){
        int command,x,y;
        scanf("%d",&command);
        if(command==1){
            scanf("%d",&x);
            printf("%d\n",work(x));
        }
        else if(command==2){
            scanf("%d%d",&x,&y);
            change(x,y);
            debug_out();
        }
    }
}
int main(){
    init();
    system("pause");
    return 0;
}