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
    
    // previousNode da nextNode vira a previousNode atual
    *currentNode->nextNode->previousNode = *currentNode->previousNode;
    
    // nextNode da previousNode vira a nextNode atual
    *currentNode->previousNode->nextNode = *currentNode->nextNode;
    
}


// funcao que printa uma node
void printNode(Node* node){

    printf("%s | %d | %d", node->nome, node->ddd, node->numero);
}


// testes
int main(){

    Node node1 = {"Victor", 47, 999999999};
    Node node2 = {"Manfred", 49, 888888888};

    criarContato(&node1);
    criarContato(&node2);

    
    printf("%d", (*head).numero);
    printf("\n");
    printf("%d", (*head).nextNode->numero);
    
    
    
    printf("\n");
    atualizarContatoNome("Manfred", 777777777, 42);
    printf("%d-%d", (*head).ddd, (*head).numero);
    
    //printf("\n");
    //printf("%d", lerContatoNome("Victor")->ddd);
    //printf("\n");
    //printf("%d", lerContatoNumero(888888888)->ddd);

    printf("\n");
    printNode((*head).nextNode);

    return 0;
}
