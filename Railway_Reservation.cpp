#include <iostream>
#include <string>
using namespace std;
class passenger{
    public:
    string name;
    int age;
    char gender;
    int seatNo;
    passenger* next;
    passenger(string n, int a, char g, int s){
        name = n;
        age = a;
        gender = g;
        seatNo = s;
        next = NULL;
    }
};

class list{
public:
    passenger* head;
    int arr[50];
    list(){
        head = NULL;
        for(int i=0; i<50; i++){
            arr[i] = 0;
        }
    }

    void cases(){
        int choice;
        do{
            cout<< "\n\n\n-----------------MENU-----------------\n\n";
            cout<< "For Ticket Booking press : 1 \n";
            cout<< "For Cancel Ticket press : 2 \n";
            cout<< "For Show status : 3 \n";
            cout<< "For see Tiket Availibility : 4 \n";
            cout<< "For Exit press : 0 \n\n";
            cout<< "-----------------------------------------\n";
            cin>> choice;
        
            if(choice == 1){
                Book_Ticket();
            }
            else if(choice == 2){
                int seatno;
                cout<< "\nEnter Your Seat no. : \n";
                cin>> seatno;
                cancelTicket(seatno);
            }
            else if(choice == 3){
                cout<< "\nEnter your seatNo.: \n";
                int seatno;
                cin>> seatno;
                show_Status(seatno);
            }
            else if(choice == 4) available_Seat();
            
            else if(choice == 0) break;

        }while(choice!=0 );
        
    }

    void push_back(string name, int age, char gender, int seatNo){
        passenger* newPassenger = new passenger(name,age,gender,seatNo);
        if(head==NULL){
            head = newPassenger;
        }
        else{
            passenger* ptr = head;
            while(ptr-> next!= NULL){
                ptr = ptr-> next;
            }
            ptr-> next = newPassenger;
            newPassenger-> next = NULL;
        }
    }


    void Book_Ticket(){
        for (int i=0; i<50; i++){
            if(arr[i] == 0){
                string name;
                int age;
                char gender;
                int seatNo;
                cout<< "Enter your name: \n";
                cin>> name;
                cout << "Enter your age: \n";
                cin>>age;
                cout<< "Enter your Gender: \n";
                cin>> gender;
                seatNo = i;
                arr[i] = 1;
                push_back(name, age, gender,seatNo);
                return;
            }
        }
        cout<< "\n\nSeat is not left: \n ";
    }


    bool available_Seat(){
        for(int i=0; i<50; i++){
            if(arr[i] == 0){
                cout<< "\n\nSome tickets are left: \n";
                return true;
            }
        }
        return false;
    }


    void show_Status(int keySeat){
        if(arr[keySeat]==0){
            cout<<"\n\nNot Ticket book yet! \n\n";
            return;
        }
        else{
            passenger* ptr = head;
            while(ptr-> seatNo!= keySeat ){
                ptr = ptr-> next;
            }
                cout<<"\n\nName is : "<< ptr-> name<<endl;
                cout<<"Age is : "<< ptr-> age << endl;
                cout<<"Gender is : "<< ptr-> gender << endl;
                cout<<"Seat Number is : "<< ptr-> seatNo << endl;
                cout<<"\n\n";
        }
    }


    void cancelTicket(int keySeat){
        if(arr[keySeat]==0){
            cout<<"\nYou hadn't booked ticket yet\n\n";
            return;
        }
        else if(arr[keySeat] == 1){
            remove(keySeat);
            arr[keySeat]= 0;
            cout<< "\n\n Your ticket has canceled: \n\n";
        }
    }

    
    void remove(int keySeat){
        if (head ==NULL) return;
        else if(head-> seatNo == keySeat){
            passenger* ptr = head;
            head = head -> next;
            delete ptr;
            return;
        }
        else{
            passenger* curr = head;
            while(curr->seatNo != keySeat){
                curr = curr-> next;
            }
            if(curr==NULL) {
                cout<< "\n Galat seat no. \n";
                return;
            }
            passenger* ptr = curr;
            curr-> next = ptr-> next->next;
            delete ptr;
        }
    }

};


int main (){
    list ll;
    ll.cases();
    return 0;
}
