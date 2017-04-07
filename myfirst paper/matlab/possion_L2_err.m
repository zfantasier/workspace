function err =possion_L2_err(m,n)
    NE=m*n;
    [iii,xy,ibe]=ifg(m,n);
    [A,F,U]=qeb(m,n);
    [pha,pca,pea] = sha();
    err=0;

    GP = [-sqrt(3)/3,sqrt(3)/3];
    GW = [1,1];
    for Le=1:NE
         for k=1:4
        point = iii(k,Le);
        xe(k) = xy(1,point);
        ye(k) = xy(2,point);
         end
    x0=sum(xe)/4;
    y0=sum(ye)/4;
    hx =(xe(2)-xe(1))/2;
    hy =(ye(3)-ye(1))/2;
         L0=0;
         for L=1:2
            for M=1:2
                L0=L0+1;
                uu=u(x0+hx*GP(L),y0+hy*GP(M));
                s=0;
                for ni=1:4
                    point=iii(ni,Le);
                    s=s+U(point)*pha(ni,L0);
                end
                err=err+GW(L)*GW(M)*(uu-s)*(uu-s)*hx*hy;
            end
         end
   end
    err=sqrt(err);
   
       
    