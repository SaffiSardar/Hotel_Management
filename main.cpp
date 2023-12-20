#include <iostream>
#include <fstream>
using namespace std;

ofstream MyFile("filename.txt");
int reservation_count = 0;
 
class Rooms;
class Services;

class Hotel{
    public:
        int ID,no_of_family_members,time_of_stay,outstanding_payment ;
        string First_name, Second_name;
        Hotel*next;
        Hotel*prev;
        Hotel(int ID,string First_name,string Second_name,int no_of_family_members,int time_of_stay){
            next = NULL;
            prev = NULL;
            this->ID = ID;
            this->First_name = First_name;
            this->Second_name = Second_name;
            this->no_of_family_members = no_of_family_members;
            this->time_of_stay = time_of_stay;
            this->outstanding_payment = 0;
        }
};
        void addathead(Hotel*&head ,int ID,string First_name,string Second_name,int no_of_family_members,int time_of_stay){
            if(reservation_count<=19){
                Hotel*temp = new Hotel(ID,First_name,Second_name,no_of_family_members,time_of_stay);
                temp->next = head;
                head->prev = temp;
                head = temp;
                reservation_count++;
            }
            else{
                cout<<"Hotel Full, No further reservations can be made!"<<endl;
            }
        }
        void deletefromtail(Hotel*&tail){
            if(tail!=NULL){
            Hotel*del = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete del;
            reservation_count--;
            }
        }
       
        void searchinLL(Hotel*&head,int cni){
            if(head!=NULL){
            Hotel*temp = head;
            while(temp!=NULL){
                if(temp->ID == cni){
                cout<<"ID Found"<<endl;
                return;
            }
            temp = temp->next;
            }
            cout<<"ID Not Found"<<endl;
            }
        }

        void sortrecords(Hotel*&head){
            if(head!=NULL){
                Hotel*current = head;
                while(current->next!=NULL){
                    Hotel*currloc = current->next;
                    while(currloc!=NULL){
                        if((current->ID)>(currloc->ID)){
                            Hotel*temp = new Hotel(0,"","",0,0);
                            temp->ID = current->ID;
                            current->ID = currloc->ID;
                            currloc->ID = temp->ID;
                            currloc = currloc->next;
                            current = current->next;
                        }
                    }
                }
            }
        }

        void display(Hotel*&head){
            Hotel*temp = head;
            while(temp!=NULL){
            cout<<"ID: "<<temp->ID<<endl;
            cout<<"First Name: "<<temp->First_name<<endl;
            cout<<"Last Name: "<<temp->Second_name<<endl;
            cout<<"Outstanding Payment-> "<<temp->outstanding_payment<<endl;
            cout<<endl;
            cout<<endl;
            temp = temp->next;
        }
    }




class Rooms{
    
    public:
    void single_room(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (20*head->time_of_stay);
    }
    void double_room(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (40*head->time_of_stay);
    }
    void connecting_room(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (100*head->time_of_stay);
    }
};

class Services{
    public:
    void room_laundry(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (15*head->no_of_family_members);
    }
    void room_makeup(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + 20;
    }
    void room_eatery(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (7*head->no_of_family_members);
    }

};



