#include<iostream>
//#include<cstring>
#include<fstream>
#include <sstream> 
#include <string.h>
//#include <cstdlib>
#include <ctime>

using namespace std;
char savl[10][20];			
class passenger
{public: 
    static int n;
    static string traveldate;
//static int np; // no of passengers
	int i;								
	int choice;
	static int age[5];
	char fname[5][20];
	char lname[5][20];
	double phoneno;
    static char gender[5][20];
	
	virtual void getdata()
	{cout<<"Enter the total number of passengers : ";
	cin>>n;
	cout<< endl;

	for(i=1;i<=n;i++)
	{
		cout<<"Passenger Details"<<endl;
		cout<<"Enter the first name of Passenger " << i <<" : " ;
		cin>>fname[i];
		cout<< endl;
		cout<<"Enter the last name of Passenger "<< i << " : ";
		cin>>lname[i];
		cout<< endl;

		cout<<"Enter gender of passenger "<< i << " (M/F) : ";
		cin>>gender[i];
		cout<< endl;
		cout<<"Enter age of Passenger " << i << " : ";
		cin>>age[i];
		cout<< endl;
	}
	
	}
	
	};
	int passenger::age[5];
	char passenger::gender[5][20];
	int passenger::n;
	string passenger::traveldate;
	class airlines
	{ public:
		int choice;
		string airline;
		void air_data()
		{
		cout<<"choice of your airline"<<endl;
		cout<< endl;
		cout<<"1:  Indian Airlines"<<endl;
		cout<<"2:  Jetairways"<<endl;
		cout<<"3:  Indigo"<<endl;
		cout<<"4:  Spicejet"<<endl;
		cout<<"5:  Airasia"<<endl;
		cout<<"6:  Air India"<<endl;
		cout<<"7:  Singapore Airlines"<<endl;
		cout<<"8:  Arab Emirates"<<endl;
		cout<<"9:  Luftansa"<<endl;
		cout<<"10: British Airways"<<endl;
		cout<< endl;
		cout<<"Enter your choice ....: ";
		cin>>choice; // choice of airline
		cout<< endl;
		system("cls");
		switch(choice)
		{
			case 1:
			airline = "Indian Airlines";
		break;
			case 2:
			airline = "Jetairways";
		break;
		case 3:
			airline = "Indigo";
		break;
		case 4:
			airline = "Spicejet";
		break;
		case 5:
			airline = "Airasia";
		break;
		case 6:
			airline = "Air India";
		break;
		case 7:
			airline = "Singapore Airlines";
		break;
		case 8:
			airline = "Arabemirates";
		break;
		case 9:
			airline = "Luftanza";
		break;
		case 10:
			airline ="British Airways";
		break;
		}
		cout<< "Welcome to "<<airline<<endl;	
		cout<<endl;	
	}
	};
class places
{private:
	string data;
public:
	int opt;
	int optd;
	int opta;
	string pdep, parr, deparr;
	void select()
	{cout<<"Choose the places to travel Departure aand later Arrival...."<<endl;
	cout<< endl;
	
	ifstream infile; 
    infile.open("place.txt");
	infile.seekg(0);
// departure place selection 
    for(int i=1;i<10;i++)
    {
//cout << "Reading from the file" << endl; 
		getline(infile,data);
		      	cout << i << ":  " << data << "\n" ;

	}
//	infile.close();

	cout<<"Enter your choice of DEPARTURE .... : ";
	cin>>optd; 
	cout<< endl;
	infile.seekg(0);
	
// arrival place selection
for(int i=1;i<10;i++)
    {

      getline(infile,data);
      cout << i << ":  " << data << "\n" ;

	}
//    infile.close();
    opta = optd;
	cout<<"Enter your choice of ARRIVAL.... : ";
	cin>>opta; 
	while (opta == optd)
	{
		cout <<endl << "ARRIVAL CANNOT BE SAME AS DEPARTURE..." << endl;
		cout<<"Re-enter your choice of ARRIVAL.... : ";
	    cin>>opta; 
	}
	cout<< endl;
	
	infile.seekg(0);
// Save departure place opted		
	for(int i=1;i<optd;i++)
    {

      getline(infile,data);
//      cout << "" << data << "\n" ; // uncomment this line for checking

	}
    getline(infile,pdep);
    
    infile.seekg(0);
//    cout << " Option Dep is " << optd << endl;
//    cout << " Option Arr is " << opta << endl;
// Save arrival place opted		
	for(int i=1;i<opta;i++)
    {

      getline(infile,data);
//      cout << "" << data << "\n" ; // uncomment this line for checking

	}
    getline(infile,parr);
    infile.close();
    deparr = pdep + " to " + parr;
//    cout << "test    deprr is " << deparr << endl ;
    
    opt = 10*optd + opta;
//    cout << "opt from file is " << opt << endl;
    
    cout << "Your travel is from " << pdep << "  to  " << parr  << endl;
    }
};
class payment:public passenger,public airlines,public places
{
	private:
	int tamt;
	float tax;
	float totalcost;
	string data1;
	public:
	
