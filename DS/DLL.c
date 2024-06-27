// ADVANTAGES:
// Can traverse easily in both directions
//DISADVANTAGES:
//More memory
//APPLICATIONS:
// Browser back/next buttons, undo/redo

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next; 
    struct node *prev;
};
struct node* head=NULL;
struct node *tail=NULL;//GLOBAL DECLARATION OF HEAD POINTER
void insertbeg(int val)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node*));//create node
    if(nn==NULL)
    {
        printf("Node is not created !");
        return;
    }
    //(*nn).data=val also be given
    nn->data=val;
    nn->next=head;
    if(head==NULL)
    {
        tail=nn;
    }
    else
    {
        head->prev=nn;
    }
    head=nn;
    nn->prev=NULL;
    printf("Value %d is inserted ",val);
}

void insertsp(int pos,int val)
{
    struct node *nn = (struct node*)malloc(sizeof(struct node*));//create node
    if(nn==NULL)
    {
        printf("Node is not created !");
        return;
    }
    nn->data=val;
    struct node * temp=head;
    for(int i=0;i<pos-1;i++)//previous
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Invalid Position");
            return;
        }
    }
    nn->next=temp->next;
    temp->next=nn;
    printf("Value %d is inserted",val);
}

void insertl(int val)
{
    struct node *nn = (struct node*)malloc(sizeof(struct node*));//create node
    if(nn==NULL)
    {
        printf("Node is not created !");
        return;
    }
    //(*nn).data=val also be given
    nn->data=val;
    nn->next=NULL;
    if(head==NULL)
    {
        head=nn;
    }
    else
    {
        struct node * temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
    }
    printf("Value %d is inserted",val);
}

void deletebeg()
{
    if (head==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct node * temp=head;
    head=head->next;
    free(temp);
}

void deletel()
{
    if (head==NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (head->next==NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void deletesp(int pos)
{
    int i;
    struct node *temp = head;
    struct node *prev;
    if(head==NULL)
    {
        printf("List Is Empty");
        return;
    }
    if(pos==0)
    {

    }
    for(i=0;i<pos;i++)
    {
        prev=temp;
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Invalid Position");
            return;
        }
    }
    prev->next=temp->next;
    printf("Value %d is deleted",temp->data);
    free(temp);
}

int count()
{
    int count=0;
    struct node *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void middle()
{
    struct node *temp=head;
    int counts=count();
    if (counts==0)
    {
        printf("The list is empty.\n");
        return;
    }
    if(counts%2==0)
    {
        counts=counts/2 - 1;
    }
    else
    {
        counts=counts/2;
        while(counts--)
        {
            temp=temp->next;
        }
    }
    printf("The middle element is %d\n", temp->data);
}

void reverse()
{
    struct node* prev=NULL;
    struct node* current=head;
    struct node* next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;//link reversal
        prev=current;
        current=next;
    }
    head=prev;
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
    struct node *temp=head;
    printf("Elements Are\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;//jumping
    }
    }
}

void displayrev()
{
    if(tail==NULL)
    {
        printf("List is empty");
    }
    else
    {
    struct node *temp=tail;
    printf("Elements Are\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;//jumping
    }
    }
}

int main(){
    int choice,val,pos;
    while(1){
        printf("\n -------- Linked List Menu -----------\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert at specified position \n");
        printf("4.Delete at begining\n");
        printf("5.Delete at end\n");
        printf("6.Delete from specified position\n");
        printf("7.Middle element\n");
        printf("8.Count \n");
        printf("9.Reverse\n");
        printf("10.Display the list\n");
        printf("11.Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice){
        case 1://insert beg
        printf("Enter the data: ");
        scanf("%d",&val);
        insertbeg(val);
        break;

        case 2://insert end
        printf("Enter the data: ");
        scanf("%d",&val);
        insertl(val);
        break;

        case 3://insert sp 
        printf("Enter the pos(starts at 0): ");
        scanf("%d",&pos);
        if(pos<0)
        {
        printf("Invalid position");
        break;
        }
        printf("Enter the data: ");
        scanf("%d",&val);
        if(pos==0)
        {
            insertbeg(val);
        }
        else
        {
            insertsp(pos,val);
        }
        break;

        case 4://delete beg
        deletebeg();
        break;

        case 5://delete end
        deletel();
        break;

        case 6://delete sp
        printf("Enter the pos: ");
        scanf("%d",&pos);
        if(pos<0)
        {
        printf("Invalid position");
        break;
        }
        deletesp(pos);
        break;

        case 7://mid
        middle();
        break;

        case 8:
        int c=count();
        printf("Count : %d",c);
        break;

        case 9:
        reverse();
        break;

        case 10://display
        display();
        displayrev();
        break;

        case 11://exit 
        exit(0);
        break;

        default://others
        printf("Wrong choice");
        }
    }
    return 0;
}
