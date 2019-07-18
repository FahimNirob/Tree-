#include<stdio.h>
#define MAX 1234567
#define SIZE 10000

int tree[10000];
int last;

void PrintTree(int n);
void max_heapify(int i,int N);
void TreeInsert(int i);
void Delete(int i,int n);

int main(){
    int n,i,j,item,x;
    int index =  -1;
    printf("Enter number of items in heap : ");
    scanf("%d",&n);

    printf("\nEnter heap items : \n");
    for(i=0;i<n;i++){
        scanf("%d",&item);
        tree[i] = item; // creating heap
    }
    for(i=n/2-1;i>=0;i--){
        max_heapify(i,n);
    }
    PrintTree(n);

    // inserting
    printf("Enter item to insert : ");
    scanf("%d",&x);
    n++;
    tree[n-1] = x;// putting in the last index
    TreeInsert(n-1);
    PrintTree(n);

    // deleting

    printf("\nEnter item to delete : ");
    scanf("%d",&x);
    for(i=0;i<n;i++){
        if(tree[i] == x){
            index = x;
            break;
        }
    }

    if(index != -1){
        n--,Delete(index,n);
    }
    else printf("Item is not found !\n");
    PrintTree(n);
    return 0;

}

void PrintTree(int n){
    int i;
    for(i=0;i<n;i++){
        printf("Position : %d, Value: %d\n",i,tree[i]);
    }
}

void max_heapify(int i,int N){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
    if(left<N && tree[left] > tree[i]){
        largest = left;
    }
    if(right<N && tree[right] > tree[largest]){
        largest = right;
    }
    if(largest != i){
        int temp;
        temp = tree[i];
        tree[i] = tree[largest];
        tree[largest] = temp;

        max_heapify(largest,N);
    }
}

void TreeInsert(int i){
    int parent = (i-1)/2;
    if(parent<0) return ;
    else if(tree[i] > tree[parent]){
        int temp;
        temp = tree[i];
        tree[i] = tree[parent];
        tree[parent] = temp;

        TreeInsert(parent);
    }
}

void Delete(int i,int n){
    tree[i] = tree[n];
    max_heapify(i,n);
}
