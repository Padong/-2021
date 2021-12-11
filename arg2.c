#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *fp = NULL;
	int i = 35421678;
	
	fp = fopen("table1.txt", "w+b");
	fseek(fp, 100, SEEK_SET);
	fwrite(&i,sizeof(int), 1, fp);
	fclose(fp);
}

