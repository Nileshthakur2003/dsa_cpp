// Online C++ compiler to run C++ program online
#include <iostream>


// <Head Node> - |Node1 - |Node2| - |Node3| - |Node 4| ---- > <Tail Node>

struct nd{
    int data;
    struct nd* next;
};

typedef nd node;

void insert_at_beg(node *head, int value);
void insert_at_end(node *head, int value);
void insert_at_pos(node *head, int value,int pos);

void delete_beg(node *head);
void delete_end(node *head);
void delete_at_pos(node *head, int pos);

void update_at_pos(node *head, int pos, int nodevalue);

void search(node *head, int value);

void print_ll(node *head);

node *create_node(int value);
node *create_empty_node();

int main() {
    
    node *head = create_empty_node();
    node *first = create_node(27);
    node *second = create_node(122);
    node *third = create_node(322);

    head->next = first;
    first->next = second;
    second->next = third;
    

    insert_at_beg(head,232);
    insert_at_end(head,7621);
    insert_at_pos(head,62,3);

    printf("Printing the Current List :- \n");
    print_ll(head);

    //search(head,322);

    return 0;
}


node *create_node(int value){

    node *temp = (node*)malloc(sizeof(struct nd));
    temp ->data = value;
    temp ->next = NULL;
    return temp;

};

node *create_empty_node(void){

    node *temp = (node*)malloc(sizeof(struct nd));
    temp ->next = NULL;

    return temp;
};

void print_ll(node *head){

    node *temp = head->next;
    while(temp!=NULL){
        printf("%d \n",temp->data);
        temp = temp->next;
    }
}

void search(node *head, int value){

    int pos = 1;
    int found_flag = 0;
    node *temp = head->next;
    while(temp!=NULL){
        if(temp->data==value){
            printf("Item %d Found at : %d",value,pos);
            found_flag=1;
        }
        temp = temp->next;
        pos++;
    }
    if(found_flag==0){
        printf("Item %d not Found.",value);
    }
}


void insert_at_beg(node *head, int value){
    // create a new node , n;
    // point n towards first;
    // point head towards n;


    node *temp = create_node(value);

    if(head->next==NULL)
    {
         head->next = temp;

    }else{
        node *first = head->next;
        temp->next = first;
        head->next = temp;
    }

}

void insert_at_end(node *head, int value){
    
    node *temp = create_node(value);

    node *iter = head->next;
    while(iter->next!=NULL)
    iter = iter->next;
    
    iter->next = temp;

}

void insert_at_pos(node *head, int value,int pos){

    int pos_iter = 1;
    int found_flag = 0;

    node *temp = create_node(value);

    node *iter = head->next;
    while(iter->next!=NULL)
    { printf("LOOP:iap::[%d:%d]\n",pos_iter,pos+1);
        if(pos_iter==(pos+1))
        {
            printf("Inside IF\n");
            node *prev = iter->next;
            node *nxt = prev->next;

            temp->next = nxt;
            prev->next = temp;
            found_flag = 1;           
        }
        iter = iter->next;
        pos_iter++;
    }

    if(found_flag==0){
        printf("Entered Position is Out of bounds!!!\n");
    }

}

void delete_beg(node *head)
{
    if(head->next->next!=NULL)
    {
         head->next = head->next->next;

    }else{
        
        head->next = NULL;
    }
}

void delete_end(node *head)
{
    node *temp = head->next;
    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = NULL;
    

}
