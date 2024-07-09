NAFS (NUCES Airline Flight System)

Project Description:
NAFS (NUCES Airline Flight System) is a C++ console application that simulates an airline reservation system. It allows users to book flights, cancel bookings, and view flight information. The system includes both passenger and admin panels for handling different functionalities.

Features:
User Registration and Login: Passengers can register and log in using a username and password.
Flight Booking: Passengers can book flights and receive ticket information.
Flight Cancellation: Passengers can cancel bookings and receive refunds.
Flight Information: Passengers can view flight schedules and details.
Admin Panel: Admins can log in to manage flights and view flight schedules.

Classes and Key Functions:

Person Class
	Constructors: Default, parameterized, and copy constructors.
	Member Functions: Getters and setters for name and id.

PassengerPanel Class (Inherits Person)
	Constructors: Default, parameterized, and copy constructors.

	Member Functions:
	registrationValidation(): Handles user registration.
	loginValidation(): Handles user login.
	displayTicketInfo(string flightNum, string seatNum): Displays ticket information.
	cancelBooking(string flightNum): Cancels a booking and provides a refund.
	displayFlightInfo(string flightNum): Displays information about a specific flight.

AdminPanel Class (Inherits Person)
	Constructors: Default, parameterized, and copy constructors.

	Member Functions:
	loginValidation(): Handles admin login.
	searchIndex(string flightNo): Searches for a flight in the flight list.
	displayFlightSchedule(): Displays the flight schedule.

Usage:

Passenger Registration and Login:
	Run the program and select the option to register as a new passenger.
	Enter the required details (username, password, CNIC, age).
	Log in using the registered credentials.

Flight Booking:
	After logging in, select the option to book a flight.
	Choose a flight from the available options and select a seat.
	Confirm the booking to receive the ticket information.

Flight Cancellation:
	After logging in, select the option to cancel a booking.
	Enter the flight number to cancel the booking and receive a refund.

Viewing Flight Information:
	After logging in, select the option to view flight information.
	Enter the flight number to view detailed information about the flight.

Admin Panel:
	Log in as an admin using the admin credentials.
	Manage flights and view the flight schedule.

Contributing:
Contributions are welcome! Please follow these steps:
	Fork the repository.
	Create a new branch (git checkout -b feature-branch).
	Commit your changes (git commit -m 'Add some feature').
	Push to the branch (git push origin feature-branch).
	Open a pull request.

Acknowledgments:
This project was developed as part of a software engineering course at FAST National University of Computer and Emerging Sciences.
Special thanks to the course instructor and teaching assistants for their support and guidance.