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
	char digitoFinal[2];
	char hexadecimal[255];
	

	printf("****************************************************\n");
	printf("*CONVERSÃO DE HEXADECIMAL PARA DECIMAL E VICE-VERSA*\n");
	printf("****************************************************\n");
	while (1) {
		printf("Digite uma opção\n 1 - Hexadecimal para Decimal \n 2 - Decimal para Hexadecimal\n");
		scanf("%d", &opcao);
		hexadecimal[0] = '\0';
		digitoFinal[0] = '\0';
		decimal     = 0;
		if (opcao == 1) {
			cont = strlen(hexadecimal);
			printf("Digite o número hexadecimal: ");
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
			printf("Digite um número na base decimal: ");
			scanf("%d", &decimal);

			while ((decimal / 16) != 0) {
				if (decimal % 16 == 10) {
					resto[0] = 'A';
				}
				else if (decimal % 16 == 11) {
					resto[0] = 'B';
				}
				else if (decimal % 16 == 12) {
					resto[0] = 'C';
				}
				else if (decimal % 16 == 13) {
					resto[0] = 'D';
				}
				else if (decimal % 16 == 14) {
					resto[0] = 'E';
				}
				else if (decimal % 16 == 15) {
					resto[0] = 'F';
				}
				else {
					resto[0] = (decimal % 16) + '0';
				}
				
				resto[1] = '\0';
				strcat(hexadecimal, resto);

				decimal = decimal / 16;
			}
	        digitoFinal[0] = decimal + '0';
			digitoFinal[1] = '\0';
			strcat(hexadecimal, digitoFinal);
			printf("%s\n", reverseString(hexadecimal));

	}
	

	}
	return 0;
}