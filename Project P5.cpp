#include<iostream>
#include<fstream>
#include <ctime>
#include<string.h>
#include <unistd.h>
#include <Windows.h>
using namespace std;
int p=0, constant=4;


struct Student{
    char student_name[100];
    char father_name[100];
    char university_name[100];
    char department[100];
    int semester;
    int roll_num;
    char batch[100];
    int fee;

    public:
        void fee_deposite(int x);
        void fees_receipt(int y);
}s[30];
struct bills{
	string Customer_Name;
	string Account_Number;
	string Due_Date;
	int After_Due_Date;
	int Payable_Amount;
	string Billing_Month;
	int With_in_Due_Date;

}bill[14];
struct Account{
	string Acc_type;
	string Cust_Name;
	string Cust_Name2;
	string Acc_Title;
	long long Cus_CNIC;
	long long Cus_CNIC2;
	string DoB;
	string DoB2;
	string Cus_Adrs;
	string Cus_Contact;
	string Cus_Contact2;
	string Cus_Email;
	string Bank_Name;
	int Branch_Code;
	string Branch_Name;
	string Acc_Number;
	string Acc_Operated_by;
	int balance;
	string IBAN_Number;
	int pin;
}bus_acc[100], cur_acc[100], asan_acc[100];


void login();
void main_menu();
void new_customer();
void accounts();
void cash_transaction();
void cash_deposit();
void cash_withdraw();
void online_transaction();
void debit_card();
int pin_checker();
void dc_cash_withdraw();
void fund_transfer();
void online_deposit();
void online_withdraw();
void billing_info();
void utility_bill();
void fee_collection();
void account_search();
void account_statement();
void edit();


int asan_tax(int x);
int debit_tax(int x);
int online_withdraw_tax(int x);
int online_deposit_tax(int x);

void time(){
time_t ttime = time(0);

char* dt = ctime(&ttime);
cout << dt;
}

void line()
{
	int j;
	for(j=1;j<=100;j++)
	cout << "*";
}
///accounts data
void accounts()
{
    //Business Accounts
	bus_acc[0].Acc_Title = "Emperor Transport Company";
	bus_acc[0].Acc_type = "Business Account";
	bus_acc[0].Acc_Number = "1102226712";
	bus_acc[0].balance = 5064000;
	bus_acc[0].Bank_Name = "EMPEROR BANK";
	bus_acc[0].Acc_Operated_by = "Single";
	bus_acc[0].Branch_Code = 1212;
	bus_acc[0].IBAN_Number = "PK10EMPR0012121102226712";
	bus_acc[0].Branch_Name = "Cilifton BR-KHI";
	bus_acc[0].Cust_Name = "Ahsan Ali";
	bus_acc[0].Cus_CNIC = 4230188812125;
	bus_acc[0].DoB = "03/12/1995";
	bus_acc[0].Cus_Contact = "0347-1234567";
	bus_acc[0].Cus_Contact2 = "0313-1234567";
	bus_acc[0].Cus_Email = "ahsan@etc.com";
	bus_acc[0].Cus_Adrs = "Ramzan Tower Block A Jinnahabad # 1 Karachi";
	bus_acc[0].pin = 1203;

	bus_acc[1].Acc_Title = "Khan Traders";
	bus_acc[1].Acc_type = "Business Account";
	bus_acc[1].Acc_Number = "1102127861";
	bus_acc[1].balance = 3500000;
	bus_acc[1].Bank_Name = "EMPEROR BANK";
	bus_acc[1].Acc_Operated_by = "Single";
	bus_acc[1].Branch_Code = 1212;
	bus_acc[1].IBAN_Number = "PK11EMPR0012121102127861";
	bus_acc[1].Branch_Name = "Cilifton BR-KHI";
	bus_acc[1].Cust_Name = "Haseeb Khan";
	bus_acc[1].Cus_CNIC = 4240134357687;
	bus_acc[1].DoB = "04/04/1992";
	bus_acc[1].Cus_Contact = "0344-0137843";
	bus_acc[1].Cus_Email = "haseeb888@gmail.com";
	bus_acc[1].Cus_Adrs = "Emporium Tower Block D North Nazimabad Karachi";
	bus_acc[1].pin = 7722;

	bus_acc[2].Acc_Title = "A & M Electronics";
	bus_acc[2].Acc_type = "Business Account";
	bus_acc[2].Acc_Number = "1101265321";
	bus_acc[2].balance = 4854300;
	bus_acc[2].Bank_Name = "EMPEROR BANK";
	bus_acc[2].Acc_Operated_by = "Joint";
	bus_acc[2].Branch_Code = 1722;
	bus_acc[2].IBAN_Number = "PK12EMPR0017221101265321";
	bus_acc[2].Branch_Name = "Hala Naka BR-HYD";
	bus_acc[2].Cust_Name = "Ahsan Ali";
	bus_acc[2].Cust_Name2 = "Mohsin Ali";
	bus_acc[2].Cus_CNIC = 4230188812126;
	bus_acc[2].Cus_CNIC2 = 4230176834637;
	bus_acc[2].DoB = "03/12/1995";
	bus_acc[2].DoB2 = "28/09/1997";
	bus_acc[2].Cus_Contact = "0347-1234567";
	bus_acc[2].Cus_Contact2 = "0313-1234567";
	bus_acc[2].Cus_Email = "ame@gmail.com";
	bus_acc[2].Cus_Adrs = "House no A-521 Sahafi Colony Hyderabad";
	bus_acc[2].pin = 1209;

	bus_acc[3].Acc_Title = "Danish Motors";
	bus_acc[3].Acc_type = "Business Account";
	bus_acc[3].Acc_Number = "1105630912";
	bus_acc[3].balance = 1020800;
	bus_acc[3].Bank_Name = "EMPEROR BANK";
	bus_acc[3].Acc_Operated_by = "Single";
	bus_acc[3].Branch_Code = 1011;
	bus_acc[3].IBAN_Number = "PK13EMPR0010111105630912";
	bus_acc[3].Branch_Name = "Saddar BR-KHI";
	bus_acc[3].Cust_Name = "Muhammad Danish";
	bus_acc[3].Cus_CNIC = 1730154365325;
	bus_acc[3].DoB = "18/06/1985";
	bus_acc[3].Cus_Contact = "0305-2292251";
	bus_acc[3].Cus_Contact2 = "0319-9876543";
	bus_acc[3].Cus_Email = "danish@dmotors.com";
	bus_acc[3].Cus_Adrs = "House no M-95 DHA Phase 6 Karachi";
	bus_acc[3].pin = 3333;

	bus_acc[4].Acc_Title = "King Cargo Service";
	bus_acc[4].Acc_type = "Business Account";
	bus_acc[4].Acc_Number = "1105832814";
	bus_acc[4].balance = 6545801;
	bus_acc[4].Bank_Name = "EMPEROR BANK";
	bus_acc[4].Acc_Operated_by = "Single";
	bus_acc[4].Branch_Code = 9812;
	bus_acc[4].IBAN_Number = "PK14EMPR0098121105832814";
	bus_acc[4].Branch_Name = "Khyber Rd BR-PSW";
	bus_acc[4].Cust_Name = "Hamza Mehmood";
	bus_acc[4].Cus_CNIC = 4150132376329;
	bus_acc[4].DoB = "17/11/1996";
	bus_acc[4].Cus_Contact = "0334-5657794";
	bus_acc[4].Cus_Contact2 = "0309-1215569";
	bus_acc[4].Cus_Email = "hamza@kcs.com";
	bus_acc[4].Cus_Adrs = "House no 901 Chaman Road Peshawar";
	bus_acc[4].pin = 1117;


	//Asaan Accounts
	asan_acc[0].Acc_Title = "Rajab Ali";
	asan_acc[0].Acc_type = "Asaan Account";
	asan_acc[0].Acc_Number = "1107671112";
	asan_acc[0].balance = 54050;
	asan_acc[0].Bank_Name = "EMPEROR BANK";
	asan_acc[0].Acc_Operated_by = "Single";
	asan_acc[0].Branch_Code = 1212;
	asan_acc[0].IBAN_Number = "PK20EMPR0012121107671112";
	asan_acc[0].Branch_Name = "Cilifton BR-KHI";
	asan_acc[0].Cust_Name = "Rajab Ali";
	asan_acc[0].Cus_CNIC = 4230143412321;
	asan_acc[0].DoB = "15/11/1994";
	asan_acc[0].Cus_Contact = "0390-1532091";
	asan_acc[0].Cus_Contact2 = "0340-2131231";
	asan_acc[0].Cus_Email = "rajabali@gmail.com";
	asan_acc[0].Cus_Adrs = "Ramzan City Flat B-16 Karachi";
	asan_acc[0].pin = 1511;

	asan_acc[1].Acc_Title = "Raja Kamran";
	asan_acc[1].Acc_type = "Asaan Account";
	asan_acc[1].Acc_Number = "1109107832";
	asan_acc[1].balance = 320500;
	asan_acc[1].Bank_Name = "EMPEROR BANK";
	asan_acc[1].Acc_Operated_by = "Single";
	asan_acc[1].Branch_Code = 1074;
	asan_acc[1].IBAN_Number = "PK21EMPR0010741109107832";
	asan_acc[1].Branch_Name = "Keamari BR-KHI";
	asan_acc[1].Cust_Name = "Raja Kamran";
	asan_acc[1].Cus_CNIC = 4250165389765;
	asan_acc[1].DoB = "26/01/1991";
	asan_acc[1].Cus_Contact = "0305-19909832";
	asan_acc[1].Cus_Email = "rajakamran@gmail.com";
	asan_acc[1].Cus_Adrs = "Shumail Building Flat no F-29 Karachi";
	asan_acc[1].pin = 2601;

	asan_acc[2].Acc_Title = "Saqib Shah";
	asan_acc[2].Acc_type = "Asaan Account";
	asan_acc[2].Acc_Number = "1100100915";
	asan_acc[2].balance = 480000;
	asan_acc[2].Bank_Name = "EMPEROR BANK";
	asan_acc[2].Acc_Operated_by = "Single";
	asan_acc[2].Branch_Code = 1221;
	asan_acc[2].IBAN_Number = "PK22EMPR0012211100100915";
	asan_acc[2].Branch_Name = "Nazimabad BR-KHI";
	asan_acc[2].Cust_Name = "Saqib Shah";
	asan_acc[2].Cus_CNIC = 1710160138201;
	asan_acc[2].DoB = "23/12/1997";
	asan_acc[2].Cus_Contact = "0349-5310911";
	asan_acc[2].Cus_Email = "saqib@gmail.com";
	asan_acc[2].Cus_Adrs = "House no 45 Blue Sky City Karachi";
	asan_acc[2].pin = 2312;

	asan_acc[3].Acc_Title = "Saad Yousuf";
	asan_acc[3].Acc_type = "Asaan Account";
	asan_acc[3].Acc_Number = "1102100401";
	asan_acc[3].balance = 500000;
	asan_acc[3].Bank_Name = "EMPEROR BANK";
	asan_acc[3].Acc_Operated_by = "Single";
	asan_acc[3].Branch_Code = 2122;
	asan_acc[3].IBAN_Number = "PK23EMPR0021221102100401";
	asan_acc[3].Branch_Name = "Lee Market BR-KHI";
	asan_acc[3].Cust_Name = "Saad Yousuf";
	asan_acc[3].Cus_CNIC = 4290178420181;
	asan_acc[3].DoB = "21/06/1981";
	asan_acc[3].Cus_Contact = "0389-541305";
	asan_acc[3].Cus_Email = "saad@gmail.com";
	asan_acc[3].Cus_Adrs = "Shahnawaz Garden Flat B-16 Karachi";
	asan_acc[3].pin = 2106;

	asan_acc[4].Acc_Title = "Hameed Gul";
	asan_acc[4].Acc_type = "Asaan Account";
	asan_acc[4].Acc_Number = "1108751000";
	asan_acc[4].balance = 375600;
	asan_acc[4].Bank_Name = "EMPEROR BANK";
	asan_acc[4].Acc_Operated_by = "Single";
	asan_acc[4].Branch_Code = 1212;
	asan_acc[4].IBAN_Number = "PK24EMPR0012121108751000";
	asan_acc[4].Branch_Name = "Cilifton BR-KHI";
	asan_acc[4].Cust_Name = "Hameed Gul";
	asan_acc[4].Cus_CNIC = 4210191277783;
	asan_acc[4].DoB = "01/02/1989";
	asan_acc[4].Cus_Contact = "0395-2322128";
	asan_acc[4].Cus_Email = "hameed@gmail.com";
	asan_acc[4].Cus_Adrs = "Khan Manzil Khyber Road Peshawar";
	asan_acc[4].pin = 4444;

	//Current Accounts
	cur_acc[0].Acc_Title = "Muhammad Usman";
	cur_acc[0].Acc_type = "Current Account";
	cur_acc[0].Acc_Number = "1102348761";
	cur_acc[0].balance = 123987;
	cur_acc[0].Bank_Name = "MEZAAN BANK";
	cur_acc[0].Acc_Operated_by = "Single";
	cur_acc[0].Branch_Code = 9201;
	cur_acc[0].IBAN_Number = "PK15EMPR0092011102348761";
	cur_acc[0].Branch_Name = "Canal Rd BR-LHR";
	cur_acc[0].Cust_Name = "Muhammad Usman";
	cur_acc[0].Cus_CNIC = 4410111143281;
	cur_acc[0].DoB = "29/10/1989";
	cur_acc[0].Cus_Contact = "0319-2221111";
	cur_acc[0].Cus_Contact2 = "0339-9090901";
	cur_acc[0].Cus_Email = "musman@gmail.com";
	cur_acc[0].Cus_Adrs = "House no B-16 St no 1 Cilifton Karachi";
	cur_acc[0].pin = 1029;

	cur_acc[1].Acc_Title = "Muhammad Danial";
	cur_acc[1].Acc_type = "Current Account";
	cur_acc[1].Acc_Number = "1107663318";
	cur_acc[1].balance = 890123;
	cur_acc[1].Bank_Name = "MEZAAN BANK";
	cur_acc[1].Acc_Operated_by = "Single";
	cur_acc[1].Branch_Code = 1213;
	cur_acc[1].IBAN_Number = "PK16EMPR0012131107663318";
	cur_acc[1].Branch_Name = "II Chandrigar Rd BR-KHI";
	cur_acc[1].Cust_Name = "Muhammad Danial";
	cur_acc[1].Cus_CNIC = 4210109059381;
	cur_acc[1].DoB = "23/08/1991";
	cur_acc[1].Cus_Contact = "0301-5673910";
	cur_acc[1].Cus_Email = "mdk@gmail.com";
	cur_acc[1].Cus_Adrs = "Emaar Tower Flat D-30 DHA Phase 6 Karachi";
	cur_acc[1].pin = 5723;

	cur_acc[2].Acc_Title = "Sidra Sajid";
	cur_acc[2].Acc_type = "MEZAAN Account";
	cur_acc[2].Acc_Number = "1101167231";
	cur_acc[2].balance = 756400;
	cur_acc[2].Bank_Name = "EMPEROR BANK";
	cur_acc[2].Acc_Operated_by = "Single";
	cur_acc[2].Branch_Code = 1219;
	cur_acc[2].IBAN_Number = "PK17EMPR0012191101167231";
	cur_acc[2].Branch_Name = "Korangi BR-KHI";
	cur_acc[2].Cust_Name = "Sidra Sajid";
	cur_acc[2].Cus_CNIC = 4560187823686;
	cur_acc[2].DoB = "12/07/1999";
	cur_acc[2].Cus_Contact = "0332-332901";
	cur_acc[2].Cus_Email = "sidra@gmail.com";
	cur_acc[2].Cus_Adrs = "House no A-90 Korangi Karachi";
	cur_acc[2].pin = 1207;

	cur_acc[3].Acc_Title = "Muhammad Umair";
	cur_acc[3].Acc_type = "Current Account";
	cur_acc[3].Acc_Number = "1102101455";
	cur_acc[3].balance = 650000;
	cur_acc[3].Bank_Name = "MEZAAN BANK";
	cur_acc[3].Acc_Operated_by = "Single";
	cur_acc[3].Branch_Code = 1212;
	cur_acc[3].IBAN_Number = "PK18EMPR0012121102101455";
	cur_acc[3].Branch_Name = "Saddar BR-KHI";
	cur_acc[3].Cust_Name = "Muhammad Umair";
	cur_acc[3].Cus_CNIC = 4420132888731;
	cur_acc[3].DoB = "09/07/1997";
	cur_acc[3].Cus_Contact = "0390-7632195";
	cur_acc[3].Cus_Email = "mumair@gmail.com";
	cur_acc[3].Cus_Adrs = "Bahria Icon Flat A-90 Karachi";
	cur_acc[3].pin = 4647;

	cur_acc[4].Acc_Title = "Shahjahan Ali";
	cur_acc[4].Acc_type = "Current Account";
	cur_acc[4].Acc_Number = "1104590231";
	cur_acc[4].balance = 756030;
	cur_acc[4].Bank_Name = "MEZAAN BANK";
	cur_acc[4].Acc_Operated_by = "Single";
	cur_acc[4].Branch_Code = 1011;
	cur_acc[4].IBAN_Number = "PK19EMPR0010111104590231";
	cur_acc[4].Branch_Name = "Saddar BR-KHI";
	cur_acc[4].Cust_Name = "Shahjahan Ali";
	cur_acc[4].Cus_CNIC = 4230130959437;
	cur_acc[4].DoB = "21/03/1998";
	cur_acc[4].Cus_Contact = "0349-1003217";
	cur_acc[4].Cus_Email = "shahjahan@gmail.com";
	cur_acc[4].Cus_Adrs = "Belle View Flat G-901 Karachi";
	cur_acc[4].pin = 4321;

}

