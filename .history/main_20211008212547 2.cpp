#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

// -------------------------start of functions defination-------------------------------------
void getchoice(string,int);
int checkadmin();
void createuser();
void loginuser();
void deleteuser();
void changepass();

//---------------------------start of main function-------------------------------------------
int main()
{   
    strings username;
    int n,password,status=1;
    cout<<"---------------------------------------------------\n"
        <<"|      Hello and Welcome to Our System            |\n"
        <<"---------------------------------------------------\n"
        <<"|ENTER 1 TO LOGIN                                 |\n"
        <<"|ENTER 0 TO EXIT                                  |\n"
        <<"---------------------------------------------------\n";
    cin>>n;
    {
        if(n==1)
        {
             cout<<"-----------------------------------------------------------\n"
                 <<"Please enter the username-\n";
            cin>>username;
            cout<<"Please enter the password-\n";
            cin>>password;
            status=checkadmin(name,password);
            getchoice();
        }
        else
            if(n==0)
                exit();
            else
             {   
                cout<<"Wrong chocie Please Try again";
                main();         
             } 
    }
    return 0;
}


//----------------------This functions takes the input from the user and calls different functions---------------
void getchoice(string name,int s) 
{   
    if(s==1)
    {
        int ch;
        cout << "-----------------------------------------------------\n"
            << "       Hello admin "<<name<<"                         \n"
            << "-----------------------------------------------------\n"
            << "| Please Enter from the choice given below          |\n"
            << "| Enter 1 to Create a New User Account              |\n"
            << "| Enter 2 to Login using existing User Account      |\n"
            << "| Enter 3 to Logout from your User Account          |\n"
            << "| Enter 4 to Delete any User Account                |\n"
            << "| Enter 5 To Change your Password                   |\n"
            << "| Enter O To Exit                                   |\n"
            << "-----------------------------------------------------\n";

        cin >> ch;
        switch(ch)
        {
            case(1) : createuser();
                        break;
            case(2) : loginuser();
                        break;
            case(3) :
                        break;
            case(4) :  deleteuser();
                        break;
            case(5) :  changepass();
                        break;
            case(0) :  exit();
            // default:
        }
    }
    else
    {   
        int ch;
        cout << "-----------------------------------------------------\n"
            << "        Hello user "<<name<<"                         \n"
            << "-----------------------------------------------------\n"
            << "| Please Enter from the choice given below          |\n"
            << "| Enter 1 to Login using existing User Account      |\n"
            << "| Enter 2 to Logout from your User Account          |\n"
            << "| Enter 3 To Change your Password                   |\n"
            << "| Enter O To Exit                                   |\n"
            << "-----------------------------------------------------\n";

        cin >> ch;
        switch(ch)
        {
            case(1) : loginuser();
                        break;
            case(2) :
                        break;
            case(3) : changepass();
                        break;
            case(0) :  exit();
            // default:
        }
    }
}

//---------------------------This functions checks if the user is admin or not-----------------------
 int checkadmin(string name,string pass)
 {      
    ifstream file;
    file.open("Users.dat");
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;
     while (file>>get<0>(userdata)){
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        users.push_back(userdata);
    }

     for (auto elem: users)
    {   
        if(get<0>(elem)==name && get<2>(elem)==pass && get<1>(elem)==1)
        return 1;
    else 
        return 0;
    }
    file.close();
 }
//----------------------------This functions creates the new user---------------------------------
void createuser() 
{
    ifstream file;
    file.open("Users.dat");
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;
     while (file>>get<0>(userdata)){
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        users.push_back(userdata);
    }

     for (auto elem: users)
    {   
        string user,pass;
        int status,power;
        if (!file.is_open())
        {
            cout << " File not found\n";
            exit(-1);
        }
        else
        {   int pos;
            cout << "-----------------------------------------------------\n"
                <<"Enter a unique user name -\n";
            cin >> user;
            cout << "-----------------------------------------------------\n"
                <<"Enter your password -\n";
            cin >> pass;
            ofstream outfile;
            outfile.open("Users.dat",ios::out|ios::ate|ios::app);
            status=1;
            power=0;
            outfile << user << " " << power << " " << pass << " " << status<<endl;
            outfile.close();
            file.close();
            cout<<"Username and password created successfully."<<endl;
            break;
        }
        }
    }

