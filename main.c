#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //Biblioteca para sleep;
#include <time.h>

typedef struct{
    int codigo;
    char nome[50];
    char email[50];
    char cpf[20];
    char dataNascimento[20];
    char dataCadastro[20];
} Cliente;

typedef struct {
    int numero;
    Cliente cliente;
    float saldo;
    float limite;
    float saldoTotal; //Soma de saldo + limite;
} Conta;

void menu();
void infoCliente(Cliente cliente);
void infoConta(Conta conta);
void criarConta();
void efetuarSaque();
void efetuarDeposito();
void efetuarTransferencia();
void listarContas();
float atualizaSaldoTotal(Conta conta);
Conta buscarContaPorNumero(int numero);
void sacar(Conta conta, float valor);
void depositar(Conta conta, float valor);
void transferir(Conta contaOrigem, Conta contaDestino, float valor );

static Conta contas[50];
static int contadorContas = 0;
static int contadorClientes = 0;


int main() {
    menu();

    return 0;
}

void menu(){
    int opcao = 0;
    printf("--------------------------\n");
    printf("---------- ATM -----------\n");
    printf("--- Banco Cyber Marssy ---\n");
    printf("--------------------------\n");

    printf("Selecione uma opção no menu:\n");
    printf("1 - Criar conta\n");
    printf("2 - Efetuar saque:\n");
    printf("3 - Efetuar depósito:\n");
    printf("4 - Efetuar transferência:\n");
    printf("5 - Listar contas:\n");
    printf("6 - Sair:\n");

    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            criarConta();
            break;
        case 2:
            efetuarSaque();
            break;
        case 3:
            efetuarDeposito();
            break;
        case 4:
            efetuarTransferencia();
            break;
        case 5:
            listarContas();
            break;
        case 6:
            printf("Obrigado(a) por utilizar nosso sistema !\n");
            sleep(2);
            exit(0);
        default:
            printf("Por favor selecione uma opção válida !\n");
            sleep(2);
            menu();
            break;
    }

}

void infoCliente(Cliente cliente){
    printf("Código: %d \nNome: %s \nData de nascimento %s \nData de cadastro %s\n",
           cliente.codigo, strtok(cliente.nome, "\n"), strtok(cliente.dataNascimento, "\n"),
           strtok(cliente.dataCadastro, "\n"));

}

void infoConta(Conta conta){
    printf("Número da conta: %d \nCliente: %s \nData de nascimento: %s \nData de cadastro: %s \nSaldo Total: %.2f\n",
           conta.numero, strtok(conta.cliente.nome, "\n"), strtok(conta.cliente.dataNascimento, "\n"),
           strtok(conta.cliente.dataCadastro, "\n"), conta.saldoTotal);
}

