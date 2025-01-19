// #include <stdlib.h>
// #include <stdio.h>

// struct Node{
//     int data;
//     struct Node* next;
// };

// int count[100];

// struct Node* create(struct Node* start){
//     int n;
//     struct Node* curr = start;
//     printf("\nEnter the no. of elements - ");
//     scanf("%d", &n);
//     for(int i=0;i<n;i++){
//         struct Node* temp;
//         temp = (struct Node*)malloc(sizeof(struct Node));
//         printf("\n- ");
//         scanf("%d", &(temp->data));
//         if(count[temp->data] == 0){
//             count[temp->data] = 1;
//         }
//         else{
//             count[temp->data] += 1;
//         }
//         temp->next = NULL;
//         curr->next = temp;
//         curr = temp;
//     }
//     return curr;
// }

// void llcomm(struct Node* start1, struct Node* start2){
//     int x=1, i=0;
//     printf("\nCommon Elements are - ");
//     while(x){
//         if(count[i]>1){
//             printf("%d | ", i);
//         }
//         else if(i==  100){
//             x=0;
//         }
//         i++;
//     }
// }

// void llunion(struct Node* start1, struct Node* start2){
//     int x=1, i=0;
//     printf("\nUnion of Elements is - ");
//     while(x){
//         if(count[i]>0){
//             printf("%d | ", i);
//         }
//         else if(i==  100){
//             x=0;
//         }
//         i++;
//     }
// }

// void display(struct Node* start){
//     struct Node* temp;
//     temp = start;
//     while(temp != NULL){
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
// }

// int main(){
//     struct Node* start1;
//     struct Node* curr1;
//     struct Node* start2;
//     struct Node *curr2;
//     start1 = (struct Node*)malloc(sizeof(struct Node));
//     start2 = (struct Node*)malloc(sizeof(struct Node));
//     for(int i=0;i<100;i++){
//         count[i] = 0;
//     }
//     printf("Enter the elements for linked lists : ");
//     curr1 = create(start1);
//     curr2 = create(start2);
//     printf("\nFirst List: ");
//     display(start1);
//     printf("\nSecond List: ");
//     display(start2);
//     llcomm(start1, start2);
//     llunion(start1, start2);
// }

// ------------------------------------------------------------------------------------------------

// #include <stdlib.h>
// #include <stdio.h>

// struct Node{
//     int data;
//     struct Node* next;
// };

// struct Node* create(struct Node* start){
//     int n;
//     struct Node* curr = start;
//     printf("\nEnter the no. of elements - ");
//     scanf("%d", &n);
//     for(int i=0;i<n;i++){
//         struct Node* temp;
//         temp = (struct Node*)malloc(sizeof(struct Node));
//         printf("\n- ");
//         scanf("%d", &(temp->data));
//         temp->next = NULL;
//         curr->next = temp;
//         curr = temp;
//     }
//     return curr;
// }

// void split(struct Node* start0, struct Node* start1, struct Node* start2){
//     struct Node * temp;
//     struct Node * curr1;
//     struct Node* curr2;
//     curr1 = start1;
//     curr2 = start2;
//     start0 = start0->next;
//     for(int i =0;start0!=NULL;i++){
//         temp = (struct Node *)malloc(sizeof(struct Node));
//         temp->next = NULL;
//         if(i%2 != 0){
//             temp->data = start0->data;
//             curr1->next = temp;
//             curr1 = temp;
//         }
//         else{
//             temp->data = start0->data;
//             curr2->next = temp;
//             curr2 = temp;
//         }
//         start0 = start0->next;
//     }

// }

// void display(struct Node* start){
//     struct Node* temp;
//     temp = start->next;
//     printf("\nThe Linked List: ");
//     while(temp != NULL){
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
// }

// int main(){
//     struct Node* start0;
//     struct Node *curr0;
//     struct Node* start1;
//     struct Node* curr1;
//     struct Node* start2;
//     struct Node *curr2;
//     start0 = (struct Node*)malloc(sizeof(struct Node));
//     start1 = (struct Node*)malloc(sizeof(struct Node));
//     start2 = (struct Node*)malloc(sizeof(struct Node));
//     printf("Enter the elements for linked lists - ");
//     curr0 = create(start0);
//     display(start0);
//     split(start0, start1, start2);
//     display(start1);
//     display(start2);
// }