///Main Function
int main()
{
    int choice, choice_1;
    cout<<"Options:\n";
    cout<<"1.ATM"<<endl;
    cout<<"2.Admin"<<endl;
    cout<<"Chosen option: ";
    cin>>choice;
    if(choice==1)
    {
        system("cls");
        debit_card();
    }
    else if(choice==2)
    {
        login();
        main_menu();
    }

}
///Debit Card
void debit_card()
{
    int option,option_1;
    int amount, cash;
    char confirm_msg1;
    cash=pin_checker();
menu:
    cout<<"\n\nOptions: \n";
    cout<<"1.Fast Cash"<<endl;
    cout<<"2.Cash Withdraw"<<endl;
    cout<<"3.Balance Inquiry"<<endl;
    cout<<endl<<"Chosen Option: ";
    cin>>option;
    if(option==1)
    {
        system("cls");
        cout<<"\n\nOptions: \n";
        cout<<"1. PKR 500\t";
        cout<<"2. PKR 1,000"<<endl;
        cout<<"3. PKR 3,000\t";
        cout<<"4. PKR 5,000"<<endl;
        cout<<"5. PKR 10,000\t";
        cout<<"6. Main Menu"<<endl;
        cout<<endl<<"Chosen Option: ";
        cin>>option_1;
        if(option_1==1)
        {
            if(cash>500)
            {
                cout<<"\nDo you want receipt?(Y/N):\n";
                cin>>confirm_msg1;
                if(confirm_msg1=='Y' || confirm_msg1=='y')
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    sleep(2);
                    cout<<endl<<"Please Collect Your Receipt!";
                    sleep(2);
                    cout<<"\nCurrent Balance: Rs"<<cash-540<<"\nCash withdraw: PKR 500";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    main_menu();
                }
                else
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
            }
            else
            {
                cout<<"\nInsufficient Balance!";
                getchar();
                exit(0);
            }
        }
        else if(option_1==2)
        {
            if(cash>1000)
            {
                cout<<"\nDo you want receipt?(Y/N):\n";
                cin>>confirm_msg1;
                if(confirm_msg1=='Y' || confirm_msg1=='y')
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    sleep(2);
                    cout<<endl<<"Please Collect Your Receipt!";
                    sleep(2);
                    cout<<"\nCurrent Balance: Rs"<<cash-1070<<"\nCash withdraw: PKR 1000";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
                else
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
            }
            else
            {
                cout<<"\nInsufficient Balance!";
                exit(0);
            }
        }
        else if(option_1==3)
        {
            if(cash>3000)
            {
                cout<<"\nDo you want receipt?(Y/N):\n";
                cin>>confirm_msg1;
                if(confirm_msg1=='Y' || confirm_msg1=='y')
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    sleep(2);
                    cout<<endl<<"Please Collect Your Receipt!";
                    sleep(2);
                    cout<<"\nCurrent Balance: Rs"<<cash-3100<<"\nCash withdraw: PKR 3000";
                    cout<<endl<<"Thank You So Much!";
                    sleep(3);
                    exit(0);
                }
                else
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
            }
            else
            {
                cout<<"\nInsufficient Balance!";
                getchar();
                exit(0);
            }
        }
        else if(option_1==4)
        {
            if(cash>5000)
            {
                cout<<"\nDo you want receipt?(Y/N):\n";
                cin>>confirm_msg1;
                if(confirm_msg1=='Y' || confirm_msg1=='y')
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    sleep(2);
                    cout<<endl<<"Please Collect Your Receipt!";
                    sleep(2);
                    cout<<"\nCurrent Balance: Rs"<<cash-5130<<"\nCash withdraw: PKR 5000";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
                else
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
            }
            else
            {
                cout<<"\nInsufficient Balance!";
                getchar();
                exit(0);
            }
        }
        else if(option_1==5)
        {
            if(cash>10000)
            {
                cout<<"\nDo you want receipt?(Y/N):\n";
                cin>>confirm_msg1;
                if(confirm_msg1=='Y' || confirm_msg1=='y')
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    sleep(2);
                    cout<<endl<<"Please Collect Your Receipt!";
                    sleep(2);
                    cout<<"\nCurrent Balance: Rs"<<cash-10160<<"\nCash withdraw: PKR 10000";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
                else
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
            }
            else
            {
                cout<<"\nInsufficient Balance!";
                exit(0);
            }
        }
        else if(option_1==6)
        {
            goto menu;
        }
        else
        {
            exit(0);
        }
    }
    else if(option==2)
    {
        cout<<endl<<"Enter The Amount: ";
        cin>>amount;
        amount=debit_tax(amount);
        if(amount<cash)
        {
                    cout<<endl<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                cout<<"\nDo you want receipt?(Y/N):\n";
                cin>>confirm_msg1;
                if(confirm_msg1=='Y' || confirm_msg1=='y')
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    sleep(2);
                    cout<<endl<<"Please Collect Your Receipt!";
                    sleep(2);
                    cout<<"\nCurrent Balance: Rs"<<cash-amount<<"\nCash withdraw: "<<amount;
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    exit(0);
                }
                else
                {
                    cout<<"Please Wait";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<".";
                    sleep(1);
                    cout<<"."<<endl;
                    cout<<"Please Collect Your Cash!";
                    cout<<endl<<"Thank You So Much!";
                    getchar();
                    main_menu();
                }
            }
            else
            {
                cout<<"\nInsufficient Balance!";
                exit(0);
            }

    }
    else if(option==3)
    {
        cout<<"Your Balance is "<<cash<<".";
        getchar();
        goto menu;
    }

}
//Pin Checker
int pin_checker()
{
    accounts();
    int balance, pin, loginAttempt = 1;
    cout<<endl<<endl<<"***Debit Card***\n";
menu:
    cout<<"\t\t\t\tPIN: ";
    cin>>pin;
    for(int i=0;i<5;i++)
        {
                if(pin == bus_acc[i].pin)
                {
                    sleep(2);
                    balance = bus_acc[i].balance;
                    return balance;
                    break;
                }
                else if(pin==cur_acc[i].pin)
                {
                    sleep(2);
                    balance = cur_acc[i].balance;
                    return balance;
                    break;
                }
                else if(pin==asan_acc[i].pin)
                {
                    sleep(2);
                    balance = asan_acc[i].balance;
                    return balance;
                    break;
                }

        }
        if(loginAttempt<3)
        {
                    loginAttempt=loginAttempt+1;
                    goto menu;
        }

    if (loginAttempt == 3)
    {
            cout <<endl<<"Too many attempts! The program now terminate.";
            cout<<endl<<"Contact Your System Administration or Concern Department. \n\n";
            exit(0);
    }
}
///login
void login()
{
    int loginAttempt = 0;
    string nic,paswrd,user_name,dcn;
    while(loginAttempt < 3)
	{
	cout<<endl<<"\t\t\t\t\t***Sign in***";
	cout<<endl<<endl;
	cout<<endl<<"\t\t\t\tUsername: ";
	cin>>user_name;
	cout<<endl<<"\t\t\t\tPassword: ";
	cin>>paswrd;

	if(user_name == "admin" && paswrd == "1234")
	{
		cout<<endl<<endl<<"\t\t\t\t  Sign in Successful";
		system("cls");
		break;
        }
	else
        {
            cout <<endl<< "Wrong User_Name or Password. Please try again"<<endl<<endl;
            loginAttempt++;
        }
    }

    if (loginAttempt == 3)
    {
            cout <<endl<<"Too many Sign in attempts! The program now terminate.";
            cout<<endl<<"Contact Your System Administration or Concern Department. \n\n";
            exit(0);
    }
}
///main menu
void main_menu()
{
    cout<<endl<<endl<<endl;
    line();
    cout <<endl;
    cout <<"\t\t\t\t *****WELCOME TO EMPEROR BANK***** ";
    cout<<endl;
    line();
    int n;
    cout<<"\n\n\tSelect from the menu: "<<endl;
    cout<<"\t1.New Customer\n";
    cout<<"\t2.Cash Transaction\n";
    cout<<"\t3.Online Cash Transfer\n";
    cout<<"\t4.Utility Bill\n";
    cout<<"\t5.Fee Collection\n";
    cout<<"\t6.Edit Account\n";
    cout<<"\t7.Account Search From CNIC\n";
    cout<<"\t8.Account Statement\n";
    cout<<"\t9.EXIT\n\tPlease Enter Your Option"<<endl;
    cin>>n;
    if(n==1)
    {
        new_customer(); //100%
    }
    else if(n==2)
    {
        cash_transaction(); //100%
    }
    else if(n==3)
    {
        fund_transfer(); //100%
    }
    else if(n==4)
    {
        billing_info(); //100%
        utility_bill(); //100%
    }
    else if(n==5)
    {
        fee_collection(); //100%
    }
    else if(n==6)
    {
        edit(); //100%
    }
    else if(n==7)
    {
        account_search(); //100%
    }
    else if(n==8)
    {
        account_statement(); //100%
    }
    else if(n==9)
    {
        exit(0);;
    }
}

