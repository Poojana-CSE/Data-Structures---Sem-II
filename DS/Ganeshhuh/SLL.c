#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node *q;
node* create(int data){
    node nn=(node)malloc(sizeof(node));
    nn->next=NULL;
    nn->data=data;
    return nn;
}
void insert_end(int d){
    if(q==NULL){
        q=create(d);
        return;
        }
    node *temp=q;
    while(temp->next){
        temp=temp->next;
    }temp->next=create(d);
}
void insert_beg(int d){
    if(q==NULL){
        q=create(d);
        return;
        }
    node *nn=create(d);
    nn->next=q;
    q=nn;
}
void insert_pos(int data,int pos){
    if(pos<1){
        q=create(data);
    }
    if(pos==1){
        insert_beg(data);
        return;
    }
    node *temp=q;
    for(int i=0;temp && i<pos-2;i++){
        temp=temp->next;
    }
    node *nn=create(data);
    nn->next=temp->next;
    temp->next=nn;
}
void delete_end(){
    if(q==NULL || q->next==NULL){
        q=NULL;
        printf("\n  empty da venna");
        return;
    }
    node *temp=q;
    while(temp->next->next){
        temp=temp->next;
    } 
    temp->next=NULL;
}
void delete_beg(){
    if(q==NULL){
        printf("\n Already empty da venna");
        return;
        }
        node *temp=q;
    q=q->next;
    free(temp);
}
void delete_pos(int pos){
    if(pos<=1){
        delete_beg();
        return;
    }
    node *temp=q;
    for(int i=0;temp && i<pos-2;i++){
        temp=temp->next;
    }
    if(!temp){
        delete_end();
        return;
    }
    node *t=temp->next;
    temp->next=temp->next->next;
    free(t);
}
void display(){
    node *temp=q;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL){
            printf(" -> ");
        }temp=temp->next;
    }
}
int main(){
    int cho,data,pos;
    while(1){
        printf("\nChoose \n1.create\n2.insert at beg\n3.insert at end\n4.insert at pos\n5.delete at beg\n6.delete at end\n7.delete at pos\n8.Exit\n");
        scanf("%d",&cho);
        switch(cho){
            case 1:
            printf("\nEnter data for first element :");
            scanf("%d",&data);
            q=create(data);
            break;
            case 2:
            printf("\nEnter data :");
            scanf("%d",&data);
            insert_beg(data);
            break;
            case 3:
            printf("\nEnter data :");
            scanf("%d",&data);
            insert_end(data);
            break;
            case 4:
            printf("\nEnter data and position :");
            scanf("%d",&data);scanf("%d",&pos);
            insert_pos(data,pos);
            break;
            case 5:
            delete_beg();
            break;
            case 6:
            delete_end();
            break;
            case 7:
            printf("\nEnter position to delete :");
            scanf("%d",&pos);
            delete_pos(pos);
            break;
            case 8:
            exit(0);
        }printf("\n");
        display();
    }
}