void criarConta(){
     Cliente cliente;

    //Criação de data de cadastro;
    char dia[3];
    char mes[3];
    char ano[5];
    char dataCadastro[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //Dia;
    if(tm.tm_mday < 10){
        sprintf(dia, "0%d", tm.tm_mday);
    }else{
        sprintf(dia, "%d", tm.tm_mday);
    }

    //Mês;
    if((tm.tm_mon + 1) < 10){
        sprintf(mes, "0%d", tm.tm_mon + 1);
    }else{
        sprintf(mes, "%d", tm.tm_mon + 1);
    }

    //Ano;
    sprintf(ano, "%d", tm.tm_year + 1900);

    strcpy(dataCadastro, "");
    strcat(dataCadastro, dia);
    strcat(dataCadastro, "/");
    strcat(dataCadastro, mes);
    strcat(dataCadastro, "/");
    strcat(dataCadastro, ano);
    strcat(dataCadastro, "\0");
    strcpy(cliente.dataCadastro, dataCadastro);

    //Criação de cliente;
    printf("Informe os dados do cliente: \n"); //Preenchimento do código (ID);
    cliente.codigo = contadorClientes + 1;

    printf("Nome do cliente:\n"); //Preenchimento do nome;
    fgets(cliente.nome, 50, stdin);

    printf("E-mail do cliente:\n"); //Preenchimento do e-mail;
    fgets(cliente.email, 50, stdin);

    printf("CPF do cliente:\n"); //Preenchimento do CPF;
    fgets(cliente.cpf, 20, stdin);

    printf("Data de nascimento do cliente:\n"); //Preenchimento da data de nascimento;
    fgets(cliente.dataNascimento, 20, stdin);

    contadorClientes++;

    //Criação da conta;
    //Preenchimento do numero da conta(ID);
    contas[contadorContas].numero = contadorContas + 1;
    //Vincula o cliente a conta;
    contas[contadorContas].cliente = cliente;
    //Define saldo inicial (sempre iniciado em 0);
    contas[contadorContas].saldo = 0.0;
    //Define limite inicial (sempre iniciado em 0);
    contas[contadorContas].limite = 0.0;
    //Define saldo total (saldo + limite);
    contas[contadorContas].saldoTotal = atualizaSaldoTotal(contas[contadorContas]);

    printf("Conta criada com sucesso !\n");
    printf("\n");
    printf("Dados da conta criada: \n");
    printf("\n");
    infoConta(contas[contadorContas]);
    contadorContas++;

    sleep(5);
    menu();
}

float atualizaSaldoTotal(Conta conta){
    return conta.saldo + conta.limite;
}

Conta buscarContaPorNumero(int numero){
    Conta c;
    if(contadorContas > 0){ //Verifica se user tem conta aberta no banco;
        for(int i = 0; i < contadorContas; i++){ //Laço de repetição para consultar as contas do user;
            if(contas[i].numero == numero){ //Verifica nas contas do user o número de conta pesquisada;
                c = contas[i]; //Recebe a conta pesquisada;
            }
        }
    }
    return c;
}

void sacar(Conta conta, float valor){
    //Verifica se o valor é maior que zero e se possui saldo para saque;
    if(valor > 0 && conta.saldoTotal >= valor){
        //Consultar as contas do user;
        for(int i = 0; i < contadorContas; i ++){
            //Verifica o numero da conta;
            if(contas[i].numero == conta.numero){
                //Verifica se user possui saldo suficiente;
                if(contas[i].saldo >= valor){
                    //Faz a subtração do valor sacado;
                    contas[i].saldo = contas[i].saldo - valor;
                    //Atualiza saldo total da conta;
                    contas[i].saldoTotal = atualizaSaldoTotal(contas[i]);
                    printf("Saque efetuado com sucesso !\n");
                //Caso user não possua saldo suficiente mas, tenha limite;
                }else{
                    //Faz a subtração do saldo + limite;
                    float restante = contas[i].saldo - valor;
                    //Atualiza limite;
                    contas[i].limite = contas[i].limite - restante;
                    //Atualiza saldo automaticamente para 0;
                    contas[i].saldo = 0.0;
                    //Atualiza saldo total da conta;
                    contas[i].saldoTotal = atualizaSaldoTotal(contas[i]);
                    printf("Saque relizado com sucesso !\n");
                }
            }
        }
    //Caso valor informado for menor que zero ou não possuir saldo para saque;
    }else{
        printf("Saque não realizado. Tente novamente.\n");
    }
}

void depositar(Conta conta, float valor){
    //Verifica se o valor a ser depositado é maior que 0;
    if(valor > 0){
        for(int i = 0; i < contadorContas; i++){
            //Verifica o número da conta;
            if(contas[i].numero == conta.numero){
                //Atualiza o valor do saldo;
                contas[i].saldo = contas[i].saldo + valor;
                //Atualiza o valor do saldo total;
                contas[i].saldoTotal = atualizaSaldoTotal(contas[i]);
                printf("Depósito realizado com sucesso !\n");
            }
        }
    //Caso o valor for igual ou menor que zero;
    }else{
        printf("Deposito não realizado. Tente novamente\n");
    }
}

void transferir(Conta contaOrigem, Conta contaDestino, float valor){
    //Verifica se o valor é maior que zero, se possui conta e se possui saldo para deposito;
    if(valor > 0 && contadorContas > 0 && contaOrigem.saldoTotal >= valor){
        //Consultar as contas do user (depositador);
        for (int co = 0; co < contadorContas; co++) {
            //Verifica o numero da conta (depositador);
            if(contas[co].numero == contaOrigem.numero){
                //Consultar as contas do user (recebidor);
                for(int cd = 0; cd < contadorContas; cd++){
                    //Verifica o número da conta (recebidor);
                    if(contas[cd].numero == contaDestino.numero){
                        //Verifica se possuí saldo suficiente(depositador);
                        if(contas[co].saldo >= valor){
                            //Faz a subtração do valor depositado;
                            contas[co].saldo = contas[co].saldo - valor;
                            //Faz a adição do valor recebido;
                            contas[cd].saldo = contas[cd].saldo + valor;
                            //Atualiza saldo total (depositador);
                            contas[co].saldoTotal = atualizaSaldoTotal(contas[co]);
                            //Atualiza saldo total (recebidor);
                            contas[cd].saldoTotal = atualizaSaldoTotal(contas[cd]);
                            printf("Tasnferência realizada com sucesso !\n");
                        //Caso user (depositador) não possua saldo suficiente mas, tenha limite;
                        }else{
                            //Faz a subtração do saldo parcial;
                            float restante = contas[co].saldo - valor;
                            //Faz a subtração do limite suficiente para fechar o valor total;
                            contas[co].limite = contas[co].limite - restante;
                            //Atualiza saldo (depositador)
                            contas[co].saldo = 0.0;
                            //Atualiza saldo (recebidor);
                            contas[cd].saldo = contas[cd].saldo + valor;
                            //Atualiza saldo total (depositador);
                            contas[co].saldoTotal = atualizaSaldoTotal(contas[co]);
                            //Atualiza saldo total (recebidor);
                            contas[cd].saldoTotal = atualizaSaldoTotal(contas[cd]);
                            printf("Tasnferência realizada com sucesso !\n");
                        }
                    }
                }
            }
        }
    }else{
        printf("Transferência não realizada. Tente novamente\n");
    }
}

void efetuarSaque(){
    //Verifica se existem contas;
    if(contadorContas > 0){
        //Verifica o numero da conta;
        int numero;
        printf("Informe o número da conta: \n");
        scanf("%d", &numero);

        //Realiza a busca da conta chamando a função "buscarContaPorNumero()";
        Conta conta = buscarContaPorNumero(numero);

        //Verifica o número da conta;
        if(conta.numero == numero){
            //Verifica o valor do saque;
            float valor;
            printf("Informe o valor a ser sacado: \n");
            scanf("%d", &valor);
            //Realiza o saque chamando a função "sacar()";
            sacar(conta, valor);
        //Caso o número da conta não seja encontrado;
        }else{
            printf("Não foi encontrada uma conta com o numero %d \n", numero);
        }
    //Caso a conta não seja encontrada:
    }else{
        printf("Conta inexistemte para saque.\n");
    }

    sleep(2);
    menu();
}

void efetuarDeposito(){
    //Verifica se existem contas;
    if(contadorContas > 0) {
        //Verifica o numero da conta;
        int numero;
        printf("Informe o número da conta: \n");
        scanf("%d", &numero);

        //Realiza a busca da conta chamando a função "buscarContaPorNumero()";
        Conta conta = buscarContaPorNumero(numero);

        //Verifica o número da conta;
        if (conta.numero == numero) {
            //Verifica o valor do depósito;
            float valor;
            printf("Informe o valor a ser depositado: \n");
            scanf("%d", &valor);
            //Realiza o saque chamando a função "depositar()";
            depositar(conta, valor);
            //Caso o número da conta não seja encontrado;
        } else {
            printf("Não foi encontrada uma conta com o numero %d \n", numero);
        }
    //Caso a conta não seja encontrada;
    }else{
        printf("Conta inexistemte para depósito.\n");
    }

    sleep(2);
    menu();
}

void efetuarTransferencia(){
    //Verifica se existem contas:
    if(contadorContas > 0){
        //Verifica os números das contas;
        int numeroO, numeroD;
        printf("Informe o número da sua conta: \n ");
        scanf("%d", &numeroO);

        //Realiza a busca da conta de origem chamando a função "buscarContaPorNumero()";
        Conta contaO = buscarContaPorNumero(numeroO);

        //Verifica o número da conta de origem;
        if(contaO.numero == numeroO){
            printf("Informe o numero da conta de destino: \n");
            scanf("%d", &numeroD);

            //Realiza a busca da conta de destino chamando a função "buscarContaPorNumero()";
            Conta contaD = buscarContaPorNumero(numeroD);

            //Verifica o número da conta de destino;
            if(contaD.numero == numeroD){
                //Verifica o valor da transferência;
                float valor;
                printf("Informe o valor a ser transferido: \n");
                scanf("%f", &valor);
                //Realiza a transferência chamando a função "transferir()";
                transferir(contaO, contaD, valor);
            //Caso o número da conta de destino não seja encontrado;
            }else{
                printf("Conta destino de numero %d não foi encontrada.\n", numeroD);
            }
        //Caso o número da conta de origem não seja encontrado;
        }else{
            printf("Conta com número %d não foi encontrada.\n", numeroO);
        }
        //Caso a conta de origem não seja encontrado;
    }else{
        printf("Conta inexistente para transferência.\n");
    }

    sleep(2);
    menu();
}

void listarContas(){
    if(contadorContas > 0){
        for(int i = 0; i < contadorContas; i++){
            infoConta(contas[i]);
            printf("\n");
            sleep(1);
        }
    }else{
        printf("Não existem contas cadastradas.\n");
    }

    sleep(2);
    menu();
}