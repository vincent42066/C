#include <stdio.h>
#include <stdlib.h>
void MultiplicationPointeur(int *pt){
 int a = 5, b = 6;
 *pt = a*b;

}
int main()
{
    int val;
    int *monPointeur = &val;
    MultiplicationPointeur(monPointeur);
    printf(" %d", *monPointeur);

    return 0;
}
