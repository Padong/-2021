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
		fprintf(stderr, "Usage: %s source from length target \n", argv[0]);
		exit(1);
	}
	//  -i (initialize 옵션) : 배열 파일의 생성 및 초기화
	if(strcmp(argv[2],"-i") == 0){
		fp = fopen(argv[1], "w");
		fprintf(fp, "%2s%6s", argv[3], argv[4]);
		for(i = 0; i < atoi(argv[4]); i++){
			fprintf(fp, "%*s",atoi(argv[3]),argv[5]);
		}
	}
	//-w (write 옵션) : 배열 파일의 지정된 셀에 특정 값의 10진 표현을 저장
	if(strcmp(argv[2],"-w") == 0){
		fp = fopen(argv[1], "r+");
		fscanf(fp,"%d", &size);
		fseek(fp, atoi(argv[3])*size+5 , atoi(argv[3]) < 0 ? SEEK_END : SEEK_SET);
			fprintf(fp, "%*s ", size, argv[4]);
	}
	// -r (read 옵션) : 배열 파일의 셀들을 지정해 각 셀에 저장된 값을 10진수로 출력
	if(strcmp(argv[2],"-r") == 0){
		fp = fopen(argv[1], "r");
		fscanf(fp,"%d", &size);
		fscanf(fp,"%d", &scale);
		for(i = 3; i < argc; i++){
			if(scale <= atoi(argv[i])){
				printf("인덱스의 유효 범위는 0에서 99까지 입니다."); 
				return;
			}
			fseek(fp, atoi(argv[i])*size+5 , atoi(argv[i]) < 0 ? SEEK_END : SEEK_SET);
			fscanf(fp, "%s", buf); 
			printf("%s ", buf);
		}
		printf("\n");	
	}
	//  -l (list 옵션) : 배열 파일의 지정된 범위의 셀들에 저장된 값들을 저장 순서대로 10진수로 출력
	if(strcmp(argv[2],"-l") == 0){
		fp = fopen(argv[1], "r");
		fscanf(fp,"%d", &size);
		fscanf(fp,"%d", &scale);
		if(scale <= atoi(argv[3])){
			printf("인덱스의 유효 범위는 0에서 99까지 입니다.");
			return;
		}
		fseek(fp, atoi(argv[3])*size+5 , atoi(argv[3]) < 0 ? SEEK_END : SEEK_SET);
		for(i = 0; i < atoi(argv[4])-atoi(argv[3])+1; i++){
			fscanf(fp, "%s", buf);
			printf("%s ", buf);
		}
	}
	fclose(fp);
}

