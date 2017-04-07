function [fe,ke,me] =gk(xe,ye) 
    x0=sum(xe)/4;
    y0=sum(ye)/4;
    hx =(xe(2)-xe(1))/2;
    hy =(ye(3)-ye(1))/2;
    
    GP = [-sqrt(3)/3,sqrt(3)/3];
    GW = [1,1];
    [pha,pca,pea] = sha();
    for ni=1:4
        fe(ni)=0;
        L0=0;
        for L=1:2
            for M=1:2
                L0 = L0+1;
                fe(ni)=fe(ni)+GW(L)*GW(M)*f(x0+hx*GP(L),y0+hy*GP(M))*pha(ni,L0)*hx*hy;
            % 高斯积分 积分St f*v
            end
        end
    end
    
    
    for ni=1:4
        for nj=1:4
            s=0;L0=0;s1=0;
            for L=1:2
                for M=1:2
                    L0=L0+1;
                    s=s+GW(L)*GW(M)*(D1(hx*GP(L)+x0,hy*GP(M)+y0)*pca(ni,L0)*pca(nj,L0)/(hx)/(hx)+D2(hx*GP(L)+x0,hy*GP(M)+y0)*pea(ni,L0)*pea(nj,L0)/(hy)/(hy))*hx*hy;
                    %高斯积分  
                    s1=s1+GW(L)*GW(M)*pha(ni,L0)*pha(nj,L0)*hx*hy;
                    %高斯积分 
                end
            end
            ke(ni,nj)=s;%局部ni ，nj单元的基函数的内积;
                        %整体如何记录呢？
            me(ni,nj)=s1;%积分St U*V  
        end
    end  
 
    
     