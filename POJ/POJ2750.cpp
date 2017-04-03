//当之无愧的神题，环状线段树+DP//WA
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100010,M=100010;int n,m,top=0;
struct segtree_t{
    int l,r;
    int tots,maxs,mins,
    segtree_t *lc,*rc,*fa;
}seg[N<<2],*index[N];
