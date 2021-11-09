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
        void depositBook();
        static void wait();
        void insertNode(Student *ptr)
        {
            Student *temp=new Student;
            temp->stu_id=ptr->stu_id;
            temp->stu_name=ptr->stu_name;
            temp->book_id[0]=ptr->book_id[0];
            if(stu_head==NULL)
            {
              
                stu_head=temp;
                
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
void students::depositBook()
{
    system("clear");
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    if(stu_head==NULL)
    {
        cout<<"\n No record available !";
    }
    else
    {
        int id,book_id;
        q:
        cout<<"\n\n Student ID : ";
        cin>>id;
        Student *temp=stu_search_supporting(id);
        if(temp==NULL)
        {
            cout<<"\n Invalid ID !!";
            goto q;
        }
        cout<<"\n\n Book id : ";
        cin>>book_id;
        bool flag=false;
        for(int i=Book_allowed-1;i>=0;i--)
        {
        
            if(book_id==temp->book_id[i])
            {
                temp->book_id[i]=0;
                flag=true;
                break;
            }
        }
        if(flag)
        {
            Node *tempr=search_supporting(book_id);
            tempr->book_count+=1;
            cout<<" \n\nBook successfully Submitted !";
            
        }
        else
        {
            cout<<"\n\n Sorry!! Book not found in students account";
        }
        
    }
    cout<<"\n\n\t\t\t=========================================================";
    students::wait();
}
void students::studentWithBooks()
{
    system("clear");
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    
    Student *temp=stu_head;
    if(stu_head==NULL)
    {
        cout<<"\n\n No record available !!";
    }
    else
    {
        cout<<"\n\n Record of Students having Books \n";
    while(temp!=NULL)
    {
        cout<<"\n Student id : "<<temp->stu_id;
        cout<<"\n Student Name : "<<temp->stu_name;
        cout<<"\n Books alloted : ";
        for(int i=0;i<Book_allowed;i++)
        {
            if(temp->book_id[i]>0)
            {
                cout<<temp->book_id[i]<<" ";
            }
        }
         cout<<"\n\n\t\t\t=========================================================";
        temp=temp->next_add;
    }
    }
    students::wait();
   
}
void students::issueBook()
{
   
     system("clear");
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    if(head==NULL)
    {
        cout<<"\n\nNo Books available to issue............!";
    }
    else
    {
      
        displayAll();
        int id,book_id;
        c:
         cout<<"\n Book ID : ";
         cin>>book_id;
         Node *ptr=search_supporting(book_id);
         if(ptr==NULL || ptr->book_count==0)
         {
             cout<<"\n\n Invlaid Book Id.......!";
             goto c;
         }
        cout<<"\n\n Enter Student ID : ";
        cin>>id;
        Student *temp=stu_search_supporting(id);
        if(temp==NULL)
        {
              cout<<"\n No record found for student id(New record will be added)";
              Student *stu_temp=new Student;
              stu_temp->stu_id=id;
              stu_temp->book_id[0]=book_id;
              cout<<"\n\n Enter Student Name : ";
              cin>>stu_temp->stu_name;
              ptr->book_count=ptr->book_count-1;
              insertNode(stu_temp);
              cout<<"\n\nRecord added!!!";
        }
        else
        {
            int i=1;
           
            while(i<=Book_allowed)
            {
                if(temp->book_id[i-1]==0)
                {
                   
                    break;
                }
             
                i++;
            }
         
            i=i-1;
            if(i==Book_allowed)
            {
                cout<<"\n\n Sorry!! Student already has taken at Full capacity";
            }
            else
            {
                cout<<"\n\n Congratulations!! Book alloted.";
                ptr->book_count=ptr->book_count-1;
                temp->book_id[i]=book_id;
            }
           
        }
        
       
       
    }
    cout<<"\n\n\t\t\t=========================================================";
    students::wait();
    
}

void library::deleteNode()
{
    system("clear");
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n  Delete a record........!";
    int id;
    cout<<"\n\n Book ID : ";
    cin>>id;
    Node *temp=search_supporting(id);
    if(head==NULL)
    {
        cout<<"\n\n No record to delete !!";
    }
    else if(temp==NULL)
    {
        cout<<"\n\n Invalid Id !!";
    }
    else
    {
        if(head->id==id)
        {
            head=head->next_add;
            cout<<"\n\n Deleted!!!";
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
            cout<<"\n\n Record Deleted!!!";
        }
                   
    }
    cout<<"\n\n\t\t\t=========================================================";
    students::wait();
}
void library::displayAll()
{
     system("clear");
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";

    if(head==NULL)
    {
        cout<<"\n\n There is no data to show!!";
    }
    else
    {
        cout<<"\t\t\t\n\n Record of all Books Available! ";
        Node *ptr=head;
        while(ptr != NULL)
        {
                cout<<"\n\n Book id : "<<ptr->id;
                cout<<"\n\n Book Name : "<<ptr->name;
                cout<<"\n\n Book Count : "<<ptr->book_count;
                cout<<"\n\n Author Name : "<<ptr->author;
                cout<<"\n\n Publisher Name : "<<ptr->publisher;
                cout<<"\n\n\t\t\t=========================================================";
                ptr=ptr->next_add;
        }
    }
     students::wait();
   
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
        cout<<"\n\n No Record exist to update..........";
    }
    else
    {
   
        cout<<"\n\t\t\t Update book details";
        cout<<"\n\n Book id : ";
        cin>>id;
        Node *temp_node=search_supporting(id);
        if(temp_node==NULL)
        {
            cout<<"\nInvalid id to update";
        }
        else
        {
            int id_check;
            cout<<"\n\nNew Book Id : ";
            cin>>id_check;
         
            Node *ptr=search_supporting(id_check);
            if(ptr==NULL || id_check==id)
            {
                temp_node->id=id_check;
                cout<<"\n Book Name : ";
                cin>>temp_node->name;
                cout<<"\n Book Count : ";
                cin>>temp_node->book_count;
                cout<<"\n Author Name : ";
                cin>>temp_node->author;
                cout<<"\n Publisher name: ";
                cin>>temp_node->publisher;
                cout<<"\n Details updated successfully......!";
            }

           
        }
         
    }
    students::wait();
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
        cout<<"\t\t\t\n BOOK Details";
        cout<<"\n\n Book ID : ";
        cin>>id;
        Node *ptr = search_supporting(id);
        if(ptr==0)
        {
            cout<<"\n\n Invalid Id Enetered...................!";
        }
        else
        {
          
                
                cout<<"\n\n Book Name : "<<ptr->name;
                cout<<"\n\n Book count : "<<ptr->book_count;
                cout<<"\n\n Author Name : "<<ptr->author;
                cout<<"\n\n Publisher Name : "<<ptr->publisher;
               
            }
           
           
        }
        cout<<"\n\n\t\t\t=========================================================";
        students::wait();
        
   
}

