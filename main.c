#include <stdio.h>
#include <stdlib.h>
/*
Name : Ahmed Abdelhamid Shokry
Section : 1
BN : 11
Name : Omar Adel Ahmed Khedr
Section : 3
BN : 18
Name : Mohamed Maher Ahmed
Section : 3
BN : 43
*/

struct students {
char student_name[20];
int student_ID,student_last_score,student_birth_year,student_birth_month,student_birth_day;
}; //structure that contains data of the student
struct node {
struct students data;
struct node* next;
}; //node of the linked list
int N; //Number of students specified by the user
struct node* head=NULL;
struct node* tail=NULL; //Initialization of head & tail pointers for the linked list
void create_nodes () { //Function to create nodes of the linked list
    /* First we allocated memory of the first node of the linked list then we made head pointer point to it
    then we stored the data of the first student in this node
    then we made new_node pointer to insert the data of the rest of students using for loop and tmp pointer to traverse across the linked list
    finally we defined tail to point to the last node of the list*/
struct node* tmp;
struct node* new_node;
head=(struct node*)malloc(sizeof(struct node));
if (head==NULL)
printf("Memory can't be allocated!!\n");
else {
printf("Please Enter the Name of Student Number 1: \n");
scanf("%s",head->data.student_name);
printf("Please Enter the ID of Student Number 1: \n");
scanf("%d",&head->data.student_ID);
printf("Please Enter the Last Year Score of Student Number 1: \n");
scanf("%d",&head->data.student_last_score);
printf("Please Enter the Birthday of Student Number 1 (Day/Month/Year) respectively each at a time: \n");
scanf("%d %d %d",&head->data.student_birth_day,&head->data.student_birth_month,&head->data.student_birth_year);
tmp=head;
for (int i=1;i<N;i++){
new_node=(struct node*)malloc(sizeof(struct node));
if (new_node==NULL)
printf("Memory can't be allocated!!\n");
else {
tmp->next=new_node;
printf("Please Enter the Name of Student Number %d: \n",i+1);
scanf("%s",new_node->data.student_name);
printf("Please Enter the ID of Student Number %d: \n",i+1);
scanf("%d",&new_node->data.student_ID);
printf("Please Enter the Last Year Score of Student Number %d: \n",i+1);
scanf("%d",&new_node->data.student_last_score);
printf("Please Enter the Birthday of Student Number %d (Day/Month/Year) respectively each at a time: \n",i+1);
scanf("%d %d %d",&new_node->data.student_birth_day,&new_node->data.student_birth_month,&new_node->data.student_birth_year);
new_node->next=NULL;
tmp=new_node;
} tail=tmp;
}} }
void insert_begin_list () { //Function to insert a student at the beginning of the linked list
/*In this function we used the head pointer to insert the student using insertion node */
struct node* insertion= NULL;
insertion = (struct node*)malloc(sizeof(struct node));
if (insertion==NULL)
printf("Memory can't be allocated!!\n");
else {
insertion->next = head;
printf("Please Enter the Name of the Student: \n");
scanf("%s",insertion->data.student_name);
printf("Please Enter the ID of Student: \n");
scanf("%d",&insertion->data.student_ID);
printf("Please Enter the Last Year Score of Student: \n");
scanf("%d",&insertion->data.student_last_score);
printf("Please Enter the Birthday of Student (Day/Month/Year) respectively each at a time: \n");
scanf("%d %d %d",&insertion->data.student_birth_day,&insertion->data.student_birth_month,&insertion->data.student_birth_year);
head=insertion;
N++;
} }
void insert_end_list (){ //Function to insert a student at the end of the linked list
/*In this function we used the tail pointer to insert the student using insertion node */
struct node* insertion=NULL;
insertion = (struct node*)malloc(sizeof(struct node));
if (insertion==NULL)
printf("Memory can't be allocated!!\n");
else {
tail->next=insertion;
printf("Please Enter the Name of the Student: \n");
scanf("%s",insertion->data.student_name);
printf("Please Enter the ID of Student: \n");
scanf("%d",&insertion->data.student_ID);
printf("Please Enter the Last Year Score of Student: \n");
scanf("%d",&insertion->data.student_last_score);
printf("Please Enter the Birthday of Student (Day/Month/Year) respectively each at a time: \n");
scanf("%d %d %d",&insertion->data.student_birth_day,&insertion->data.student_birth_month,&insertion->data.student_birth_year);
insertion->next=NULL;
tail=insertion;
N++;
}}
void insert_middle_list () { //Function to insert a student at the middle of the linked list
/*In this function we used the tmp pointer to traverse using a for loop until it reaches the middle of the list ((N/2)-1)
then inserting the student in insertion node */
struct node* insertion=NULL;
struct node* tmp=head;
insertion = (struct node*)malloc(sizeof(struct node));
if (insertion==NULL)
printf("Memory can't be allocated!!\n");
else {
for(int i=0;i<(N/2)-1;i++)
tmp=tmp->next;
printf("Please Enter the Name of the Student: \n");
scanf("%s",insertion->data.student_name);
printf("Please Enter the ID of Student: \n");
scanf("%d",&insertion->data.student_ID);
printf("Please Enter the Last Year Score of Student: \n");
scanf("%d",&insertion->data.student_last_score);
printf("Please Enter the Birthday of Student (Day/Month/Year) respectively each at a time: \n");
scanf("%d %d %d",&insertion->data.student_birth_day,&insertion->data.student_birth_month,&insertion->data.student_birth_year);
insertion->next=tmp->next;
tmp->next=insertion;
N++;
} }
void display_list () { //Function to display the linked list
/*In this function we used tmp pointer to traverse across the whole linked list using a for loop
and displaying all nodes of the list */
struct node* tmp;
tmp=head;
int i=0;
if(tmp==NULL) {printf("List is Empty!!\n");
}
else {
while (tmp)
{
    printf("\n\nStudent Number %d Name: %s",i+1,tmp->data.student_name);
    printf("\nStudent Number %d ID: %d",i+1,tmp->data.student_ID);
    printf("\nStudent Number %d Last Year Score: %d",i+1,tmp->data.student_last_score);
    printf("\nStudent Number %d Birthday: %d/%d/%d",i+1,tmp->data.student_birth_day,tmp->data.student_birth_month,tmp->data.student_birth_year);
    tmp=tmp->next;
    i++; }
    }
}
struct students * list=NULL; //Array of students
void create_array() { //Function to create the array with specified number of students by the user
    /*In this function we allocated memory for the array using number of students "N" defined by the user
    using malloc function
    then the flow of the code is similar to the previously mentioned linked list */
list=(struct students*)malloc(sizeof(struct students)*N);
if (list==NULL)
    printf("Memory can't be allocated!!");
else {
printf("Please Enter the Name of Student Number 1: \n");
scanf("%s",list[0].student_name);
printf("Please Enter the ID of Student Number 1: \n");
scanf("%d",&list[0].student_ID);
printf("Please Enter the Last Year Score of Student Number 1: \n");
scanf("%d",&list[0].student_last_score);
printf("Please Enter the Birthday of Student Number 1 (Day/Month/Year) respectively each at a time: \n");
scanf("%d %d %d",&list[0].student_birth_year,&list[0].student_birth_month,&list[0].student_birth_day);
int i;
for(i=1;i<N;i++) {
printf("Please Enter the Name of Student Number %d: \n",i+1);
scanf("%s",list[i].student_name);
printf("Please Enter the ID of Student Number %d: \n",i+1);
scanf("%d",&list[i].student_ID);
printf("Please Enter the Last Year Score of Student Number %d: \n",i+1);
scanf("%d",&list[i].student_last_score);
printf("Please Enter the Birthday of Student Number %d (Day/Month/Year) respectively each at a time: \n",i+1);
scanf("%d %d %d",&list[i].student_birth_day,&list[i].student_birth_month,&list[i].student_birth_year);
} }
}
void insert_begin_array () { //Function to insert a student at the beginning of the array
/*In this function we incremented the number of students
then reallocated the memory of the array with the new "N"
now, there is an empty location in the last position of the array
so we pushed all the elements of the array one position forward to leave the first position of the array empty
then we inserted the student in the beginning of the array*/
N++;
realloc(list,sizeof(struct students)*N);
if (list==NULL)
    printf("Memory can't be allocated!!");
else {
int i;
for(i=N-1;i>0;i--)
list [i] = list[i-1];
printf("Please Enter the Name of the Student: \n");
scanf("%s",list[i].student_name);
printf("Please Enter the ID of the Student: \n");
scanf("%d",&list[i].student_ID);
printf("Please Enter the Last Year Score of the Student: \n");
scanf("%d",&list[i].student_last_score);
printf("Please Enter the Birthday of the Student (Day/Month/Year) respectively each at a time: \n");
scanf("%d %d %d",&list[i].student_birth_day,&list[i].student_birth_month,&list[i].student_birth_year);
}}
void insert_end_array () { //Function to insert a student at the end of the array
/*In this function we reallocated the memory for the array as mentioned before
then we just added the student in the last position of the array as it's already empty */
N++;
realloc(list,sizeof(struct students)*N);
if (list==NULL)
    printf("Memory can't be allocated!!");
else {
printf("Please Enter the Name of the Student: \n");
scanf("%s",list[N-1].student_name);
printf("Please Enter the ID of the Student: \n");
scanf("%d",&list[N-1].student_ID);
printf("Please Enter the Last Year Score of the Student: \n");
scanf("%d",&list[N-1].student_last_score);
printf("Please Enter the Birthday of the Student (Day/Month/Year) respectively each at a time: \n");
scanf("%d %d %d",&list[N-1].student_birth_day,&list[N-1].student_birth_month,&list[N-1].student_birth_year);
}}
void insert_middle_array (){ //Function to insert a student at the middle of the array
/*In this function we reallocated the memory for the array as mentioned before
then we pushed the elements one step forward but not all the elements
the elements starting from the middle of the array
so now the middle position is empty
we stored the student in this empty position*/
N++;
realloc(list,sizeof(struct students)*N);
if (list==NULL)
    printf("Memory can't be allocated!!");
else {
int i;
for (i=(N-1);i>(N-1)/2;i--)
list[i]=list[i-1];
printf("Please Enter the Name of the Student: \n");
scanf("%s",list[i].student_name);
printf("Please Enter the ID of the Student: \n");
scanf("%d",&list[i].student_ID);
printf("Please Enter the Last Year Score of the Student: \n");
scanf("%d",&list[i].student_last_score);
printf("Please Enter the Birthday of the Student (Day/Month/Year) respectively each at a time: \n");
scanf("%d %d %d",&list[i].student_birth_day,&list[i].student_birth_month,&list[i].student_birth_year);
}}
void display_array(){ //Function to display the array
    /*In this function we used a for loop to display all the elements of the array*/
 if(list==NULL)
printf("Array is empty!!");
else {
for (int i=0;i<N;i++) {
    printf("\n\nStudent Number %d Name: %s",i+1,list[i].student_name);
    printf("\nStudent Number %d ID: %d",i+1,list[i].student_ID);
    printf("\nStudent Number %d Last Year Score: %d",i+1,list[i].student_last_score);
    printf("\nStudent Number %d Birthday: %d/%d/%d",i+1,list[i].student_birth_day,list[i].student_birth_month,list[i].student_birth_year);
}
}}
int main()
{   /*The menu displayed for the user */
    int choice1,choice2;
    while(1) {
    printf("====Welcome to the Student Insertion System====\nPlease Enter the Number of Students: \n");
    scanf("%d",&N);
label1 : printf("\n1]Linked List\n2]Dynamic Arrays\n");
    scanf("%d",&choice1);
switch (choice1) {
case 1: {
create_nodes();
label2: printf("\n\n1]Insert at the Beginnig\n2]Insert at the Middle\n3]Insert at the End\n4]Display the Linked List\n5]Exit\n");
scanf("%d",&choice2);
switch (choice2) {
case 1: {insert_begin_list();break;}
case 2: {insert_middle_list();break;}
case 3: {insert_end_list();break;}
case 4: {display_list();break;}
case 5: return 0;
default: {printf("You Entered an Invalid Choice!!\nPlease Choose again\n"); goto label2;}
}
} goto label2;
case 2: {
create_array();
label3: printf("\n\n1]Insert at the Beginnig\n2]Insert at the Middle\n3]Insert at the End\n4]Display the Dynamic Array\n5]Exit\n");
scanf("%d",&choice2);
switch (choice2) {
case 1: {insert_begin_array();break;}
case 2: {insert_middle_array();break;}
case 3: {insert_end_array();break;}
case 4: {display_array();break;}
case 5: return 0;
default: {printf("You Entered an Invalid Choice!!\nPlease Choose again\n"); goto label3;}
} goto label3;
}
default: {printf("You Entered an Invalid Choice!!\nPlease Choose again\n"); goto label1;}    }
}return 0;}
