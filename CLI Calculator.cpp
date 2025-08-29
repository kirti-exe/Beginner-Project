#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
//----------Utility----------//
void saveHistory(const string& entry){
    ofstream fout("history.txt", ios::app);
    fout<<entry<<endl;
    fout.close();
}

//----------Simple Calculator----------//
void simpleCalc(){
    int choice;
    double a,b;
    cout<<"\n---Simple Calculator---\n";
    cout<<"1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n";
    cout<<"Choose: ";   cin>>choice;

    switch(choice){
        case 1: cout<<"Enter a b: ";    cin>>a>>b;
            cout<<"Result = "<<a+b<<endl;
            saveHistory(to_string(a)+"+"+to_string(b)+"="+to_string(a+b));
            break;

        case 2: cout<<"Enter a b: ";    cin>>a>>b;
            cout<<"Result = "<<a-b<<endl;
            saveHistory(to_string(a)+"-"+to_string(b)+"="+to_string(a-b));
            break;

        case 3: cout<<"Enter a b: ";    cin>>a>>b;
            cout<<"Result = "<<a*b<<endl;
            saveHistory(to_string(a)+"*"+to_string(b)+"="+to_string(a*b));
            break;

        case 4: cout<<"Enter a b: ";    cin>>a>>b;
            cout<<"Result = "<<a/b<<endl;
            saveHistory(to_string(a)+"/"+to_string(b)+"="+to_string(a/b));
            break;

        case 5:{
            int x, y;
            cout<<"Enter a  b (integers): ";    cin>>x>>y;
            if(y != 0){
                cout<<"Result = "<<x%y<<endl;
                saveHistory(to_string(x)+"%"+to_string(y)+"="+to_string(x%y));
            }
            else cout<<"Error: divide by Zero\n";
                break;
        }   
        default:    cout<<"Invalid Choice\n";
    }
}

//----------Scientific Calculator----------//
void scientificCalc(){
    int choice;
    double a, b;
    cout<<"\n---Scientific Calculator---\n";
    cout<<"1. Power\n2. Square Root\n3. Logarithm\n4. Sine\n5. Cosine\n6. Tangent\n";
    cout<<"Choose: ";   cin>>choice;

    switch(choice){
        case 1: cout<<"Enter base exp: ";   cin>>a>>b;
            cout<<pow(a,b)<<endl;
            break;

        case 2: cout<<"Enter a: ";  cin>>a;
            cout<<sqrt(a)<<endl;
            break;

        case 3: cout<<"Enter a: ";  cin>>a;
            cout<<log(a)<<endl;
            break;

        case 4: cout<<"Enter angle (rad): ";    cin>>a;
            cout<<sin(a)<<endl;
            break;

        case 5: cout<<"Enter angle (rad): ";    cin>>a;
            cout<<cos(a)<<endl;
            break;

        case 6: cout<<"Enter angle (rad): ";    cin>>a;
            cout<<tan(a)<<endl;
            break;

        default:    cout<<"Invalid Choice\n";
    }

}

//----------Programmer Calculator----------//
void programmerCalc(){
    int choice;
    int n;
    cout<<"\n---Programmer Calculator---\n";
    cout<<"1. Decimal to Binary\n2. Decimal to Hex\n3. Binary to Decimal\n4. Bitwise AND/OR/XOR\n";
    cout<<"Choose: ";   cin>>choice;

    switch(choice){
        case 1: cout<<"Enter number: "; cin>>n;
            cout<<bitset<16>(n)<<endl;
            break;

        case 2: cout<<"Enter number: "; cin>>n;
            cout<<hex<<n<<dec<<endl;
            break;

        case 3: {
            string bin;
            cout<<"Enter binary: "; cin>>bin;
            cout<<stoi(bin,0,2)<<endl;
        }break;

        case 4: {
            int a, b;
            cout<<"Enter a b: ";    cin>>a>>b;
            cout<<"AND="<<(a&b)<<" OR="<<(a|b)<<" XOR="<<(a^b)<<endl;
        }break;

        default: cout<<"Invalid choice\n";
    }
}

//----------Financial Calculator----------//


int main(){
    int choice;
    do{
        cout<<"\n---CLI Calculator---\n";
        cout<<"1. Simple Calculator\n2. Scientific\n3. Programmer\n4. Financial\n5. Exit\n";
        cout<<"Choose: ";   cin>>choice;

        switch(choice){
            case 1: simpleCalc();   break;
            case 5: cout<<"Exiting...\n";  break;
            default: cout<<"Invalid Option\n";
        }
    }while(choice != 5);
    return 0;
}