void new_customer()
{
    accounts();
    int choice;
new_cos:
    constant=constant+1;
    cout<<"\n\n\tSelect the Type of account:"<<endl;
    cout<<"\tEmperor Bank Accounts:"<<endl;
    cout<<"\t1. Asaan Account"<<endl;
    cout<<"\t2. Business Account"<<endl;
    cout<<"\tMezaan Bank Accounts:"<<endl;
    cout<<"\t3. Current Account"<<endl;
    cout<<"\t4. Back to Main Menu"<<endl;
    cout<<endl<<"\tSelect Your Choice: ";
    cin>>choice;
    if(choice==1)
    {
        cout<<endl<<"Enter Account Title:\t";
        cin>>asan_acc[constant].Acc_Title;   ///Account number...
        cout<<endl<<"Enter Customer Name:\t";
        cin>>asan_acc[constant].Cust_Name;
        cout<<endl<<"Enter Customer CNIC(xxxxxxxxxxxxx):\t";
        cin>>asan_acc[constant].Cus_CNIC;
        cout<<endl<<"Enter Customer Date Of Birth[dd/mm/yyyy]:\t";
        cin>>asan_acc[constant].DoB;
        cout<<endl<<"Enter Customer Contact:\t";
        cin>>asan_acc[constant].Cus_Contact;
        cout<<endl<<"Enter Customer Contact 2:\t";
        cin>>asan_acc[constant].Cus_Contact2;
        cout<<endl<<"Enter Customer Email Address:\t";
        cin>>asan_acc[constant].Cus_Email;
        cout<<endl<<"Enter Customer Address:\t";
        cin>>asan_acc[constant].Cus_Adrs;
        cout<<endl<<"Enter Initial Account Balance:\t";
        cin>>asan_acc[constant].balance;
        cout<<endl<<"Enter Bank Name:\t";
        cin>>asan_acc[constant].Bank_Name;
        cout<<endl<<"Enter Marital Status:\t";
        cin>>asan_acc[constant].Acc_Operated_by;
        cout<<endl<<"Enter Branch Code:\t";
        cin>>asan_acc[constant].Branch_Code; ///IBAN
        cout<<endl<<"Enter Branch Name:\t";
        cin>>asan_acc[constant].Branch_Name;
    }
    else if(choice==2)
    {
        cout<<endl<<"Enter Account Title:\t";
        cin>>bus_acc[constant].Acc_Title;   ///Account number...
        cout<<endl<<"Enter Customer Name:\t";
        cin>>bus_acc[constant].Cust_Name;
        cout<<endl<<"Enter Customer CNIC(xxxxxxxxxxxxx):\t";
        cin>>bus_acc[constant].Cus_CNIC;
        cout<<endl<<"Enter Customer Date Of Birth[dd/mm/yyyy]:\t";
        cin>>bus_acc[constant].DoB;
        cout<<endl<<"Enter Customer Contact:\t";
        cin>>bus_acc[constant].Cus_Contact;
        cout<<endl<<"Enter Customer Contact 2:\t";
        cin>>bus_acc[constant].Cus_Contact2;
        cout<<endl<<"Enter Customer Email Address:\t";
        cin>>bus_acc[constant].Cus_Email;
        cout<<endl<<"Enter Customer Address:\t";
        cin>>bus_acc[constant].Cus_Adrs;
        cout<<endl<<"Enter Initial Account Balance:\t";
        cin>>bus_acc[constant].balance;
        cout<<endl<<"Enter Bank Name:\t";
        cin>>bus_acc[constant].Bank_Name;
        cout<<endl<<"Enter Marital Status:\t";
        cin>>bus_acc[constant].Acc_Operated_by;
        cout<<endl<<"Enter Branch Code:\t";
        cin>>bus_acc[constant].Branch_Code; ///IBAN
        cout<<endl<<"Enter Branch Name:\t";
        cin>>bus_acc[constant].Branch_Name;
    }
    else if(choice==3)
    {
        cout<<endl<<"Enter Account Title:\t";
        cin>>cur_acc[constant].Acc_Title;   ///Account number...
        cout<<endl<<"Enter Customer Name:\t";
        cin>>cur_acc[constant].Cust_Name;
        cout<<endl<<"Enter Customer CNIC(xxxxxxxxxxxxx):\t";
        cin>>cur_acc[constant].Cus_CNIC;
        cout<<endl<<"Enter Customer Date Of Birth[dd/mm/yyyy]:\t";
        cin>>cur_acc[constant].DoB;
        cout<<endl<<"Enter Customer Contact:\t";
        cin>>cur_acc[constant].Cus_Contact;
        cout<<endl<<"Enter Customer Contact 2:\t";
        cin>>cur_acc[constant].Cus_Contact2;
        cout<<endl<<"Enter Customer Email Address:\t";
        cin>>cur_acc[constant].Cus_Email;
        cout<<endl<<"Enter Customer Address:\t";
        cin>>cur_acc[constant].Cus_Adrs;
        cout<<endl<<"Enter Initial Account Balance:\t";
        cin>>cur_acc[constant].balance;
        cout<<endl<<"Enter Bank Name:\t";
        cin>>cur_acc[constant].Bank_Name;
        cout<<endl<<"Enter Marital Status:\t";
        cin>>cur_acc[constant].Acc_Operated_by;
        cout<<endl<<"Enter Branch Code:\t";
        cin>>cur_acc[constant].Branch_Code; ///IBAN
        cout<<endl<<"Enter Branch Name:\t";
        cin>>cur_acc[constant].Branch_Name;
    }
    else if(choice==4)
    {
        main_menu();
    }
    else
    {
        cout<<"\nInvalid Choice..."<<endl;
        constant=constant-1;
        goto new_cos;
    }
        cout<<endl<<constant;
    main_menu();

}





