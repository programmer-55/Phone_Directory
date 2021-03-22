#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>

using namespace std;
fstream myfile;
fstream temp;

//structure for storing contacts.
struct clients
{
    string name;
    string number;
    string id_no;
    string place;
    string profession;
    clients *Link;
    clients()
    {
        Link=NULL;
    }
};

//initailization of a class 
class Directory
{
    clients *start, *cur, *temp;
public:
    Directory()
    {
        start=NULL;
    }

//creating nodes using linked list.
    void create_file(string n, string num, string cn,string p,string pl)
	{
    //first node creation
        if(start == NULL)
		{
            start = new clients;
            start -> Link = NULL;
            start -> name = n;
            start -> number = num;
            start -> id_no = cn;
            start->profession=p;
            start->place=pl;
            myfile.open("Directory.txt", ios::out | ios::app);
            myfile<<start -> name<<" "<<start -> id_no <<" "<<start -> number <<" "<<start->profession<<" "<<start->place <<endl;
            myfile.close();
        }
        //creating further nodes
        else{
            cur = start;
            while(cur -> Link != NULL){
                cur = cur -> Link;
            }
            temp = new clients;
            temp -> name = n;
            temp -> number = num;
            temp -> id_no = cn;
            temp->profession=p;
            temp->place=pl;
            temp -> Link = NULL;
            cur -> Link = temp;

            myfile.open("Directory.txt", ios::out | ios::app);
            myfile<<temp -> name<<" "<<temp -> id_no <<" "<<temp -> number <<" "<<temp->profession<<" "<<temp->place <<endl;
            myfile.close();
        }
    }
 
//search and modify contact.   
//searching from file directory
void search_file()
{
    string line, Name, strName, tNumber;
    int nextLoc=0,flag=0;
    cout <<"\tPlease enter the name of contact you want to search: ";
    cin>>strName;
    ifstream myfile;
    
    myfile.open("Directory.txt");
    
   
    while (!myfile.eof())
    {
    	getline (myfile,line);
    	nextLoc=line.find(" ");
	    Name=line.substr(0,nextLoc);
	    line = line.substr(nextLoc+1,line.length());
	    nextLoc=line.find(" ");
	    tNumber = line;
	    if((Name==strName))
        	{
			flag++;
			cout<<"\tID Phone No.  proff. place"<<"\n";
			cout<<"\t"<<tNumber<<"\n";
            }
	
   }
   
   if(flag==0)
   {
   	cout<<"\tData Not Found!\t";
   }
   myfile.close();
}

//search using linked list
 void search()
{
    cout<<"\tOn What basis do you want to find out the contact information?";
	cout<<"\n";
	cout<<"                           1.)Name";
	cout<<"\n";
	cout<<"                           2.)Profession";
	cout<<"\n\t";
	int n;
	cin>>n;
	if(n==1)
	{clients* temp=start;
	cout<<"\tEnter Name : ";
	cout<<"\n\t";
	string y;
	int flag=0;
	cin>>y;
	while(temp!=NULL)
	{
		if(temp->name==y)
		{flag++;
		cout<<"\tEnter the Id : ";
		cout<<"\n\t";
		string u1;
		cin>>u1;
		if(compareUsername(u1,temp->id_no)==0)
		{cout<<"\tWrong id. \n\tYou cannot view or make changes to the data unless the id is correct";
		}
		else
		 {
		 cout<<"\tData Found"<<"\n";
		 cout<<"\tName: "<<temp->name;
		 cout<<"\n";
		 cout<<"\tPhone: "<<temp->number;
		 cout<<"\n";
         cout<<"\tID NO: "<<temp->id_no;	
         cout<<"\n";
         cout<<"\tPlace: "<<temp->place;	
         cout<<"\n";
         cout<<"\tProfession: "<<temp->profession;	
         cout<<"\n\tDo you want to Modify the Phone Number(y/n) ";
         char s;
         cin>>s;
         if(s=='y')
         {
         	cout<<"\tEnter New Number ";
         	string n1;
         	cin>>n1;
			temp->number=n1;
			cout<<"\n";
			cout<<"\tChanges made in the Phone Number of "<<temp->name;
		 }
		 else
		 {
		    break;
	     }
	     }
		 }
		
	temp=temp->Link;
	}
	    if(flag==0)
	    {
	        cout<<"\tData was not Found";
	    }
	}
	
	else if(n==2)
	{clients* temp=start;
	cout<<"\tEnter Profession ";
	cout<<"\n\t";
	string y;
	cin>>y;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->profession==y)
		{flag=1;
		 cout<<"\n";
		 cout<<"\tName : "<<temp->name;
		 cout<<"\n";
		 cout<<"\tPhone : "<<temp->number;
		 cout<<"\n";
         cout<<"\tID NO. : "<<temp->id_no;	
         cout<<"\n";
         cout<<"\tPlace : "<<temp->place;	
         cout<<"\n";
         cout<<"\tProfession : "<<temp->profession;	
         
	}
		
		
	temp=temp->Link;
	}
	    if(flag==0)
	    {
	        cout<<"\tData NOT Found.";
	        cout<<"\n";
	    }
	}
}

