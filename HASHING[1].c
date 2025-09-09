#include <stdio.h>
#include <stdlib.h>
#define TABLESIZE 10
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* HashTable[TABLESIZE];
void initHashTable() {
    for (int i = 0; i < TABLESIZE; i++) {
        HashTable[i] = NULL; 
    }
}
int hashFunction(int key) {
    return key % TABLESIZE;
}
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);
    
    if (HashTable[index] == NULL) {
        HashTable[index] = newNode;
    } else {
        Node* temp = HashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void delete(int key){
    int index = hashFunction(key);
    Node* temp = HashTable[index];
    Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key %d not found in the hash table.\n", key);
        return;
    }
    if (prev == NULL) {
        HashTable[index] = temp->next; 
    } else {
        prev->next = temp->next; 
    }
    free(temp);
    printf("Key %d deleted from the hash table.\n", key);
}
int search(int key) {
    int index = hashFunction(key);
    Node* temp = HashTable[index];
    while (temp != NULL) {
        if (temp->data == key) {
            return 1; 
        }
        temp = temp->next;
    }
    return 0; 
}
void display() {
    for (int i = 0; i < TABLESIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = HashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    initHashTable();
    int choice, key;
    while (1) {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3.Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(key)) {
                    printf("Key %d found in the hash table.\n", key);
                } else {
                    printf("Key %d not found in the hash table.\n", key);
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
