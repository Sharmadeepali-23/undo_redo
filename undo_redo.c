
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Node for Linked List
struct Node {
    char data;
    struct Node *next;
};

// Stack for storing text states
struct Stack {
    char text[MAX][MAX];
    int top;
};

struct Node *head = NULL;
struct Stack undoStack, redoStack;

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Push text into stack
void push(struct Stack *s, char text[]) {
    if (s->top < MAX - 1) {
        strcpy(s->text[++s->top], text);
    }
}

// Pop text from stack
int pop(struct Stack *s, char text[]) {
    if (s->top == -1)
        return 0;

    strcpy(text, s->text[s->top]);
    s->top--;
    return 1;
}

// Convert linked list into string
void getText(char text[]) {
    struct Node *temp = head;
    int i = 0;

    while (temp != NULL) {
        text[i++] = temp->data;
        temp = temp->next;
    }
    text[i] = '\0';
}

// Update linked list
void setText(char text[]) {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    for (int i = 0; text[i] != '\0'; i++) {
        struct Node *newNode =
            (struct Node*)malloc(sizeof(struct Node));

        newNode->data = text[i];
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Display current text
void display() {
    char text[MAX];
    getText(text);

    printf("\nCurrent Text: %s\n", text);
}

// Insert text
void insertText() {
    char oldText[MAX], newText[MAX];

    getText(oldText);
    push(&undoStack, oldText);
    init(&redoStack);

    printf("Enter text to insert: ");
    getchar();
    fgets(newText, MAX, stdin);
    newText[strcspn(newText, "\n")] = '\0';

    strcat(oldText, newText);
    setText(oldText);

    printf("Text inserted successfully!\n");
}

// Undo operation
void undo() {
    char current[MAX], previous[MAX];

    if (pop(&undoStack, previous)) {
        getText(current);
        push(&redoStack, current);
        setText(previous);

        printf("Undo successful!\n");
    } else {
        printf("Nothing to undo!\n");
    }
}

// Redo operation
void redo() {
    char current[MAX], next[MAX];

    if (pop(&redoStack, next)) {
        getText(current);
        push(&undoStack, current);
        setText(next);

        printf("Redo successful!\n");
    } else {
        printf("Nothing to redo!\n");
    }
}

// Main function
int main() {
    int choice;

    init(&undoStack);
    init(&redoStack);

    do {
        printf("\n===== UNDO REDO TEXT EDITOR =====\n");
        printf("1. Insert Text\n");
        printf("2. Display Text\n");
        printf("3. Undo\n");
        printf("4. Redo\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertText();
                break;

            case 2:
                display();
                break;

            case 3:
                undo();
                break;

            case 4:
                redo();
                break;

            case 5:
                printf("Exiting Editor...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
