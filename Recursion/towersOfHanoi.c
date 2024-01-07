#include <stdio.h>

void towersOfHanoi (int no_of_discs, char source, char destination, char temporary)
{
    if (no_of_discs==1)
        // Move the one disk from the source to the destination.
        printf("Move disc %d from %c to %c.\n", no_of_discs, source, destination);
    
    else
    {
        // Move no_of_discs-1 from the source to the temporary using the destination.
        towersOfHanoi(no_of_discs-1, source, temporary, destination);
        printf("Move disc %d from %c to %c.\n", no_of_discs, source, destination);
        
        //Move the no_of_discs-1 back from the temporary to the destination using the source.
        towersOfHanoi(no_of_discs-1, temporary, destination, source);
    }
}

int main()
{
    int n;
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    towersOfHanoi(n, 'S', 'D', 'T');
    
    return 0;
}
