#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char name[20];
    int score;
    struct Node *next;
};


int main() {
    char input[7];
    scanf("%s", input);

    struct Node *prevNode = malloc(sizeof(struct Node));
    struct Node *head = prevNode;
    struct Node *tail = head;

    while (1) {
        if (!strcmp(input, "quit")) {
            break; 
        }

        if (!strcmp(input, "add")) {
            struct Node *nextNode = malloc(sizeof(struct Node));
            nextNode->next = NULL;

            tail->next = nextNode;
            tail = nextNode;

            scanf("%s %d", nextNode->name, &nextNode->score);

            prevNode = prevNode->next;
        } else if (!strcmp(input, "delete")) {
            char name[20];
            scanf("%s", name);

            struct Node *current = head;
            while (current->next != NULL)
            {
                struct Node *n = current->next;
                if (!strcmp(n->name, name)) {
                    current->next = n->next;
                    free(n);
                    n = NULL;
                } else {
                    current = n;
                }
            }
        } else if (!strcmp(input, "print")) {
            struct Node *current = head->next;
            while (current != NULL)
            {
                printf("%s %d\n", current->name, current->score);
                current = current->next;
            }
        }

        scanf("%s", input);
    }

    struct Node *current = head;
    while(current != NULL) {
        struct Node *n = current->next;
        free(current);
        current = n;
    }
}