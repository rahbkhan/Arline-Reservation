// airlineReservationList.cpp
// included from airlineReservationList.h
//#include "airlineReservationList.h"
#include <iostream>
using namespace std;


List::List()
{
	head = NULL;
	seatID = reservationID = pID = chickenAlfredo = potRoast = toFu = nothing = 0;

} // end of List constructor


void List::insertFront(string lastName,string firstName,string telephoneNumber, string seatNum, int passID,int rNumber, string mPreference)
{
	if( head == NULL ) // if the list is empty
	{
		head = new Reservation; // give head something to point to
		head->passengerLastName = lastName; // set the data
		head->passengerFirstName = firstName; // set the data
		head->telephoneNumber = telephoneNumber; // set the data
		head->seatNumber = seatNum; // set the data
		head->passengerID = passID; // set the data
		head->reservationNumber = rNumber; // set the data
		head->menuPreference = mPreference; // set the data
		head->next = NULL; // is only in list, nothing to point to

	} // end of if
	else // if the list is not empty
	{
		Reservation * temp = head; // head will change, save old
		head = new Reservation; // make head the new node
		head->passengerLastName = lastName; // set the data
		head->passengerFirstName = firstName; // set the data
		head->telephoneNumber = telephoneNumber; // set the data
		head->seatNumber = seatNum; // set the data
		head->passengerID = passID; // set the data
		head->reservationNumber = rNumber; // set the data
		head->menuPreference = mPreference; // set the data
		head->next = temp; // is only in list, nothing to point to
	} // end of else

} // end of insertFront(int)

void List::makeReservation()
{
	int passID,rNumber;
	string mPreference;
	string lastName, firstName, telephoneNumber;
	string seatNum= "bs";

	cout<<"What is your last name?";
	cin>> lastName;

	cout<<"What is your first name?";
	cin>>firstName;

	cout<<"What is your telephone number?";
	cin>>telephoneNumber;

	mPreference=foodMenu();//trying to obtain the selection that was chosen below and save it into MenuPreferences.

	pID++;
	passID=pID;

	reservationID++;
	rNumber=reservationID;//saving the ReservationNumber

	seatID++;
	ostringstream ostr;
	ostr << seatID;
	seatNum+= ostr.str();// attempting to convert seatID and append it to seatNum. Havent found a function that works yet.
	
	// in case the seat number is taken
	Reservation * temp = head;

/*	bool run = true;
	while(run) 
	{
		run = false;
 		seatID++;
        	ostringstream ostr;
        	ostr << seatID;
        	seatNum+= ostr.str();// attempting to convert seatID and append it to seatNum. Havent found a function$
		ostr.str("");
		while (temp != NULL)
		{
			if( temp->seatNumber == seatNum)
			seatNum = 'bs';
			run = true;
		} // end of while
	} // end of while
*/

	insertMid(lastName,firstName,telephoneNumber, seatNum, passID,rNumber,mPreference);

}

void List::insertBack(string lastName,string firstName,string telephoneNumber, string seatNum, int passID,int rNumber, string mPreference)
{
	Reservation * temp = head; //so we don't have to change head

	if( temp == NULL ) // if the list is empty
        {
                head = new Reservation; // give head something to point to
                head->passengerLastName = lastName; // set the data
                head->passengerFirstName = firstName; // set the data
                head->telephoneNumber = telephoneNumber; // set the data
                head->seatNumber = seatNum; // set the data
                head->passengerID = passID; // set the data
                head->reservationNumber = rNumber; // set the data
                head->menuPreference = mPreference; // set the data
                head->next = NULL; // is only in list, nothing to point to

        } // end of if
        else // if the list is not empty
        {

		while(temp->next != NULL) // while the node points to a node
			temp = temp->next; // change the pointer to the next node

	// create the new node

		temp->next = new Reservation; // change the last values next to new node
		temp = temp->next; // change temp to the new nodes addr
		temp->passengerLastName = lastName; // set the data
		temp->passengerFirstName = firstName; // set the data
		temp->telephoneNumber = telephoneNumber; // set the data
		temp->seatNumber = seatNum; // set the data
		temp->passengerID = passID; // set the data
		temp->reservationNumber = rNumber; // set the data
		temp->menuPreference = mPreference; // set the data
		temp->next = NULL; // is only in list, nothing to point to


        } // end of else

} // end of insertBack(int)


