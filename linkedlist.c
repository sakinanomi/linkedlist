#include<stdio.h>
#include<stdlib.h>
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insert_beg()
{
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&nn->data);
    nn->next=NULL;
    nn->next=head;
    head=nn;
}
void insert_end()
{
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&nn->data);
    nn->next=NULL;
    struct node *temp;
   temp=head;
   while(temp->next!=NULL)
   {
       temp=temp->next;
   }
   temp->next=nn;
}
void insert_ran()
{
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&nn->data);
    nn->next=NULL;
    printf("The linked list is:\n");
    display();
    printf("After which element you want to insert?\n");
    int ele;
    scanf("%d",&ele);
    struct node *temp;
    temp=head;
    while(temp->data!=ele)
    {
        temp=temp->next;
    }
    nn->next=temp->next;
    temp->next=nn;
}
void remove_beg()
{
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);

}
void remove_end()
{
    struct node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    struct node *temp2;
    temp2=head;
    while(temp2->next!=temp)
    {
        temp2=temp2->next;
    }
    temp2->next=NULL;
    free(temp);
}
void remove_ran()
{
    printf("The list is\n");
    display();
    printf("Enter the element to be deleted\n");
    int ele;
    scanf("%d",&ele);
    struct node *temp;
    temp=head;
    while(temp->data!=ele)
    {
        temp=temp->next;
    }
    struct node *temp2;
    temp2=head;
    while(temp2->next!=temp)
    {
        temp2=temp2->next;
    }
    temp2->next=temp->next;
    free(temp);
}
void search()
{
    printf("Enter the element you want to search\n");
    int ele;
    scanf("%d",&ele);
    struct node *temp;
    temp=head;
    int count=1;
    while(temp->data!=ele&&temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Sorry Element not found\n");
    }
    else{
        printf("Element found at %d position\n",count);
    }

}

void sort()
{
    struct node *temp;
    struct node *temp2;
    temp=head;
    while(temp!=NULL)
    {
        temp2=temp->next;
        while(temp2!=NULL)
        {
            int t;
            if(temp->data>temp2->data)
            {
                t=temp->data;
                temp->data=temp2->data;
                temp2->data=t;
            }
            temp2=temp2->next;

        }
        temp=temp->next;
    }
    printf("The list is sorted\n");

}
void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Linked List empty\n");
    }
    else
    {
             while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }

    }
}
int main()
{
    head=NULL;
     int a;
    char ch='y';
    do{
             printf("Please enter your choice\n1:To insert in the beginning \n2:To insert at the end\n3:To insert after any element\n4:To display\n5:To remove from the beginning\n6:To remove from the end\n7:To remove after specified position\n8:To search element\n9:To sort\n10:To display\n11:To exit\n");

            scanf("%d",&a);
            switch(a)
            {
                case 1:insert_beg();
                break;

                case 2:insert_end();
                break;

                case 3:insert_ran();
                break;

                case 4:display();
                break;

                case 5:remove_beg();
                break;

                case 6:remove_end();
                break;

                case 7:remove_ran();
                break;

                case 8:search();
                break;

                case 9:sort();
                break;

                case 10:display();
                break;

                case 11:exit(0);
            }


    }while(1);
}
