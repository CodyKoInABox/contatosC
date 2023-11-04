//-----------------------------------------------------------//
//  Estrutura de Dados                                       //
//  N2 -> Gerenciador de Contatos com Doubly Linked List     //
//-----------------------------------------------------------//
//  Maruan Biasi    |  https://github.com/codykoinabox       //
//  Victor Matheus  |  https://github.com/victormmoreira98   //
//-----------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mainMenu();

typedef char String[100];

// Estrutura de uma node da lista
struct Node{
    String nome;
    int ddd;
    int numero;

    struct Node *nextNode;
    struct Node *previousNode;
};

typedef struct Node Node;


// Head da lista
Node* head = NULL;

// Criar novo contato
// newNode = Nova node que sera adicionada a lista (deve conter o contato)
void criarContato(Node* newNode){
    
    // Caso a lista esteja vazia
    if(head == NULL){

        // Head aponta para a primeira node
        head = newNode;

        // Primeira node aponta para null
        newNode->previousNode = NULL;
        newNode->nextNode = NULL;
    }
    // Caso ja existam nodes na lista, adicionar a nova node no inicio
    else{

        // Nova node aponta para NULL
        newNode->previousNode = NULL;

        // Nova node aponta para a proxima node
        newNode->nextNode = &(*head);

        // Head aponta para a nova node
        head = newNode;
        
        // proxima node aponta para a nova primeira node
        newNode->nextNode->previousNode = newNode;
    }
}


// Ler um contato baseado no nome do titular
Node *lerContatoNome(String nome){
    
    Node *currentNode = head;

    while(strcmp(currentNode->nome, nome) != 0){
    
       currentNode = currentNode->nextNode;
    }

    return currentNode;
}

// Ler um contato baseado no numero
Node *lerContatoNumero(int numero){
    
    Node *currentNode = head;

    while(currentNode->numero != numero){
    
       currentNode = currentNode->nextNode;
    }

    return currentNode;
}


// atualizar o numero de um contato baseado no nome
// nome = nome do contato a ser atualizado
// novoNumero = novo numero do contato
// novoDDD = novo DDD do contato
void atualizarContatoNome(String nome, int novoNumero, int novoDDD){
    
    Node *currentNode = head;

    while(strcmp(currentNode->nome, nome) != 0){
    
       currentNode = currentNode->nextNode;
    }
    
    currentNode->numero = novoNumero;
    currentNode->ddd = novoDDD;
    
}


// deletar um contato baseado no nome
void deletarContatoNome(String nome){
    
    Node *currentNode = head;

    while(strcmp(currentNode->nome, nome) != 0){
    
       currentNode = currentNode->nextNode;
    }
    
    // se for a unica node
    if(currentNode->nextNode == NULL && currentNode->previousNode == NULL){
        // head vira null
        head = NULL;
        
    }
    // se for a ultima node
    else if(currentNode->nextNode == NULL){
        // node anterior aponta para null
        currentNode->previousNode->nextNode = NULL;

    }
    // se for a primeira node
    else if(currentNode->previousNode == NULL){
        // head aponta para a proxima node e proxima node aponta para head
        head = currentNode->nextNode;
        currentNode->nextNode->previousNode = head;
          
    }
    // se estiver no meio
    else{
        // node anterior aponta para a proxima node e proxima node aponta para node anterior
        currentNode->previousNode->nextNode = currentNode->nextNode;
        currentNode->nextNode->previousNode = currentNode->previousNode;
    }

    
}

// funcao que printa uma node
void printNode(Node* node){

    printf(" %d | %d | %s", node->ddd, node->numero, node->nome);

}


// funcao que lista todos os contatos
void listarContatos(){

    Node *currentNode = head;

    printf("DDD |  NUMERO   | NOME");

    while(currentNode != NULL){
        printf("\n");
        printNode(currentNode);
        currentNode = currentNode->nextNode;
    }

    return;
    
}

void criarContatoMenu(){

    Node newContato;

    printf("CRIAR CONTATO");
    printf("\n");
    printf("-------------");
    printf("\n");
    printf("Insira o nome: ");
    gets(newContato.nome);
    printf("Insira o DDD: ");
    scanf("%d", &newContato.ddd);
    fflush(stdin);
    printf("Insira o numero: ");
    scanf("%d", &newContato.numero);
    fflush(stdin);

    criarContato(&newContato);

    mainMenu();

}


void listarContatosMenu(){

    listarContatos();

    printf("\n");
    printf("Pressione alguma tecla para voltar ao menu: ");
    getchar();
    mainMenu();

}

