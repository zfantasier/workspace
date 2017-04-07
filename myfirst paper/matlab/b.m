function result=b()      
        [test]= a();
        for i=1:4
           result(i) = log2(test(i)/test(i+1));
       end
    