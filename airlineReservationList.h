// airlineReservationList.h
// included in main

#ifndef airlineReservationList_h_
#define airlineReservationList_h

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Reservation
{
	string passengerFirstName;
	string passengerLastName;
	int passengerID;
	int reservationNumber;
	string telephoneNumber;
	string seatNumber;
	string menuPreference;

	Reservation * next; //pointer to the next node in the list

}; // end of node struct

class List
{
	Reservation * head; // the beginning of the list
	int seatID, reservationID;
	int chickenAlfredo, potRoast, toFu, nothing;
	int selection;
	int pID;

  public:
	// combine these to make the enterReservation()
	void insertFront(string,string,string,string,int, int, string); // put a node at the front of the list
	void insertBack(string,string,string,string,int, int, string); // put a node at the back of the list
	void insertMid(string,string,string,string,int, int, string); // put a node in the middle of the list

	// actual functions
	List(); // constructor that defaults head to NULL;

	void enterReservation(); // basically the insert function
	void printList(); // print from the head until Null pointer
	void printMenuReport(); // list of what passengers had which menu option?
	void makeReservation();// Collects data from the user
	void menuReport();
	int mainMenu(); // to get the menu preference, returns the preference number
	string foodMenu();
	bool searchForPassenger(); // searches the list for the accepted passengerID
	bool cancelReservation(); // deletes the reservation with the accepted passengerID
	bool changeReservation(); // modifies the seat number and/or menu preference
	int menuPreference(int);
}; // end of list class



#include "airlineReservationList.cpp"

#endif
