#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Matrizes que armazenam as escritas dos números
const char zero_dezenove[20][15] = {"Zero", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove"};
const char vinte_noventa[8][15] = {"Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"};
const char cem_novecentos[10][15] = {"Cem", "Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos"};

//Funções
void zero_cem(long long int num) {
    //O primeiro "if" de cada função garante que o número seja tratado pela função correta
    if (num < 20) {
        printf("%s", zero_dezenove[num]); //Acessa o dado do número correspondente na matriz

    } else if ((num % 10) == 0) {
        printf("%s", vinte_noventa[(num / 10) - 2]); //O "- 2" é necessário para acessar o dado correto dentro da matriz

    } else {
        printf("%s e %s", vinte_noventa[(num / 10) - 2], zero_dezenove[num % 10]);

    }

}

void cem_mil(long long int num) {
    if (num < 100) {
        zero_cem(num);

    } else if (num == 100) {
        printf("%s", cem_novecentos[0]); //Exceção para o "cem" no lugar de "cento"

    } else if ((num % 100) == 0) {
        printf("%s", cem_novecentos[num / 100]);

    } else {
        printf("%s e ", cem_novecentos[num / 100]);
        zero_cem(num % 100); //Manda a "sobra" para a próxima função

    }

}

void mil_milhao(long long int num) {
    if (num < 1000) {
        cem_mil(num);

    } else if ((num % 1000) == 0) {
        cem_mil(num / 1000);
        printf(" Mil");

    } else {
        cem_mil(num / 1000);
        printf(" Mil e ");
        cem_mil(num % 1000);

    }

}

void milhao_bilhao(long long int num) {
    if (num < 1000000) {
        mil_milhao(num);

    } else if (num < 2000000) {
        wprintf(L"Um Milhão"); //Um "if" específico para o singular e outro para o plural
        if ((num % 1000000) != 0) {
            printf(" e ");
            mil_milhao(num % 1000000);

        }

    } else {
        cem_mil(num / 1000000);
        wprintf(L" Milhões");
        if ((num % 1000000) != 0) {
            printf(" e ");
            mil_milhao(num % 1000000);

        }

    }

}

void bilhao_trilhao(long long int num) {
    if (num < 1000000000) {
        milhao_bilhao(num);

    } else if (num < 2000000000) {
        wprintf(L"Um Bilhão");
        if ((num % 1000000000) != 0) {
            printf(" e ");
            milhao_bilhao(num % 1000000000);

        }

    } else {
        cem_mil(num / 1000000000);
        wprintf(L" Bilhões");
        if ((num % 1000000000) != 0) {
            printf(" e ");
            milhao_bilhao(num % 1000000000);

        }

    }

}

//Função main
int main(int argc, char *argv[]) {
    long long int num;

    setlocale(LC_ALL, "Portuguese");

    //Tratamento para mais de uma entrada
    if (argc != 2) {
        wprintf(L"Uso incorreto: extenso_cli <número> \n");
        return 1;

    }

    //Tratamento para entrada diferente de um número
    if (sscanf(argv[1], "%lld", &num) != 1) {
        wprintf(L"Entrada inválida. Digite apenas números. \n");
        return 1;

    }

    //Saída
    wprintf(L"Número escrito por extenso: ");
    if (num < 0) {
        num = llabs(num); //Converte o número para positivo
        printf("Menos ");

    }
    bilhao_trilhao(num);
    printf(". \n");

    return 0;

}
