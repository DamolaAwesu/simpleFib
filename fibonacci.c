#include <stdio.h>

//#define SEQUENCE_OUTPUT

unsigned long long fibonacciMemoized(int n);

int main(void)
{
	int n = 20;
    unsigned long long result = fibonacciMemoized(n);
    printf("\nThe Fibonacci sum of %d = %d\n",n,result);
	return 0;
}

unsigned long long fibonacciMemoized(int n)
{
    int prev_result[] = {0,1};
    int result = 0;int i = 2;
    
	if (n == 0)
		return prev_result[0];
	
	#ifdef SEQUENCE_OUTPUT
    printf("%d " ,prev_result[0]);
    printf("%d " ,prev_result[1]);
    #endif
    if (n <= 2)
        return prev_result[0]+prev_result[1];
    else
    {
        while (i <= n)
        {
            result = prev_result[0]+prev_result[1];
            #ifdef SEQUENCE_OUTPUT
            printf("%d ",result);
            #endif
            prev_result[0] = prev_result[1];
            prev_result[1] = result;
            i++;
        }
    }
    return result;
}