void menu()
{
  
    students obj;
    int choice;
    p:
    system("clear");
   
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n 1. Add a New Book";
    cout<<"\n 2. Search a Book";
    cout<<"\n 3. Update record of Books";
    cout<<"\n 4. Delete a Book";
    cout<<"\n 5. Show stock of available Books";

    cout<<"\n\n\t\t\t=========================================================";
   
    cout<<"\n 6. Issue a book to student";
    cout<<"\n 7. Desposit a book of stduent";
    cout<<"\n 8. Issued books to stduents";
   
       cout<<"\n\n\t\t\t=========================================================";
   
   
    cout<<"\n 9. Exit";
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
        case 7:
            obj.depositBook();
            break;
        case 8:
            obj.studentWithBooks();
            break;
               
        case 9:
            exit(0);
        default:
            cout<<" \nInvalid Choice please try again";
    }
    getch();
    goto p;
   
}

void library :: insert()
{
    system("clear");
    cout<<"\n\n\t\t\t=========================================================";
    cout<<"\n\n\t\t\t================LIBRARY MANAGEMENT SYSTEM================";
    cout<<"\n\n\t\t\t=========================================================";
    Node *temp_node = new Node;
    cout<<"\t\t\t\n\n Adding a new Book in LIBRARY";
    q:
    cout<<"\n\n Book Id : ";
    cin>>temp_node->id;
   
    Node *ptr=search_supporting(temp_node->id);
    
  
    if(ptr!=NULL)
    {
        cout<<"\n Invalid Id alreay exist !!";
        goto q;
    }

    cout<<"\n Book Name : ";
    cin>>temp_node->name;
    cout<<"\n Book Count : ";
    cin>>temp_node->book_count;
    cout<<"\n Author Name : ";
    cin>>temp_node->author;
    cout<<"\n Publisher name: ";
    cin>>temp_node->publisher;
    temp_node->next_add=NULL;
    if(head==NULL)
    {
        
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
    cout<<" Record added successfully........................!";
    cout<<"\n\n\t\t\t =========================================================";
    students::wait();
}
void students::wait()
{
    char a;
    while(1)
    {

        cout<<"\n\n Press Y to conutinue : ";
        cin>>a;
        if(a=='Y')
        {
            break;
        }
    }
}
int main()
{
    menu();
    return 0;
}
