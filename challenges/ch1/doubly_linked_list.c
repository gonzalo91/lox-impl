#include <stdio.h>
#include <stdlib.h>




int readInt();
void printMenu();
void printWelcome();
void printLinkedList(struct Node**);
void insertEndNode(struct Node**, int);
void insertFrontNode(struct Node**, int);
void deleteNodeByValue(struct Node**, int);
void findFirstOccurrenceByValue(struct Node**, int);

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

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

        if(selectedOption == 0){
            continue;            
        }

        int newData;
        printf("Value: ");
        newData = readInt();

        

        if(selectedOption == 1){

            insertFrontNode(&head, newData);
            system("clear");
        }

        if(selectedOption == 2){
            insertEndNode(&head, newData);
            system("clear");
        }

        if(selectedOption == 3){
            deleteNodeByValue(&head, newData);
            system("clear");
        }

        if(selectedOption == 4){
            system("clear");
            findFirstOccurrenceByValue(&head, newData);
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

void insertEndNode(struct Node** head, int data){
    struct Node* newNode =  malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;    
    newNode->prev = NULL;

    if((*head) == NULL){
        (*head) = newNode;
    }else{
        struct Node* tmp = (*head);
        while((tmp)->next != NULL){                        
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }  
}

void deleteNodeByValue(struct Node** head, int data){    

    if((*head) == NULL){
        return;
    }

    struct Node* tmp = (*head);

    if(tmp == NULL) return;

    do{

        if(tmp->data == data){
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            break;
        }
        tmp = tmp->next;

    }
    while((tmp)->next != NULL);           
}


void findFirstOccurrenceByValue(struct Node** head, int data){

    struct Node* tmp = (*head);

    
    if(tmp == NULL) { printf("=== Not found ===\n"); return; } 

    do{

        if(tmp->data == data){
            printf("===== ");

            if(tmp->prev != NULL){
                printf("%d->", tmp->prev->data);
            }

            printf("%d", tmp->data);

            if(tmp->next != NULL){
                printf("->%d", tmp->next->data);
            }

            printf(" =====\n");
            return;
        }
        tmp = tmp->next;

    }
    while((tmp) != NULL);

    printf("=== Not found ===\n");
}

void printMenu(){
    printf("Select Option\n1) Insert Value at the begining\n2) Insert Value at the end\n3) Delete first occurrence\n4) Find firts occurrence\n0) Exit: ");
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