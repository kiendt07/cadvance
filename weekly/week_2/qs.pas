procedure qs(l,h: integer); inline;
  var temp,pi1,pi2,i,j,k: integer;
  begin
    if l>=h then exit;
    i:=l; j:=h;
    k:=random(h-l+1)+l;
    pi1:=xu[k]; pi2:=sl[k];
    repeat
      while (xu[i]<pi1) or ((xu[i]=pi1) and (sl[i]>pi2)) do inc(i);
      while (xu[j]>pi1) or ((xu[j]=pi1) and (sl[j]<pi2)) do dec(j);
      if i<=j then
        begin
          temp := xu[i];
          xu[i] := xu[j];
          xu[j] := temp;
          temp := sl[i];
          sl[i] := sl[j];
          sl[j] := temp;
          inc(i); dec(j);
        end;
    until i>j;
    qs(l,j); qs(i,h);
  end;