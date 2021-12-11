#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i;
int j; 



int initFile(FILE *fp, int cellSize, long cellCount, long initValue){
	
	char tempBuf[10] = {0}; // itoa, ltoa 시 값이 넘치는 것을 방지하기 위한 버퍼 
	fprintf(fp, "%2s", itoa(cellSize, tempBuf, 10));
	fprintf(fp, "%6s", ltoa(cellCount,tempBuf, 10));
	char* tempS = ltoa(initValue,tempBuf, 10);
	char* targetStr = (char *)malloc(sizeof(char) * (cellSize + 1));
	
	printf("%d\n", cellCount);
	for(i = 0; i < cellCount; i++){
		if(tempS[i] == '\0')
			break;
	}
	int cnt = i;

	// 성 공 
	printf("%d\n", cnt);
	printf("%d\n", cellSize);
	printf("%d\n", i);
	if(cnt == cellSize){
		for(i = j; i < cellSize; i++){
			targetStr[i] = tempS[i];
		}
	}
	//성공  
	else{
		for(j = 0; j < cellSize - i; j++){
			targetStr[j] = ' ';
		}
		printf("%d\n", j);
		for(i = j; i < cellSize; i++){
			targetStr[i] = tempS[i - cnt - 1];
		}
	}
	
	targetStr[cellSize+1] = '\0';
	
	for(i = 0; i < cellCount; i++){
		fprintf(fp, "%s",targetStr);
	}
}

//성공
int writeCell(FILE *fp, long cellIndex, long cellValue){
		int size;
		fscanf(fp,"%d", &size);
		fseek(fp, cellIndex*(size+5) , cellIndex < 0 ? SEEK_END : SEEK_SET);
		fprintf(fp, "%*s ", size, cellValue);
}
//오류
int readCell(FILE *fp, long cellIndex, long *cellBuf){
//	for(i = 3; i < argc; i++){
//		if(scale <= atoi(fp)){
//			printf("인덱스의 유효 범위는 0에서 99까지 입니다."); 
//			return;
//		}
//		fseek(fp, atoi(argv[i])*size+5 , atoi(argv[i]) < 0 ? SEEK_END : SEEK_SET);
//		fscanf(fp, "%s", cellBuf); 
//		printf("%s ", cellBuf);
//	}
//	printf("\n");	
}

//오류
 int readAdjacentCells(FILE *fp, long ciStart, long ciEnd, long *cellBuf){
	int size, scale;
	fscanf(fp,"%d", &size);
	fscanf(fp,"%d", &scale);
	if(scale <= ciStart){
		printf("인덱스의 유효 범위는 0에서 99까지 입니다.");
		return 0;
	}
	fseek(fp, ciStart*(size+5 ), ciStart < 0 ? SEEK_END : SEEK_SET);
	for(i = 0; i < ciEnd-ciStart+1; i++){
		fscanf(fp, "%s", cellBuf);
		printf("%s ", cellBuf);
	}
	printf("\n");
 }

int main(int argc, char **argv)
{	
	FILE *fp = NULL;
	char buf[10];
	int size = 0, scale = 0;
	
	if(argc < 5){
		fprintf(stderr, "Usage: %s source from length target \n", argv[0]);
		exit(1);
	}
	
	// -i (initialize 옵션) : 배열 파일의 생성 및 초기화
	if(strcmp(argv[2],"-i") == 0){
		fp = fopen(argv[1], "w");
		int cellSize = atoi(argv[3]);
		long cellCount = atol(argv[4]);
		long initValue = atol(argv[5]);
		initFile(fp, cellSize, cellCount, initValue);
	}
	
	//-w (write 옵션) : 배열 파일의 지정된 셀에 특정 값의 10진 표현을 저장
	if(strcmp(argv[2],"-w") == 0){
		fp = fopen(argv[1], "r+");
		long cellIndex = atol(argv[3]);
		long cellValue = atol(argv[4]);
		writeCell(fp, cellIndex, cellValue);
	}
	
	//-r (read 옵션) : 배열 파일의 셀들을 지정해 각 셀에 저장된 값을 10진수로 출력
	if(strcmp(argv[2],"-r") == 0){
		fp = fopen(argv[1], "r");
		long cellIndex = atol(argv[3]);
		long *cellBuf;
		readCell(fp, cellIndex, cellBuf);
	}
	
	//-l (list 옵션) : 배열 파일의 지정된 범위의 셀들에 저장된 값들을 저장 순서대로
	if(strcmp(argv[2],"-l") == 0){
		fp = fopen(argv[1], "r");
		long ciStart = atol(argv[3]);
		long ciEnd = atol(argv[4]);
		long *cellBuf;
		readAdjacentCells(fp, ciStart, ciEnd, cellBuf);
	}
	fclose(fp);
}


