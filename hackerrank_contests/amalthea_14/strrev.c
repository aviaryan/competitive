#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

   	char string[] = "I love advanced computing. I equally love music.";
   	char *tPtr;
   	char strs[100][1000];
   	int stt = -1, t;

   	tPtr = strtok(string, ".");
   	while (tPtr != NULL){
   		++stt;
   		strcpy(strs[stt], tPtr);
   		tPtr = strtok(NULL, ".");
   	}

   	// w array
   	char words[stt][1000][100];
   	// reverse each string
   	for (t=0; t<=stt; t++){
   		
   	}

    return 0;
}