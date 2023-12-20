#include <iostream>
using namespace std;

int reservation_count = 0;

class Hotel{
    public:
        int cnic, Phone_number ,no_of_family_members,time_of_stay,outstanding_payment ;
        string First_name, Second_name;
        Hotel*next;
        Hotel*prev;
        Hotel(int cnic,int Phone_number,string First_name,string Second_name,int no_of_family_members,int time_of_stay){
            Hotel*next = NULL;
            Hotel*prev = NULL;
            this->cnic = cnic;
            this->Phone_number = Phone_number;
            this->First_name = First_name;
            this->Second_name = Second_name;
            this->no_of_family_members = no_of_family_members;
            this->time_of_stay = time_of_stay;
            this->outstanding_payment = 0;
        }
        void addathead(Hotel*&head ,int cnic,int Phone_number,string First_name,string Second_name,int no_of_family_members,int time_of_stay){
            if(reservation_count<=19){
                Hotel*temp = new Hotel(cnic,Phone_number,First_name,Second_name,no_of_family_members,time_of_stay);
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
                if(temp->cnic == cni){
                cout<<"Hotel Found"<<endl;
                return;
            }
            temp = temp->next;
            }
            cout<<"Hotel Not Found"<<endl;
            }
        }

        void sortrecords(Hotel*&head){
            if(head!=NULL){
                Hotel*current = head;
                while(current->next!=NULL){
                    Hotel*currloc = current->next;
                    while(currloc!=NULL){
                        if((current->cnic)>(currloc->cnic)){
                            Hotel*temp = new Hotel(0,0,"","",0,0);
                            temp->cnic = current->cnic;
                            current->cnic = currloc->cnic;
                            currloc->cnic = temp->cnic;
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
            cout<<"First Name: "<<temp->First_name<<endl;
            cout<<"Last Name: "<<temp->Second_name<<endl;
            cout<<"Outstanding Payment-> "<<temp->outstanding_payment<<endl;
            cout<<endl;
            cout<<endl;
            temp = temp->next;
        }
}

};


class Rooms:public Hotel{
    
    public:
    void single_room(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (20*time_of_stay);
    }
    void double_room(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (40*time_of_stay);
    }
    void connecting_room(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (100*time_of_stay);
    }
};

class Services:public Rooms{
    public:
    void room_laundry(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (15*no_of_family_members);
    }
    void room_makeup(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + 20;
    }
    void room_eatery(Hotel*&head){
        head->outstanding_payment = head->outstanding_payment + (7*no_of_family_members);
    }

};

class Guests:public Services{

};

int main()
{   
// cout<<"<---Welcome to Hotel Aryaduta Management System--->";
//     int choice = 1;
//     int cnic, Phone_number ,no_of_family_members,time_of_stay,outstanding_payment ;
//     string First_name, Second_name;
//     cout<<" Dear Receptionist, please enter your First Customer's "<<endl;
//     cout<<"Cnic: ";
//     cin>>cnic;
//     cout<<"Phone Number: ";
//     cin>>Phone_number;
//     cout<<"First Name: ";
//     cin>>First_name;
//     cout<<"Last Name: ";
//     cin>>Second_name;
//     cout<<"No. of Family Member: ";
//     cin>>no_of_family_members;
//     cout<<"Duration of Stay: ";
//     cin>>time_of_stay;
//     Hotel*head = new Hotel(cnic,Phone_number,First_name,Second_name,no_of_family_members,time_of_stay);
//     Hotel*tail = head;
//     if(no_of_family_members == 1){
        
        
    
//     }
//     cout<<">>>> Welcome To Management Panel <<<<"<<endl;
//     while(choice>=1 && choice<=10){
//     cout<<"         Panel of Instructions: "<<endl;
//     cout<<"Press 1 for Adding at head, another customer in reservation queue"<<endl;
//     cout<<"Press 6 for deleting at tail satisfied customer from queue"<<endl;
//     cout<<"Press 7 for Searching a customer's details "<<endl;
//     cout<<"Press 9 for Sorting customer reservation for display purposes"<<endl;
//     cout<<"Press 10 for Displaying the reservation confrimed Customers"<<endl;
//     cout<<"Press 11 for TERMINATING PROGRAM"<<endl;

//     cout<<endl;
//     cin>>choice;
//     cout<<endl;
//     if(choice == 1){
//         cout<<"Enter Num to be added: ";
//         int numb;
//         cin>>numb;
//         addathead(head,numb);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 2){
//         cout<<"Enter Num to be added: ";
//         int numb;
//         cin>>numb;
//         addattail(tail, numb);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 3){
//         cout<<"Enter Num to be added: ";
//         int numb;
//         cin>>numb;
//         cout<<"Enter Spec postion to be added to: ";
//         int spec;
//         cin>>spec;
//         addatpos(head,numb,spec);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 4){
//         deletefromhead(head);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 5){
//         cout<<"Enter Spec postion to be deleted: ";
//         int spec;
//         cin>>spec;
//         deletefrompos(head,spec);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 6){
//         deletefromtail(tail);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 7){
//         cout<<"Enter Num to be searched: ";
//         int num;
//         cin>>num;
//         searchinLL(head,num);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 8){
//         cout<<"Enter Spec postion to be updated: ";
//         int spec;
//         cin>>spec;
//         cout<<"Enter data to be added: ";
//         int dis;
//         cin>>dis;
//         searchnupdateLL(head,spec,dis);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 9){
//         deletefromtail(tail);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     if(choice == 10){
//         display(head);
//         cout<<"*DONE*"<<endl;
//         cout<<endl;
//     }
//     }
}



