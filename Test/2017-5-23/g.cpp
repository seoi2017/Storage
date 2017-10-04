#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define p 10000009
using namespace std;
int x,y,z,ans=0,goal[303]={0},tgoal[303]={0};
string ign[23],txt,str,tstr;
void solve(){
    for(int i=1;i<=x;i++)
        cin>>ign[i];
    cin>>y;
    for(int i=1;i<=y;i++){
        cin>>txt;
        for(int j=0;j<txt.size();j++)
            txt[j]+=32;
        cin>>z;
        for(int j=1;j<=z;j++){
            cin>>tstr;
            for(int k=1;k<=x;k++)
                if(tstr==ign[k])
                    goto tag;
            str+=tstr;
            tag:;
        }
        //cout<<str<<endl;
        for(int i=0;i<str.size();i++){
            if(txt[0]==str[i])tgoal[0]=goal[0]+1;
            for(int j=1;j<txt.size();j++){
                tgoal[j]=goal[j];
                if(txt[j]==str[i]){
                    tgoal[j]=(goal[j]+goal[j-1])%p;
                    tgoal[j-1]-=goal[j-1];
                    goal[j-1]=0;
                }
            }
            for(int j=0;j<txt.size();j++){
                goal[j]=tgoal[j];
                cout<<goal[j]<<" ";
                tgoal[j]=0;
            }
            cout<<endl;
        }
        cout<<goal[txt.size()-1]<<endl;
        str.clear();
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("g.in","r",stdin);
    //freopen("g.out","w",stdout);
    ios::sync_with_stdio(false);
    while(cin>>x && x!=EOF){
        solve();
        memset(goal,0,sizeof(goal));
    }
    //printf("%d %d\n",'A','a');
    fclose(stdin);
    fclose(stdout);
    return 0;
}