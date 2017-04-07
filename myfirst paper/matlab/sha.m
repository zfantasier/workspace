function [pha,pca,pea] = sha()
   %记录sh函数在高斯点的函数值
 GP = [-sqrt(3)/3,sqrt(3)/3];
 L0 = 0;
 for L=1:2
     for M=1:2
         L0=L0+1;
        [ph,pc,pe]=sh(GP(L),GP(M));
        %当前高斯点函数值
        for ni=1:4
            pha(ni,L0)=ph(ni);
            pca(ni,L0)=pc(ni);
            pea(ni,L0)=pe(ni);
        end
     end
 end
 %得到所有高斯点上的值
 
 
 