///completed


void cash_transaction()
{
menu:
    int search_acc,br_cd,acc_num,opsion,cash_amount,Dpst_slp_no,cis,transaction_done,t_prt;
	string nic,paswrd,user_name,dcn;

	string wnc_nam, wnc_nic;
	int sv,prt;
	int flag,limit;
    int choice=0;
    cout <<endl;
	cout <<"1. Cash Deposit"<<endl;
	cout <<"2. Cash Withdraw"<<endl;
	cout <<"3. Main Menu"<<endl;
	cout <<"4. EXIT"<<endl;
	cout <<endl<< "Select Consumer: ";
	cin >> choice;

	if(choice == 1)
	{
		cash_deposit();
	}
	else if(choice==2)
    {
        cash_withdraw();
    }
    else if(choice==3)
    {
        main_menu();
    }
    else if(choice==4)
    {
        exit(0);
    }
    else{ goto menu;}

}
void cash_deposit()
{
        accounts();
        int search_acc,br_cd,acc_num,opsion,cash_amount,Dpst_slp_no,cis,transaction_done,t_prt;
        string nic,paswrd,user_name,dcn;

        string wnc_nam, wnc_nic;
        cout<<endl<<endl<<"\t***Cash Deposit***"<<endl<<endl<<endl;
		cout<<endl<<"Enter Account Number: ";
		cin>>acc_num;

		if(acc_num == 1102226712)
		{
			cout<<endl<<"Account Title:\t"<<bus_acc[0].Acc_Title;
			cout<<endl<<"Branch Name:\t"<<bus_acc[0].Branch_Name;
			cout<<endl<<"IBAN Number:\t"<<bus_acc[0].IBAN_Number;
			cout<<endl<<"Account Type:\t"<<bus_acc[0].Acc_type;
			cout<<endl<<endl<<"Cash Deposit Amount:\t";
			cin>>cash_amount;
			cout<<endl<<"Deposit Slip:\t\t";
			cin>>Dpst_slp_no;


			cout<<endl<<"Capture Info Selection: ";;
			cout<<endl<<"1. EBL.Ac.Holder";
			cout<<endl<<"2. Self";
			cout<<endl<<"3. Walk.in.Customer";
			cout<<endl<<"4. Exit";

			cout<<endl<<endl<<"Select Number: ";
			cin>>cis;
			if(cis == 1)
			{
				cout<<endl<<"Account Number:\t";
				cin>>dcn;

				if(dcn == bus_acc[0].Acc_Number)
				{
					cout<<endl<<"Same Account Not Allowed";
				}
				else if(dcn == bus_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[1].Acc_Title;
				}
				else if(dcn == bus_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[2].Acc_Title;
				}
				else if(dcn == bus_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[3].Acc_Title;
				}
				else if(dcn == bus_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[4].Acc_Title;
				}
				else if(dcn == asan_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[0].Acc_Title;
				}
				else if(dcn == asan_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[1].Acc_Title;
				}
				else if(dcn == asan_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[2].Acc_Title;
				}
				else if(dcn == asan_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[3].Acc_Title;
				}
				else if(dcn == asan_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[4].Acc_Title;
				}
				else{
					cout<<endl<<"Invalid Account Number!";
				}
			}
			else if(cis == 2)
			{
				cout<<endl<<"Customer Name:\t"<<bus_acc[0].Cust_Name;
			}
			else if(cis == 3)
			{
				cout<<endl<<"Customer Name: ";
				cin.ignore();
				getline(cin,wnc_nam);
				cout<<endl<<"Customer CNIC: ";
				cin>>wnc_nic;
			}
			else{
				cout<<endl<<"Invalid Option!";
			}

		cout<<endl<<endl<<endl<<"Press 1 For Save \t\tPress 2 For Exit"<<endl;
		cin>>transaction_done;

		if(transaction_done == 1)
		{
			cout<<endl<<"\tSaved"<<endl;
			cout<<endl<<"Press 1 For Print: ";
			cin >>t_prt;

			if(t_prt == 1)
			{
				cout<<endl<<"\t\tCash Deposited";
				cout<<endl<<"\t\t";time();
				cout<<"\t\tCILIFTON BRANCH KARACHI";
				cout<<endl<<"\t\tUser ID AHSAN.110";
				cout<<endl<<"\t\tPKR "<<cash_amount;
				bus_acc[0].balance=cash_amount+asan_acc[0].balance;
				cout<<endl<<"\t\tA/C # "<<bus_acc[0].Acc_Number;
				cout<<endl<<"\t\t"<<bus_acc[0].Acc_Title;
			}
		}


		}
		else if(acc_num == 1102127861)
		{
			cout<<endl<<"Account Title:\t"<<bus_acc[1].Acc_Title;
			cout<<endl<<"Branch Name:\t"<<bus_acc[1].Branch_Name;
			cout<<endl<<"IBAN Number:\t"<<bus_acc[1].IBAN_Number;
			cout<<endl<<"Account Type:\t"<<bus_acc[1].Acc_type;
			cout<<endl<<endl<<"Cash Deposit Amount:\t";
			cin>>cash_amount;
			cout<<endl<<"Deposit Slip:\t\t";
			cin>>Dpst_slp_no;


			cout<<endl<<"Capture Info Selection: ";;
			cout<<endl<<"1. EBL.Ac.Holder";
			cout<<endl<<"2. Self";
			cout<<endl<<"3. Walk.in.Customer";
			cout<<endl<<"4. Exit";

			cout<<endl<<endl<<"Select Number: ";
			cin>>cis;
			if(cis == 1)
			{
				cout<<endl<<"Account Number:\t";
				cin>>dcn;

				if(dcn == bus_acc[1].Acc_Number)
				{
					cout<<endl<<"Same Account Not Allowed";
				}
				else if(dcn == bus_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[0].Acc_Title;
				}
				else if(dcn == bus_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[2].Acc_Title;
				}
				else if(dcn == bus_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[3].Acc_Title;
				}
				else if(dcn == bus_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[4].Acc_Title;
				}
				else if(dcn == asan_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[0].Acc_Title;
				}
				else if(dcn == asan_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[1].Acc_Title;
				}
				else if(dcn == asan_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[2].Acc_Title;
				}
				else if(dcn == asan_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[3].Acc_Title;
				}
				else if(dcn == asan_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[4].Acc_Title;
				}
				else{
					cout<<endl<<"Invalid Account Number!";
				}
			}
			else if(cis == 2)
			{
				cout<<endl<<"Customer Name:\t"<<bus_acc[1].Cust_Name;
			}
			else if(cis == 3)
			{
				cout<<endl<<"Customer Name: ";
				cin.ignore();
				getline(cin,wnc_nam);
				cout<<endl<<"Customer CNIC: ";
				cin>>wnc_nic;
			}
			else{
				cout<<endl<<"Invalid Option!";
			}

		cout<<endl<<endl<<endl<<"Press 1 For Save \t\tPress 2 For Exit"<<endl;
		cin>>transaction_done;

		if(transaction_done == 1)
		{
			cout<<endl<<"\tSaved"<<endl;
			cout<<endl<<"Press 1 For Print: ";
			cin >>t_prt;

			if(t_prt == 1)
			{
				cout<<endl<<"\t\tCash Deposited";
				cout<<endl<<"\t\t";time();
				cout<<"\t\tCILIFTON BRANCH KARACHI";
				cout<<endl<<"\t\tUser ID AHSAN.110";
				cout<<endl<<"\t\tPKR "<<cash_amount;
				bus_acc[1].balance=cash_amount+asan_acc[1].balance;
				cout<<endl<<"\t\tA/C # "<<bus_acc[1].Acc_Number;
				cout<<endl<<"\t\t"<<bus_acc[1].Acc_Title;
			}
		}


		}
				else if(acc_num == 1107671112)
		{
			cout<<endl<<"Account Title:\t"<<asan_acc[0].Acc_Title;
			cout<<endl<<"Branch Name:\t"<<asan_acc[0].Branch_Name;
			cout<<endl<<"IBAN Number:\t"<<asan_acc[0].IBAN_Number;
			cout<<endl<<"Account Type:\t"<<asan_acc[0].Acc_type;
			cout<<endl<<endl<<"Cash Deposit Amount:\t";
			cin>>cash_amount;
			cout<<endl<<"Deposit Slip:\t\t";
			cin>>Dpst_slp_no;


			cout<<endl<<"Capture Info Selection: ";;
			cout<<endl<<"1. EBL.Ac.Holder";
			cout<<endl<<"2. Self";
			cout<<endl<<"3. Walk.in.Customer";
			cout<<endl<<"4. Exit";

			cout<<endl<<endl<<"Select Number: ";
			cin>>cis;
			if(cis == 1)
			{
				cout<<endl<<"Account Number:\t";
				cin>>dcn;

				if(dcn == asan_acc[0].Acc_Number)
				{
					cout<<endl<<"Same Account Not Allowed";
				}
				else if(dcn == bus_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[0].Acc_Title;
				}
				else if(dcn == bus_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[2].Acc_Title;
				}
				else if(dcn == bus_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[3].Acc_Title;
				}
				else if(dcn == bus_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[4].Acc_Title;
				}
				else if(dcn == bus_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[1].Acc_Title;
				}
				else if(dcn == asan_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[1].Acc_Title;
				}
				else if(dcn == asan_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[2].Acc_Title;
				}
				else if(dcn == asan_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[3].Acc_Title;
				}
				else if(dcn == asan_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[4].Acc_Title;
				}
				else{
					cout<<endl<<"Invalid Account Number!";
				}
			}
			else if(cis == 2)
			{
				cout<<endl<<"Customer Name:\t"<<asan_acc[0].Cust_Name;
			}
			else if(cis == 3)
			{
				cout<<endl<<"Customer Name: ";
				cin.ignore();
				getline(cin,wnc_nam);
				cout<<endl<<"Customer CNIC: ";
				cin>>wnc_nic;
			}
			else{
				cout<<endl<<"Invalid Option!";
			}

		cout<<endl<<endl<<endl<<"Press 1 For Save \t\tPress 2 For Exit"<<endl;
		cin>>transaction_done;

		if(transaction_done == 1)
		{
			cout<<endl<<"\tSaved"<<endl;
			cout<<endl<<"Press 1 For Print: ";
			cin >>t_prt;

			if(t_prt == 1)
			{
				cout<<endl<<"\t\tCash Deposited";
				cout<<endl<<"\t\t";time();
				cout<<"\t\tCILIFTON BRANCH KARACHI";
				cout<<endl<<"\t\tUser ID AHSAN.110";
				cout<<endl<<"\t\tPKR "<<cash_amount;
				asan_acc[0].balance=cash_amount+asan_acc[0].balance;
				cout<<endl<<"\t\tA/C # "<<asan_acc[0].Acc_Number;
				cout<<endl<<"\t\t"<<asan_acc[0].Acc_Title;
			}
		}


		}
		else if(acc_num == 1108751000)
		{
			cout<<endl<<"Account Title:\t"<<asan_acc[4].Acc_Title;
			cout<<endl<<"Branch Name:\t"<<asan_acc[4].Branch_Name;
			cout<<endl<<"IBAN Number:\t"<<asan_acc[4].IBAN_Number;
			cout<<endl<<"Account Type:\t"<<asan_acc[4].Acc_type;
			cout<<endl<<endl<<"Cash Deposit Amount:\t";
			cin>>cash_amount;
			cout<<endl<<"Deposit Slip:\t\t";
			cin>>Dpst_slp_no;


			cout<<endl<<"Capture Info Selection: ";;
			cout<<endl<<"1. EBL.Ac.Holder";
			cout<<endl<<"2. Self";
			cout<<endl<<"3. Walk.in.Customer";
			cout<<endl<<"4. Exit";

			cout<<endl<<endl<<"Select Number: ";
			cin>>cis;
			if(cis == 1)
			{
				cout<<endl<<"Account Number:\t";
				cin>>dcn;

				if(dcn == asan_acc[4].Acc_Number)
				{
					cout<<endl<<"Same Account Not Allowed";
				}
				else if(dcn == bus_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[0].Acc_Title;
				}
				else if(dcn == bus_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[2].Acc_Title;
				}
				else if(dcn == bus_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[3].Acc_Title;
				}
				else if(dcn == bus_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[4].Acc_Title;
				}
				else if(dcn == bus_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[1].Acc_Title;
				}
				else if(dcn == asan_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[1].Acc_Title;
				}
				else if(dcn == asan_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[2].Acc_Title;
				}
				else if(dcn == asan_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[3].Acc_Title;
				}
				else if(dcn == asan_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[0].Acc_Title;
				}
				else{
					cout<<endl<<"Invalid Account Number!";
				}
			}
			else if(cis == 2)
			{
				cout<<endl<<"Customer Name:\t"<<asan_acc[4].Cust_Name;
			}
			else if(cis == 3)
			{
				cout<<endl<<"Customer Name: ";
				cin.ignore();
				getline(cin,wnc_nam);
				cout<<endl<<"Customer CNIC: ";
				cin>>wnc_nic;
			}
			else{
				cout<<endl<<"Invalid Option!";
			}

		cout<<endl<<endl<<endl<<"Press 1 For Save \t\tPress 2 For Exit"<<endl;
		cin>>transaction_done;

		if(transaction_done == 1)
		{

			cout<<endl<<"\tSaved"<<endl;
			cout<<endl<<"Press 1 For Print: ";
			cin >>t_prt;

			if(t_prt == 1)
			{
				cout<<endl<<"\t\tCash Deposited";
				cout<<endl<<"\t\t";time();
				cout<<"\t\tCILIFTON BRANCH KARACHI";
				cout<<endl<<"\t\tUser ID AHSAN.110";
				cout<<endl<<"\t\tPKR "<<cash_amount;
				asan_acc[4].balance=cash_amount+asan_acc[4].balance;
				cout<<endl<<"\t\tA/C # "<<asan_acc[4].Acc_Number;
				cout<<endl<<"\t\t"<<asan_acc[4].Acc_Title;
			}
		}
		}
		else{
            cout<<"\nIncorrect Account Number!\n\tTry Again...\n";
		}
    main_menu();

}
void cash_withdraw()
{
    accounts();
        string acc_num, acc_type;
        int cash, k, tax=0;
        cout<<endl<<endl<<"\t***Cash Withdraw***"<<endl<<endl<<endl;
		cout<<endl<<"Enter Account Number: ";
		cin>> acc_num;
		for( k=0;k<5;k++)
            {
                if(bus_acc[k].Acc_Number==acc_num)
                            {
                                cout<<"Searching";
                                sleep(1);
                                cout<<".";
                                sleep(1);
                                cout<<".";
                                sleep(1);
                                cout<<".";
                                cout<<"\n\nAccount Found!"<<endl;
                                cout<<"\n\n\tCash amount: ";
                                cin>>cash;
                                if(bus_acc[k].balance>cash)
                                {
                                    bus_acc[k].balance=bus_acc[k].balance-cash;
                                    cout<<"Thank You!\n";
                                    cout<<bus_acc[k].balance<<endl;
                                    main_menu();
                                }
                                else if(bus_acc[k].balance<cash)
                                {
                                    cout<<"Insufficient Balance...\n";
                                    main_menu();
                                }
                                else
                                {
                                    cout<<"Error";
                                }

                            }
                else if(asan_acc[k].Acc_Number==acc_num)
                            {
                                cout<<"Searching";
                                sleep(1);
                                cout<<".";
                                sleep(1);
                                cout<<".";
                                sleep(1);
                                cout<<".";
                                cout<<"\n\nAccount Found!"<<endl;
                                cout<<"\n\n\tCash amount: ";
                                cin>>cash;
                                asan_acc[k].balance=asan_acc[k].balance-asan_tax(cash);
                                if(asan_acc[k].balance>cash)
                                    {
                                        cout<<"\n(Asan)Thank You!\n";
                                        cout<<"Remaining Balance is:\t PKR "<<asan_acc[k].balance;
                                        main_menu();
                                    }
                                else if(asan_acc[k].balance>cash)
                                    {
                                        cout<<"\nInsufficient Balance...\n";
                                        main_menu();
                                    }
                                else
                                    {
                                    cout<<"\nError!\n";
                                    }
                            }
                else if(cur_acc[k].Acc_Number==acc_num)
                            {
                                cout<<"Searching";
                                sleep(1);
                                cout<<".";
                                sleep(1);
                                cout<<".";
                                sleep(1);
                                cout<<".";
                                cout<<"\n\nAccount of Another Bank!"<<endl;
                                cout<<"\nThank You!\n";
                                main_menu();
                                    }
                                }

}
void fund_transfer()
{
menu:
    int search_acc,br_cd,acc_num,opsion,cash_amount,Dpst_slp_no,cis,transaction_done,t_prt;
	string nic,paswrd,user_name,dcn;

	string wnc_nam, wnc_nic;
	int sv,prt;
	int flag,limit;
    int choice=0;
    cout <<endl;
	cout <<"1. Online Cash Deposit"<<endl;
	cout <<"2. Online Cash Withdraw"<<endl;
	cout <<"3. Main Menu"<<endl;
	cout <<"4. EXIT"<<endl;
	cout <<endl<< "Select Consumer: ";
	cin >> choice;

	if(choice == 1)
	{
		online_deposit();
	}
	else if(choice==2)
    {
        online_withdraw();
    }
    else if(choice==3)
    {
        main_menu();
    }
    else if(choice==4)
    {
        exit(0);
    }
    else{ goto menu;}

}
void online_deposit()
{
    accounts();
        int search_acc,br_cd,acc_num,opsion,cash_amount,Dpst_slp_no,cis,transaction_done,t_prt;
        string nic,paswrd,user_name,dcn;

        string wnc_nam, wnc_nic;
        cout<<endl<<endl<<"\t***Cash Deposit***"<<endl<<endl<<endl;
		cout<<endl<<"Enter Account Number: ";
		cin>>acc_num;

		if(acc_num == 1102101455)
		{
			cout<<endl<<"Account Title:\t"<<cur_acc[3].Acc_Title;
			cout<<endl<<"Branch Name:\t"<<cur_acc[3].Branch_Name;
			cout<<endl<<"IBAN Number:\t"<<cur_acc[3].IBAN_Number;
			cout<<endl<<"Account Type:\t"<<cur_acc[3].Acc_type;
			cout<<endl<<endl<<"Cash Deposit Amount:\t";
			cin>>cash_amount;
			cout<<endl<<"Deposit Slip:\t\t";
			cin>>Dpst_slp_no;
			cout<<endl<<"Account Number to Transfer From:\t";
				cin>>dcn;

				if(dcn == cur_acc[3].Acc_Number)
				{
					cout<<endl<<"Same Account Not Allowed";
				}
				else if(dcn == bus_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[0].Acc_Title;
					bus_acc[0].balance=bus_acc[0].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == bus_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[2].Acc_Title;
					bus_acc[2].balance=bus_acc[2].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == bus_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[3].Acc_Title;
					bus_acc[3].balance=bus_acc[3].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == bus_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[4].Acc_Title;
					bus_acc[4].balance=bus_acc[4].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == cur_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<cur_acc[0].Acc_Title;
					cur_acc[0].balance=cur_acc[0].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == cur_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<cur_acc[1].Acc_Title;
					cur_acc[1].balance=cur_acc[1].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == cur_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<cur_acc[2].Acc_Title;
					cur_acc[2].balance=cur_acc[2].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == bus_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[1].Acc_Title;
					bus_acc[1].balance=bus_acc[1].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == cur_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<cur_acc[4].Acc_Title;
					cur_acc[4].balance=cur_acc[4].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[0].Acc_Title;
					asan_acc[0].balance=asan_acc[0].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[1].Acc_Title;
					asan_acc[1].balance=asan_acc[1].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[2].Acc_Title;
					asan_acc[2].balance=asan_acc[2].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[3].Acc_Title;
					asan_acc[3].balance=asan_acc[3].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[4].Acc_Title;
					asan_acc[4].balance=asan_acc[4].balance-online_deposit_tax(cash_amount);
				}
				else{
					cout<<endl<<"Invalid Account Number!";
				}
		}
    else if(acc_num == 1104590231)
		{
			cout<<endl<<"Account Title:\t"<<cur_acc[4].Acc_Title;
			cout<<endl<<"Branch Name:\t"<<cur_acc[4].Branch_Name;
			cout<<endl<<"IBAN Number:\t"<<cur_acc[4].IBAN_Number;
			cout<<endl<<"Account Type:\t"<<cur_acc[4].Acc_type;
			cout<<endl<<endl<<"Cash Deposit Amount:\t";
			cin>>cash_amount;
			cout<<endl<<"Deposit Slip:\t\t";
			cin>>Dpst_slp_no;
			cout<<endl<<"Account Number:\t";
				cin>>dcn;

				if(dcn == cur_acc[4].Acc_Number)
				{
					cout<<endl<<"Same Account Not Allowed";
				}
				else if(dcn == bus_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[0].Acc_Title;
					bus_acc[0].balance=bus_acc[0].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == bus_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[2].Acc_Title;
					bus_acc[2].balance=bus_acc[2].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == bus_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[3].Acc_Title;
					bus_acc[3].balance=bus_acc[3].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == bus_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[4].Acc_Title;
					bus_acc[4].balance=bus_acc[4].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == cur_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<cur_acc[0].Acc_Title;
					cur_acc[0].balance=cur_acc[0].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == cur_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<cur_acc[1].Acc_Title;
					cur_acc[1].balance=cur_acc[1].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == cur_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<cur_acc[2].Acc_Title;
					cur_acc[2].balance=cur_acc[2].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == bus_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<bus_acc[1].Acc_Title;
					bus_acc[1].balance=bus_acc[1].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == cur_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<cur_acc[3].Acc_Title;
					cur_acc[3].balance=cur_acc[3].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[0].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[0].Acc_Title;
					asan_acc[0].balance=asan_acc[0].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[1].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[1].Acc_Title;
					asan_acc[1].balance=asan_acc[1].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[2].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[2].Acc_Title;
					asan_acc[2].balance=asan_acc[2].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[3].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[3].Acc_Title;
					asan_acc[3].balance=asan_acc[3].balance-online_deposit_tax(cash_amount);
				}
				else if(dcn == asan_acc[4].Acc_Number)
				{
					cout<<"Account Title:\t"<<asan_acc[4].Acc_Title;
					asan_acc[4].balance=asan_acc[4].balance-online_deposit_tax(cash_amount);
				}

				else{
					cout<<endl<<"Invalid Account Number!";
				}
			}

		cout<<endl<<endl<<endl<<"Press 1 For Save \t\tPress 2 For Exit"<<endl;
		cin>>transaction_done;

		if(transaction_done == 1)
		{
			cout<<endl<<"\tSaved"<<endl;
			cout<<endl<<"Press 1 For Print: ";
			cin >>t_prt;

			if(t_prt == 1)
			{
				cout<<endl<<"\t\tCash Deposited PKR "<<cash_amount;
				cout<<endl<<"\t\t";time();
				cout<<"\t\tCILIFTON BRANCH KARACHI";
				cout<<endl<<"\t\tUser ID AHSAN.110";
				cur_acc[4].balance=cur_acc[4].balance+cash_amount;
				cout<<endl<<"\t\tAvailible Balance PKR "<<cur_acc[4].balance;
				cout<<endl<<"\t\tA/C # "<<cur_acc[4].Acc_Number;
				cout<<endl<<"\t\t"<<cur_acc[4].Acc_Title;
			}
		}

}

