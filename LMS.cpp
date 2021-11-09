#include <iostream>
#include <stdio.h>
#include<conio.h>
#define Book_allowed 2
using namespace std;

class library
{
    protected:
        struct Node
        {
            int id,book_count;
            string name,author,publisher;
            Node *next_add=NULL;
        };
 
    public:
        Node *head=NULL;
        void displayAll();
        void insert();
        void search();
        void update();
        void deleteNode();
         Node *search_supporting(int id)
        {
            if(head==NULL)
            {
                return NULL;
            }
            else
            {
            Node *temp=head;
            while(temp!= NULL)
            {
                if(id==temp->id)
                {
                    cout<<"Id found in search_supporting";
                   
                    return temp;
                }
                temp=temp->next_add;
            }
            return NULL;
            }
        }  
};

class students:public library
{
      private:
        struct Student
        {
            int stu_id;
            string stu_name;
            int book_id[Book_allowed];
            Student *next_add=NULL;
        };
    public:
   
        Student *stu_head=NULL;
        void issueBook();
        void studentWithBooks();
       
        void insertNode(Student *ptr)
        {
            Student *temp=new Student;
            temp->stu_id=ptr->stu_id;
            temp->stu_name=ptr->stu_name;
            temp->book_id[0]=ptr->book_id[0];
            if(stu_head==NULL)
            {
                cout<<"head is null in student";
                stu_head=temp;
                cout<<"stu name"<<ptr->stu_name;
            }
            else
            {
                Student *temp_ptr=stu_head;
                 while(temp_ptr-> next_add != NULL)
                {
           
                        temp_ptr=temp_ptr->next_add;
                }
                temp_ptr->next_add=temp;  
            }
           
        }
       
        Student *stu_search_supporting(int id)
        {
            if(stu_head==NULL)
            {
                cout<<" head is null no id found";
                return NULL;
            }
            else
            {
            Student *temp=stu_head;
            while(temp!= NULL)
            {
                if(id==temp->stu_id)
                {
                    return temp;
                }
                temp=temp->next_add;
            }
            return NULL;
            }
        }
   
};
void students::studentWithBooks()
{
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    Student *temp=stu_head;
    if(stu_head==NULL)
    {
        cout<<"No record available";
    }
    else
    {
    while(temp!=NULL)
    {
        cout<<"\nStudent id : "<<temp->stu_id;
        cout<<"\nStudent Name : "<<temp->stu_name;
        cout<<"\nBooks alloted :";
        for(int i=0;i<Book_allowed;i++)
        {
            if(temp->book_id[i]>0)
            {
                cout<<temp->book_id[i]<<" ";
            }
        }
        temp=temp->next_add;
    }
    }
   
}
void students::issueBook()
{
   
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    if(head==NULL)
    {
        cout<<"No Books available to issue............!";
    }
    else
    {
        cout<<"\n Books available for issue.....!";
        displayAll();
        int id,book_id;
     
        c:
         cout<<"Enter Book ID:";
         cin>>book_id;
         Node *ptr=search_supporting(book_id);
         if(ptr==NULL && ptr->book_count>0)
         {
             cout<<"Invlaid Book Id";
             goto c;
         }
        cout<<"\n\nEnter student ID:";
        cin>>id;
        Student *temp=stu_search_supporting(id);
        if(temp==NULL)
        {
              cout<<"No record found for student id";
              Student *stu_temp=new Student;
              stu_temp->stu_id=id;
              stu_temp->book_id[0]=book_id;
              cout<<"Enter Student Name : ";
              cin>>stu_temp->stu_name;
              ptr->book_count=ptr->book_count-1;
              insertNode(stu_temp);
              cout<<"Record added!!!";
        }
        else
        {
            int i=1;
           
            while(i<=Book_allowed)
            {
                if(temp->book_id[i-1]==0)
                {
                    cout<<"Okay we got 0";
                    break;
                }
             
                i++;
            }
         
            i=i-1;
            if(i==Book_allowed)
            {
                cout<<"Book can not be alloted you are already full";
            }
            else
            {
                cout<<"Ookay we can give you a book";
                temp->book_id[i]=book_id;
                cout<<"Book alloted";
            }
           
        }
       
       
    }
}

