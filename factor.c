// Program to print all prime factors 
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

  
// A function to print all prime factors of a given number n 
void primeFactors(unsigned long n) 
{   
    printf(1, "factor %d: ", n);
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        printf(1, "%d ", 2); 
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (unsigned long i = 3; i*i <= n; i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            printf(1, "%d ", i); 
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        printf (1,"%d ", n); 
    printf(1,"\n");
} 
  
/* Driver program to test above function */
int main(int argc, char *argv[]) 
{   
    unsigned long n = 0;
    
    if(argc == 1){
        printf(1,"This Command Need 1 Argument (Number)\n");
        exit();
    }

    if(argv[1][0]=='-'){
        printf(1,"Negative Value!, Input Positive Instead!\n");
        exit();
    }
    n = atoi(argv[1]);

    char string_temp[22];
    strcpy(string_temp,"");
    int i = 0;
    for (i = 0; i < (20 - strlen(argv[1])); i++){
        strcpy(string_temp+i, "0");
    }
    strcpy(string_temp+i, argv[1]);
//    sprintf(string_temp, "%020d", n);
    if (strcmp("18446744073709551615", string_temp) < 0){
        printf(1,"Value To Big!\n");
        exit();
    }
    

    primeFactors(n);
    exit(); 
} 