void online_withdraw()
{
    accounts();
        string acc_num, acc_type;
        int cash, k, tax=0;
        cout<<endl<<endl<<"\t***Online Cash Withdraw***"<<endl<<endl<<endl;
		cout<<endl<<"Enter Account Number: ";
		cin>> acc_num;
		for(k=0;k<5;k++)
            {
                if(cur_acc[k].Acc_Number==acc_num)
                            {
                                cout<<"Searching";
                                sleep(1);
                                cout<<".";
                                sleep(1);
                                cout<<".";
                                sleep(1);
                                cout<<".";
                                cout<<"\n\nAccount of Mezaan Bank Found!"<<endl;
                                cout<<"\n\n\tCash amount: PKR ";
                                cin>>cash;
                                cur_acc[k].balance=cur_acc[k].balance-online_withdraw_tax(cash);
                                if(cur_acc[k].balance>cash)
                                {
                                    cout<<"Here's Your PKR "<<cash;
                                    cout<<"\nThank You!\n";
                                    cout<<cur_acc[k].balance<<endl;
                                    main_menu();
                                }
                                else if(cur_acc[k].balance<cash)
                                {
                                    cout<<"Insufficient Balance...\n";
                                    main_menu();
                                }
                                else
                                {
                                    cout<<"Error";
                                }
                            }

                            }
                            cout<<"\n\n\n\tThank You!\n\n";
                            main_menu();

}
///asaan Account tax Calculator
int asan_tax(int x)
{
    if(x>50000)
    {
        cout<<"Out of limit!"<<endl;
        main_menu();
    }
    else if(x>=5000 && x<10000)
    {
        return x+300;
    }
    else if(x>=10000 && x<15000)
    {
        return x+600;
    }
    else if(x>=15000 && x<20000)
    {
        return x+900;
    }
    else if(x>=20000 && x<25000)
    {
        return x+1200;
    }
    else if(x>=25000 && x<30000)
    {
        return x+1500;
    }
    else if(x>=30000 && x<35000)
    {
        return x+1800;
    }
    else if(x>=35000 && x<40000)
    {
        return x+2100;
    }
    else if(x>=40000 && x<45000)
    {
        return x+2400;
    }
    else if(x>=45000 && x<50000)
    {
        return x+2700;
    }
    else{
        return x;
    }
}
///Bank to Bank transfer tax Calculator
int online_withdraw_tax(int x)
{
    if(x>50000)
    {
        cout<<"Out of limit!"<<endl;
        main_menu();
    }
    else if(x>=5000 && x<10000)
    {
        return x+400;
    }
    else if(x>=10000 && x<15000)
    {
        return x+700;
    }
    else if(x>=15000 && x<20000)
    {
        return x+1000;
    }
    else if(x>=20000 && x<25000)
    {
        return x+1300;
    }
    else if(x>=25000 && x<30000)
    {
        return x+1600;
    }
    else if(x>=30000 && x<35000)
    {
        return x+1900;
    }
    else if(x>=35000 && x<40000)
    {
        return x+2200;
    }
    else if(x>=40000 && x<45000)
    {
        return x+2500;
    }
    else if(x>=45000 && x<50000)
    {
        return x+2800;
    }
    else{
        return x;
    }
}
///online_deposit tax
int online_deposit_tax(int x)
{
    if(x>500000)
    {
        cout<<"Out of limit!"<<endl;
        main_menu();
    }
    else if(x>=50000 && x<100000)
    {
        return x+4;
    }
    else if(x>=100000 && x<150000)
    {
        return x+7;
    }
    else if(x>=150000 && x<200000)
    {
        return x+10;
    }
    else if(x>=200000 && x<250000)
    {
        return x+13;
    }
    else if(x>=250000 && x<300000)
    {
        return x+16;
    }
    else if(x>=300000 && x<350000)
    {
        return x+19;
    }
    else if(x>=350000 && x<400000)
    {
        return x+22;
    }
    else if(x>=400000 && x<450000)
    {
        return x+25;
    }
    else if(x>=450000 && x<500000)
    {
        return x+2800;
    }
    else{
        return x;
    }
}
//Bank to Bank transfer tax Calculator
int debit_tax(int x)
{
    if(x>10000)
    {
        cout<<"Out of limit!"<<endl;
        main_menu();
    }
    else if(x>=500 && x<1000)
    {
        return x+40;
    }
    else if(x>=1000 && x<3000)
    {
        return x+70;
    }
    else if(x>=3000 && x<5000)
    {
        return x+100;
    }
    else if(x>=5000 && x<10000)
    {
        return x+130;
    }
    else if(x>=10000 && x<20000)
    {
        return x+160;
    }
    else{
        return x;
    }
}


