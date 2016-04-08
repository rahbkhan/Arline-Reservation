#include "airlineReservationList.h"
#include <iostream>
using namespace std;

int main()
{
	List bluesky;
	char choice;
	int done=0;
	string lastName, firstName, telephoneNumber,seatNumber;
	int passengerID, reservationNumber,menuPreference;


	while(!done)
	{
		cout << endl;
		choice= bluesky.mainMenu();

		switch(choice)
	{
	case '1': bluesky.makeReservation();
				break;
	case '2': if(bluesky.cancelReservation())
			cout << "The reservation was canceled." << endl;
		  else
			cout << "The reservation id did not exist." << endl;
				break;
	case '3': bluesky.printList();
				break;
	case '4': if(bluesky.searchForPassenger())
			cout << "The reservation was found." << endl;
		  else
			cout << "The reservation was not found." << endl;
				break;
	case '5': bluesky.menuReport();
				break;
	case '6': bluesky.changeReservation();
				break;
	case '7': cout<<"Thank You for using the Reservation System!!!!\n";
			done=1;
			break;
	default: cerr<< "invalid choice!!!!\n"<< endl;

	cin.get();
	}
	}


return 0;

}
