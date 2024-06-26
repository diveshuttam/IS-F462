#include<stdio.h>
#include<stdlib.h>
typedef struct Node 
{
        int data;
        struct Node *next;
}node;
node* insert(node *pointer, int data)
{
        /* Insert at the beginning.*/        
        /* Allocate memory for the new node and put data in it.*/
        node* tmp = (node *)malloc(sizeof(node));

        tmp->data = data;
        tmp->next = pointer;

        /* return new head*/
        return tmp;
}
int find(node *pointer, int key)
{

        /* Iterate through the entire linked list and search for the 
         * key. */
        while(pointer!=NULL)
        {
                if(pointer->data == key) //key is found.
                {
                        return 1;
                }
                pointer = pointer -> next;//Search in the next node.
        }
        /*Key is not found */
        return 0;
}

node* delete(node *pointer, int data)
{
        node *prev=NULL;
        node *list=pointer;

        /* Iterate to find pointer */
        while( (pointer != NULL) && (pointer->data != data ))
        {
                prev = pointer;
                pointer = pointer -> next;
        }

        if(pointer==NULL)
        {
                printf("Element %d is not present in the list\n",data);
                return list;
        }
        else if(prev==NULL) //implies first element
        {
          list=pointer->next;
          free(pointer);
          return list;
        }
        /* Set previous pointer to next pointer */
        prev->next = pointer->next;
        free(pointer);
        return list;
}
void print(node *pointer)
{
        if(pointer==NULL)
        {
                return;
        }
        printf("%d ",pointer->data);
        print(pointer->next);
}
int main()
{

        node *list = NULL;
        delete(list,5);
        //inserting elements
        list = insert(list, 5);
        list = insert(list, 3);
        list = insert(list, 2);
        list = insert(list, 9);

        //printing list
        print(list);
        printf("\n");

        //deleting nodes
        list = delete(list,3);
        list = delete(list,6);
        list = delete(list,5);
        list = delete(list,9);
        list = delete(list,2);
        list = delete(list,6);

        //print list
        print(list);
        printf("\n");

        return 0;
}
