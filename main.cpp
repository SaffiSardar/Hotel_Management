#include <iostream>
using namespace std;

int reservation_count = 0;

class Hotel{
    protected:
        int cnic, Phone_number ,outstanding_payment ;
        string First_name, Second_name, no_of_family_members, time_of_stay;
        Hotel*next;
        Hotel*prev;
    public:
        Hotel(int cnic,int Phone_number,string First_name,string Second_name,int no_of_family_members,int time_of_stay,int outstanding_payment){
            Hotel*next = NULL;
            Hotel*prev = NULL;
            this->cnic = cnic;
            this->Phone_number = Phone_number;
            this->First_name = First_name;
            this->Second_name = Second_name;
            this->no_of_family_members = no_of_family_members;
            this->time_of_stay = time_of_stay;
            this->outstanding_payment = outstanding_payment;
        }
        void addathead(Hotel*&head ,int cnic,int Phone_number,string First_name,string Second_name,int no_of_family_members,int time_of_stay,int outstanding_payment){
            if(reservation_count<=19){
                Hotel*temp = new Hotel(cnic,Phone_number,First_name,Second_name,no_of_family_members,time_of_stay,outstanding_payment);
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

        void display(Hotel*&head){
            Hotel*temp = head;
            while(temp!=NULL){
            cout<<temp->First_name<<endl;
            cout<<temp->outstanding_payment<<endl;
            cout<<endl;
            temp = temp->next;
        }
}

};


class Rooms: Hotel{
    protected:
        string room_type;
    void single_room(int time_of_stay){
        outstanding_payment = outstanding_payment + (20*time_of_stay);
        room_type = "Single Room";
    }
    void double_room(int time_of_stay){
        outstanding_payment = outstanding_payment + (40*time_of_stay);
        room_type = "Double Room";
    }
    void connecting_room(int time_of_stay){
        outstanding_payment = outstanding_payment + (100*time_of_stay);
        room_type = "Connecting Room";
    }
};

class Services: Hotel{
    protected:
    


};

int main()
{

}