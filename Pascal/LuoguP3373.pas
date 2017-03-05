program rrr(input,output);
type
  tree=record
     l,r,sum,mul,plus:longint;   //sum区间和，mul乘标记，plus加标记
  end;
var
  n,m,p,i,t,x,y,d:longint;
  a:array[0..400040]of tree;
  num:array[0..100010]of longint;
procedure build(k,l,r:longint);        //建树
var
  i,mid:longint;
begin
   a[k].l:=l;a[k].r:=r;a[k].mul:=1;a[k].plus:=0;
   if l=r then begin a[k].sum:=num[l];exit; end;
   i:=k<<1;mid:=(l+r)>>1;
   build(i,l,mid);
   build(i+1,mid+1,r);
   a[k].sum:=a[i].sum+a[i+1].sum;
end;
procedure pushdown(k:longint);   //标记下传
var
  i:longint;
begin
   if (a[k].mul=1) and (a[k].plus=0) then exit;
   if a[k].l=a[k].r then begin a[k].mul:=1;a[k].plus:=0;exit; end;
   i:=k<<1;
   a[i].sum:=(a[i].sum*a[k].mul+a[k].plus*(a[i].r-a[i].l+1)) mod p;
   a[i+1].sum:=(a[i+1].sum*a[k].mul+a[k].plus*(a[i+1].r-a[i+1].l+1)) mod p;
   a[i].mul:=a[i].mul*a[k].mul mod p;
   a[i].plus:=(a[i].plus*a[k].mul+a[k].plus) mod p;
   a[i+1].mul:=a[i+1].mul*a[k].mul mod p;
   a[i+1].plus:=(a[i+1].plus*a[k].mul+a[k].plus) mod p;
   a[k].mul:=1;a[k].plus:=0;
end;
procedure changemul(k:longint);   //乘法修改
var
  i,mid:longint;
begin
   pushdown(k);
   if (x<=a[k].l) and (a[k].r<=y) then
       begin
          a[k].sum:=a[k].sum*d mod p;
          a[k].mul:=d mod p;
          exit;
       end;
   mid:=(a[k].l+a[k].r)>>1;i:=k<<1;
   if x<=mid then changemul(i);
   if mid<y then changemul(i+1);
   a[k].sum:=(a[i].sum+a[i+1].sum) mod p;
end;
procedure changeplus(k:longint);   //加法修改
var
  i,mid:longint;
begin
   pushdown(k);
   if (x<=a[k].l) and (a[k].r<=y) then
       begin
          a[k].sum:=(a[k].sum+d*(a[k].r-a[k].l+1)) mod p;
          a[k].plus:=d mod p;
          exit;
       end;
   mid:=(a[k].l+a[k].r)>>1;i:=k<<1;
   if x<=mid then changeplus(i);
   if mid<y then changeplus(i+1);
   a[k].sum:=(a[i].sum+a[i+1].sum) mod p;
end;
function ask(k:longint):longint;   //询问
var
  i,mid:longint;
begin
   pushdown(k);
   if (x<=a[k].l) and (a[k].r<=y) then exit(a[k].sum);
   ask:=0;
   mid:=(a[k].l+a[k].r)>>1;i:=k<<1;
   if x<=mid then ask:=ask(i);
   if mid<y then ask:=ask+ask(i+1);
   exit(ask mod p);
end;
begin
   readln(n,m,p);
   for i:=1 to n do read(num[i]);
   build(1,1,n);
   for i:=1 to m do
       begin
          read(t,x,y);
          if t=1 then begin read(d);changemul(1); end;
          if t=2 then begin read(d);changeplus(1); end;
          if t=3 then writeln(ask(1));
       end;
end.