///Utility
void billing_info()
{
    bill[0].Account_Number = "0400012345678";
	bill[0].Customer_Name = "Ahsan Ali";
	bill[0].Due_Date = "15 Dec 2020";
	bill[0].Payable_Amount = 3137;
	bill[0].After_Due_Date = 3230;

	bill[1].Account_Number = "0400002345678";
	bill[1].Customer_Name = "Danish Mehmood";
	bill[1].Due_Date = "8 Dec 2020";
	bill[1].Payable_Amount = 5340;
	bill[1].After_Due_Date = 5353;

	bill[2].Account_Number = "0400020532113";
	bill[2].Customer_Name = "Faisal Karim";
	bill[2].Due_Date = "25 Dec 2020";
	bill[2].Payable_Amount = 7011;
	bill[2].After_Due_Date = 8004;

	bill[3].Account_Number = "0400007891012";
	bill[3].Customer_Name = "Muhammad Adil Khan";
	bill[3].Due_Date = "18 Dec 2020";
	bill[3].Payable_Amount = 1023;
	bill[3].After_Due_Date = 1114;

	bill[4].Account_Number = "0400067121013";
	bill[4].Customer_Name = "Muhammad Usama";
	bill[4].Due_Date = "26 Dec 2020";
	bill[4].Payable_Amount = 890;
	bill[4].After_Due_Date = 983;

	bill[5].Account_Number = "1212034239";
	bill[5].Customer_Name = "Muhammad Junaid";
	bill[5].Due_Date = "5 Jan 2021";
	bill[5].Payable_Amount = 1045;
	bill[5].After_Due_Date = 1125;

	bill[6].Account_Number = "1201234541";
	bill[6].Customer_Name = "Muhammad Ali";
	bill[6].Due_Date = "5 Jan 2021";
	bill[6].Payable_Amount = 3500;
	bill[6].After_Due_Date = 3580;

	bill[7].Account_Number = "1301223871";
	bill[7].Customer_Name = "Muhammad Jawad";
	bill[7].Due_Date = "5 Jan 2021";
	bill[7].Payable_Amount = 9012;
	bill[7].After_Due_Date = 9092;

	bill[8].Account_Number = "1934549892";
	bill[8].Customer_Name = "Muhammad Waqas";
	bill[8].Due_Date = "5 Jan 2021";
	bill[8].Payable_Amount = 450;
	bill[8].After_Due_Date = 530;

	bill[9].Account_Number = "1812901232";
	bill[9].Customer_Name = "Bilal Khan";
	bill[9].Due_Date = "5 Jan 2021";
	bill[9].Payable_Amount = 1048;
	bill[9].After_Due_Date = 1128;

	bill[10].Account_Number = "3127681000";
	bill[10].Customer_Name = "Muhammad Rafiq";
	bill[10].Due_Date = "15 Jan 2021";
	bill[10].Payable_Amount = 750;
	bill[10].After_Due_Date = 840;

	bill[11].Account_Number = "3892348010";
	bill[11].Customer_Name = "Muhammad Danial";
	bill[11].Due_Date = "8 Jan 2021";
	bill[11].Payable_Amount = 1580;
	bill[11].After_Due_Date = 1660;

	bill[12].Account_Number = "1823097490";
	bill[12].Customer_Name = "Muhammad Usman";
	bill[12].Due_Date = "25 Jan 2021";
	bill[12].Payable_Amount = 680;
	bill[12].After_Due_Date = 760;

	bill[13].Account_Number = "8184230890";
	bill[13].Customer_Name = "Saddam Hussain";
	bill[13].Due_Date = "18 Jan 2021";
	bill[13].Payable_Amount = 1590;
	bill[13].After_Due_Date = 1670;

	bill[14].Account_Number = "3087342900";
	bill[14].Customer_Name = "Shahjahan Baloch";
	bill[14].Due_Date = "26 Jan 2021";
	bill[14].Payable_Amount = 1530;
	bill[14].After_Due_Date = 1610;
}
void utility_bill()
{
    int choice,sv,prt;
	int flag,limit;
	string account;
    choice=0;
menu:
	cout <<endl;
	cout <<"1. PTCL"<<endl;
	cout <<"2. K Electric"<<endl;
	cout <<"3. SSGC"<<endl;
	cout <<"4. Main Menu"<<endl;
	cout <<"5. EXIT"<<endl;


	cout <<endl<< "Select Consumer: ";
	cin >> choice;



	if(choice == 1)
	{
		cout<<endl<<"\t\t***PTCL***"<<endl;
		cout<<endl<<"Customer Number: ";
		cin >> account;

		if(account == "1212034239")
		{
			cout <<endl<<"Customer Name: "<<bill[5].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[5].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[5].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[5].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[5].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 690";
					cout<<endl<<"\tCustomer Name : PTCL";
				}

			else if(sv == 2)
			{
				flag = 0;
			}

		}
	}


		else if(account == "1201234541")
		{
			cout <<endl<<"Customer Name: "<<bill[6].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[6].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[6].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[6].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[6].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 691";
					cout<<endl<<"\tCustomer Name : PTCL";
				}
				else if(sv == 2)
			{
				flag = 0;
			}
			}

		}
		else if(account == "1301223871")
		{
			cout <<endl<<"Customer Name: "<<bill[7].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[7].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[7].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[7].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[7].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 692";
					cout<<endl<<"\tCustomer Name : PTCL";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}
		else if(account == "1934549892")
		{
			cout <<endl<<"Customer Name: "<<bill[8].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[8].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[8].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[8].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[8].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 693";
					cout<<endl<<"\tCustomer Name : PTCL";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}
		}
		else if(account == "1812901232")
		{
			cout <<endl<<"Customer Name: "<<bill[9].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[9].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[9].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[9].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[9].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 693";
					cout<<endl<<"\tCustomer Name : PTCL";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}
		else{
			cout<<endl<<endl<<"Invalid Customer Account Number!"<<endl;
		}
	}
	else if(choice == 2){
		cout<<endl<<"\t\t***K ELECTRIC***"<<endl;
		cout<<endl<<"Customer Number: ";
		cin >> account;

		if(account == "0400012345678")
		{
			cout <<endl<<"Customer Name: "<<bill[0].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[0].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[0].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[0].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[0].After_Due_Date<<endl;
//					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 696";
					cout<<endl<<"\tCustomer Name : K ELECTRIC";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}

		else if(account == "0400002345678")
		{
			cout <<endl<<"Customer Name: "<<bill[1].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[1].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[1].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[1].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[1].After_Due_Date<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 697";
					cout<<endl<<"\tCustomer Name : K ELECTRIC";
				}
				else if(sv == 2)
			{
				flag = 0;
			}
			}

		}
		else if(account == "0400020532113")
		{
			cout <<endl<<"Customer Name: "<<bill[2].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[2].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[2].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[2].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[2].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 698";
					cout<<endl<<"\tCustomer Name : K ELECTRIC";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}
		else if(account == "0400007891012")
		{
			cout <<endl<<"Customer Name: "<<bill[3].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[3].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[3].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[3].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[3].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 699";
					cout<<endl<<"\tCustomer Name : K ELECTRIC";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}
		else if(account == "0400067121013")
		{
			cout <<endl<<"Customer Name: "<<bill[4].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[4].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[4].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[4].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[4].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 700";
					cout<<endl<<"\tCustomer Name : K ELECTRIC";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}
		else{
			cout<<endl<<endl<<"Invalid Customer Account Number!"<<endl;
		}
	}
	else if(choice == 3){
		cout<<endl<<"\t\t***SSGC***"<<endl;
		cout<<endl<<"Customer Number: ";
		cin >> account;

		if(account == "3127681000")
		{
			cout <<endl<<"Customer Name: "<<bill[10].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[10].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[10].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[10].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[10].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 696";
					cout<<endl<<"\tCustomer Name : SSGC";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}

		else if(account == "3892348010")
		{
			cout <<endl<<"Customer Name: "<<bill[11].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[11].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[11].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[11].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[11].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 697";
					cout<<endl<<"\tCustomer Name : SSGC";
				}
				else if(sv == 2)
			{
				flag = 0;
			}
			}

		}
		else if(account == "1823097490")
		{
			cout <<endl<<"Customer Name: "<<bill[12].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[12].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[12].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[12].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[12].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 698";
					cout<<endl<<"\tCustomer Name : SSGC";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}
		else if(account == "8184230890")
		{
			cout <<endl<<"Customer Name: "<<bill[13].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[13].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[13].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[13].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[13].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 699";
					cout<<endl<<"\tCustomer Name : SSGC";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}
		}
		else if(account == "3087342900")
		{
			cout <<endl<<"Customer Name: "<<bill[14].Customer_Name<<endl;
			cout <<endl<<"Due Date: "<<bill[14].Due_Date<<endl;
			cout <<endl<<"After Due Date: "<<bill[14].After_Due_Date<<endl;
			cout <<endl<<"Payable Amount is: "<<bill[14].Payable_Amount<<endl;
			cout<<endl<<endl<<"Press 1 for Save \t\tPress 2 for Exit"<<endl;
			cin >> sv;

			if(sv == 1)
			{
				cout<<endl<<"\tSaved"<<endl;
				cout<<endl<<"Press 1 for Print"<<endl;
				cin >> prt;

				if(prt == 1)
				{
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\t\tBILL PAID           ";
					cout<<endl<<"\t````````````````````````````";
					cout<<endl<<"\tCASH COLLECTION";
					cout<<endl<<"\t1212034239";
					cout<<endl<<"\tPKR : "<<bill[14].Payable_Amount<<endl;
					cout<<"\t";time();
					cout<<"\tEmperor Bank 1212 Cilifton";
					cout<<endl<<"\tUser ID : AHSAN110";
					cout<<endl<<"\tCustomer Code : 705";
					cout<<endl<<"\tCustomer Name : SSGC";
				}

			else if(sv == 2)
			{
				flag = 0;
			}
		}

		}

		else{
			cout<<endl<<endl<<"Invalid Customer Account Number!"<<endl;
		}
	}
	else if (choice==4)
    {
        main_menu();
    }
    else if (choice==5)
    {
        exit(0);
    }
    else
    {
        cout<<"\n\nInvalid Choice...\nTry Again.\n";
        goto menu;
    }


}