// --------------------------------------------------------

// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int num;
//     struct Node *nxt;
// };
// typedef struct Node node;

// node *createList(node *start, int n)
// {
//     int i, data;
//     node *head = start;
//     for (i = 0; i < n; i++)
//     {
//         node *temp = (node *)malloc(sizeof(node));
//         printf("Enter data for node %d: ", i + 1);
//         scanf("%d", &data);
//         temp->num = data;
//         temp->nxt = NULL;
//         start->nxt = temp;
//         start = start->nxt;
//     }
//     return head;
// }

// void displayList(node *curr)
// {
//     while (curr != NULL)
//     {
//         printf("\t%d", curr->num);
//         curr = curr->nxt;
//     }
//     printf("\n");
// }
// node *mergeList(node *curr1, node *curr2)
// {
//     node *res = NULL;
//     if (curr1 == NULL)
//     {
//         return curr2;
//     }
//     else if (curr2 == NULL)
//     {
//         return curr1;
//     }
//     if (curr1->num <= curr2->num)
//     {
//         res = curr1;
//         res->nxt = mergeList(curr1->nxt, curr2);
//     }
//     else
//     {
//         res = curr2;
//         res->nxt = mergeList(curr1, curr2->nxt);
//     }
//     return res;
// }
// int main()
// {
//     int n1, n2;
//     printf("Enter no. of nodes in list 1: ");
//     scanf("%d", &n1);
//     node *head = (node *)malloc(sizeof(node));
//     head->nxt = NULL;
//     head = createList(head, n1);
//     printf("Enter no. of nodes in list 2: ");
//     scanf("%d", &n2);
//     node *head2 = (node *)malloc(sizeof(node));
//     head2->nxt = NULL;
//     head2 = createList(head2, n2);
//     node *head3 = (node *)malloc(sizeof(node));
//     head3 = mergeList(head->nxt, head2->nxt);
//     displayList(head3);
//     return 0;
// }

// ------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int coeff;
    int power;
    struct Node *next;
};
typedef struct Node node;
node *createExp(node *ele, int n)
{
    int i, coeff, power;
    node *head = ele;
    for (i = 0; i < n; i++)
    {
        node *temp = (node *)malloc(sizeof(node));
        printf("Enter power of x for term %d: ", i + 1);
        scanf("%d", &power);
        printf("Enter coefficient of x for term %d: ", i + 1);
        scanf("%d", &coeff);
        temp->coeff = coeff;
        temp->power = power;
        temp->next = NULL;
        ele->next = temp;
        ele = temp;
    }
    return head;
}
void displayExp(node *curr)
{
    while (curr != NULL)
    {
        printf(" %dx^%d ", curr->coeff, curr->power);
        if (curr->next != NULL)
        {
            printf("+");
        }
        curr = curr->next;
    }
    printf("\n");
}
int result(node *ele, int x)
{
    int sum = 0, term_val;
    while (ele != NULL)
    {
        term_val = (ele->coeff) * (pow(x, ele->power));
        sum += term_val;
        ele = ele->next;
    }
    return sum;
}
int main()
{
    int res, x, n;
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    node *curr = head;
    printf("Enter no. of terms: ");
    scanf("%d", &n);
    head = createExp(curr, n);
    printf("\nThe expression is: ");
    displayExp(head->next);
    printf("Enter value of x: ");
    scanf("%d", &x);
    res = result(head->next, x);
    printf("\nThe result of the expression is %d", res);
    return 0;
}

// ------------------------------------------------------------

