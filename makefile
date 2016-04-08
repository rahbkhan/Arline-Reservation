myAirLine.o: main.cpp airlineReservationList.cpp airlineReservationList.h
	c++ -o myAirLine.o main.cpp
	./myAirLine.o
clean:
	rm myAirLine.o
