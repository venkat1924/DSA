#include<stdio.h>

//s=source rod, d=destination rod, t=temporary rod
void TowerHanoi(int n, char s, char d, char t)
{
  if (n==1)
    printf("move %d disc from %c to %c\n",n,s,d);
  else
  {
    TowerHanoi(n-1,s,t,d);
    printf("Move disc %d from %c to %c.\n",n,s,d);
    TowerHanoi(n-1,t,d,s);
  }
}
int main()
{
int n;
printf("Enter number of disks here:");
scanf("%d",&n);
TowerHanoi(n,'S','D','T');
return 0;
}