///Fee Collection
void fee_collection()
{
    int p=0;
    system("cls");
student_portal:
    int n;
    cout<<"\n\t\t*Students Portal*"<<endl;
    cout<<"\n\n\tSelect from the list: "<<endl;
    cout<<"\t1.Fees Deposite\n\t2.Total Fees Deposited\n\t3.Back to Main Menu\n\t4.Exit\n\n\n\tEnter Your Choice Here: ";
    cin>>n;
    if(n==1)
    {
        char confirm;
fee:

      s[p].fee_deposite(p);
      cout<<"The Fees has been added to the Fees Database..."<<endl;
      cout<<"Do you want to continue adding Fees?(Y/N): ";
      cin>>confirm;
      if (confirm=='y' || confirm=='Y')
      {
          p=p+1;
          goto fee;
      }
      else if (confirm=='n' || confirm=='N')
      {
          cout<<"\nPress Enter to get back to the Student Portal";
          getchar();
          goto student_portal;
      }
      getchar();
    }
    if(n==2)
    {
        system("cls");
        s[p].fees_receipt(p);
        char confirm;
        cout<<"\n\n\tDo you want to go back to main menu?(Y/N): ";
        cin>>confirm;
      if (confirm=='y' || confirm=='Y')
      {
                  main_menu();
      }
      else if (confirm=='n' || confirm=='N')
      {
          cout<<"\nTerminating the program...";
          getchar();
          main_menu();
      }
    }
    else if(n==3)
    {
        main_menu();
    }
    else if(n==4)
    {
        exit(0);
    }
}
void Student::fee_deposite(int x)
{

        cout<<"\nEnter Student's Name: ";
        cin>>s[x].student_name;
        cout<<"\nEnter Student's Father's Name: ";
        cin>>s[x].father_name;
        cout<<"\nEnter Student's University Name: ";
        cin>>s[x].university_name;
        cout<<"\nEnter University Department Name: ";
        cin>>s[x].department;
        cout<<"\nEnter Semester(in digits[1,2,3,4,5,6,7,8]): ";
        cin>>s[x].semester;
        cout<<"\nEnter Student's Roll No.: ";
        cin>>s[x].roll_num;
        cout<<"\nEnter Student's Batch: ";
        cin>>s[x].batch;
        cout<<"\nEnter Student's Fee: PKR ";
        cin>>s[x].fee;

}
void Student::fees_receipt(int y)
{
    int total=0;
    for(int i=0;i<y+1;i++)
    {
        cout<<"\n"<<i+1<<endl;
        cout<<"\tStudent Name: \t"<<s[i].student_name<<endl;
        cout<<"\tFather's Name: \t"<<s[i].father_name<<endl;
        cout<<"\tUniversity: \t\t"<<s[i].university_name<<endl;
        cout<<"\tDepartment: \t\t"<<s[i].department<<endl;
        cout<<"\tSemester: \t\t"<<s[i].semester<<endl;
        cout<<"\tRoll Number"<<s[i].roll_num<<endl;
        cout<<"\tBatch: "<<s[i].batch<<endl;
        cout<<"\tFees: "<<s[i].fee<<endl;
        total+=s[i].fee;
    }
    cout<<"\n\tTotal Fee: "<<total<<endl;

}