void buscarContatoMenu(){

    int buscarOp;

    printf("BUSCAR CONTATO");
    printf("\n");
    printf("--------------");
    printf("\n");
    printf("1 -> Buscar nome");
    printf("\n");
    printf("2 -> Buscar numero");
    printf("\n");
    printf("Insira sua opcao: ");
    scanf("%d", &buscarOp);
    fflush(stdin);

    system("cls");

    String nome;
    int numero;



    switch(buscarOp){
        // buscar nome
        case 1:
            printf("BUSCAR NOME");
            printf("\n");
            printf("--------------");
            printf("\n");
            printf("Insira o nome: ");
            gets(nome);
            system("cls");
            printNode(lerContatoNome(nome));
            printf("\n");
            printf("Pressione alguma tecla para voltar ao menu: ");
            getchar();
            mainMenu();
        break;
        // buscar numero
        case 2:
        
            printf("BUSCAR NUMERO");
            printf("\n");
            printf("--------------");
            printf("\n");
            printf("Insira o numero: ");
            scanf("%d", &numero);
            fflush(stdin);
            system("cls");
            printNode(lerContatoNumero(numero));
            printf("\n");
            printf("Pressione alguma tecla para voltar ao menu: ");
            getchar();
            mainMenu();

        break;

        default:
            buscarContatoMenu();
        break;
    }
}

void atualizarContatoMenu(){

    String nome;
    int ddd;
    int numero;

    printf("ATUALIZAR CONTATO");
    printf("\n");
    printf("-------------");
    printf("\n");
    printf("Insira o nome do contato: ");
    gets(nome);
    printf("Insira o novo DDD: ");
    scanf("%d", &ddd);
    fflush(stdin);
    printf("Insira o novo numero: ");
    scanf("%d", &numero);
    fflush(stdin);

    atualizarContatoNome(nome, numero, ddd);

    printf("\n");
    printf("Pressione alguma tecla para voltar ao menu: ");
    getchar();
    mainMenu();

}

void deletarContatoMenu(){

    String nome;

    printf("DELETAR CONTATO");
    printf("\n");
    printf("-------------");
    printf("\n");
    printf("Insira o nome do contato: ");
    gets(nome);

    deletarContatoNome(nome);

    printf("\n");
    printf("Pressione alguma tecla para voltar ao menu: ");
    getchar();
    mainMenu();

}


void mainMenu(){
    int op;
    
    system("cls");

    printf("|-- GERENCIADOR DE CONTATOS --|");
    printf("\n");
    printf("-------------------------------");
    printf("\n");
    printf("| 1 -> Listar Contatos");
    printf("\n");
    printf("| 2 -> Buscar Contato");
    printf("\n");
    printf("| 3 -> Criar Contato");
    printf("\n");
    printf("| 4 -> Atualizar Contato");
    printf("\n");
    printf("| 5 -> Deletar Contato");
    printf("\n");
    printf("| 6 -> Sair");
    printf("\n");
    printf("-------------------------------");
    printf("\n");
    printf("Insira a opcao: ");
    
    scanf("%d", &op);
    fflush(stdin);
    
    system("cls");
    
    switch(op){

        // listar contatos
        case 1:
            listarContatosMenu();
        break;

        // buscar contato
        case 2:
            buscarContatoMenu();
        break;

        // criar contato
        case 3:
            criarContatoMenu();
        break;

        // atualizar contato
        case 4:
            atualizarContatoMenu();
        break;

        // deletar contato
        case 5:
            deletarContatoMenu();
        break;

        // sair
        default:
            exit(1);
        break;
    }
}


// testes
int main(){

    //Node node1 = {"Victor", 47, 999999999};
    //Node node2 = {"Manfred", 49, 888888888};
    //Node node3 = {"Joao", 42, 555555555};
    //Node node4 = {"Thiago", 44, 444444444};

    //criarContato(&node1);
    //criarContato(&node2);
    //criarContato(&node3);
    //criarContato(&node4);
    
    mainMenu();


    //printf("%d", (*head).numero);
    //printf("\n");
    //printf("%d", (*head).nextNode->numero);
    
    
    
    //printf("\n");
    //atualizarContatoNome("Manfred", 777777777, 42);
    //printf("%d-%d", (*head).ddd, (*head).numero);
    
    //printf("\n");
    //printf("%d", lerContatoNome("Victor")->ddd);
    //printf("\n");
    //printf("%d", lerContatoNumero(888888888)->ddd);

    //printf("\n");
    //printNode((*head).nextNode);
    //printf("\n");
    //printf("\n");


    //listarContatos();
    //printf("\n");
    //deletarContatoNome("Victor");
    //printf("\n");
    //listarContatos();

    return 0;
}
