#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "reverseString.c"
// CONVERSÃO DE DECIMAL PARA BINÁRIO E VICE-VERSA
int main(){
	setlocale(LC_ALL, "");
    int decimal = 0;
	int cont,opcao;
	char resto[2];
	char binario[255];

	printf("************************************************\n");
	printf("*CONVERSÃO DE BINARIO PARA DECIMAL E VICE-VERSA*\n");
	printf("************************************************\n");
	while (1) {
		decimal = 0;
		binario[0] = '\0';
		printf("Digite a conversão que voce queira fazer\n 1 - binário para decimal\n 2 - decimal para binário\n");

		scanf("%d", &opcao);

		if (opcao == 1) {
			printf("Digite um numero em binário: ");
			scanf("%s", binario);
			cont = strlen(binario) - 1;
			for (int i = 0; i < strlen(binario); i++) {

				int bit = binario[i] - '0';

				int potencia = pow(2.0, (double)cont);
				decimal += bit * potencia;
				cont -= 1;
			}

			printf("%d", decimal);
		}
		else if (opcao == 2) {
			printf("Digite um número na base decimal: ");
			scanf("%d", &decimal);
			while ((decimal / 2) != 0) {

				resto[0] = (decimal % 2) + '0';
				resto[1] = '\0';
				strcat(binario, resto);

				decimal = decimal / 2;
			}

			printf("%d", decimal);
			if (decimal / 2 == 1) {
				char caractereFinal = '1';
				strcat(binario, &caractereFinal);
			}
			printf("%s\n", reverseString(binario));


		}
	}
	

	
	
	return 0;
}