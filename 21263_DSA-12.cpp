#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class HashTable{
    public:
        int addr;
        HashTable();

} ;
HashTable HT[10];


HashTable::HashTable(){
    for(int i=0;i<10;i++){
        HT[i].addr=-1;
    }
}

class Employee : public HashTable{
    int emp_id;
    char salary[10];
    char name[10];
    char exp[10];

    public:
        void add_Rec(); //...Add Records

        void display_Rec(); //...Read Records

        void search_Rec(); //...Search A Record

        void delete_Rec(); //...Delete A Record

};

void Employee :: add_Rec()
{
    int index,count, tablesize = 10;
    int location;

    cout<<"\n\n How many records..? : ";
    cin>>count;

    ofstream fout;
    fout.open("FileDAF.txt", ios::out);

    for (int i = 0; i < count; i++)
    {
        cout << "\n Enter Employee id: ";
        cin >> emp_id;
        cout << "\n Enter Employee name: ";
        cin >> name;
        cout << "\n Enter Employee salary: ";
        cin >> salary;
        cout << "\n Enter Experience: ";
        cin >> exp;

        location = fout.tellp(); //...Return location

        index = emp_id % tablesize; //....Find index of Hashtable
        HT[index].addr = location; //...Store location in Hashtable
    
        //Write the Record in File
        fout<<emp_id<<" "<<name<<" "<<""<<exp<<" "<<salary<<endl;
    }
    fout.close();
}

void Employee :: display_Rec(){
    char buffer[40];
    int cnt = 1;
    ifstream fin;
    //.....Open File for Reading

    fin.open("FileDAF.txt", ios::in);
    //........Read till End of the File
    while(fin.getline(buffer,40))
    {
        
        cout<<"\n\n Record "<<cnt<<" : "<<buffer;
        cnt++;
    }
}

void Employee :: search_Rec()
{
    int id;
    int tablesize = 10;
    //.......Accept Emp_id to search
    cout<<"\n\t Enter Emp_id to search record: ";
    cin>>id;
    //......Find index to get the address of record
    int index = id % tablesize;
    //......read and store the address
    int location = HT[index].addr;
    //....Open the file for reading
    ifstream fin;
    fin.open("FileDAF.txt", ios::in);
    //.....go to the location
    fin.seekg(location, ios::beg);
    //.....Read from location
    char buffer[40];
    fin.getline(buffer, 40);
    cout<<"\n\t Found Record : "<<buffer;
}

void Employee ::delete_Rec()
{
    int i, id;
    int tablesize = 10;
    cout<<"\n\t Enter the Emp_id to delete: ";
    cin>>id;
    int index = id % tablesize;
    int location = HT[index].addr;
    //....Open the file for reading
    ifstream fin;

    fin.open("FileDAF.txt", ios::in);
    //.....go to the location
    fin.seekg(location, ios::beg);
    //.....Read from location
    char buffer[40];
    fin.getline(buffer, 40);
    cout<<"\n\t Deleted Record : "<<buffer;
    fin.close();
    
    cout<<"\n\t Remaining Records:- ";
    //....Open the file for reading
    fin.open("FileDAF.txt", ios::in);
    for(i=0; i<10; i++)
    {
    if(HT[i].addr != -1 && HT[i].addr != location)
    {
    //.....Read from location
    fin.seekg(HT[i].addr, ios::beg);
    fin.getline(buffer, 40);
    cout<<"\n\t Record : "<<buffer;
    }
    }
    fin.close();
}

int main()
{
    Employee E;
    int r;
    bool repeat=true;
    int choice;
    while(repeat){
        cout << endl;
        cout << " ***** MENU *****" << endl;
        cout << "1. Add Data" << endl;
        cout << "2. Display Data" << endl;
        cout << "3. Delete Data" << endl;
        cout << "4. Search Data" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){

              case 1:
                E.add_Rec();
                break;

            case 2:
                E.display_Rec();
                break;

            case 3:
                E.delete_Rec();
                break;

            case 4:
                E.search_Rec();
                break;

            case 5:
                cout << "Exiting the code" << endl;
                repeat = false;
                break;

            default:
                cout << "Invalid Choice" << endl;
                break;

        }

    }

    return 0;
}