void List::insertMid(string lastName,string firstName,string telephoneNumber, string seatNum, int passID,int rNumber, string mPreference)
{
	Reservation * prev, * cur;



	if(head == NULL) // if the list is empty
	{
			insertFront(lastName,firstName,telephoneNumber, seatNum, passID,rNumber,mPreference); // have insertFront(int) deal with it
		
	} // end of if

	else // if the list isnt empty
	{
		if( lastName.compare(head->passengerLastName) <= 0)
		{
			cout << lastName << " is lower than" << head->passengerLastName << endl;
			insertFront(lastName,firstName,telephoneNumber, seatNum, passID,rNumber,mPreference);
		}
		else
		{
		cur = head;

		while( cur != NULL && lastName.compare(cur->passengerLastName) >= 0 ) // to find the position to insert, find the position with a larger value
		{
			prev = cur;
			cur = cur->next;

		} // end of while

	   // create the new reservation, set it to the next of the pointer the prev points to
		prev->next = new Reservation;

		(prev->next)->passengerLastName = lastName; // set the data
                (prev->next)->passengerFirstName = firstName; // set the data
                (prev->next)->telephoneNumber = telephoneNumber; // set the data
                (prev->next)->seatNumber = seatNum; // set the data
                (prev->next)->passengerID = passID; // set the data
                (prev->next)->reservationNumber = rNumber; // set the data
                (prev->next)->menuPreference = mPreference; // set the data

		(prev->next)->next = cur; // set the new nodes next to prev's old pointer

		} // end of else
	} // end of else

} // end of insertMid()

void List::printList()
{
	Reservation * temp = head; // get the starting location

	while( temp != NULL)
	{
		cout <<"Name: "<< temp->passengerFirstName << " ";
		cout << temp->passengerLastName << " "<<endl;
		cout << "PassengerID: "<<temp->passengerID << " "<<endl;
		cout << "Reservation #: "<< temp->reservationNumber << " "<<endl;
		cout << "Telephone # "<<temp->telephoneNumber << " "<<endl;
		cout << "Seat Number: "<<temp->seatNumber << " "<<endl;
		cout << "Menu Selection: "<<temp->menuPreference << " "<<endl;
		temp = temp->next;

	} // end of while

	cout << endl;

} // end of printList()

bool List::searchForPassenger()
{
	cout << "Enter the reservation number you want to search for: " ;
	int key;
	cin >> key;

	Reservation * temp = head; // starting location
	while ( temp != NULL ) // to move until the end
	{
		if( temp->reservationNumber == key) // found
			return true;
		else // move pointer to next node
			temp = temp->next;
	 }// end of while

  // if we get here, it wasnt found
	return false;
} // end of searchForPassenger(int)

