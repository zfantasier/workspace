    #include <string.h>  
    #include <stdio.h>  
    #include <assert.h>  
      
    int findval(int &a[], int len, int val,int &equal)  
    {  
        int begin, end, mid;  
        begin = 0;  
        end = len -1;  
        while (begin < end)  
        {  
            mid = begin + ((end - begin)>>1);  
            if (val > a[mid])  
                begin = mid + 1;  
            else   
                end = mid;  
        }  
      
      
        if (a[end] > val)  
        	{equal=0;return end;}  
        else if (a[begin] > val)
			{equal=0;return begin;}  
        else if (a[end]==val)
			{equal=1;return end;}  
		else if (a[begin] == val)
			{equal=1;return begin;}
        else return -1;  
    }  
      
    void main(void)  
    {  
        int a[] = {5,5,5,6,8,9,10,12};  
        int b = 8;  
        int len = sizeof(a)/sizeof(int);  
        int n = -1;  
        n = findval(a, len, b);  
        printf("find the val index is %d",n);  
    }  