//comparing Admin Username i.e. user
    int compareAdmin(string enterAdminUsername, string AdminUsername)
    {
    int x = enterAdminUsername.compare(AdminUsername);
 
    if (x != 0) {
        cout <<"\t'"<< enterAdminUsername << "' is Not Correct Username."<< endl;
    return 0;
	}
    else
        cout <<"\t"<<" Username Accepted " << endl;
    return 1;
	}

//comparing password i.e.1234
    int comparePassword(string enterPassword, string password)
    {
    int x = enterPassword.compare(password);
 
    if (x != 0) {
        cout <<"\t'"<< enterPassword << "' is Not Correct Password."<< endl;
        return 0;
    }
    else
        cout <<"\t"<< " Password Accepted " << endl;
        return 1;
    }
   
//used in search function to compare the IDS.
  int compareUsername(string k,string u)
    {
    	if(k.size()!=u.size())
    	{
    		return 0;
		}
		else
		{
			for(int t=0;k[t]!='\0';t++)
			{
				if(k[t]!=u[t])
				{
					return 0;
				}
			}
		}
		return 1;
	}

//print contact details.
//print currently saved contacts (from the linked list).
	void print_now()
	{
		cur = start;
		int c;
		cout<<"\tperson #"<<"----> NAME \tNUMBER   \tID  PROFESSION  PLACE"<<endl;
		for(c=1;cur->Link!= NULL;c++)
		{
		    cout<<"\tPerson "<<c<<"---->"<<cur->name<<"\t"<<cur->number<<"\t"<<cur->id_no<<"\t"<<cur->profession<<"\t"<<cur->place<<endl;
			cur = cur->Link;
		}
		    cout<<"\tPerson "<<c<<"---->"<<cur->name<<"\t"<<cur->number<<"\t"<<cur->id_no<<"\t"<<cur->profession<<"\t"<<cur->place<<endl;
	}

//print all the contacts(from the file directory).
	void print()
	{
		string s;
		myfile.open("Directory.txt", ios::in);
		if(myfile.fail())
		{
			cout<<"\tError in opening file"<<endl;
			return;
		}
		while(!myfile.eof())
		{
			myfile>>s;
			cout<<"\t"<<s<<"\n";
		}
		myfile.close();
	}

//delete contact details.
//deletes from the linked list.
    void Terminating_File(string n)
    {
        cur=start;
        if(start->name==n)
        {
            temp=start;
            start=start->Link;
            cout<<"\tNumber of "<<n<<" has been DELETED from your Directory.\n";
			delete temp;
        }
        else
        {
            while(cur->name!=n)
            {
                if(cur->Link==NULL)
                {
                    cout<<"\tCurrently the details of "<<n<<" Does NOT Exist"<<endl;
                    cout<<"\tTry to delete the contact from file."<<endl;
					return;
                }
                temp=cur;
                cur=cur->Link;
            }
            temp->Link=cur->Link;
            delete cur;
        }
    }
    
//delete data from file.
  void deleting()
{
    string line, Name, strName, tNumber;
    int nextLoc=0,flag=0;
    cout <<"\tPlease enter the Name of contact you want to Delete: ";
    cin>>strName;
    ifstream myfile;
    ofstream temp;
    myfile.open("Directory.txt");
    temp.open("temp.txt");
   
    while (!myfile.eof())
    {
    	getline (myfile,line);
    	nextLoc=line.find(" ");
	    Name=line.substr(0,nextLoc);
	    line = line.substr(nextLoc+1,line.length());
	   // nextLoc=line.find(" ");
	    tNumber = line;
	    if(!(Name==strName))
        	temp << Name <<" "<< tNumber<< endl;
        else 
        	flag++;  
    }
   if(flag==0)
   {
  	    cout<<"\n\tRecord NOT Found!!\n\n";
	    return;
   }
   cout << "\tThe record with the NAME '" << strName <<"' has been DELETED successfully." << endl;
   myfile.close();
   temp.close();
   remove("Directory.txt");
   rename("temp.txt", "Directory.txt");
   return;
}
};
//Class ends here.

//function to check the username and password (called by the main function)
int admin()
{       Directory ll;
        string eP;
        string eU;
        cout<<"\tEnter the Username:  ";
        cin>>eU;
        if(ll.compareAdmin(eU,"admin") == 1)
            {
                cout<<"\tEnter the Password:  ";
                 cin>>eP;
                 if(ll.comparePassword(eP,"1234") == 1)
                 {
                   return 1;       
                 }
            }
return 0;
}

