#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <locale.h>
#include <conio.h>
#include <ctype.h>

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   CRIAÇÃO DAS CHAVES   -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#define HASH_SIZE 64
#define KEY_ORIGINAL "IWaSAwAzCHaN"
#define KEY_COMPLEMENT "!SerIaL ExPERimenTs_lAiN"
#define KEY_EXTEND "iwA-MAsaMI_sEL{21haSh7keYbiT4K64"
#define KEY_LOCK "1w@$4Vv/-|=(lI)[x1]60m7-_Ccj&vJ+o(2-1){9-5}L3Xp%8-5#R1M3nts=LAIN"

//!_@dm1n_!256!
char __admin_hash__[HASH_SIZE+1] = "!@dm1n1$tr4t0r!";

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÃO HASH PARA SENHA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
unsigned int* fun_hash_ (char* x_cvPass_) {
	int x_iKeyPos_ = 0;
	unsigned int x_uiPass_[HASH_SIZE];
	
	//printf("\n\nSENHA ORIGINAL : %s", x_cvPass_);
	
	/*printf("\n\nSENHA EM ASCII :");
	for (int x_iIndex_ = 0; x_iIndex_ < strlen(x_cvPass_); x_iIndex_++)
		printf(" %d", int(x_cvPass_[x_iIndex_]));*/
	
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		x_uiPass_[x_iIndex_] = 0;
	
	for (int x_iIndex_ = 0; x_iIndex_ < strlen(x_cvPass_); x_iIndex_++, x_iKeyPos_<(strlen(KEY_ORIGINAL)-1)?(x_iKeyPos_++):x_iKeyPos_=0)
		x_uiPass_[x_iIndex_] = int(x_cvPass_[x_iIndex_]) * int(KEY_ORIGINAL[x_iKeyPos_]);
	
	/*printf("\n\nPRIMEIRA CHAVE (ORIGINAL) :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf(" %u", x_uiPass_[x_iIndex_]);*/
	
	for (int x_iIndex_ = int(strlen(KEY_ORIGINAL)/strlen(x_cvPass_)), x_iPassSize_ = strlen(x_cvPass_); x_iIndex_ < x_iPassSize_; x_iIndex_+=int(HASH_SIZE/strlen(KEY_ORIGINAL))) {
		int x_iAux_ = x_uiPass_[x_iIndex_];
		x_uiPass_[x_iIndex_] = x_uiPass_[x_iPassSize_-x_iIndex_-1];
		x_uiPass_[x_iPassSize_-x_iIndex_-1] = x_iAux_;
	}
	
	/*printf("\n\nINVERSAO PRIMEIRA CHAVE :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf(" %u", x_uiPass_[x_iIndex_]);*/
	
	for (int x_iIndex_ = 0, x_iPassSize_ = strlen(x_cvPass_); x_uiPass_[strlen(KEY_EXTEND)-1] == 0; x_iIndex_++)
		x_uiPass_[x_iPassSize_+x_iIndex_] = x_uiPass_[x_iPassSize_-(x_iIndex_<(x_iPassSize_)?x_iIndex_:(x_iIndex_+1-x_iPassSize_))-1] / int(KEY_COMPLEMENT[strlen(KEY_COMPLEMENT)-1-x_iIndex_]) * int(KEY_COMPLEMENT[x_iIndex_]);
	
	/*printf("\n\nSEGUNDA CHAVE (COMPLEMENT) :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf (" %u", x_uiPass_[x_iIndex_]);*/
	
	for (int x_iIndex_ = int(x_uiPass_[HASH_SIZE/2-1]/x_uiPass_[0]), x_iPassSize_ = strlen(KEY_EXTEND); x_iIndex_ < x_iPassSize_; x_iIndex_+=int(HASH_SIZE/strlen(KEY_EXTEND))) {
		int x_iAux_ = x_uiPass_[x_iIndex_];
		x_uiPass_[x_iIndex_] = x_uiPass_[x_iPassSize_-x_iIndex_-1];
		x_uiPass_[x_iPassSize_-x_iIndex_-1] = x_iAux_;
	}
	
	/*printf("\n\nINVERSAO SEGUNDA CHAVE :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf (" %u", x_uiPass_[x_iIndex_]);*/
	
	for (int x_iIndex_ = 0, x_iPassSize_ = strlen(KEY_EXTEND); x_iIndex_ < x_iPassSize_; x_iIndex_++)
		x_uiPass_[x_iPassSize_+x_iIndex_] = x_uiPass_[x_iPassSize_-x_iIndex_-1] / int(KEY_EXTEND[strlen(KEY_EXTEND)-1-x_iIndex_]) * int(KEY_EXTEND[x_iIndex_]);
	
	/*printf ("\n\nTERCEIRA CHAVE (EXTEND) :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf (" %u", x_uiPass_[x_iIndex_]);*/
	
	for(int x_iIndex_ = int(x_uiPass_[HASH_SIZE-1]/x_uiPass_[1]); x_iIndex_ < HASH_SIZE; x_iIndex_ += int(HASH_SIZE/strlen(KEY_COMPLEMENT))) {
		int x_iAux_ = x_uiPass_[x_iIndex_];
		x_uiPass_[x_iIndex_] = x_uiPass_[HASH_SIZE-x_iIndex_-1];
		x_uiPass_[HASH_SIZE-x_iIndex_-1] = x_iAux_;
	}
	
	/*printf("\n\nINVERSAO TERCEIRA CHAVE :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf(" %u", x_uiPass_[x_iIndex_]);*/
	
	for(int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		x_uiPass_[x_iIndex_] = x_uiPass_[x_iIndex_] / KEY_LOCK[HASH_SIZE-x_iIndex_-1] * KEY_LOCK[x_iIndex_];
	
	/*printf("\n\nQUARTA CHAVE (LOCK) :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf(" %u", x_uiPass_[x_iIndex_]);*/
	
	for(int x_iIndex_ = 0; x_iIndex_ < (HASH_SIZE/2); x_iIndex_++) {
		int x_iAux_ = x_uiPass_[x_iIndex_];
		x_uiPass_[x_iIndex_] = x_uiPass_[HASH_SIZE/2+x_iIndex_];
		x_uiPass_[HASH_SIZE/2+x_iIndex_] = x_iAux_;
	}
	
	/*printf("\n\nINVERSAO QUARTA CHAVE :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf(" %u", x_uiPass_[x_iIndex_]);*/
	
	/*printf("\n\nCONVERSAO HEXADECIMAL :");
	for (int x_iIndex_ = 0; x_iIndex_ < HASH_SIZE; x_iIndex_++)
		printf(" %x", x_uiPass_[x_iIndex_]);*/
	
	//printf("\n\n%d\n\n", x_uiPass_[0]);
	//system("PAUSE");
	
	return x_uiPass_;
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-------------------------=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//

int main() {
//	printf("%s\n", setlocale(LC_ALL, "Portuguese"));
	char usu[43], pass[HASH_SIZE+1];
	FILE *file_usu;
	FILE *file_pass;
	
	//fun_hash_(__admin_hash__);

	printf("_____________________________________\n");
	printf("        ...   INICIANDO   ...        \n");
	printf("-------------------------------------\n\n");

	file_usu = fopen("__arq__usu_iwa.chan", "r");
	file_pass = fopen("__arq__pass_iwa.chan", "r");

	if (file_usu == NULL || file_pass == NULL) {
		fclose(file_usu);
		file_usu = fopen("__arq__usu_iwa.chan", "w");
		fprintf(file_usu, "__admin__");

		fclose(file_pass);
		file_pass = fopen("__arq__pass_iwa.chan", "w");
		
		unsigned int* iwa;
		iwa = fun_hash_(__admin_hash__);
		char IWA[7];
		for (int iIndex = 0; iIndex < HASH_SIZE; iIndex++)
			fprintf(file_pass, itoa(iwa[iIndex], IWA, 16));
	} else {
		/*while (fgets(usu, HASH_SIZE, file_usu) != NULL)
			printf("usu ");
		while (fgets(pass, HASH_SIZE, file_pass) != NULL)
			printf("pass ");*/
		printf("Ta certinho!");
		system("PAUSE");
	}
	
	system("PAUSE");

//	fclose(file_usu);
//	fclose(file_pass);

	//system("CLS");
/*
	if (!strcmp(strupr(usu), "__ADMIN__")){
		printf("O USUARIO EH ADMIN!\n");

		if (!strcmp(pass, fun_hash_(__admin_hash__)) {
			printf("A SENHA ESTA CORRETA");
			exit(0);
		}
	}*/

	while(true){
		printf ("USER NOW : %s!", usu);
		printf ("PASS NOW : %s!", pass);

		int iIndex = 0;
		printf("\n_________\n");
		printf("-=LOGIN=-");
		printf("\n---------\n");

		printf("\n\nUSUARIO: ");

		for (iIndex = 0; ; ){
			char cStr = getch();

			if (cStr == 13 && iIndex > 0){
				break;
			}
			if (cStr == '\b'){
				if (iIndex > 0){
					putch('\b');
					putch(' ');
					putch('\b');

					iIndex --;
				}
			}
			else if (iIndex < 42){
				usu[iIndex] = cStr;
				putch(usu[iIndex]);
				iIndex++;
			}
		}
		usu[iIndex] = '\0';

		printf("\n\n%s!\n\n", usu);

		if (!strcmp(strupr(usu), "__ADMIN__")){
			printf("UHU\n");
			break;
		}
	}

	return 0;
}
