xe=[0 0.25 0 0.25];
ye=[0 0 0.25 0.25];
[fe,ke]=gk(xe,ye);
   
    for ni=1:4
        for nj=1:4
            s=0;L0=0;
            for L=1:2
                for M=1:2
                    L0=L0+1;
                    s=s+GW(L)*GW(M)*D1(hx*GP(L)+x0,hy*GP(M)+y0)*pca(ni,L0)*pca(nj,L0)/(hx)/(hx)+D2(hx*GP(L)+x0,hy*GP(M)+y0)*pea(ni,L0)*pea(nj,L0)/(hy)/(hy)*hx*hy;
                end
            end
            ke(ni,nj)=s;
        end
    end
    