//main function.
int main()
{
	Directory ll;          //defining object.
	int nooffile, i, p, ch;
	string n, nm, cnc,p1,pl;
//	string Username ="admin";
//	string Password="1234";
	cout<<"\n\t==================================================================================\n\n";
	cout<<"\t\t\t PHONE DIRECTORY SYSTEM\n";
	cout<<"\n\t==================================================================================\n\n";
    cout<<"\n\t1 CAN LOGIN AND SAVE NUMBERS\n";
    cout<<"\n\t2 CAN SEARCH AND UPDATE THE NUMBERS\n";
    cout<<"\n\t3 CAN DELETE A NUMBER FROM THE DIRECTORY\n";
    cout<<"\n\t4 CAN SEE ALL THE LIST ANY TIME\n";
    cout<<"\n\t==================================================================================\n\n";
    cout<<"\n";
	cout<<"\n\t==================================================================================\n\n";      
   
    //if userid and password are correct then procede further(in the admin mode)
    if(admin()==1)
    {
    	cout<<"\n\t==============================WELCOME TO USER MODE=================================\n\n";
    cout<<"\n\t===================================SAVE NUMBERS=====================================\n";
    cout<<"\tHow many numbers you want to save?\n\t";
    cin>>nooffile;            //no of files.
    
    //create/save data for each member. (function call pass data)
    for(i=1; i<=nooffile; i++)
    {
        cout<<"\n\tEnter Name ";
        cin>>n;
        cout<<"\n\tPhone Number ";
        cin>>nm;
        cout<<"\n\tEnter ID Number ";
        cin>>cnc;
        cout<<"\n\tProfession ";
        cin>>p1;
        cout<<"\n\tPlace ";
        cin>>pl;
        ll.create_file(n, nm, cnc,p1,pl);
        
    }
        // system("CLS");  for clearing screen.
    
    do
    {
        cout<<"\n\n\tWhat do you want to do with your saved record\n";
        cout<<"\n\t1. Save new phone number";
        cout<<"\n\t2. Delete any number";
        cout<<"\n\t3. Search and Modify";
        cout<<"\n\t4. See all list";
        cout<<"\n\t5. Delete number from file";
        cout<<"\n\t6. search name from directory";
		cout<<"\n\t7. EXIT\n";
        cout<<"\t";
        cout<<"\n\tEnter your choice of input: ";
        cin>>ch;
        
        // system("CLS");  for clearing screen.
        switch(ch)
        {
        case 1:
             cout<<"\n\t=========================== SAVE NEW NUMBER ======================================\n\n";
                    cout<<"\tEnter new contact's data\n";
                    cout<<"\n\tEnter Name: ";
                    cin>>n;
                    cout<<"\n\tPhone Number: ";
                    cin>>nm;
                    cout<<"\n\tEnter ID: ";
                    cin>>cnc;
                    cout<<"\n\tProfession: ";
                    cin>>p1;
                    cout<<"\n\tPlace: ";
                    cin>>pl;
                    ll.create_file(n, nm, cnc,p1,pl);
                    cout<<"\n\tNumber of "<<n<<" has been saved in your phone directory.\n";
            break;
        case 2:
            cout<<"\n\t=========================== DELETE CURRENTLY SAVED NUMBER ========================================\n\n";
            cout<<"\tEnter the name of the person whose number you want to delete\n";
            cout<<"\t";
            cin>>n;
            ll.Terminating_File(n);
            break;
        case 3:
            cout<<"\n\t======================== SEARCH AND UPDATE NUMBER ================================\n\n";
            ll.search();
            break;
        case 4:
            cout<<"\n\t============================= PRINTING WHOLE CONTACT LIST ==================================\n\n";
            ll.print();
            break;
        case 5:
        	cout<<"\n\t============================== DELETING RECORD FROM FILE ==================================\n\n";
            ll.deleting();
            break;
        case 6:
        	cout<<"\n\t============================== SEARCH RECORD FROM DIRECTORY ==================================\n\n";
            ll.search_file();
            break;    
        case 7:
            cout<<"\n\t========================== LIST OF NUMBERS ADDED NOW =============================\n\n";
            ll.print_now();
            break;
        default:
            cout<<"\t\t\tINVALID INPUT\t\t\t\n";
            cout<<"\t\t\tPLEASE TRY AGAIN\t\t\t\n";
        }
    }while(ch!=7);
    }
    
    //if the username and password are incorrect (in the user mode)
    else
    {do
    {
       cout<<"\n\tYou are not the Admin. So, you are in the user mode.";
       cout<<"\n\tWhat do you want to do with your saved record\n";
       cout<<"\n\t1. See all list";
       cout<<"\n\t2. search name from directory";
	   cout<<"\n\t3. EXIT\n";
       cout<<"\t";
       cout<<"\n\tEnter your choice of input: ";
       cin>>ch;
       switch(ch)
        { 
            case 1:
            cout<<"\n\t============================= PRINTING WHOLE CONTACT LIST ==================================\n\n";
            ll.print();
            break;
            case 2:
        	cout<<"\n\t============================== SEARCH RECORD FROM DIRECTORY ==================================\n\n";
            ll.search_file();
            break;   
            case 3:
            cout<<"\n\tYOU ARE EXITING THE WINDOW.\n";
            break;
            default:
            cout<<"\t\t\tINVALID INPUT\t\t\t\n";
            cout<<"\t\t\tPLEASE TRY AGAIN\t\t\t\n";
        }
    }
    while(ch!=3);
    }
    
    cout<<"\n\tTHANK YOU FOR USING\n";
    cout<<"\tHAVE A GOOD DAY";  
  
    getch();

    return 0;                                                         
}

