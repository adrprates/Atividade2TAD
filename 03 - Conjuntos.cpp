//Autor: Adriano Prates

#include <stdio.h>

//definindo valores
#define maxElemento 20
#define maxConjunto 50

//criando contador para o numero de conjuntos
int contConjunto = 0;

struct Conjunto {
    int numeros[maxElemento], tamanho = 0;

    void ler(){
        while(1){
            printf("\n");
            printf("Digite o tamanho do conjunto: ");
            scanf("%d%*c", &tamanho);
            printf("\n");

            if(tamanho <= 0 || tamanho > maxElemento){
                printf("O conjunto so pode ter no maximo 20 elementos.\n\n");
                continue;
            } else {
                break;
            }
        }

        for(int i = 0; i < tamanho; i++){
            printf("Digite o valor do numero %d de %d: ", (i+1), tamanho);
            scanf("%d%*c", &numeros[i]);
        }

        printf("\n");
    }

    void imprimir(){
        if(tamanho == 0){
            printf("\nQuantidade de elementos no conjunto: nenhum (conjunto vazio)\n");
            printf("{}\n");
        } else{
            printf("\nQuantidade de elementos no conjunto: %d\n", tamanho);
            printf("{ ");
            for(int i = 0; i < tamanho; i++){
                if((i+1) == tamanho){
                    printf("%d", numeros[i]);
                } else {
                    printf("%d, ", numeros[i]);
                }
            }
            printf(" }");
            printf("\n");
        }
    }
};

struct FabricaConjunto {
    Conjunto conjunto[maxConjunto];

    void conjuntoVazio(){
        conjunto[contConjunto].tamanho = 0;
        contConjunto++;
        printf("\nConjunto vazio criado.\n");
    }

    void cadastrar(){
        if(contConjunto < maxConjunto){
            conjunto[contConjunto].ler();
            contConjunto++;
            printf("Cadastro realizado com sucesso!!\n");
        } else {
            printf("O numero de conjuntos cadastrados chegou ao limite, nao e possivel cadastrar mais.\n");
        }
    }

    void listarConjuntos(){
        for(int i = 0; i < contConjunto; i++){
            printf("\nID Conjunto: %d\n", (i+1));
            if(conjunto[i].tamanho == 0){
                printf("{}\n");
            } else{
                printf("{ ");
                for(int j = 0; j < conjunto[i].tamanho; j++){
                    if((j+1) == conjunto[i].tamanho){
                        printf("%d", conjunto[i].numeros[j]);
                    } else{
                        printf("%d, ", conjunto[i].numeros[j]);
                    }
                }
                printf(" }\n");
            }
        }
    }

    void uniaoConjuntos(){
        int primeiro = 0, segundo = 0;
        if(contConjunto <= 1){
            printf("\nO numero de conjuntos cadastrados precisa ser igual ou maior que dois.\nCadastre mais conjuntos.\n");
        } else {
            printf("\n\n- - - Lista de conjuntos cadastrados - - -\n");
            listarConjuntos();
            printf("\nEscolha dois conjuntos da lista para unir:\n\n");
            while(1){
                printf("Escolha o primeiro conjunto: ");
                scanf("%d%*c", &primeiro);
                if(primeiro <= 0 || primeiro > contConjunto){
                    printf("\nID de conjunto invalido. Tente novamente.\n\n");
                    continue;
                } else{
                    printf("\n");
                    break;
                }
            }
            while(1){
                printf("Escolha o segundo conjunto: ");
                scanf("%d%*c", &segundo);
                if(segundo <= 0 || segundo > contConjunto || segundo == primeiro){
                    printf("\nID de conjunto inválido ou já selecionado. Tente novamente.\n");
                    continue;
                } else{
                    printf("\n");
                    break;
                }
            }

            Conjunto conjuntoA = conjunto[primeiro - 1];
            Conjunto conjuntoB = conjunto[segundo - 1];

            if(conjuntoA.tamanho == 0 && conjuntoB.tamanho == 0){
                conjunto[contConjunto] = conjuntoA;
            } else if(conjuntoA.tamanho == 0){
                conjunto[contConjunto] = conjuntoB;
            } else if(conjuntoB.tamanho == 0){
                conjunto[contConjunto] = conjuntoA;
            } else{
                for(int i = 0; i < conjuntoA.tamanho ; i++){
                conjunto[contConjunto].numeros[conjunto[contConjunto].tamanho] = conjuntoA.numeros[i];
                conjunto[contConjunto].tamanho++;
                }

                for(int i = 0; i < conjuntoB.tamanho; i++){
                    int elementoPresente = 0;
                    for(int j = 0; j < conjuntoA.tamanho; j++){
                        if(conjuntoB.numeros[i] == conjuntoA.numeros[j]){
                            elementoPresente = 1;
                            break;
                        }
                    }
                    if(elementoPresente != 1){
                        conjunto[contConjunto].numeros[conjunto[contConjunto].tamanho] = conjuntoB.numeros[i];
                        conjunto[contConjunto].tamanho++;
                    }
                }
            }
            printf("O resultado da uniao criou um novo conjunto:\n");
            conjunto[contConjunto].imprimir();
            contConjunto++;
        }
    }

