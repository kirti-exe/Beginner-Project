#include<iostream>
#include<iomanip>
using namespace std;
void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){
    double balance = 0;
    int choice = 0;

    do{
        cout<<"-----Enter Your Choice-----"<<endl;
        cout<<"!. Show Balance"<<endl;
        cout<<"2. Deposit Money"<<endl;
        cout<<"3. Withdraw Money"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>choice;

        switch(choice){
            case 1: showBalance(balance);
                break;

            case 2: balance += deposit();
                showBalance(balance);
                break;

            case 3: balance -= withdraw(balance);
                showBalance(balance);
                break;

            case 4: cout<<"Thanks for visiting!"<<endl;
                break;

            default: cout<<"Invalid choice."<<endl;
        }
    }while(choice != 4);
    return 0;
}

void showBalance(double balance){
    cout<<"Your balance is $"<<setprecision(2)<<fixed<<balance<<endl;
}

double deposit(){
    double amount = 0;
    cout<<"Enter amount to be deposited: ";
    cin>>amount;
    if(amount < 0){
        cout<<"Your amount is invalid."<<endl;
        return 0;
    }else{
        return amount;
    }
}

double withdraw(double balance){
    double amount = 0;
    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    if(amount > balance){
        cout<<"Insufficient Balance!"<<endl;
        return 0;
    }else if(amount < 0){
        cout<<"Your amount is invalid."<<endl;
        return 0;
    }else{
        return amount;
    }
}
