char *reverseString(char string[]);

char *reverseString(char string[])
{
	int tamanhoString = strlen(string);
	int meio = tamanhoString / 2;
	char temp;

	for (int i = 0; i < meio; i++) {
		temp = string[i];
		string[i] = string[tamanhoString - i - 1];
		string[tamanhoString - i - 1] = temp;
	}

	return string;
}
