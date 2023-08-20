#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "reverseString.c"
int main() {

	setlocale(LC_ALL, "");
	int decimal = 0;
	int potencia;
	int cont, opcao;
	char resto[2];
	char hexadecimal[255];
	

	printf("****************************************************\n");
	printf("*CONVERS�O DE HEXADECIMAL PARA DECIMAL E VICE-VERSA*\n");
	printf("****************************************************\n");
	while (1) {
		printf("Digite uma op��o\n 1 - Hexadecimal para Decimal \n 2 - Decimal para Hexadecimal");
		scanf("%d", &opcao);

		if (opcao == 1) {
			cont = strlen(hexadecimal);
			printf("Digite o n�mero hexadecimal: ");
			scanf("%s", &hexadecimal);
			char* reverseHexadecimal = reverseString(hexadecimal);
			for (int i = 0; i < strlen(reverseHexadecimal); i++) {

				potencia = pow(16.0, (double)i);

				printf("%c vezes %d ", reverseHexadecimal[i], potencia);
				if (reverseHexadecimal[i] == 'A') {
					decimal += 10 * potencia;
				}
				else if (reverseHexadecimal[i] == 'B') {
					decimal += 11 * potencia;
				}
				else if (reverseHexadecimal[i] == 'C') {
					decimal += 12 * potencia;
				}
				else if (reverseHexadecimal[i] == 'D') {
					decimal += 13 * potencia;
				}
				else if (reverseHexadecimal[i] == 'E') {
					decimal += 14 * potencia;
				}
				else if (reverseHexadecimal[i] == 'F') {
					decimal += 15 * potencia;
				}
				else {
					decimal += (reverseHexadecimal[i] - '0') * potencia;
				}


			}

			printf("%d", decimal);
		}
		else if (opcao == 2) {
			printf("Digite um n�mero na base decimal: ");
			scanf("%d", &decimal);
			while ((decimal / 16) != 0) {

				resto[0] = (decimal % 16) + '0';
				resto[1] = '\0';
				strcat(hexadecimal, resto);

				decimal = decimal / 16;
			}

			printf("%s\n", reverseString(hexadecimal));

	}
	

	}
	return 0;
}