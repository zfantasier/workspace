function [pha,pca,pea] = sha()
   %��¼sh�����ڸ�˹��ĺ���ֵ
 GP = [-sqrt(3)/3,sqrt(3)/3];
 L0 = 0;
 for L=1:2
     for M=1:2
         L0=L0+1;
        [ph,pc,pe]=sh(GP(L),GP(M));
        %��ǰ��˹�㺯��ֵ
        for ni=1:4
            pha(ni,L0)=ph(ni);
            pca(ni,L0)=pc(ni);
            pea(ni,L0)=pe(ni);
        end
     end
 end
 %�õ����и�˹���ϵ�ֵ
 
 
 