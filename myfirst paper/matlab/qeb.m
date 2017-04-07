function [A,F,U]=qeb(m,n)
Lee =(n+1)*( m+1);%未知量
NE=m*n;%单元
%将网格剖分
[iii,xy,ibe]=ifg(m,n);
A=sparse(Lee,Lee);
F=sparse(Lee,1);
for Le=1:NE
    for k=1:4
        point = iii(k,Le);
        xe(k) = xy(1,point);
        ye(k) = xy(2,point);
    end
    [fe,ke,me]=gk(xe,ye);
    for ni=1:4
        for nj=1:4
            nii = iii(ni,Le);
            njj = iii(nj,Le);
            A(nii,njj)=A(nii,njj)+ke(ni,nj);%计算整体的有限元总刚矩阵
        end 
        F(nii)=F(nii)+fe(ni);
    end
end   
for i=1:length(ibe)%边界条件
    point=ibe(i);
    A(point,point)=1;
    A(1:point-1,point)=0;%上
    A(point+1:Lee,point)=0;%下
    A(point,point+1:Lee)=0;%左
    A(point,1:point-1)=0;%右
    F(point)=0;
end
U = A\F;
 