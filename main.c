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
        printf("primeiro");
    }
    // se for a ultima node
    else if(currentNode->nextNode == NULL){
        // node anterior aponta para null
        currentNode->previousNode->nextNode = NULL;
        printf("segundo");
    }
    // se for a primeira node
    else if(currentNode->previousNode == NULL){
        // head aponta para a proxima node e proxima node aponta para head
        head = currentNode->nextNode;
        currentNode->nextNode->previousNode = head;
        printf("terceiro");
        
    }
    // se estiver no meio
    else{
        // node anterior aponta para a proxima node e proxima node aponta para node anterior
        currentNode->previousNode->nextNode = currentNode->nextNode;
        currentNode->nextNode->previousNode = currentNode->previousNode;
        printf("quarto");
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
    
}



// testes
int main(){

    Node node1 = {"Victor", 47, 999999999};
    Node node2 = {"Manfred", 49, 888888888};
    Node node3 = {"Joao", 42, 555555555};
    Node node4 = {"Thiago", 44, 444444444};

    criarContato(&node1);
    criarContato(&node2);
    criarContato(&node3);
    criarContato(&node4);

    
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


    listarContatos();
    printf("\n");
    deletarContatoNome("Manfred");
    printf("\n");
    listarContatos();

    return 0;
}
