    #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Job {
    int id;
    char name[25];
    char qualification[25];
    struct Job* next;
};

typedef struct Job Node;

Node* front = NULL;
Node* rear = NULL;

void createjob(char na[25], int ide, char qual[25]) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Not enough memory available");
    }
    else
    {
        strcpy(newNode->name, na);
        newNode->id = ide;
        strcpy(newNode->qualification, qual);
        newNode->next = NULL;
        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            Node* ptr1 = front;
            Node* ptr2 = front;
            while (ptr1 != NULL && strcmp(qual, ptr1->qualification) < 0)
            {
                ptr2 = ptr1;
                ptr1 = ptr1->next;
            }
            if (ptr1 == NULL)
            {
                ptr2->next = newNode;
                rear = newNode;
            }
            else if (ptr1 == front)
            {
                newNode->next = front;
                front = newNode;
            }
            else
            {
                newNode->next = front;
                ptr2->next = newNode;
            }
        }
    }
}

void removejob()
{
    if (front == NULL)
    {
        printf("No Jobs scheduled");
    }
    else
    {
        printf("Removing %s, %d from the list\n", front->name, front->id);
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
    }
}

void display()
{
    if (rear == NULL)
    {
        printf("No Jobs scheduled");
    }
    else
    {
        Node* ptr = front;
        while (ptr != NULL)
        {
            printf("%s %d %s\n", ptr->name, ptr->id, ptr->qualification);
            ptr = ptr->next;
        }
    }
}

int count()
{
    int c = 0;
    if (rear == NULL)
        c = 0;
    else
    {
        Node* ptr = front;
        while (ptr != NULL)
        {
            c++;
            ptr = ptr->next;
        }
    }
    return c;
}

int main()
{
    int id, ch;
    char n[25], qual[25];
    do
    {
        printf("Menu \n1.Add new \n2.Delete \n3.Display\n4.Count\n5.Exit\n");
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch)
        {
            case 1:
                printf("Enter the name, id, and qualification (e.g. Btech, 12th, etc.): ");
                scanf("%s %d %s", n, &id, qual);
                fflush(stdin);
                createjob(n, id, qual);
                break;
            case 2:
                removejob();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Count: %d\n", count());
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (ch != 5);

    return 0;
}