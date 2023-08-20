#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "reverseString.c"
// CONVERSÃO DE DECIMAL PARA BINÁRIO E VICE-VERSA
int main() {
	setlocale(LC_ALL, "");
	int decimal = 0;
	int cont, opcao;
	char resto[2];
	char octal[255];

	printf("************************************************\n");
	printf("* CONVERSÃO DE OCTAL PARA DECIMAL E VICE-VERSA *\n");
	printf("************************************************\n");
	while (1) {
		decimal = 0;
		octal[0] = '\0';
		printf("Digite a conversão que voce queira fazer\n 1 - octal para decimal\n 2 - decimal para octal\n");

		scanf("%d", &opcao);

		if (opcao == 1) {
			printf("Digite um numero em octal: ");
			scanf("%s", octal);
			cont = strlen(octal) - 1;
			for (int i = 0; i < strlen(octal); i++) {

				int bit = octal[i] - '0';

				int potencia = pow(8.0, (double)cont);
				decimal += bit * potencia;
				cont -= 1;
			}

			printf("%d\n", decimal);
		}
		else if (opcao == 2) {
			printf("Digite um número na base decimal: ");
			scanf("%d", &decimal);
			while ((decimal / 8) != 0) {

				resto[0] = (decimal % 8) + '0';
				resto[1] = '\0';
				strcat(octal, resto);

				decimal = decimal / 8;
			}

			printf("%d", decimal);
			if (decimal / 8 == 1) {
				char caractereFinal = '1';
				strcat(octal, &caractereFinal);
			}

			/*int tamanhoOctal = strlen(octal);
			int meio = tamanhoOctal / 2;
			char temp;

			for (int i = 0; i < meio; i++) {
				temp = octal[i];
				octal[i] = octal[tamanhoOctal - i - 1];
				octal[tamanhoOctal - i - 1] = temp;
			}*/
			printf("%s\n", reverseString(octal));


		}
	}




	return 0;
}