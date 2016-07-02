#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int lonelyinteger(int a_size, int* a) {

    int arr[101] = {0};
    int i, c;
    for (i=0; i<a_size; i++)
        arr[ a[i] ] = (arr[ a[i] ] == 0) ? 1 : 0;
    
    for (i=0; i<=100; i++)
        if ( arr[i] == 1){
            c = i;
            break;
        }

return c;

}

int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d", res);
    
    return 0;
}
