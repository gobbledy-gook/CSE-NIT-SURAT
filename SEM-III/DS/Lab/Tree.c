#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

void inorder(struct node * root){
    if(root != NULL){ 
        // printf("\nRoot: %p\nRoot-left: %p, Root-data: %d, Root-right: %p\n", root, root->left, root->data, root->right);
        inorder(root -> left);
        printf("%d ", root->data);
        inorder(root -> right);
    }
}

struct node * search(struct node * root, int val){
    while((root!=NULL)&& (root->data != val)){
        if(val < root->data){
            root = root->left;
        }
        else if(val > root->data){
            root = root ->right;
        }
    }        
    printf("\n==>%d | %p", root->data, root);
    return root;
}


struct node * inorder_successor(struct node * root, int val){
    struct node * parent;
    int x=0;
    if(root!=NULL){
        inorder(root->left);
        if(val == root->data){
            x = 1;
        }
        x++;
        printf("%d ", root->data);
        if(x==2){
            return root;
        }
        inorder(root->right);
    }
}

struct node * parentsearch(struct node * root, int val){
    struct node * prev = NULL;
    while((root!=NULL)&& (root->data != val)){
        prev = root;
        if(val < root->data){
            root = root->left;
        }
        else if(val > root->data){
            root = root ->right;
        }
    }        
    printf("\n==>%d | %p", prev->data, prev);
    return prev;
}


void insert(struct node * root){
    struct node * curr;
    curr = root;
    struct node * temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value - ");
    temp->left = NULL;
    temp->right = NULL;
    scanf("%d", &(temp->data));

    
    while(1){
        if(temp->data < curr->data){
            if(curr->left == NULL){
                curr->left = temp;
                return;
            }
            else{
                curr = curr->left;
            }
        }
        else if(temp->data > curr->data){
            if(curr->right == NULL){
                curr->right = temp;
                return;
            }
            else{
                curr = curr->right;
            }
        }
    }
}

void delete(struct node * root, struct node * key, int val){
    // int val;
    // struct node * curr = NULL;
    struct node * prev;
    prev = NULL;
    struct node * succ;
    struct node * succ_prev;
    // printf("Enter the value to delete - ");
    // scanf("%d", &val);
    // curr = search(root, val);
    // printf("\n%p", search(root, val));
    // printf("\n%p", &curr);
    printf("\n--> %d\n", key->data);   
    if(key == NULL){
        printf("\n%d not found in the tree.", val);
        return;
    }
    else{
        printf("-->");
        
        prev = parentsearch(root, val);
        printf("\nPrevious - %p", prev);
        // Leaf Node Deletion
        if((key->left == NULL)&&(key->right == NULL)){
            if(val < prev->data){
                prev->left = NULL;
            }
            else{
                prev->right = NULL;
            }
        }

        // Single Child Node Deletion
        else if((key->left == NULL)||(key->right == NULL)){
           
            if(key->right == NULL){
                int temp;
                temp = (key->left)->data;
                (key->left)->data = key->data;
                key->data = temp;
                key->left = NULL;
               
            }
            else if(key->left == NULL){
                int temp;
                temp = (key->right)->data;
                (key->right)->data = key->data;
                key->data = temp;
                key->right = NULL;
            }
        }

        // Double Child Node Deletion
        else{
    
            succ = inorder_successor(root, val);
            succ_prev = inorder_successor(root, succ->data);
            int temp;
            temp = succ -> data;
            succ -> data = key -> data;
            key->data = temp;
        
            if(succ->data < succ_prev->data){
                succ_prev->left = NULL;
            }
            else{
                succ_prev->right = NULL;
            }

            
        }
    }

    

}

int main(){
    struct node * root;
    root = (struct node *)malloc(sizeof(struct node));

    struct node * curr;
    int menu=4;
    while(menu){
        printf("\n1. Create\n2. Insert\n3. Delete\n4. Search\n5. Traverse\n0. Exit\n--> ");
        scanf("%d", &menu);
        int n = 0;
        switch(menu){
            case 1:
                root -> left = NULL;
                root -> right = NULL;
                printf("Enter the root value - ");
                scanf("%d", &(root->data));
                break;
            case 2:
                printf("Enter the no. of values to add - ");
                scanf("%d", &n);
                for(int i=0;i<n;i++){
                    insert(root);
                }
                break;
            case 3:
                printf("Enter the value to delete - ");
                struct node * key=NULL;
                int val;
                scanf("%d", &val);
                key = search(root, val);
                if(key == NULL){
                    printf("Not Found !");
                }
                else{
                    printf("\nAt - %p", key);
                    delete(root, key, val);
                }
                break;
            case 4:
                printf("Enter the value to search for - ");
                struct node * fnode;
                int num;
                scanf("%d", &num);
                fnode = search(root, num);
                printf("\nAt - %p", fnode);
                break;
            case 5:
                inorder(root);
                break;
            default:
                break;            
        }
    }
}