///search engine
void account_search()
{
    system("cls");
    accounts();
    long long cnic;
    cout<<"Enter CNIC(xxxxxxxxxxxxx): ";
    cin>>cnic;
    for(int i=0;i<100;i++){
    if(cnic==bus_acc[i].Cus_CNIC)
    {
        cout<<endl<<"Account Title:\t"<<bus_acc[i].Acc_Title;
        cout<<endl<<"Account Type:\t"<<bus_acc[i].Acc_type;
        cout<<endl<<"Account Number:\t"<<bus_acc[i].Acc_Number;
        cout<<endl<<"Account Balance:\t"<<bus_acc[i].balance;
        cout<<endl<<"Bank Name:\t"<<bus_acc[i].Bank_Name;
        cout<<endl<<"Branch Name:\t"<<bus_acc[i].Branch_Name;
        cout<<endl<<"Branch Code:\t"<<bus_acc[i].Branch_Code;
        cout<<endl<<"IBAN Number:\t"<<bus_acc[i].IBAN_Number;
        cout<<endl<<"CNIC:\t"<<bus_acc[i].Cus_CNIC;
        cout<<endl<<"Date Of Birth:\t"<<bus_acc[i].DoB;
        cout<<endl<<"Customer Contact:\t"<<bus_acc[i].Cus_Contact;
        cout<<endl<<"Customer Email Address:\t"<<bus_acc[i].Cus_Email;
        cout<<endl<<"Customer Mailing Address:\t"<<bus_acc[i].Cus_Adrs;
        break;
    }
    else if (cnic==cur_acc[i].Cus_CNIC)
    {
        cout<<endl<<"Account Title:\t"<<cur_acc[i].Acc_Title;
        cout<<endl<<"Account Type:\t"<<cur_acc[i].Acc_type;
        cout<<endl<<"Account Number:\t"<<cur_acc[i].Acc_Number;
        cout<<endl<<"Account Balance:\t"<<cur_acc[i].balance;
        cout<<endl<<"Bank Name:\t"<<cur_acc[i].Bank_Name;
        cout<<endl<<"Branch Name:\t"<<cur_acc[i].Branch_Name;
        cout<<endl<<"Branch Code:\t"<<cur_acc[i].Branch_Code;
        cout<<endl<<"IBAN Number:\t"<<cur_acc[i].IBAN_Number;
        cout<<endl<<"CNIC:\t"<<cur_acc[i].Cus_CNIC;
        cout<<endl<<"Date Of Birth:\t"<<cur_acc[i].DoB;
        cout<<endl<<"Customer Contact:\t"<<cur_acc[i].Cus_Contact;
        cout<<endl<<"Customer Email Address:\t"<<cur_acc[i].Cus_Email;
        cout<<endl<<"Customer Mailing Address:\t"<<cur_acc[i].Cus_Adrs;
        break;
    }
    else if (cnic==asan_acc[i].Cus_CNIC)
    {
        cout<<endl<<"Account Title:\t"<<asan_acc[i].Acc_Title;
        cout<<endl<<"Account Type:\t"<<asan_acc[i].Acc_type;
        cout<<endl<<"Account Number:\t"<<asan_acc[i].Acc_Number;
        cout<<endl<<"Account Balance:\t"<<asan_acc[i].balance;
        cout<<endl<<"Bank Name:\t"<<asan_acc[i].Bank_Name;
        cout<<endl<<"Branch Name:\t"<<asan_acc[i].Branch_Name;
        cout<<endl<<"Branch Code:\t"<<asan_acc[i].Branch_Code;
        cout<<endl<<"IBAN Number:\t"<<asan_acc[i].IBAN_Number;
        cout<<endl<<"CNIC:\t"<<asan_acc[i].Cus_CNIC;
        cout<<endl<<"Date Of Birth:\t"<<asan_acc[i].DoB;
        cout<<endl<<"Customer Contact:\t"<<asan_acc[i].Cus_Contact;
        cout<<endl<<"Customer Email Address:\t"<<asan_acc[i].Cus_Email;
        cout<<endl<<"Customer Mailing Address:\t"<<asan_acc[i].Cus_Adrs;
        break;
    }

}
main_menu();
}

void account_statement()
{
    system("cls");
    accounts();
    string ac;
    cout<<"Enter account number: ";
    cin>>ac;
    for(int i=0;i<100;i++){
    if(ac==bus_acc[i].Acc_Number)
    {
        cout<<endl<<"Account Title:\t"<<bus_acc[i].Acc_Title;
        cout<<endl<<"Account Type:\t"<<bus_acc[i].Acc_type;
        cout<<endl<<"Account Number:\t"<<bus_acc[i].Acc_Number;
        cout<<endl<<"Account Balance:\t"<<bus_acc[i].balance;
        cout<<endl<<"Bank Name:\t"<<bus_acc[i].Bank_Name;
        cout<<endl<<"Branch Name:\t"<<bus_acc[i].Branch_Name;
        cout<<endl<<"Branch Code:\t"<<bus_acc[i].Branch_Code;
        cout<<endl<<"IBAN Number:\t"<<bus_acc[i].IBAN_Number;
        cout<<endl<<"CNIC:\t"<<bus_acc[i].Cus_CNIC;
        cout<<endl<<"Date Of Birth:\t"<<bus_acc[i].DoB;
        cout<<endl<<"Customer Contact:\t"<<bus_acc[i].Cus_Contact;
        cout<<endl<<"Customer Email Address:\t"<<bus_acc[i].Cus_Email;
        cout<<endl<<"Customer Mailing Address:\t"<<bus_acc[i].Cus_Adrs;
        break;
    }
    else if (ac==cur_acc[i].Acc_Number)
    {
        cout<<endl<<"Account Title:\t"<<cur_acc[i].Acc_Title;
        cout<<endl<<"Account Type:\t"<<cur_acc[i].Acc_type;
        cout<<endl<<"Account Number:\t"<<cur_acc[i].Acc_Number;
        cout<<endl<<"Account Balance:\t"<<cur_acc[i].balance;
        cout<<endl<<"Bank Name:\t"<<cur_acc[i].Bank_Name;
        cout<<endl<<"Branch Name:\t"<<cur_acc[i].Branch_Name;
        cout<<endl<<"Branch Code:\t"<<cur_acc[i].Branch_Code;
        cout<<endl<<"IBAN Number:\t"<<cur_acc[i].IBAN_Number;
        cout<<endl<<"CNIC:\t"<<cur_acc[i].Cus_CNIC;
        cout<<endl<<"Date Of Birth:\t"<<cur_acc[i].DoB;
        cout<<endl<<"Customer Contact:\t"<<cur_acc[i].Cus_Contact;
        cout<<endl<<"Customer Email Address:\t"<<cur_acc[i].Cus_Email;
        cout<<endl<<"Customer Mailing Address:\t"<<cur_acc[i].Cus_Adrs;
        break;
    }
    else if (ac==asan_acc[i].Acc_Number)
    {
        cout<<endl<<"Account Title:\t"<<asan_acc[i].Acc_Title;
        cout<<endl<<"Account Type:\t"<<asan_acc[i].Acc_type;
        cout<<endl<<"Account Number:\t"<<asan_acc[i].Acc_Number;
        cout<<endl<<"Account Balance:\t"<<asan_acc[i].balance;
        cout<<endl<<"Bank Name:\t"<<asan_acc[i].Bank_Name;
        cout<<endl<<"Branch Name:\t"<<asan_acc[i].Branch_Name;
        cout<<endl<<"Branch Code:\t"<<asan_acc[i].Branch_Code;
        cout<<endl<<"IBAN Number:\t"<<asan_acc[i].IBAN_Number;
        cout<<endl<<"CNIC:\t"<<asan_acc[i].Cus_CNIC;
        cout<<endl<<"Date Of Birth:\t"<<asan_acc[i].DoB;
        cout<<endl<<"Customer Contact:\t"<<asan_acc[i].Cus_Contact;
        cout<<endl<<"Customer Email Address:\t"<<asan_acc[i].Cus_Email;
        cout<<endl<<"Customer Mailing Address:\t"<<asan_acc[i].Cus_Adrs;

        break;
    }

}
main_menu();
}
void edit()
{
    accounts();
    int choice,test=0;
    string acount_number;
    cout<<"\nEnter the account no. of the customer whose info you want to change:";
    cin>>acount_number;
    for(int i=0;i<100;i++){
    if(acount_number==bus_acc[i].Acc_Number)
    {
        cout<<"\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):";
        cin>>choice;
        system("cls");
            if(choice==1)
                {cout<<"Enter the new address:";
                getline(cin,bus_acc[i].Cus_Adrs);
                cout<<"Changes saved!";
                system("cls");
                }
            else if(choice==2)
                {
                cout<<"Enter the new phone number:";
                getline(cin,bus_acc[i].Cus_Contact);
                cout<<"Changes saved!";
                system("cls");
                }
                break;
    }
    else if (acount_number==cur_acc[i].Acc_Number)
    {
        cout<<"\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):";
        cin>>choice;
        system("cls");
            if(choice==1)
                {cout<<"Enter the new address:";
                getline(cin,cur_acc[i].Cus_Adrs);
                cout<<"Changes saved!";
                system("cls");
                }
            else if(choice==2)
                {
                cout<<"Enter the new phone number:";
                getline(cin,cur_acc[i].Cus_Contact);
                cout<<"Changes saved!";
                system("cls");
                }

        break;
    }
    else if (acount_number==asan_acc[i].Acc_Number)
    {
        cout<<"\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):";
        cin>>choice;
        system("cls");
            if(choice==1)
                {cout<<"Enter the new address:";
                getline(cin,asan_acc[i].Cus_Adrs);
                cout<<"Changes saved!";
                system("cls");
                }
            else if(choice==2)
                {
                cout<<"Enter the new phone number:";
                getline(cin,asan_acc[i].Cus_Contact);
                cout<<"Changes saved!";
                system("cls");}

        break;
    }
}
main_menu();
}

