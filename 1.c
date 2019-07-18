#include<stdio.h>
#define MAX 1234567
#define SIZE 10000

int tree[10000];
int last;

void TreeInsert(int root,int data);

int main(){
    int i,j,item;
    int n;
    int root = 0;

    printf("Number of items to insert : \n");
    scanf("%d",&n);
    // initializing all the tree[] index by MAX
    for(i=0;i<SIZE;i++){
        tree[i] = MAX;
    }
    printf("Enter items : ");
    for(i=0;i<n;i++){
        scanf("%d",&item);
        TreeInsert(0,item);
    }
    for(i=0;i<=last;i++){
        if(tree[i] != MAX){
            printf("Position %d , Value: %d\n",i,tree[i]);
        }
    }

    return 0;
}

void TreeInsert(int root,int data){
    if(tree[root] == MAX){
        tree[root] = data;
        last = root;
        return;
    }

    else if (tree[root] == data){
        printf("Data existed on position : %d\n",root);
        return;
    }
    int left = 2*root + 1;
    int right = 2*root + 2;
    if(data <= tree[root]){
        TreeInsert(left,data);
    }
    else TreeInsert(right,data);

}
