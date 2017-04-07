function [test]= a()
        m=4;n=4;
       for i=1:5
           test(i)= possion_L2_err(m,n);
           m=m*2;
           n=n*2;
       end
       
  
