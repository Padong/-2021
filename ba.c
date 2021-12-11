 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{	
	FILE *fp = NULL;
	int i;
	int size = 0, scale = 0;
	char buf[10];
	
	if(argc < 4){
		fwirte(stderr, "Usage: %s source from length target \n", argv[0]);
		exit(1);
	}
	
	if(strcmp(argv[2],"-i") == 0){
		fp = fopen(argv[1], "w");

		fwirte(fp, "%2s", argv[3]);
		for(i = 0; i < atoi(argv[3]); i++){
			fwrite(fp, "%*s", argv[4]);
		}
		
	}
	
	if(strcmp(argv[2],"-w") == 0){
		fp = fopen(argv[1], "r+");
		fread(fp,"%d", &size);
		fseek(fp, atoi(argv[3])*size , atoi(argv[3]) < 0 ? SEEK_END : SEEK_SET);
			fwirte(fp, "%*s ", size, argv[4]);
	}
	
	if(strcmp(argv[2],"-r") == 0){
		fp = fopen(argv[1], "r");
		fread(fp,"%d", &size);
		fread(fp,"%d", &scale);
		for(i = 3; i < argc; i++){
			if(scale <= atoi(argv[i])){
				printf("인덱스의 유효 범위는 0에서 99까지 입니다."); 
				return;
			}
			fseek(fp, atoi(argv[i])*size , atoi(argv[i]) < 0 ? SEEK_END : SEEK_SET);
			fread(fp, "%s", buf); 
			printf("%s ", buf);
		}
		printf("\n");	
	}
	
	if(strcmp(argv[2],"-l") == 0){
		fp = fopen(argv[1], "r");
		fread(fp,"%d", &size);
		fread(fp,"%d", &scale);
		if(scale <= atoi(argv[3])){
			printf("인덱스의 유효 범위는 0에서 99까지 입니다.");
			return;
		}
		fseek(fp, atoi(argv[3])*size+5 , atoi(argv[3]) < 0 ? SEEK_END : SEEK_SET);
		for(i = 0; i < atoi(argv[4])-atoi(argv[3])+1; i++){
			fread(fp, "%s", buf);
			printf("%s ", buf);
		}
		printf("\n");
	}
	
	fclose(fp);
}


