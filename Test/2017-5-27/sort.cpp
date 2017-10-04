//!@#$#%@$^()*(%^@%$!@$#^%^&&^*^#)!?!!@$@?$@$!%$
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
int c[300003],len=0,c_mid=0,ans=0,tot=0,lst,rst;
struct lnk_t{
    lnk_t *last,*next;
    int s;
}q[300003],*head,*tail;
void erfen(){
    //up
    int l=1,r=k,mid=k>>1;
    while(r-l>1){
        if(c[mid]<tail->s)l=mid,mid=(l+r)>>1;
        else/*if(c[mid]>tail->s)*/r=mid,mid=(l+r)>>1;
    }
    rst=l;
    //down
    l=1,r=k,mid=k>>1;
    while(r-l>1){
        if(c[mid]>head->s)r=mid,mid=(l+r)>>1;
        else/*if(c[mid]>tail->s)*/l=mid,mid=(l+r)>>1;
    }
    lst=r;
}
void ins(int s,int f){
    if(len==0){
        q[++len].s=s;
        head=tail=&q[len];
        return;
    }
    if(!f){
        lnk_t *now=head;
        while(now->s<s && now->s!=0){
            now=now->next;
            ans++;
        }
        len++;
        if(now->last)now->last->next=&q[len];
        q[len].next=now,q[len].s=s;
        q[len].last=now->last,now->last=&q[len];
        if(s<=head->s)head=&q[len];
    }
    else{
        lnk_t *now=tail;
        while(now->s>s && now->s!=0){
            now=now->last;
            ans++;
        }
        len++;
        if(now->next)now->next->last=&q[len];
        q[len].last=now,q[len].s=s;
        q[len].next=now->next,now->next=&q[len];
        if(s>=tail->s)tail=&q[len];
    }
}
void inse(){
    c_mid=(lst+rst)>>1;
    for(int l=c_mid;l>=lst;l--){
        ans=0;
        ins(c[l],0);
        tot+=ans;
        //printf("%d:%d\n",c[l],ans);
    }
    for(int l=c_mid+1;l<=rst;l++){
        ans=0;
        ins(c[l],1);
        tot+=ans;
        //printf("%d:%d\n",c[l],ans);
    }
    printf("%d\n",tot);
    for(int l=lst-1;l>=1;l--)ins(c[l],0);
    for(int l=rst+1;l<=k;l++)ins(c[l],1);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        tot=0;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&c[j]);
        }
        sort(c+1,c+1+k);
        if(len)
            erfen();
        else
            lst=1,rst=k;
        //printf("%d-%d\n",lst,rst);
        inse();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}