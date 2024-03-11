//Autor: Adriano Prates

#include <stdio.h>
#include <ctype.h>
#include <time.h>

//definindo valores
#define maxCliente 50
#define maxNome 50

//criando contador para o numero de clientes
int contCliente = 0;

struct Data{
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;

    int diaAtual;
    int mesAtual;
    int anoAtual;

    //data atual
    void dataInicial(){
        time_t dataAtual;
        struct tm *infoTempo;
        time(&dataAtual);
        infoTempo = localtime(&dataAtual);
        diaAtual = infoTempo->tm_mday;
        mesAtual = infoTempo->tm_mon + 1;
        anoAtual = infoTempo->tm_year + 1900;
    }
};

struct Cliente{
    char nome[maxNome];
    Data data;
    int idade;
    char sexo;

    void ler(){
        printf("Digite o nome: ");
        scanf("%[^\n]%*c", nome);
        while(1){
            printf("Digite a data de nascimento no formato dia/mes/ano: ");
            int verificaData = scanf("%d/%d/%d", &data.diaNascimento, &data.mesNascimento, &data.anoNascimento);
            if(verificaData != 3 || !validarData(data.diaNascimento, data.mesNascimento, data.anoNascimento)){
                continue;
            } else{
                calcularIdade(data.diaNascimento, data.mesNascimento, data.anoNascimento);
                break;
            }
        }
        do{
            printf("Informe o sexo (M/F):\n");
            scanf(" %c", &sexo);
            sexo = tolower(sexo);
            switch(sexo){
                case 'm':
                    printf("Sexo masculino selecionado.\n");
                    break;
                case 'f':
                    printf("Sexo feminino selecionado.\n");
                    break;
                default:
                    printf("Opcao invalida.\n");
            }
        }while(sexo != 'm' && sexo != 'f');

        sexo = toupper(sexo);
    }

    bool validarData(int diaNascimento, int mesNascimento, int anoNascimento){
        if(diaNascimento< 1 || mesNascimento < 1 || mesNascimento > 12 || anoNascimento < 0 ||
           ((mesNascimento == 1 || mesNascimento == 3 || mesNascimento == 5 || mesNascimento == 7 ||
            mesNascimento == 8 || mesNascimento == 10 || mesNascimento == 12) && diaNascimento > 31) ||
           ((mesNascimento == 4 || mesNascimento == 6 || mesNascimento == 9 || mesNascimento == 11) &&
            diaNascimento > 30) || (mesNascimento == 2 && ((anoNascimento % 4 != 0 && diaNascimento > 28)
            || (diaNascimento > 29)))){
            printf("Data invalida. Insira uma data valida no formato dia/mes/ano.\n");
            return false;
        } else{
            return true;
        }
    }

    void calcularIdade(int diaNascimento, int mesNascimento, int anoNascimento){
        data.dataInicial();
        idade = data.anoAtual - anoNascimento;
        if(data.mesAtual < mesNascimento || (data.mesAtual == mesNascimento && data.diaAtual < diaNascimento)){
            idade--;
        }

        this->idade = idade;
    }

    void imprimir(){
        printf("Nome: %s\n", nome);
        printf("Data de Nascimento: %02d/%02d/%d\n", data.diaNascimento, data.mesNascimento, data.anoNascimento);
        printf("Idade: %d\n", idade);
        printf("Sexo: %c\n", sexo);
    }
};

struct Gerenciador{
    Cliente cliente[maxCliente];

    void cadastrar(){
        if(contCliente < maxCliente){
            cliente[contCliente].ler();
            contCliente++;
            printf("\nCliente cadastrado com sucesso!!\n");
            printf(" - - - - - - - - - - -\n");
        } else{
            printf("\nO numero de clientes cadastrados chegou ao limite, nao e possivel cadastrar mais.\n");
        }
    }

    void listar(){
        if(contCliente > 0){
            for(int i = 0; i < contCliente; i++){
                printf("ID Cliente: %d\n", (i+1));
                cliente[i].imprimir();
                printf("- - - - - - - -\n");
            }
        } else{
            printf("\nLista de clientes vazia, ainda nao ha clientes cadastrados.\n");
        }
    }
};

int main(){
    Gerenciador gerenciador;
    int escolha;

    do{
        printf("\n- - - Gerenciamento de Clientes - - -\n");
        printf(">                 Menu                <\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Sair\n");
        scanf("%d%*c", &escolha);

        switch (escolha)
        {
        case 1:
            printf("\n- - - Cadastro - - -\n");
            gerenciador.cadastrar();
            printf("\n");
            break;
        case 2:
            printf("\n- - - Lista - - -\n");
            gerenciador.listar();
            printf("\n");
            break;
        case 3:
            printf("\nSaindo, volte sempre! :)");
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }while(escolha != 3);

    return 0;
}
