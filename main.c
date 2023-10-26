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




// testes
int main(){

    Node node1 = {"Victor", 47, 999999999};
    Node node2 = {"Manfred", 49, 888888888};

    criarContato(&node1);
    criarContato(&node2);

    
    //printf("%d", (*head).ddd);
    //printf("\n");
    //printf("%d", (*head).nextNode->ddd);
    
    printf("\n");
    printf("%d", lerContatoNome("Victor")->ddd);
    printf("\n");
    printf("%d", lerContatoNumero(888888888)->ddd);

    return 0;
}