// #include <stdio.h>
// #include <stdlib.h>
// typedef struct Node
// {
//     int num;
//     struct Node *next;
//     struct Node *prev;
// } node;
// node *createList(node *head)
// {
//     int n, i, data;
//     printf("Enter no. of nodes to create list: ");
//     scanf("%d", &n);
//     node *start = head;
//     for (i = 0; i < n; i++)
//     {
//         printf("Enter data for node %d: ", i + 1);
//         scanf("%d", &data);
//         node *new = (node *)malloc(sizeof(node));
//         new->num = data;
//         new->next = NULL;
//         head->next = new;
//         new->prev = head;
//         head = new;
//     }
//     return start;
// }
// node *insert(node *curr)
// {
//     int i, pos, data;
//     node *head = curr;
//     printf("Enter position: ");
//     scanf("%d", &pos);
//     printf("Enter data for node: ");
//     scanf("%d", &data);
//     for (i = 0; i < pos - 1; i++)
//     {
//         curr = curr->next;
//     }
//     node *new = (node *)malloc(sizeof(node));
//     new->num = data;
//     new->next = curr->next;
//     new->prev = curr;
//     if (curr->next != NULL)
//     {
//         curr->next->prev = new;
//     }
//     curr->next = new;
//     return head;
// }
// void displayList(node *curr)
// {
//     int opt;
//     printf("Press 1 for Front Traversal & 2 for Reverse Traversal: ");
//     scanf("%d", &opt);
//     switch (opt)
//     {
//     case 1:
//         while (curr != NULL)
//         {
//             printf(" %d", curr->num);
//             curr = curr->next;
//         }
//         break;
//     case 2:
//         while (curr->next != NULL)
//         {
//             curr = curr->next;
//         }
//         while (curr->prev != NULL)
//         {
//             printf(" %d", curr->num);
//             curr = curr->prev;
//         }
//         break;
//     default:
//         printf("Enter valid option!");
//     }
// }
// node *delete (node *curr)
// {
//     int i, pos;
//     node *head = curr;
//     printf("Enter position: ");
//     scanf("%d", &pos);
//     for (i = 0; i < pos - 1; i++)
//     {
//         curr = curr->next;
//     }
//     curr->next = curr->next->next;
//     if (curr->next != NULL)
//         curr->next->prev = curr;

//     return head;
// }
// int main()
// {
//     int opt;

//     node *head = (node *)malloc(sizeof(node));

//     head->prev = NULL;

//     head->next = NULL;

//     head = createList(head);
//     while (1)
//     {

//         printf("\nChoose from corresponding options:\n");
//         printf("\t1.Insert Node");

//         printf("\t2.Delete Node");

//         printf("\t3.Display List");

//         printf("\t4.Exit\n");
//         scanf("%d", &opt);

//         switch (opt)
//         {
//         case 1:
//             head = insert(head);

//             break;
//         case 2:
//             head = delete (head);
//             break;

//         case 3:
//             displayList(head->next);
//             break;

//         case 4:
//             printf("Ended");

//             return 0;

//             break;

//         default:
//             printf("Enter valid option!");
//         }
//     }
//     return 0;
// }

// ---------------------------------------------------------------

// #include <stdio.h>
// struct node
// {
//     int data;
//     struct node *right;
//     struct node *left;
// };
// struct node *create(struct node *head)
// {
//     struct node *current;
//     current = head;
//     int n;
//     printf("enter the number of nodes you want to add\n");
//     scanf("%d", &n);
//     int i = 0;
//     for (i = 0; i < n; i++)
//     {
//         struct node *temp;
//         temp = (struct node *)malloc(sizeof(struct node));
//         printf("enter the data:\n");
//         scanf("%d", &(temp->data));
//         temp->right = NULL;
//         current->right = temp;
//         temp->left = current;
//         current = temp;
//     }
//     return current;
// }
// void traverseright(struct node *head)
// {
//     struct node *current;
//     current = head->right;
//     while (current != NULL)
//     {
//         printf("%d\t", current->data);
//         current = current->right;
//     }
//     printf("\n");
// }
// void exchange(struct node *head, struct node *cur)
// {
//     struct node *h, *t;
//     h = head->right;
//     t = cur;
//     struct node *c;
//     c = head->right;
//     int count = 0;
//     while (c != NULL)
//     {
//         count++;
//         c = c->right;
//     }
//     // printf("%d is the list length\n",count);
//     int i = 0, d;
//     for (int i = 0; i < count / 2; i++)
//     {
//         d = h->data;
//         h->data = t->data;
//         t->data = d;

//         h = h->right;
//         t = t->left;
//     }
// }
// int main()
// {
//     struct node *head, *current;
//     head = (struct node *)malloc(sizeof(struct node));
//     head->right = NULL;
//     head->left = NULL;
//     current = head;
//     current = create(head);
//     traverseright(head);
//     exchange(head, current);
//     traverseright(head);
//     return 0;
// }
