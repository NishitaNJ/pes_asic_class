#include <stdio.h>
#include <math.h>
int main(){
	long long int max=(long long int) (pow(2,63) -1);
        long long int min=(long long int) (-pow(2,63));
	printf("The highest number represented by long long int is %lld\n",max);
	printf("The lowest number represented by long long int is %lld\n",min);		return 0;	
}
