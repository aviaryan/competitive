
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
findPalind(char *arr)
{    
    int flag = 0;
    int slen,i;
    slen = strlen(arr)%2;

    int abc[26] = {0};

    char *sptr;
    sptr = &arr[0];
    // count
    while (sptr[0] != '\0'){
        abc[ (int)sptr[0] - 97 ]++;
        sptr++;
    }

    // check
    if (slen==0){
        for (i=0; i<26; i++){
            if (abc[i] % 2 == 1){ // find odd
                flag = 1;
                break;
            }
        }
    } else {
        int ct=0;
        for (i=0; i<26; i++){
            if (abc[i] % 2 == 1){ // find odd
                ct++;
            }
        }
        if (ct!=1)
            flag = 1;
    }

    if (flag==0)
        printf("YES\n");
    else
        printf("NO\n");
    
    return;
}


int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}
