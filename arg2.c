#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *f = NULL;
	int i = 35421678;
	
	f = fopen("table1.txt", "w+b");
	fseek(f, 100, SEEK_SET);
	fwrite(&i,sizeof(int), 1, f);
	fclose(f);
}