//----------------------------This functions login user in the system---------------------------------
void loginuser() 
{
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;
    ifstream file;
    file.open("Users.dat");
    while (file>>get<0>(userdata))
    {
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        users.push_back(userdata);
    }

    file.close();

    string name, pass;
    cout << "-----------------------------------------------------\n"
        << "Enter Username-\n";
    cin >> name;
    cout << "-----------------------------------------------------\n"
        << "Enter Password-\n ";
    cin >> pass;

    for (auto elem: users)
    {
         if (name == get<0>(elem) &&
             pass == get<2>(elem) &&
             get<3>(elem)==1)
        {
            cout << get<0>(elem) << ": "
                 << ((get<1>(elem)==1)?"admin":"user")
                 << ": " <<get<2>(elem) << ": "
                 << ((get<3>(elem)==1)?"Active":"Deleted")
                 << endl;
            if(get<1>(elem)==1)
            {
                cout<<"Welcome admin- "<<get<0>(elem)<<endl;
                datafilereader();
            }
            else{
                cout<<"Id- "<<get<0>(elem)<< " is not an admin "<<endl;
            }
                 break;
        }
        else{
            cout << "-----------------------------------------------------\n"
                <<"Wrong username or password\n"
                <<"Please try again\n";
                loginuser();
        }
}
}
//----------------------------This functions the user from the system---------------------------------
// void logout()
// {

// }
//----------------------------This functions changes the password---------------------------------
void changepass() 
{
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;
    ifstream file;
    file.open("users.dat");
        while (file>>get<0>(userdata))
    {
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        users.push_back(userdata);
    }
        string newpass1,newpass2,oldpass,user;           
        cout <<"Enter username" <<endl;
        cin >> user;
        cout << "Enter your old password to continue..." << endl;
        cin >> oldpass;       
        for (auto elem: users)
    {
        if (oldpass == get<2>(elem) && user == get<0>(elem))
       {    
            cout << "Please enter the new password"
                    << endl;
            cin >> newpass1;
            cout << "Please re-enter your new password"
                    << endl;
            cin >> newpass2;
            if(newpass1==newpass2)
            {
                get<2>(elem)=newpass1;
                break;
           }
           else
           {  
               cout <<"You entered incorrect password"<< endl;
           }
       }
        else
        {
            cout << "--------------------------------------------------------" << endl;
            cout <<"Either the username or the password you entered is incorrect," 
                << "please try again"<< endl;
                changepass();
        }
        cout << "Password changed you may procced to login"<< endl;;
            ofstream outfile;
            outfile.open("users.dat" , ios::out);
            while(!eof("users.dat"))
            {
                outfile<<get<0>(userdata)<<" "
                        <<get<1>(userdata)<<" "
                        <<get<2>(userdata)<<" "
                        <<get<3>(userdata)<<" "
                        << endl;
                users.push_back(userdata);
            }
            outfile.close();
       file.close();
    }
}
//----------------------------This functions deletes the new user ---------------------------------
void deleteuser() 
{
    vector<tuple<string,int,string,int>> users;
    tuple<string,int,string,int> userdata;

    ifstream file;
    file.open("Users.dat");
    while (file>>get<0>(userdata))
    {
        file >>get<1>(userdata);
        file >>get<2>(userdata);
        file >>get<3>(userdata);
        users.push_back(userdata);
    }
    file.close();
  
     for (auto elem: users)
    {   
        if (checkadmin(get<0>(elem),get<2>(elem),get<1>(elem))==true)
             {  string name, pass;
                cout << "-----------------------------------------------------\n"
                    << "Enter the Username to delete-\n";
                cin >> name;
                cout << "-----------------------------------------------------\n"
                    << "Enter Password to confirm deletion-\n";
                cin >> pass;
                cout << get<0>(elem) << ": "
                 << ((get<1>(elem)==1)?"admin":"user")
                 << ": " <<get<2>(elem) << ": "
                 << ((get<3>(elem)==1)?"Deleted":"Active")
                 << endl;
                
                get<3>(elem)=0;
               
                cout << "---------------------------------------------------\n"
                    <<"Account deletion was successful." << endl;
                    break;
             }
        else {
              cout << "-----------------------------------------------------\n"
                <<"Wrong username or password\n"
                <<"Please try again\n";
                deleteuser();
        }
    }
    ofstream outfile;
    outfile.open("Users.dat",ios::out);
    while(!eof("users.dat"))
   { 
       outfile << get<0>(userdata) << " " 
            << get<1>(userdata) << " " 
            << get<2>(userdata) << " " 
            << get<3>(userdata) <<endl;
        users.push_back(userdata);
    }
    outfile.close();
    
}