void library::deleteNode()
{
                cout<<"\n\n\t\t\t=========================================================";
                cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
                cout<<"\n\n\t\t\t=========================================================";
                cout<<"\n\n  Delete a record........!";
                int id;
                cout<<"\n\n BookId";
                cin>>id;
                Node *temp=search_supporting(id);
                if(head==NULL)
                {
                    cout<<"No record to delete !!";
                }
                else if(temp==NULL)
                {
                    cout<<"\n\nInvalid Id !!";
                }
                else
                {
                   
                    if(head->id==id)
                    {
                        head=head->next_add;
                        cout<<"Deleted!!!";
                        cout<<"Now List is empty!";
                    }
                    else
                    {
                        Node* prev=NULL;
                        Node* temp2=head;
                        while(temp2->id!=id)
                        {
                            prev=temp2;
                            temp2=temp2->next_add;
                        }
                        if(temp->next_add==NULL)
                        {
                            prev->next_add=NULL;
                        }
                        else
                        {
                            prev->next_add=temp->next_add;
                        }
                        cout<<"Record Deleted!!!";
                    }
                   
                }
}
void library::displayAll()
{
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";

    if(head==NULL)
    {
        cout<<"There is no data to show!!";
    }
    else
    {
        Node *ptr=head;
        while(ptr != NULL)
        {
                cout<<"\n\n Book id : "<<ptr->id;
                cout<<"\n\n Book Name : "<<ptr->name;
                cout<<"\n\n Book Count : "<<ptr->book_count;
                cout<<"\n\n Author Name : "<<ptr->author;
                cout<<"\n\n Publisher Name : "<<ptr->publisher;
                cout<<"\n\n\t\t\t=========================================================";
                ptr =ptr->next_add;
        }
    }
   
}

void library::update()
{
     system("clear");
    int id;
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    if(head==NULL)
    {
        cout<<"No Record exist to update..........";
    }
    else
    {
   
        cout<<"Update book details";
        cout<<"Book id : ";
        cin>>id;
        Node *temp_node=search_supporting(id);
        if(temp_node==NULL)
        {
            cout<<"Invalid id to update";
        }
        else
        {
            int id_check;
            cout<<"\n\nBook Id : ";
            cin>>id_check;
            cout<<"\n\nVerifying Id";
            Node *ptr=search_supporting(id_check);
            if(ptr==NULL || id_check==id)
            {
                           temp_node->id=id_check;
                           cout<<"Valid Id!!..continue filling details";
                           cout<<"Name : ";
                           cin>>temp_node->name;
                           cout<<"Book Count : ";
                           cin>>temp_node->book_count;
                           cout<<" Author Name : ";
                           cin>>temp_node->author;
                           cout<<" Publisher name: ";
                            cin>>temp_node->publisher;
                            cout<<"Details updated successfully......!";
                           
               
            }

           
        }
         
    }
}
void library::search()
{
    system("clear");
    int id;
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    if(head==NULL)
    {
        cout<<"\n\n Linked List is Empty............";
       
    }
    else
    {
        cout<<"\n\n Book ID:";
        cin>>id;
        Node *ptr = search_supporting(id);
        if(ptr==0)
        {
            cout<<"Invalid Id Enetered...................!";
        }
        else
        {
                system("clear");
                cout<<"\n\n\t\t\t=========================================================";
                cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
                cout<<"\n\n\t\t\t=========================================================";
                cout<<"\n\n Book id : "<<ptr->id;
                cout<<"\n\n Book Name : "<<ptr->name;
                cout<<"\n\n Book count : "<<ptr->book_count;
                cout<<"\n\n Author Name : "<<ptr->author;
                cout<<"\n\n Publisher Name : "<<ptr->publisher;
               
            }
           
           
        }
   
}

void menu()
{
    students obj;
    p:
 
    int choice;
     cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n1. Insert a New Book";
    cout<<"\n2. Search a Book";
    cout<<"\n3. Update record of Books";
    cout<<"\n4. Delete a Book";
    cout<<"\n5. Show all record o Books";

    cout<<"\n\n\t\t\t=========================================================";
   
    cout<<"\n6. Issue a book to student";
    cout<<"\n7. Desposit a book of stduent";
    cout<<"\n8. Issued books to stduents";
   
       cout<<"\n\n\t\t\t=========================================================";
   
   
    cout<<"\n9. Exit";
    cout<<"\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.search();
           
            break;
        case 3:
            obj.update();
            break;
        case 4:
            obj.deleteNode();
            break;
        case 5:
            obj.displayAll();
            break;
        case 6:
           obj.issueBook();
            break;
        case 8:
            obj.studentWithBooks();
            break;
               
        case 9:
            exit(0);
        default:
            cout<<"Invalid Choice please try again";
    }
    getch();
    goto p;
   
}

void library :: insert()
{
   
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    Node *temp_node = new Node;
    q:
    cout<<"\n\nBook Id : ";
    cin>>temp_node->id;
    cout<<"\n\nVerifying Id";
    Node *ptr=search_supporting(temp_node->id);
    cout<<" here is the ptr : "<<ptr;
    if(ptr!=NULL)
    {
        cout<<"\n\nInvalid Id alreay exist !!";
        goto q;
    }
    cout<<"Valid Id!!..continue filling details";
    cout<<"Name : ";
    cin>>temp_node->name;
    cout<<"Book Count";
    cin>>temp_node->book_count;
    cout<<" Author Name : ";
    cin>>temp_node->author;
    cout<<" Publisher name: ";
    cin>>temp_node->publisher;
    temp_node->next_add=NULL;
    if(head==NULL)
    {
        cout<<"head Null";
        head=temp_node;
    }
    else
    {
        Node *ptr=head;
        while(ptr-> next_add != NULL)
        {
           
            ptr =ptr->next_add;
        }
        ptr->next_add=temp_node;
    }
    cout<<"Record added successfully........................";
}
int main()
{
    menu();
    return 0;
}