	void setcost()
	{
	tax=20;
	ifstream infile; 
    infile.open("basefare1.txt");
	infile.seekg(0);
	for(int i=1;i<opt;i++)
    {

      getline(infile,data1);
//      cout << "" << data << "\n" ; // comment this line

	}
    getline(infile,data1);
    infile.close();
    cout << "Basic cost per passenger is ..." << data1 << endl;
    stringstream ss(data1);
    ss >> tamt;

	} 
	
	
		void display()
		{
		  // current date/time based on current system
   		time_t now = time(0);
   
   		// convert now to string form
   		char* dt = ctime(&now);

//   		cout << "The local date and time is: " << dt << endl;
		cout<< endl;
		cout << "*******************************************************"<<endl;
		cout << "Welcome to "<< airline << endl;
		cout <<endl;
		cout << "Number of Passengers travelling ..." << n << endl;
		cout << "-------------------------------------------------------" << endl;
		for (i=1;i<=n;i++)
		{
		cout << "Passanger"<<i <<" : " << fname[i] <<"  " << lname [i]<< "\t  Gender : "<< gender[i]<<"\tAge :"<< age[i]<<endl;
	    } 
	    cout << "-------------------------------------------------------" << endl;
	    cout << endl;
		cout << "Your Journey is from " << deparr << endl;
		cout << "Your travel date is : " << traveldate << endl ;
//        cout << " Your confirmed seat number is " << col << row << endl;
        cout << "Your baggage allowance is 40Kgs" << endl;
        cout << "Ticket booked on : " << dt << endl;
        cout << endl;
        string data2;
		ifstream fin; 
    	fin.open("tcost1.txt");
    	fin.seekg(0);
    	getline(fin,data2);	
		cout<<" Total Amount to be paid is  "<<data2<<"\n";
		cout<<endl;
        cout << "-------------------------------------------------------"<<endl;
        cout << airline <<" Wishes you a Happy Journey" << endl;
        cout << "-------------------------------------------------------"<<endl;
        cout << endl;
        cout << "*******************************************************"<<endl;
    	}		
	
		friend void cost(payment p);   
};
	void cost(payment p)
	{
	ofstream fout; 
    fout.open("tcost1.txt");
	p.totalcost = p.n*p.tamt*(1+ p.tax/100); // total fare includes taxes..
//	cout<<" Total cost including tax = "<< p.totalcost;
	fout << p.totalcost;
	cout<< endl; 
	fout.close();
	}

    void cost()
	{
	string data2;
	ifstream fin; 
    fin.open("tcost1.txt");
    fin.seekg(0);
    getline(fin,data2);	
	cout<<" Total cost including tax = "<<data2<<"\n";
	cout<<endl;
	}
	class date:public passenger
	{public:
//		string traveldate;
		int day;
	    int month;
	    int year;
		
		void getdata()
		{
		cout<<"Enter your Phone Number : ";
		cin>>phoneno; 
		cout<< endl;
	    //while(phoneno<10 || phoneno > 99)
        while(phoneno<1000000000 || phoneno > 9999999999)
		{
		cout<<"Invalid...Renter a 10 digit Phone Number : ";
		cin>>phoneno;
		cout<<endl;
		}	
		cout<<"Enter the date of travel .... "<<"\n" << endl;
		
		cout<<"Enter day (dd) : " ;
		cin>>day;
		while(day<1 || day > 31)
		{
		cout<<"Invalid...Renter valid dd 01 to 31 : ";
		cin>>day;
		cout<<endl;
		}	
		cout<<"Enter month (mm) : ";
		cin>>month;
		while(month<1 || month > 12)
		{
		cout<<"Invalid...Renter valid mm 01 to 12 : ";
		cin>> month;
		cout<<endl;
		}	
		cout<<"Enter year (yyyy) :  ";
		cin>>year;
		while(year<2018 || year > 2020)
		{
		cout<<"Invalid...Renter valid yyyy 2018 to 2020 : ";
		cin>>year;
		cout<<endl;
		}	
		}
		void display()
		{
//			int a = 10;
//			char *intStr = itoa(a);
//			string str = string(intStr);
//			char *intstr = itoa(a);
			stringstream sd;
			sd << day;
			string strd = sd.str();
//			traveldate = strd;
			stringstream sm;
			sm << month;
			string strm = sm.str();
//			traveldate += ":" + str;
			stringstream sy;
			sy << year;
			string stry = sy.str();
			traveldate = strd+":" + strm +":" + stry;
			cout << "Your traveldate ... : " <<traveldate << endl;
			cout << "----------------------------------"<< endl;
			
		}
	};

	class seat
	{
		private:
			int row;
			char col;//columns A to F
			int c,r;
			int sno;
			public:
				void seat_sel()
				{ c=0;
				  r=1;
					while (c==0)
					{
					cout<<"enter the column of your seat (A to F) : ";
					cin>>col;
					cout<<endl;
					if(col=='A' || col=='a')
						c=1;
					else if(col=='B' || col=='b')
						c=2;
					else if(col=='C' || col=='c')
						c=3;
					else if(col=='D' || col=='d')
						c=4;
					else if(col=='E' || col=='e')
						c=5;
					else if(col=='F' || col=='f')
						c=6;
					else
					    {
						c=0;
						cout<<"Invalid option...please try again :-)  ";
						cout<< endl;
						}
					}
					
					cout<<"Enter row of your seat (1 to 10 )  : ";
					cin>>row;
					cout<<endl;	
					if (savl[c][row] == 'N')
					{
					cout<< "Selected seat already occupied ... please change selection..."<< endl;
					seat_sel();
					}
					else
				    {
					cout<<"Your Selected seat is  " <<col<<row;
					cout<< endl;
					}
				}	
				
				
	};
		

int main()
{	
for (int i=1;i<=5;i++)
		{
		for (int j=1;j<=6;j++)
			{
			savl[j][2*i-1]='N';
			savl[j][2*i]='Y';	
			}
		} 
  				
payment p;
p.getdata();
passenger *ptr;
    date d;
    ptr = &d;
     
    //virtual function, binded at runtime
    ptr->getdata();
    d.display();
p.air_data();
p.select();
p.setcost();
cost(p);
cost();

seat s;
s.seat_sel();
p.display();

}


