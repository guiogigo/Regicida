#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct table {
    char rei[3];
    int i;
    int j;
    int intriga;
};

struct pos {
    char input[10];
    int linha;
    int coluna;
};

void exibir_matriz(struct table **, int);
void inserir_valor(struct table **, int, int, int);
void colocar_rei(struct table **, struct pos);
void jogar(struct table**, struct pos, int);
int avaliador(struct pos );

void main() {
    struct table **m;
    struct pos p;
    int i, j;
    int tamanho = 11;
    int validando;

    //Criador da matriz
    m = (struct table**)malloc(11*sizeof(struct table*));
    for(i = 0; i<11; i++) {
        for(j = 0; j<11; j++) {
            m[i] = (struct table*)malloc(11*sizeof(struct table));

        }
    }
    for(i = 0; i<11; i++) {
        for(j = 0; j<11; j++) {
            //m[i][j].rei = 'A';
            strcpy(m[i][j].rei, "0");
        }
    }
    exibir_matriz(m, tamanho);

    /*
    //Pedindo o primeiro reino
    printf("Insira a primeira cordenada: ");
    scanf("%d", &n);
    inserir_valor(m, 5, 5, n);
    exibir_matriz(m, tamanho);
    */
    //Próximos reinos
    do {
        printf("Insira a cordenada: ");
        fflush(stdin);
        gets(p.input);
        //printf("%d", p.input[0]);
        validando = avaliador(p);
    }while(validando);

    p.linha = p.input[0] - 65;
    if(p.input[1] == 49) {
        p.coluna = 10;
    } else  p.coluna = p.input[1] + p.input[2] - 97;

    //printf("(%d, %d)\n", p.linha, p.coluna);
    colocar_rei(m, p);
    exibir_matriz(m, tamanho);

    jogar(m, p, tamanho);
    jogar(m, p, tamanho);
    jogar(m, p, tamanho);
}

void exibir_matriz(struct table **matriz, int tamanho) {
    int i, j;
    for(i = 0; i<tamanho; i++) {
        for(j = 0; j<tamanho; j++) {
            printf("[%s]", matriz[i][j].rei);
        }
        printf("\n");
    }
}

void jogar(struct table **m, struct pos p, int tamanho) {
    int validando;
    do {
        printf("Insira a cordenada: ");
        fflush(stdin);
        gets(p.input);
        //printf("%d", p.input[0]);
        validando = avaliador(p);
    }while(validando);

    p.linha = p.input[0] - 65;
    if(p.input[1] == 49) {
        p.coluna = 10;
    } else  p.coluna = p.input[1] + p.input[2] - 97;

    //printf("(%d, %d)\n", p.linha, p.coluna);
    colocar_rei(m, p);
    exibir_matriz(m, tamanho);
}

void colocar_rei(struct table **matriz, struct pos pos) {
    int i, j;
    for(i=0; i<11; i++) {
        for(j=0; j<11; j++) {
            if(i == pos.linha && j == pos.coluna) {
                strcpy(matriz[i][j].rei, "1");
            }
        }
    }
}

void inserir_valor(struct table **matriz, int linha, int coluna, int valor) {
    //matriz[linha][coluna].intriga = valor;
    strcpy(matriz[linha][coluna].rei, "A");
}

int avaliador(struct pos pos) {
    /*if (strlen(pos.input)<3 || strlen(pos.input)>3) {
        return 1;
    } else if(pos.input[0] < 65 || pos.input[0] > 75) {
        return 1;
    } else if(pos.coluna < 97 || pos.coluna > 105) {
        return 1;
    }
    return 0;*/

    if(strlen(pos.input)== 3) {
        if(pos.input[0] >= 65 && pos.input[0] <= 75) {
            if(pos.input[1] == 48 || (pos.input[1] == 49 && pos.input[2] == 48)) {
                return 0;
            }
        }
    }
    return 1;
}
