//Autor: Adriano Prates

#include <stdio.h>

//definindo valores
#define maxNome 50
#define maxCargo 50
#define maxFuncionario 10

//criando contador para o numero de funcionarios
int contFuncionario = 0;

struct Funcionario{
    char nome[maxNome];
    char cargo[maxCargo];
    double salarioBase, beneficios, descontos, salarioLiquido;

    void ler(){
        printf("Digite o nome do funcionario: ");
        scanf("%[^\n]%*c", nome);
        printf("Digite o cargo do funcionario: ");
        scanf("%[^\n]%*c", cargo);
        printf("Informe o valor do salario base: ");
        scanf("%lf", &salarioBase);
        printf("Infome o valor dos beneficios: ");
        scanf("%lf", &beneficios);
        printf("Informe o valor dos descontos: ");
        scanf("%lf", &descontos);
        salarioLiquido = salarioBase + beneficios - descontos;
    }

    void imprimir(){
        printf("Nome: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        printf("Salario Base: %2.lf\n", salarioBase);
        printf("Beneficios: %2.lf\n", beneficios);
        printf("Descontos: %2.lf\n", descontos);
        printf("Salario Liquido: %2.lf\n", salarioLiquido);
    }
};

struct Loja{
    Funcionario funcionario[maxFuncionario];

    void cadastrar(){
        if(contFuncionario < maxFuncionario){
            funcionario[contFuncionario].ler();
            contFuncionario++;
            printf("\nFuncionario cadastrado com sucesso!!\n");
            printf(" - - - - - - - - - - -\n");
        } else{
            printf("\nO numero de funcionarios cadastrados chegou ao limite, nao e possivel cadastrar mais.\n");
        }
    }

    void listar(){
        if(contFuncionario > 0){
            for(int i = 0; i < contFuncionario; i++){
                printf("ID Funcionario: %d\n", (i+1));
                funcionario[i].imprimir();
                printf("- - - - - - - -\n");
            }
        } else{
            printf("\nLista de funcionarios vazia, ainda nao ha funcionarios cadastrados.\n");
        }
    }

    void mediaSalarial(){
        if(contFuncionario > 0){
            double somaSalario = 0;
            double salarioMedio = 0;
            for(int i = 0; i < contFuncionario; i++){
                somaSalario += funcionario[i].salarioLiquido;
            }
            salarioMedio = somaSalario / contFuncionario;
            printf("A media salarial dos funcionarios e de: %.2lf\n", salarioMedio);
            printf("- - - - - - - -\n");
        } else{
            printf("\nLista de funcionarios vazia, ainda nao ha funcionarios cadastrados.\n");
        }
    }

    void maiorSalario(){
        if(contFuncionario > 0){
            int indiceMaior = 0;
            for(int i = 0; i < contFuncionario; i++){
                if(funcionario[i].salarioLiquido > funcionario[indiceMaior].salarioLiquido){
                    indiceMaior = i;
                }
            }
            printf("Nome: %s\n", funcionario[indiceMaior].nome);
            printf("Cargo: %s\n", funcionario[indiceMaior].cargo);
            printf("Salario Base: %2.lf\n", funcionario[indiceMaior].salarioBase);
            printf("Beneficios: %2.lf\n", funcionario[indiceMaior].beneficios);
            printf("Descontos: %2.lf\n", funcionario[indiceMaior].descontos);
            printf("Salario Liquido: %2.lf\n", funcionario[indiceMaior].salarioLiquido);
            printf("- - - - - - - -\n");
        } else{
            printf("\nLista de funcionarios vazia, ainda nao ha funcionarios cadastrados.\n");
        }
    }
};

int main(){
    Loja loja;

    int escolha;

    do{
        printf("\n- - - Loja - - -\n");
        printf(">        Menu        <\n");
        printf("1 - Cadastrar novo funcionario\n");
        printf("2 - Listar todos os funcionarios\n");
        printf("3 - Mostrar a media salarial dos funcionarios\n");
        printf("4 - Mostrar o funcionario com maior salario\n");
        printf("5 - Sair\n");
        scanf("%d%*c", &escolha);

        switch(escolha)
        {
        case 1:
            printf("\n- - - Cadastro - - -\n");
            loja.cadastrar();
            printf("\n");
            break;
        case 2:
            printf("\n- - - Lista - - -\n");
            loja.listar();
            printf("\n");
            break;
        case 3:
            printf("\n- - - Media salarial - - -\n");
            loja.mediaSalarial();
            printf("\n");
            break;
        case 4:
            printf("\n- - - Maior salario - - -\n");
            loja.maiorSalario();
            printf("\n");
            break;
        case 5:
            printf("\nSaindo, volte sempre! :)");
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;



        }
    }while(escolha != 5);


    return 0;
}
