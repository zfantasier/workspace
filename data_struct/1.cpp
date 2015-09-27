#include <iostream>
#define MAX 500000
int main(){	
	int points,querys,data[MAX],left,right;
	std::cin>>points>>querys;
	for(int i=0;i<points;i++)
	{
//		std::cin>>data[i];
	}
	for(int i=0;i<querys;i++){
		std::cin>>left>>right;
		int result =0,left_equal=0,right_equal=0,font=0,end=points-1,mid;
		mid = font + ((end-font)>>1);
        while (font<end){
        	if(data[mid]<left&&left_equal==0) {
				font = mid; mid = font + ((end-font)>>1);
			}
			else if(data[mid]>right&&right_equal==0){
				
				end = mid; mid = font + ((end-font)>>1);
			}
        	else if(data[mid]>left) mid--;
        	else if(data[mid]<right) mid++;
        	else if(data[mid]==left&&left_equal==0) {font=mid;left_equal=1;mid = font +((end-font)>>1);} 
        	else if(data[mid]==left&&right_equal==0) { end=mid;right_equal=1;mid = font + ((end-font)>>1);} 
        	else std::cout<<end-font-1+left_equal+right_equal<<std::endl;
		} 
		std::cout<<result<<std::endl;
	}
	return 0;
} 


