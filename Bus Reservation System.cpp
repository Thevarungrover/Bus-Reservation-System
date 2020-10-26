#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<cstdlib>
using namespace std;

static int p = 0;
int totalseat = 32; // toatal number of seats in a bus

// PARENT CLASS
class a{
		char busn[5]; // bus number
		char driver[10]; // driver name
		char depart[5]; // departure time
		char arrival[5]; // arrival time
		char from[10]; // travelling from
		char to[10]; // travelling to
		char seat[8][4][10]; // seat number 
	
	public :
		void install(); // add bus and driver info
		void allotment(); // to reserve seat
		void empty(); // to save empty seats in newly added bus
		void show(); // to show info and seats available of a bus
		void avail(); // to show availability of buses
		void position(int i); // to set positions
}

bus[10];

// to draw line
void vline(char ch){
	for(int i = 80;i>0;i--)
	{
		cout<<ch;
	}
}

// entering bus and driver info
void a :: install(){
	cout<<"\nEnter Bus no : ";
	cin>>bus[p].busn;
	cout<<"\nEnter driver's name : ";
	cin>>bus[p].driver;
	cout<<"\nArrival Time : ";
	cin>>bus[p].arrival;
	cout<<"\nDeparture Time : ";
	cin>>bus[p].depart;
	cout<<"\nFrom : ";
	cin>>bus[p].from;
	cout<<"\nTo : ";
	cin>>bus[p].to;

	bus[p].empty();
	p++;
}

// to reserve seat
void a :: allotment()
{
	int seat;
	char number[5];
	top: // label
	cout<<"\nBus no : ";
	cin>>number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number) == 0)
		break;
	}
	
	while(n<=p)
	{
		cout<<"\nSeat number : ";
		cin>>seat;
		if(seat > totalseat)
		{
			cout<<"\nThere are only "<<totalseat<<" seats available in this bus.";	
		}
		else
		{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1] , "Empty") == 0)
			{
				cout<<"\nEnter Passanger's Name : ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
				cout<<"\nThe seat no. "<<seat<<" is already reserved.";
		}
	}
	
	if(n > p)
	{
		cout<<"\nEnter correct bus no. again !! ";
		goto top;
	}
}

void a :: empty(){
	for(int i = 0;i < 8; i++)
	{
		for(int j = 0;j < 4;j++)
		{
			strcpy(bus[p].seat[i][j] , "Empty");
		}
	}
}

// to show info and seats available of a bus
void a :: show(){
	int n;
	char number[5];
	cout<<"\nEnter Bus no. : ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number) == 0)
		break;
	}
	
		while(n<=p)
		{
			vline('*'); // draw '*'
			
			cout<<"\n\nBus no : \t"<<bus[n].busn
			<<"\nDriver : \t"<<bus[n].driver<<"\t\tArrival time : \t"<<bus[n].arrival
			<<"\tDeparture time : "<<bus[n].depart
			<<"\nFrom : \t\t"<<bus[n].from<<"\t\tTo : "<<bus[n].to<<endl;
			
			vline('*'); // draw '*'
			
			bus[0].position(n);
			int a=1;
			for(int i=0;i<8;i++)
			{
				for(int j = 0;j<4;j++)
				{
					a++;
					
					if(strcmp(bus[n].seat[i][j],"Empty") != 0)
					{
						cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";			
					}
				}
			}
			break;
		}
		if(n>p)
		{
			cout<<"\nEnter correct bus no : ";
		}
	}

// to set positions
void a :: position(int i){
	int s=0;p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
    for (int j = 0;j<4; j++)
    {
		s++;
		if(strcmp(bus[i].seat[i][j] , "Empty") == 0)
		{
			cout.width(5);
			cout.fill(' ');
			cout<<s<<".";
			cout.width(10);
			cout.fill(' ');
			cout<<bus[i].seat[i][j];
			
			p++;
		}
		else
		{
			cout.width(5);
			cout.fill(' ');
			cout<<s<<".";
			cout.width(10);
			cout.fill(' ');
			cout<<bus[i].seat[i][j];
		}
	}
}
	cout<<"\n\nThere are "<<p<<" seats empty in Bus no : "<<bus[i].busn;
}

// to show availability of buses
void a :: avail(){
	for(int n = 0;n<p;n++)
	{
		vline('*'); // draw '*'
		cout<<"\n";
		cout<<"\nBus no : \t"<<bus[n].busn<<"\nDriver : \t"<<
		bus[n].driver<<"\t\tArrival Time : \t"<<bus[n].arrival<<"\tDeparture Time : \t"
		<<bus[n].depart<<"\nFrom : \t\t"<<bus[n].from<<"\t\tTo : \t\t\t"
		<<bus[n].to<<"\n";
		vline('*'); // draw '*'
		cout<<"\n";
		vline('_'); // draw '_'
	}
}

// main function
int main(){
	int w;
	while(1)
	{
		// MENU
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t1.Install";
		cout<<"\n\t\t\t2.Reservation";
		cout<<"\n\t\t\t3.Show";
		cout<<"\n\t\t\t4.Buses Available";
		cout<<"\n\t\t\t5.Exit";
		cout<<"\n\t\t\tEnter your choice :";
		cin>>w;
		
		switch(w)
		{
			case 1 : bus[p].install();
				break;
			case 2 : bus[p].allotment(); // to reserve seat
				break;
			case 3 : bus[p].show(); 
				break;
			case 4 : bus[p].avail(); // to show availability of buses
				break;
			case 5 : exit(0);
				break;
			default : cout<<"\nINVALID CHOICE!! ENTER CHOICE AGAIN..";
				main();
		}
	}
	return 0;
}