    void intersecaoConjuntos(){
        int primeiro = 0, segundo = 0;
        if(contConjunto <= 1){
            printf("\nO numero de conjuntos cadastrados precisa ser igual ou maior que dois.\nCadastre mais conjuntos.\n");
        } else {
            printf("\n\n- - - Lista de conjuntos cadastrados - - -\n");
            listarConjuntos();
            printf("\nEscolha dois conjuntos da lista para fazer intersecao:\n\n");
            while(1){
                printf("Escolha o primeiro conjunto: ");
                scanf("%d%*c", &primeiro);
                if(primeiro <= 0 || primeiro > contConjunto){
                    printf("\nID de conjunto invalido. Tente novamente.\n\n");
                    continue;
                } else{
                    printf("\n");
                    break;
                }
            }
            while(1){
                printf("Escolha o segundo conjunto: ");
                scanf("%d%*c", &segundo);
                if(segundo <= 0 || segundo > contConjunto || segundo == primeiro){
                    printf("\nID de conjunto inválido ou já selecionado. Tente novamente\n");
                    continue;
                } else{
                    printf("\n");
                    break;
                }
            }

            Conjunto conjuntoA = conjunto[primeiro - 1];
            Conjunto conjuntoB = conjunto[segundo - 1];

            if(conjuntoA.tamanho == 0 || conjuntoB.tamanho == 0){
                conjunto[contConjunto] = conjuntoA;
            } else{
                for(int i = 0; i < conjuntoA.tamanho; i++){
                    int elementoPresente = 0;
                    for(int j = 0; j < conjuntoB.tamanho; j++){
                        if(conjuntoA.numeros[i] == conjuntoB.numeros[j]){
                            elementoPresente = 1;
                            break;
                        }
                    }
                    if(elementoPresente == 1){
                        conjunto[contConjunto].numeros[conjunto[contConjunto].tamanho] = conjuntoA.numeros[i];
                        conjunto[contConjunto].tamanho++;
                    }
                }
            }
            printf("O resultado da intersecao criou um novo conjunto:\n");
            conjunto[contConjunto].imprimir();
            contConjunto++;
        }
    }

    void imprimirUmConjunto(){
        int idConjunto;
        if(contConjunto == 0){
            printf("\nNao ha conjuntos cadastrados ainda.\n");
        } else{
            printf("\n\n- - - Lista de conjuntos cadastrados - - -\n");
            listarConjuntos();
            while(1){
                printf("\nDigite o ID do conjunto que deseja imprimir: ");
                scanf("%d%*c", &idConjunto);
                if(idConjunto <= 0 || idConjunto > contConjunto){
                    printf("\nID de conjunto invalido. Tente novamente.\n\n");
                    continue;
                } else{
                    break;
                }
            }
            conjunto[idConjunto-1].imprimir();
        }
    }
};

int main(){
    FabricaConjunto fabricaConjunto;

    int escolha;

    do{
        printf("\n- - - Menu - - -\n");
        printf("1 - Criar um conjunto vazio\n");
        printf("2 - Cadastrar conjunto\n");
        printf("3 - Fazer a uniao de dois conjuntos\n");
        printf("4 - Fazer a intersecao de conjuntos\n");
        printf("5 - Ler um conjunto\n");
        printf("6 - Sair\n");
        scanf("%d%*c", &escolha);

        switch(escolha)
        {
        case 1:
            printf("\n- - - Conjunto Vazio - - -\n");
            fabricaConjunto.conjuntoVazio();
            printf("\n- - - - - - - - - - - - -\n");
            break;
        case 2:
            printf("\n- - - Cadastrar conjunto - - -\n");
            fabricaConjunto.cadastrar();
            printf("\n- - - - - - - - - - - - -\n");
            break;
        case 3:
            printf("\n- - - Uniao - - -\n");
            fabricaConjunto.uniaoConjuntos();
            printf("\n- - - - - - - - - - - - -\n");
            break;
        case 4:
            printf("\n- - - Intersecao - - -\n");
            fabricaConjunto.intersecaoConjuntos();
            printf("\n- - - - - - - - - - - - -\n");
            break;
        case 5:
            printf("\n- - - Ler conjunto - - -\n");
            fabricaConjunto.imprimirUmConjunto();
            printf("\n- - - - - - - - - - - - -\n");
            break;
        case 6:
            printf("\nSaindo, volte sempre! :)\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }while(escolha != 6);

    return 0;

}
