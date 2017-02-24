#include <stdio.h>
#include <string.h>
#include <math.h>
void nextMove(int n, int r, int c, char grid[101][101]){
    int i,j,s=0;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++)
            if (grid[i][j] == 'p'){
                s = 1;
                break;
            }
        if (s==1)
            break;
    }

    if (i==r)
        printf("%s", (j>c) ? "RIGHT" : "LEFT");
    else if (j==c)
        printf("%s", (i>r) ? "DOWN" : "UP");
    else if (j<c)
        printf("LEFT");
    else
        printf("RIGHT");
}

int main(void) {

    int n, r, c;

    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &c);

   char grid[101][101];
    
    for(int i=0; i<n; i++) {
        scanf("%s[^\n]%*c", grid[i]);
    }

    nextMove(n, r, c, grid);
    return 0;
}
