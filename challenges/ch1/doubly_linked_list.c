    #include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertFrontNode(struct Node**, int);
void printMenu();
void printWelcome();

int main(){
    int selectedOption = -1;

    struct Node *head = NULL;
        
    printWelcome();
        
    while(selectedOption != 0){

        printMenu();
        selectedOption = readInt();
        
        
        if( (selectedOption > 4 || selectedOption < 0)){
            system("clear");
            printf("\nValue not valid: %d\n", selectedOption);     
            selectedOption = -1;       
            continue;
        }

        if(selectedOption == 1){
            int newData;
            printf("Value: ");
            newData = readInt();

            insertFrontNode(&head, newData);
            system("clear");
        }

        printLinkedList(&head);        
        
    }


    return 0;
}


void printLinkedList(struct Node** head){
    if((*head) == NULL){
        return;
    }

    struct Node* tmp = (*head);
    
    while((tmp) != NULL){
        if(tmp->prev == NULL){
            printf("(HEAD) ");
        }

        printf("%d", tmp->data);        

        if(tmp->next != NULL){
            printf("->");
        }

        tmp = (tmp->next);
    }    
    printf("\n");
}

void insertFrontNode(struct Node** head, int data){

    struct Node* newNode =  malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = (*head);    
    newNode->prev = NULL;

    if((*head) != NULL)
        (*head)->prev = newNode; // (Dereference operator)
    
    (*head) = newNode;
}


void printMenu(){
    printf("Select Option\n1) Insert Value at the begining\n0) Exit: ");
}

void printWelcome(){
    printf("************ Doubly linked List *************\n");
}

int readInt(){
    int read = 0;

    while(scanf("%d", &read) != 1){
        system("clear");
        continue;
    };
    fflush(stdin);   

    return read;
}