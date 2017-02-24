#include<stdio.h>

void next_move(int posr, int posc, char board[5][5]) {
    
}

int main(void) {
    int pos[2], i; 
    char board[5][5], line[6];
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    for(i=0; i<5; i++) {
        scanf("%s[^\\n]%*c", line);
        strncpy(board[i], line, 5);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