bool List::cancelReservation()
{
	int reservationDel;
	cout << "Enter the reservation number you want to cancel: " ;
	cin >> reservationDel;

		if( head->reservationNumber == reservationDel ) // if it is the head
		{
			Reservation *newHead = head->next; // copy the address of next
			head->next = NULL; // for safety
			delete head; // remove the head
			head = newHead; // change head to the next one
			return true;
		} // end of if head
		else // if not the head
		{
			Reservation *prev = head, *cur = prev->next; // pointer to beginning and second in list

			while ( cur != NULL ) // to move until the end
		        {
                		if( cur->reservationNumber == reservationID) // found
                        	{
					prev->next = cur->next; // logical remove
					cur->next = NULL; //safety
					delete cur; //physical remove
					return true;
				} // end of if found
                		else // move pointer to next node
				{
                        		prev = cur;
					cur = cur->next;
				} // end of else not found
         		}// end of while


		} // end else not head

		return false;
}// end of cancelReservation(int)

	int List::mainMenu()
	{
		char choice;

		cout<< "**********Menu**********\n";
		cout<< "1. Make Reservation\n";
		cout<< "2. Cancel Reservation\n";
		cout<< "3. Show List\n";
		cout<< "4. Search for passengers\n";
		cout<< "5. Menu report\n";
		cout<< "6. Change reservation\n";
		cout<< "7. Exit\n";

		cin>> choice;

		return choice;

	}

	string List::foodMenu()// simple food menu.
	{
		string foodChoice;
		char selection;
		cout<< "************Food Menu**************\n";
		cout<< "1. Chicken alfredo with garlic bread.\n";
		cout<< "2. Pot roast with veggies and white rice.\n";
		cout<< "3. Tofu burgers with fries.\n";
		cout<< "4. No thank you, no food please.\n";

		cout << "Enter a menu number: ";
		cin>> selection;

		switch(selection)//selection increments which selection that you choose for later reports.
			{
			case '1': chickenAlfredo++;
			foodChoice="Chicken alfredo with garlic bread.\n";
								break;
			case '2': potRoast++;
			foodChoice="Pot roast with veggies and white rice.\n";
								break;
			case '3': toFu++;
			foodChoice="Tofu burgers with fries.\n";
								break;
			case '4': nothing++;
			foodChoice="No thank you, no food please.\n";
								break;
			default: cerr<< "invalid choice!!!\n"<< endl;
					foodMenu();
					break;
			}
		cout << endl;
		return foodChoice;
	}

void List::menuReport()
{
	cout<< chickenAlfredo<< " People/person ordered Chicken alfredo.\n";
	cout<< potRoast<< " People/person ordered Pot Roast.\n";
	cout<< toFu<< " People/person ordered toFu.\n";
	cout<< nothing<< " People/person wanted nothing at all.\n\n";
}

bool List::changeReservation()
{
	int reservationID;
	cout <<"Enter the reservation number to be changed.";
	cin >> reservationID;

	Reservation * temp = head;
	while( temp != NULL && temp->reservationNumber != reservationID)
	{
		temp = temp-> next;
	}

	if( temp == NULL)
		return false;

	char selection = 'f';

	while( selection != '6' )
	{

		cout<< "**********Menu**********\n";
                cout<< "1. Change Last Name\n";
                cout<< "2. Change First Name\n";
                cout<< "3. Change Seat Number\n";
                cout<< "4. Change Menu Preference\n";
                cout<< "5. Change Telephone Number\n";
                cout<< "6. Exit\n";

		char choice;
                cin>> choice;

		switch(choice)
		{
			case '1': 
			{
				cout << "Enter the new last name: ";
				string newLast;
				cin >> newLast;
				temp->passengerLastName = newLast;
				break;
			}
			case '2':
			{ 
				cout<< "Enter the new first name: ";
				string newFirst;
				cin >>newFirst;
				temp->passengerFirstName = newFirst;
				break;
			}
			case '3':
			{
				 cout <<"Enter the new seat number: ";
				string newSeat;
				cin >> newSeat;
				
				while(temp!= NULL)
				{
					if(temp -> seatNumber == newSeat)
					{
						cout << "The seat is already in use.";
						break;
					}
					temp = temp->next;
				}
				temp->seatNumber = newSeat;
			
				break;
			}
			case '4':
			{
				 if( temp->menuPreference == "Chicken alfredo with garlic bread.\n")
					chickenAlfredo--;
				 else if( temp-> menuPreference == "Pot roast with veggies and white rice.\n")
					potRoast--;
				 else if(temp-> menuPreference == "Tofu burgers with fries.\n")
					toFu--;
				 else
					nothing--;
				string newFood = foodMenu();
				temp->menuPreference = newFood;
				break;
			}
			case '5':
			{
				 cout <<"Enter the new telephone number: ";
				 string newPhone;
				 cin >> newPhone;
				 temp->telephoneNumber = newPhone;
				 break;
			}

		default: cerr<< "Invalid Choice!!\n" << endl; break;
		} // end of switch
	} // end of while 


} // end of change reservation
