#include <stdio.h>
#include <string.h>
#include <math.h>

void displayPathtoPrincess(int n, char grid[101][101]){
    // find princess
    int s=0;
    char one[6],two[6];
    if (grid[0][0] == 'p'){
        strcpy(one, "UP");
        strcpy(two, "LEFT");
    } else if (grid[n-1][0] == 'p'){
        strcpy(one, "DOWN");
        strcpy(two, "LEFT");
    } else if (grid[0][n-1] == 'p'){
        strcpy(one, "UP");
        strcpy(two, "RIGHT");
    } else if (grid[n-1][n-1] == 'p'){
        strcpy(one, "DOWN");
        strcpy(two, "RIGHT");
    }

    int i;
    for (i=0; i<(n/2); i++)
        printf("%s\n", one);
    for (i=0; i<(n/2); i++)
        printf("%s\n", two);
}

int main(void) {

    int m,i;
    scanf("%d", &m);
    char grid[101][101]={};
    char line[101];

    for(i=0; i<m; i++) {
        scanf("%s", line);
        strcpy(grid[i], line);
    }
    displayPathtoPrincess(m,grid);
    return 0;
}
