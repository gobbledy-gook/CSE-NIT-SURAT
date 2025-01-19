#include<stdio.h>
#include<stdlib.h>

int COUNT = 0;

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root=NULL;

void insert(int key){
    struct node *t=root;
    struct node *p;
    struct node *r;//TAILING POINTER..i.e it follows the root.
    if(root==NULL){
   p=(struct node *)malloc(sizeof(struct node));
   p->lchild=NULL;
   p->rchild=NULL;
   p->data=key;
   root=p;
   return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data){
            t=t->lchild;
        }
        else if(key>t->data){
            t=t->rchild;
        }
        else{
            return;
        }
    }
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->lchild=NULL;
    p->rchild=NULL;
    if(key<r->data){
        r->lchild=p;
    }
    else{
        r->rchild=p;
    } 
}

void inorder(struct node *p){
    
    if(p == NULL)
        return;

    inorder(p->lchild);
    printf("%d", p->data);
    COUNT++;
    inorder(p->rchild);
    
}

int main(){
    int n=1, val;

    while(n){
        int m;
        printf("How many nodes to add ? - ");
        scanf("%d", &m);
        for(int i =0;i<m;i++){
            printf("Enter the node data - ");
            scanf("%d", &val);
            insert(val);
        }
        printf("Continue(1/0)? ");
        scanf("%d", &n);
    }
    
   inorder(root);
   printf("Total No. of nodes are - %d", COUNT);
}   


// ---------------------------------------------------

// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     struct node *lchild;
//     int data;
//     struct node *rchild;
// } *root=NULL;

// void insert(int key){
//     struct node *t=root;
//     struct node *p;
//     struct node *r;//TAILING POINTER..i.e it follows the root.
//     if(root==NULL){
//    p=(struct node *)malloc(sizeof(struct node));
//    p->lchild=NULL;
//    p->rchild=NULL;
//    p->data=key;
//    root=p;
//    return;
//     }
//     while(t!=NULL){
//         r=t;
//         if(key<t->data){
//             t=t->lchild;
//         }
//         else if(key>t->data){
//             t=t->rchild;
//         }
//         else{
//             return;
//         }
//     }
//     p=(struct node *)malloc(sizeof(struct node));
//     p->data=key;
//     p->lchild=NULL;
//     p->rchild=NULL;
//     if(key<r->data){
//         r->lchild=p;
//     }
//     else{
//         r->rchild=p;
//     } 
// }

// void inorder(struct node *p){
//     if(p){
//         inorder(p->lchild);
//         printf("%d ",p->data);
//         inorder(p->rchild);
//     }
// }

// void preorder(struct node *p){
//     if(p){
//         printf("%d ",p->data);
//         preorder(p->lchild);
//         preorder(p->rchild);
//     }
//     // printf("\n");
// }

// void postorder(struct node *p){
//     if(p){
//         postorder(p->lchild);
//         postorder(p->rchild);
//         printf("%d ",p->data);
//     }
// }

// int height(struct node *p){
//     int x,y;
//     if(p==0){
//         return -1;
//     }
//     else{
//         x=height(p->lchild);
//         y=height(p->rchild);
//         if(x>y){
//             return x+1;
//         }
//     else{
//         return y+1;
//     }
//     }
// }

// void printLeaf(struct node *p){
//     if(p){
//         printLeaf(p->lchild);
//         printLeaf(p->rchild);
//         if(p->lchild==NULL && p->rchild==NULL){
//             printf("%d ",p->data);
//         }
//     }
// }

// int main(){
//    insert(25);
//    insert(20);
//    insert(36);
//    insert(10);
//    insert(22);
//    insert(30);
//    insert(40);
//    insert(5);
//    insert(12);
//    insert(28);
//    insert(38);
//    insert(48);
//     // insert(124);

//    printf("Value at leaf nodes are:\n");
//    printLeaf(root);
//     printf("\n");
//     printf("Height of tree is:");
//     int k=height(root);
//     printf("%d\n",k);
//    printf("preorder traversal:\n");
//    preorder(root);
//    printf("\n");
//    printf("Inorder traversal:\n");
//    inorder(root);
//    printf("\n");
//    printf("postorder traversal:\n");
//    postorder(root);
//     return 0;
// }

// -------------------------------------------------

// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     struct node *lchild;
//     int data;
//     struct node *rchild;
// }*root=NULL;

// void insert(int key){
//     struct node *t=root;
//     struct node *p;
//     struct node *r;//TAILING POINTER..i.e it follows the root.
//     if(root==NULL){
//    p=(struct node *)malloc(sizeof(struct node));
//    p->lchild=NULL;
//    p->rchild=NULL;
//    p->data=key;
//    root=p;
//    return;
//     }
//     while(t!=NULL){
//         r=t;
//         if(key<t->data){
//             t=t->lchild;
//         }
//         else if(key>t->data){
//             t=t->rchild;
//         }
//         else{
//             return;
//         }
//     }
//     p=(struct node *)malloc(sizeof(struct node));
//     p->data=key;
//     p->lchild=NULL;
//     p->rchild=NULL;
//     if(key<r->data){
//         r->lchild=p;
//     }
//     else{
//         r->rchild=p;
//     } 
// }

// void inorder(struct node *p){
//     if(p){
//         inorder(p->lchild);
//         printf("%d ",p->data);
//         inorder(p->rchild);
//     }
// }

// struct node* search(struct node *p,int key){
// struct node *t;
// t=p;
// while(t!=NULL){
//     if(key<t->data){
//         t=t->lchild;
//     }
//     else if(key>t->data){
//         t=t->rchild;
//     }
//     else{
//         return t;
//     }
// }
// return NULL;
// }

// struct node* finMin(struct node *p){
//  //This function finds the inorder successor and inorder successor is the 
//  //leftmost child of the right subtree.   
//     while(p->lchild!=NULL){
//         p=p->lchild;
//     }
//     return p;
// }

// struct node* delete(struct node *p,int key){//delete() returns a struct node type
//  //pointer of root of the tree.
//     if(p==NULL){
//         return NULL;
//     }
//     else if(key<p->data){
// //Basically we are using recursion delete function will return root of the subtree
// // which we will store in left child of root.    
//         p->lchild=delete(p->lchild,key);
//     }
//     else if(key>p->data){
//         p->rchild=delete(p->rchild,key);
//     }
//     else{
//         if(p->lchild==NULL && p->rchild==NULL){
//             free(p);
//             p=NULL;
//             // return p;
//         }
//         else if(p->lchild==NULL){
//             struct node *temp;
//             temp=p;
//             p=p->rchild;
//             free(temp);
//             // return p;
//         }
//         else if(p->rchild==NULL){
//             struct node *temp;
//             temp=p;
//             p=p->lchild;
//             free(temp);
//             // return p;
//         }
//         else{
//             // struct node *temp;
//             // temp=finMin(p->rchild);
//             // temp->data=p->data;
//             // p->rchild=delete(p->rchild,temp->data);
//             // // return p;
//             struct node *temp = finMin(p->rchild);
// 			p->data = temp->data;
// 			p->rchild = delete(p->rchild,temp->data);
	
//         }
//     }
//     return p;
// }

// int main(){
//      insert(25);
//    insert(20);
//    insert(36);
//    insert(10);
//    insert(22);
//    insert(30);
//    insert(40);
//    insert(5);
//    insert(12);
//    insert(28);
//    insert(38);
//    insert(48);
//    delete(root,48);
//    if(search(root,30)){
//     printf("Element is found\n");
//    }
//    else{
//     printf("Element not found.\n");
//    }
//    inorder(root);
//     return 0;
// }