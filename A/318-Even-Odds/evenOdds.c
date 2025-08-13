#include <stdio.h>

int main(){
    long long n, k;
    scanf("%lld %lld", &n, &k);
    
    // Calculate how many odd numbers there are from 1 to n
    long long odd_count = (n + 1) / 2;
    
    if (k <= odd_count) {
        // k-th position is in the odd numbers section
        // The k-th odd number is 2*k - 1
        printf("%lld\n", 2 * k - 1);
    } else {
        // k-th position is in the even numbers section
        // Position in even section: k - odd_count
        // The (k - odd_count)-th even number is 2 * (k - odd_count)
        printf("%lld\n", 2 * (k - odd_count));
    }
    
    return 0;
}