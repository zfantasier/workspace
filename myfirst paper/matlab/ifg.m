function[iii,xy,ibe] = ifg(m,n)
    Le = 0;
    for i=1:n
        for j =1:m
             Le = Le+1;
            iii(1,Le)=(i-1)*(m+1)+j;
            iii(2,Le)=(i-1)*(m+1)+j+1;
            iii(3,Le)=(i)*(m+1)+j;
            iii(4,Le)=(i)*(m+1)+j+1;%���Ϊ�������� �ڼ��о��ǵڼ�����Ԫ;
        end
    end
    
    point = 0;
    for i=1:n+1
        for j=1:m+1
            point = point+1;
            xy(1,point)=(j-1)/m;%
            xy(2,point)=(i-1)/n;%
        end
    end
    
    %������ĸ��߽� �� 
    ibe1 = 1:m+1;   %�±߽�
    ibe2 = (m+1)*n+1:(m+1)*(n+1);%�ϱ߽�
    ibe3 = (m+1)+1:m+1:(m+1)*(n-1)+1;%��߽�
    ibe4 = (m+1)*2:m+1:(m+1)*n;%�ұ߽�
    ibe=[ibe1,ibe2,ibe3,ibe4];
    
    %�������� 2*��m+n��  length(ibe)�ж��Ƿ񳤶���ͬ