int main()
{   
cout<<"<---Welcome to Hotel Aryaduta Management System--->";
    int choice = 1;
    int ID, no_of_family_members,time_of_stay,outstanding_payment ;
    string First_name, Second_name;
    cout<<" Dear Receptionist, please enter your First Customer's "<<endl;
    cout<<"ID: ";
    cin>>ID;
    MyFile<<"ID: "<<ID<<endl;
    cout<<"First Name: ";
    cin>>First_name;
    MyFile<<"First_name: "<<First_name<<endl;;
    cout<<"Last Name: ";
    cin>>Second_name;
    MyFile<<"Second_name: "<<Second_name<<endl;
    cout<<"No. of Family Member: ";
    cin>>no_of_family_members;
    MyFile<<"No_of_family_members: "<<no_of_family_members<<endl;
    cout<<"Duration of Stay: ";
    cin>>time_of_stay;
    MyFile<<"Duration_of_stay: "<<time_of_stay<<endl;
    Hotel*head = new Hotel(ID,First_name,Second_name,no_of_family_members,time_of_stay);
    Hotel*tail = head;
    if(no_of_family_members == 1){
        Rooms c1;
        c1.single_room(head);
    }
    else if(no_of_family_members == 2){
        Rooms c1;
        c1.double_room(head);
    }
    else{
        Rooms c1;
        c1.connecting_room(head);
    }
    cout<<"Does the customer want services? Press Y/N: ";
    char choose;
    cin>>choose;
    if(choose == 'Y'){
        Services c1s;
        cout<<"Do you want to avail Eatery? Press Y/n: ";
        cin>>choose;
        if(choose = 'Y'){
            c1s.room_eatery(head);
        }
        cout<<"Do you want to avail Laundry? Press Y/n: ";
        cin>>choose;
        if(choose = 'Y'){
            c1s.room_laundry(head);
        }
        cout<<"Do you want to avail room makeup? Press Y/n: ";
        cin>>choose;
        if(choose = 'Y'){
            c1s.room_makeup(head);
        }
    }
    MyFile<<"Payment to be done: "<<head->outstanding_payment<<endl;
    MyFile<<endl;
    cout<<endl;
    cout<<endl;
    cout<<">>>> Welcome To Management Panel <<<<"<<endl;
    while(choice>=1 && choice<=5){
    cout<<"         Panel of Instructions: "<<endl;
    cout<<"Press 1 for Adding another customer in reservation queue"<<endl;
    cout<<"Press 2 for deleting at tail, the satisfied customer"<<endl;
    cout<<"Press 3 for Searching a customer's details "<<endl;
    cout<<"Press 4 for Sorting customer reservation for display purposes"<<endl;
    cout<<"Press 5 for Displaying the reservation confrimed Customers"<<endl;
    cout<<"Press 6 for TERMINATING PROGRAM"<<endl;

    cout<<endl;
    cin>>choice;
    cout<<endl;
    if(choice == 1){
        cout<<" Dear Receptionist, please enter your Customer's "<<endl;
    cout<<"ID: ";
    cin>>ID;
    MyFile<<"ID: "<<ID<<endl;
    cout<<"First Name: ";
    cin>>First_name;
    MyFile<<"First_name: "<<First_name<<endl;;
    cout<<"Last Name: ";
    cin>>Second_name;
    MyFile<<"Second_name: "<<Second_name<<endl;
    cout<<"No. of Family Member: ";
    cin>>no_of_family_members;
    MyFile<<"No_of_family_members: "<<no_of_family_members<<endl;
    cout<<"Duration of Stay: ";
    cin>>time_of_stay;
    MyFile<<"Duration_of_stay: "<<time_of_stay<<endl;
    addathead(head,ID,First_name,Second_name,no_of_family_members,time_of_stay);
    if(no_of_family_members == 1){
        Rooms c1;
        c1.single_room(head);
    }
    else if(no_of_family_members == 2){
        Rooms c1;
        c1.double_room(head);
    }
    else{
        Rooms c1;
        c1.connecting_room(head);
    }
    cout<<"Does the customer want services? Press Y/N: ";
    char choose;
    cin>>choose;
    if(choose == 'Y'){
        Services c1s;
        cout<<"Do you want to avail Eatery? Press Y/n: ";
        cin>>choose;
        if(choose = 'Y'){
            c1s.room_eatery(head);
        }
        cout<<"Do you want to avail Laundry? Press Y/n: ";
        cin>>choose;
        if(choose = 'Y'){
            c1s.room_laundry(head);
        }
        cout<<"Do you want to avail room makeup? Press Y/n: ";
        cin>>choose;
        if(choose = 'Y'){
            c1s.room_makeup(head);
        }
    }
    MyFile<<"Payment to be done: "<<head->outstanding_payment<<endl;
    MyFile<<endl;
        cout<<"*DONE*"<<endl;
        cout<<endl;
    }
   
    if(choice == 2){
        deletefromtail(tail);
        cout<<"*DONE*"<<endl;
        cout<<endl;
    }
    if(choice == 3){
        cout<<"Enter ID to be searched: ";
        int num;
        cin>>num;
        searchinLL(head,num);
        cout<<"*DONE*"<<endl;
        cout<<endl;
    }
   
    if(choice == 4){
        sortrecords(head);
        cout<<"*DONE*"<<endl;
        cout<<endl;
    }
    if(choice == 5){
        display(head);
        cout<<"*DONE*"<<endl;
        cout<<endl;
    }
    }
    MyFile.close();
}
    

