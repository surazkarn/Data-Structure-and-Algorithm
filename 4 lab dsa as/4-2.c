//WAP to add two distances (in km-meter) by passing structure to a function.

#include <stdio.h>

struct Distance {
   int km;
   float meter;
} d1, d2, result;

int main() {
   // take first distance input
   printf("Enter 1st distance\n");
   printf("Enter km: ");
   scanf("%d", &d1.km);
   printf("Enter meter: ");
   scanf("%f", &d1.meter);
 
   // take second distance input
   printf("\nEnter 2nd distance\n");
   printf("Enter km: ");
   scanf("%d", &d2.km);
   printf("Enter meter: ");
   scanf("%f", &d2.meter);
   
   // adding distances
   result.km = d1.km + d2.km;
   result.meter = d1.meter + d2.meter;

   // convert meter to km if greater than 1000
   while (result.meter >= 1000.0) {
      result.meter = result.meter - 1000.0;
      ++result.km;
   }
   printf("\nSum of distances = %dkm-%.1fmeter", result.km, result.meter);
   return 0;
}