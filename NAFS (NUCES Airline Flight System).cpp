// Abdullah_Daoud_22I-2626_SE-E	

// All necessary header files

# include <iostream>
# include <Windows.h>
# include <conio.h>
# include <string>
# include <fstream>
# include <iomanip>

using namespace std;

const int ROWS = 50;
const int COLS = 10;
const int ROWS1 = 50;
const int COLS1 = 10;
const int COLS2 = 10;

int globalCount = 0;

// Dynamic Arrays to store Flight and Seat Information
string*** seatList;
string** flightList;

class Person
{
private:
	string name;
	string id;

public:

	// Default / Parameterized / Copy Constructors

	Person()
	{
		name = "";
		id = "";
	}
	Person(string name, string id)
	{
		this->name = name;
		this->id = id;
	}
	Person(const Person& obj)
	{
		name = obj.name;
		id = obj.id;
	}

	// Getters and Setters

	void setName(string name)
	{
		this->name = name;
	}
	void setId(string id)
	{
		this->id = id;
	}
	string getName()
	{
		return name;
	}
	string getId()
	{
		return id;
	}
};

class PassengerPanel : public Person			// Inheritance between PassengerPanel and Person
{
private:
	string username;
	string password1;
	string password2;

public:

	// Default / Parametrized / Copy Constructors

	PassengerPanel()
	{
		username = "";
		password1 = "";
		password2 = "";
	}
	PassengerPanel(string username, string password1, string password2)
	{
		this->username = username;
		this->password1 = password1;
		this->password2 = password2;
	}
	PassengerPanel(const PassengerPanel& obj)
	{
		username = obj.username;
		password1 = obj.password1;
	}

	// Getters and Setters

	void setUsername(string username)
	{
		this->username = username;
	}
	void setPassword1(string password)
	{
		this->password1 = password;
	}
	void setPassword2(string password)
	{
		this->password2 = password;
	}
	string getUsername()
	{
		return username;
	}
	string getPassword1()
	{
		return password1;
	}
	string getPassword2()
	{
		return password2;
	}

	// Member Functions

	void registrationValidation()
	{
		char ch1, ch2;

		cout << " Enter your Username: ";
		cin >> username;

		cout << " Enter your Password: ";

		while ((ch1 = _getch()) != '\r')				// read characters until user presses enter key
		{
			if (ch1 == '\b')							// if backspace key is pressed, remove the last character from password string
			{
				if (!password1.empty())
				{
					password1.pop_back();
					cout << "\b \b";					// remove asterisk from console
				}
			}
			else if (isalnum(ch1) || ispunct(ch1))		// if alphanumeric or special character is pressed, add it to password string
			{
				password1.push_back(ch1);
				cout << "*";							// print asterisk to console
			}
		}

		cout << "\n Re-enter your Password: ";

		while ((ch2 = _getch()) != '\r')
		{
			if (ch2 == '\b')
			{
				if (!password2.empty())
				{
					password2.pop_back();
					cout << "\b \b";
				}
			}
			else if (isalnum(ch2) || ispunct(ch2))
			{
				password2.push_back(ch2);
				cout << "*";
			}
		}

		cout << "\n\n";

		string cnic;

	CNIC:

		cout << " Enter your CNIC: ";
		cin >> cnic;

		if (cnic.length() == 13)
		{
			cout << " Valid CNIC! \n\n";
		}
		else
		{
			cout << "\n Invalid CNIC, Try Again! \n\n";

			goto CNIC;
		}


		int age = 0;

		cout << " Enter your Age: ";
		cin >> age;

		cout << "\n\n";

		cout << " Your Account has been Created! \n\n";

	}

	bool loginValidation()
	{
		char ch1, ch2;

		cout << " Enter your Username: ";
		cin >> username;

		cout << " Enter your Password: ";

		while ((ch1 = _getch()) != '\r')				// read characters until user presses enter key
		{
			if (ch1 == '\b')							// if backspace key is pressed, remove the last character from password string
			{
				if (!password1.empty())
				{
					password1.pop_back();
					cout << "\b \b";					// remove asterisk from console
				}
			}
			else if (isalnum(ch1) || ispunct(ch1))		// if alphanumeric or special character is pressed, add it to password string
			{
				password1.push_back(ch1);
				cout << "*";							// print asterisk to console
			}
		}

		cout << "\n Re-enter your Password: ";

		while ((ch2 = _getch()) != '\r')
		{
			if (ch2 == '\b')
			{
				if (!password2.empty())
				{
					password2.pop_back();
					cout << "\b \b";
				}
			}
			else if (isalnum(ch2) || ispunct(ch2))
			{
				password2.push_back(ch2);
				cout << "*";
			}
		}

		try
		{
			if ((username != "username") || (password1 != "UserName@123") || (password2 != "UserName@123")) 		// Applied Exception Handling and Hardcoded necessary requirements
			{
				throw " Invalid username or password, Try Again!";
			}

			cout << "\n Login successful! \n\n";
			return true;
		}
		catch (const char* msg)
		{
			cout << "\n" << msg << "\n\n";
			return false;
		}
	}

	// Function to Display Ticket Information after Booking

	void displayTicketInfo(string flightNum, string seatNum)
	{
		cout << " ---------- Ticket Information ---------- \n\n";
		cout << " Name: username \n";
		cout << " Flight No: " << flightNum << endl;
		cout << " Seat No: " << seatNum << endl;

		if (flightNum == "101" || flightNum == "102" || flightNum == "103")
		{
			cout << " Total Amount Deducted with Tax: " << float((0.05 * 10000) + 10000) << " PKR \n\n";
		}
		else if (flightNum == "104" || flightNum == "105" || flightNum == "106")
		{
			cout << " Total Amount Deducted with Tax: " << float((0.1 * 20000) + 20000) << " PKR \n\n";
		}
	}

	// Function to Cancel Booking

	void cancelBooking(string flightNum)
	{
		if (flightNum == "101" || flightNum == "102" || flightNum == "103")
		{
			cout << " Your booking has been cancelled! \n\n";
			cout << " Your Refunded Amount: " << float(10000 - (10000 * 0.25)) << " PKR \n\n";
		}
		else if (flightNum == "104" || flightNum == "105" || flightNum == "106")
		{
			cout << " Your booking has been cancelled! \n\n";
			cout << " Your Refunded Amount: " << float(20000 - (20000 * 0.25)) << " PKR \n\n";
		}
	}

	// Function to Display the Booked Flight Information

	void displayFlightInfo(string flightNum)
	{
		cout << " ---------- Flight Information ---------- \n\n";

		if (flightNum == "101")
		{
			cout << left << setw(20) << " Flight No ";
			cout << left << setw(20) << " Flight Name ";
			cout << left << setw(20) << " Flight From ";
			cout << left << setw(20) << " Flight Destination ";
			cout << left << setw(20) << " Departure Time ";
			cout << left << setw(20) << " Arrival Time ";
			cout << left << setw(20) << " Ticket Price " << endl << endl;
			cout << left << setw(20) << flightList[0][0];
			cout << left << setw(20) << flightList[0][1];
			cout << left << setw(20) << flightList[0][2];
			cout << left << setw(20) << flightList[0][3];
			cout << left << setw(20) << flightList[0][4];
			cout << left << setw(20) << flightList[0][5];
			cout << left << setw(20) << flightList[0][6] << endl << endl;
		}
		else if (flightNum == "102")
		{
			cout << left << setw(20) << " Flight No ";
			cout << left << setw(20) << " Flight Name ";
			cout << left << setw(20) << " Flight From ";
			cout << left << setw(20) << " Flight Destination ";
			cout << left << setw(20) << " Departure Time ";
			cout << left << setw(20) << " Arrival Time ";
			cout << left << setw(20) << " Ticket Price " << endl << endl;
			cout << left << setw(20) << flightList[1][0];
			cout << left << setw(20) << flightList[1][1];
			cout << left << setw(20) << flightList[1][2];
			cout << left << setw(20) << flightList[1][3];
			cout << left << setw(20) << flightList[1][4];
			cout << left << setw(20) << flightList[1][5];
			cout << left << setw(20) << flightList[1][6] << endl << endl;
		}
		else if (flightNum == "103")
		{
			cout << left << setw(20) << " Flight No ";
			cout << left << setw(20) << " Flight Name ";
			cout << left << setw(20) << " Flight From ";
			cout << left << setw(20) << " Flight Destination ";
			cout << left << setw(20) << " Departure Time ";
			cout << left << setw(20) << " Arrival Time ";
			cout << left << setw(20) << " Ticket Price " << endl << endl;
			cout << left << setw(20) << flightList[2][0];
			cout << left << setw(20) << flightList[2][1];
			cout << left << setw(20) << flightList[2][2];
			cout << left << setw(20) << flightList[2][3];
			cout << left << setw(20) << flightList[2][4];
			cout << left << setw(20) << flightList[2][5];
			cout << left << setw(20) << flightList[2][6] << endl << endl;
		}
		else if (flightNum == "104")
		{
			cout << left << setw(20) << " Flight No ";
			cout << left << setw(20) << " Flight Name ";
			cout << left << setw(20) << " Flight From ";
			cout << left << setw(20) << " Flight Destination ";
			cout << left << setw(20) << " Departure Time ";
			cout << left << setw(20) << " Arrival Time ";
			cout << left << setw(20) << " Ticket Price " << endl << endl;
			cout << left << setw(20) << flightList[3][0];
			cout << left << setw(20) << flightList[3][1];
			cout << left << setw(20) << flightList[3][2];
			cout << left << setw(20) << flightList[3][3];
			cout << left << setw(20) << flightList[3][4];
			cout << left << setw(20) << flightList[3][5];
			cout << left << setw(20) << flightList[3][6] << endl << endl;
		}
		else if (flightNum == "105")
		{
			cout << left << setw(20) << " Flight No ";
			cout << left << setw(20) << " Flight Name ";
			cout << left << setw(20) << " Flight From ";
			cout << left << setw(20) << " Flight Destination ";
			cout << left << setw(20) << " Departure Time ";
			cout << left << setw(20) << " Arrival Time ";
			cout << left << setw(20) << " Ticket Price " << endl << endl;
			cout << left << setw(20) << flightList[4][0];
			cout << left << setw(20) << flightList[4][1];
			cout << left << setw(20) << flightList[4][2];
			cout << left << setw(20) << flightList[4][3];
			cout << left << setw(20) << flightList[4][4];
			cout << left << setw(20) << flightList[4][5];
			cout << left << setw(20) << flightList[4][6] << endl << endl;
		}
		else if (flightNum == "106")
		{
			cout << left << setw(20) << " Flight No ";
			cout << left << setw(20) << " Flight Name ";
			cout << left << setw(20) << " Flight From ";
			cout << left << setw(20) << " Flight Destination ";
			cout << left << setw(20) << " Departure Time ";
			cout << left << setw(20) << " Arrival Time ";
			cout << left << setw(20) << " Ticket Price " << endl << endl;
			cout << left << setw(20) << flightList[5][0];
			cout << left << setw(20) << flightList[5][1];
			cout << left << setw(20) << flightList[5][2];
			cout << left << setw(20) << flightList[5][3];
			cout << left << setw(20) << flightList[5][4];
			cout << left << setw(20) << flightList[5][5];
			cout << left << setw(20) << flightList[5][6] << endl << endl;
		}
	}
};

class AdminPanel : public Person				// Inheritance between AdminPanel and Person
{
private:
	PassengerPanel passenger;					// Composition between AdminPanel and PassengerPanel

	string username;
	string password1;
	string password2;

public:

	// Default / Parametrized / Copy Constructors

	AdminPanel()
	{
		username = "";
		password1 = "";
		password2 = "";
	}
	AdminPanel(string username, string password1, string password2)
	{
		this->username = username;
		this->password1 = password1;
		this->password2 = password2;
	}
	AdminPanel(const AdminPanel& obj)
	{
		username = obj.username;
		password1 = obj.password1;
		password2 = obj.password2;
	}

	// Getters and Setters

	void setUsername(string username)
	{
		this->username = username;
	}
	void setPassword1(string password)
	{
		this->password1 = password;
	}
	void setPassword2(string password)
	{
		this->password2 = password;
	}
	string getUsername()
	{
		return username;
	}
	string getPassword1()
	{
		return password1;
	}
	string getPassword2()
	{
		return password2;
	}

	// Member Functions

	bool loginValidation()
	{
		char ch1, ch2;

		cout << " Enter your Username: ";
		cin >> username;

		cout << " Enter your Password: ";

		while ((ch1 = _getch()) != '\r')				// read characters until user presses enter key
		{
			if (ch1 == '\b')							// if backspace key is pressed, remove the last character from password string
			{
				if (!password1.empty())
				{
					password1.pop_back();
					cout << "\b \b";					// remove asterisk from console
				}
			}
			else if (isalnum(ch1) || ispunct(ch1))		// if alphanumeric or special character is pressed, add it to password string
			{
				password1.push_back(ch1);
				cout << "*";							// print asterisk to console
			}
		}

		cout << "\n Re-enter your Password: ";

		while ((ch2 = _getch()) != '\r')
		{
			if (ch2 == '\b')
			{
				if (!password2.empty())
				{
					password2.pop_back();
					cout << "\b \b";
				}
			}
			else if (isalnum(ch2) || ispunct(ch2))
			{
				password2.push_back(ch2);
				cout << "*";
			}
		}

		try
		{
			if ((username != "admin") || (password1 != "Admin@123" || password2 != "Admin@123")) 			// Used Exception Handling and Harcoded the necessary Requirements
			{
				throw " Invalid username or password, Try Again! ";
			}

			cout << "\n Login successful! \n\n";
			return true;
		}
		catch (const char* msg)
		{
			cout << "\n" << msg << ", Try Again! \n\n";
			return false;
		}

	}

	// Function to Search for a Flight Index in the Flight List Array

	int searchIndex(string flightNo)
	{
		int index = -1;

		for (int i = 0; i < globalCount; i++)
		{
			if (flightList[i][0] == flightNo)
			{
				index = i;

				break;
			}
		}

		return index;
	}

	// Function to Display the Flight Schedule

	void displayFlightSchedule()
	{
		system("cls");

		cout << " ---------- Flight Arrival and Departure Schedule ---------- \n\n\n";

		cout << left << setw(20) << " Flight No ";
		cout << left << setw(20) << " Flight Name ";
		cout << left << setw(20) << " Flight From ";
		cout << left << setw(20) << " Flight Destination ";
		cout << left << setw(20) << " Departure Time ";
		cout << left << setw(20) << " Arrival Time ";
		cout << left << setw(20) << " Ticket Price " << endl << endl;

		for (int i = 0; i < globalCount; i++)
		{
			cout << left << setw(20) << flightList[i][0];
			cout << left << setw(20) << flightList[i][1];
			cout << left << setw(20) << flightList[i][2];
			cout << left << setw(20) << flightList[i][3];
			cout << left << setw(20) << flightList[i][4];
			cout << left << setw(20) << flightList[i][5];
			cout << left << setw(20) << flightList[i][6] << endl << endl;
		}
	}

	// Function to Add Flights for Demo Purposes

	void populateFlights()
	{
		string flightNo = "";

		flightNo = "101";

		int index = searchIndex(flightNo);

		if (index == -1)
		{
			flightList[globalCount][0] = flightNo;
		}


		flightList[globalCount][1] = "NAFS";
		flightList[globalCount][2] = "Islamabad";
		flightList[globalCount][3] = "Karachi";
		flightList[globalCount][4] = "12:00PM";
		flightList[globalCount][5] = "2:00PM";
		flightList[globalCount][6] = "10000";

		globalCount++;

		flightNo = "102";

		index = searchIndex(flightNo);

		if (index == -1)
		{
			flightList[globalCount][0] = flightNo;
		}

		flightList[globalCount][1] = "NAFS";
		flightList[globalCount][2] = "Peshawar";
		flightList[globalCount][3] = "Quetta";
		flightList[globalCount][4] = "4:00PM";
		flightList[globalCount][5] = "6:00PM";
		flightList[globalCount][6] = "10000";

		globalCount++;

		flightNo = "103";

		index = searchIndex(flightNo);

		if (index == -1)
		{
			flightList[globalCount][0] = flightNo;
		}

		flightList[globalCount][1] = "NAFS";
		flightList[globalCount][2] = "Lahore";
		flightList[globalCount][3] = "Karachi";
		flightList[globalCount][4] = "8:00PM";
		flightList[globalCount][5] = "10:00PM";
		flightList[globalCount][6] = "10000";

		globalCount++;

		flightNo = "104";

		index = searchIndex(flightNo);

		if (index == -1)
		{
			flightList[globalCount][0] = flightNo;
		}

		flightList[globalCount][1] = "NAFS";
		flightList[globalCount][2] = "Islamabad";
		flightList[globalCount][3] = "UK";
		flightList[globalCount][4] = "12:00PM";
		flightList[globalCount][5] = "8:00PM";
		flightList[globalCount][6] = "20000";

		globalCount++;

		flightNo = "105";

		index = searchIndex(flightNo);

		if (index == -1)
		{
			flightList[globalCount][0] = flightNo;
		}

		flightList[globalCount][1] = "NAFS";
		flightList[globalCount][2] = "Quetta";
		flightList[globalCount][3] = "USA";
		flightList[globalCount][4] = "2:00PM";
		flightList[globalCount][5] = "10:00PM";
		flightList[globalCount][6] = "20000";

		globalCount++;

		flightNo = "106";

		index = searchIndex(flightNo);

		if (index == -1)
		{
			flightList[globalCount][0] = flightNo;
		}

		flightList[globalCount][1] = "NAFS";
		flightList[globalCount][2] = "Karachi";
		flightList[globalCount][3] = "Canada";
		flightList[globalCount][4] = "4:00PM";
		flightList[globalCount][5] = "12:00AM";
		flightList[globalCount][6] = "20000";

		globalCount++;
	}

	// Function to Display Seat Arrangements

	void seatsArrangement()
	{
		int index = 0;

		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
			{
				cout << setw(10) << " First class " << endl;
			}

			else if (i == 3)
			{
				cout << setw(10) << " Economy class " << endl;
			}

			cout << setw(2) << (i + 1) << "  ";
			cout << setw(10) << seatList[index][i][0];
			cout << setw(10) << seatList[index][i][1];
			cout << setw(10) << seatList[index][i][2];
			cout << setw(10) << seatList[index][i][3];
			cout << setw(10) << seatList[index][i][4];

			cout << setw(10) << "|||||";

			cout << setw(10) << seatList[index][i][5];
			cout << setw(10) << seatList[index][i][6];
			cout << setw(10) << seatList[index][i][7];
			cout << setw(10) << seatList[index][i][8];
			cout << setw(10) << seatList[index][i][9] << "" << endl;
		}
	}

	// Function to Add Flights

	void addFlight()
	{
		system("cls");

		cout << " ---------- Add New Flight ---------- \n\n\n";

		if (globalCount >= 50)
		{
			cout << " Flight list full! \n\n";
		}

		else
		{
			string flightNo = "";

			cout << " Enter Flight No: ";
			cin >> flightNo;

			int index = searchIndex(flightNo);

			if (index == -1)
			{
				flightList[globalCount][0] = flightNo;
			}
			else
			{
				cout << " Flight number already exists! \n";
				cout << " Aborted process! \n\n";

				return;
			}

			cout << " Enter Flight Name: ";
			cin >> flightList[globalCount][1];

			cout << " Enter Flight From: ";
			cin >> flightList[globalCount][2];

			cout << " Enter User Destination: ";
			cin >> flightList[globalCount][3];

			cout << " Enter Departure Time: ";
			cin >> flightList[globalCount][4];

			cout << " Enter Arrival Time: ";
			cin >> flightList[globalCount][5];

			cout << " Enter Amount: ";
			cin >> flightList[globalCount][6];

			globalCount++;

			cout << " Flight added successfully! \n\n";
		}
	}

	// Function to Edit Flight Information

	void editFlight()
	{
		system("cls");

		cout << " ---------- Edit Flight ---------- \n\n\n";

		displayFlightSchedule();

		string flightNo = "";

		cout << "\n Enter flight No to edit: ";
		cin >> flightNo;

		int index = searchIndex(flightNo);

		if (index == -1)
		{
			cout << " Flight not found! \n\n";
		}
		else
		{

			cout << " Enter Flight Name: ";
			cin >> flightList[index][1];

			cout << " Enter Flight From: ";
			cin >> flightList[index][2];

			cout << " Enter User Destination: ";
			cin >> flightList[index][3];

			cout << " Enter Departure Time: ";
			cin >> flightList[index][4];

			cout << " Enter Arrival Time: ";
			cin >> flightList[index][5];

			cout << " Enter Amount: ";
			cin >> flightList[index][6];

			cout << " Flight edited successfully! \n\n";

		}
	}

	// Function to Delete Flight

	void deleteFlight()
	{
		system("cls");

		cout << " ---------- Delete Flight ---------- \n\n\n";

		displayFlightSchedule();

		string flightNo = "";

		cout << "\n Enter flight No to edit: ";
		cin >> flightNo;

		int index = searchIndex(flightNo);

		if (index == -1)
		{
			cout << " Flight not found! \n\n";
		}
		else
		{
			while (index != globalCount)
			{
				flightList[index][0] = flightList[index + 1][0];
				flightList[index][1] = flightList[index + 1][1];
				flightList[index][2] = flightList[index + 1][2];
				flightList[index][3] = flightList[index + 1][3];
				flightList[index][4] = flightList[index + 1][4];
				flightList[index][5] = flightList[index + 1][5];
				flightList[index][6] = flightList[index + 1][6];

				for (int i = 0; i < 10; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						seatList[index][i][j] = seatList[index + 1][i][j];
					}
				}

				index++;
			}

			globalCount--;

			cout << "\n Flight Deleted! \n\n";
		}
	}

	// Function to Save Flight Information

	void saveFlights()
	{
		ofstream fout("flight.txt");

		if (fout.is_open())
		{
			fout << globalCount << "\n";

			for (int i = 0; i < globalCount; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					fout << setw(20) << flightList[i][j];
				}

				fout << "\n";
			}
		}

		fout.close();
	}

	// Function to Load Flight Information

	void loadFlights()
	{
		ifstream fin("flight.txt");

		if (fin.is_open())
		{
			fin >> globalCount;

			for (int i = 0; i < globalCount; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					fin >> setw(20) >> flightList[i][j];
				}
			}
		}

		fin.close();
	}

	// Function to Save Seats Information

	void saveSeats()
	{
		ofstream fout("Seats.txt");

		if (fout.is_open())
		{

			for (int i = 0; i < globalCount; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					for (int k = 0; k < 10; k++)
					{
						fout << setw(20) << seatList[i][j][k];
					}

					fout << "\n";
				}

				fout << "\n";
			}
		}

		fout.close();

		cout << " File Saved successfully! \n\n";
	}

	// Function to Load Seats Information

	void loadSeats()
	{
		ifstream fin("Seats.txt");

		if (fin.is_open())
		{
			for (int i = 0; i < globalCount; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					for (int k = 0; k < 10; k++)
					{
						fin >> setw(20) >> seatList[i][j][k];
					}
				}
			}
		}

		fin.close();

		cout << " File loaded successfully! \n\n";
	}
};

class Flight
{
private:
	AdminPanel* admin;

public:

	// Default / Parametrized / Copy Constructors

	Flight()
	{
		admin = NULL;
	}
	Flight(AdminPanel* admin)
	{
		this->admin = admin;				// Aggregation between Flight and AdminPanel
	}
	Flight(const Flight& obj)
	{
		this->admin = obj.admin;
	}

	// Getters and Setters

	void setAdmin(AdminPanel* admin)
	{
		this->admin = admin;
	}
	AdminPanel* getAdmin()
	{
		return admin;
	}
};


int main()
{
	// Creating Objects

	AdminPanel admin;
	PassengerPanel passenger;

	// Aggregation
	Flight* flight1 = new Flight(&admin);

	string flightNum = "";
	string seatNum = "";
	string flightNumber = "";

	bool visa = false;

	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int choice4 = 0;
	int choice5 = 0;

	// Dynamic Memory Allocation 

	flightList = new string * [ROWS];

	for (int i = 0; i < ROWS; i++)
	{
		flightList[i] = new string[COLS];
	}

	seatList = new string * *[ROWS1];

	for (int i = 0; i < ROWS1; i++)
	{
		seatList[i] = new string * [COLS1];

		for (int j = 0; j < COLS1; j++)
		{
			seatList[i][j] = new string[COLS2];
		}
	}

	// Function to fill the array with domestic and international flights for demonstration purposes
	admin.populateFlights();

	do
	{
	MainJump:
		cout << " Welcome to NUCES Airline Flight System \n\n";
		cout << " Select your Designation for Best Experience \n\n";
		cout << " 1. Admin Panel Member \n";
		cout << " 2. Passenger \n";
		cout << " 3. See Ongoing Flights \n";
		cout << " 4. See Most Popular Flights \n";
		cout << " 5. More about us \n";
		cout << " 6. Exit \n";
		cout << " Enter your choice: ";

		cin >> choice1;

		cout << endl;

		switch (choice1)
		{
		case 1:
			system("cls");
			Sleep(2000);
			cout << " Before you proceed, you need to Login to your Account \n\n";

			if (admin.loginValidation() == true)
			{
			AdminJump:
				cout << " ---------- Welcome to Admin Panel ---------- \n\n";
				cout << " 1. Add Flights \n";
				cout << " 2. Edit Flights \n";
				cout << " 3. Delete/Cancel Flights \n";
				cout << " 4. Display Flights \n";
				cout << " 5. Save/Load Flight Data \n";
				cout << " 6. Exit from Admin Panel \n";
				cout << " Enter your choice: ";

				cin >> choice2;

				do
				{
					switch (choice2)
					{
					case 1:
						try
						{
							system("cls");
							Sleep(2000);

							admin.addFlight();

							cout << " Press any number to go back to Main Menu: ";
							cin >> choice3;

							if ((choice3 == 0) || (choice3 == 1) || (choice3 == 2) || (choice3 == 3) || (choice3 == 4) || (choice3 == 5) || (choice3 == 6) || (choice3 == 7) || (choice3 == 8) || (choice3 == 9))
							{
								system("cls");
								Sleep(2000);
								break;
							}
							else
							{
								throw " Invalid choice! \n\n";
							}
						}
						catch (const char* msg)
						{
							cout << " Error: Try Again! " << msg << endl;

							system("pause");
							system("cls");

							break;
						}

						break;

					case 2:
						try
						{
							system("cls");
							Sleep(2000);

							admin.editFlight();

							cout << " Press any number to go back to Main Menu: ";
							cin >> choice3;

							if ((choice3 == 0) || (choice3 == 1) || (choice3 == 2) || (choice3 == 3) || (choice3 == 4) || (choice3 == 5) || (choice3 == 6) || (choice3 == 7) || (choice3 == 8) || (choice3 == 9))
							{
								system("cls");
								Sleep(2000);
								break;
							}
							else
							{
								throw " Invalid choice! \n\n";
							}

						}
						catch (const char* msg)
						{
							cout << " Error: Try Again! " << msg << endl;

							system("pause");
							system("cls");

							break;
						}

						break;

					case 3:
						try
						{
							system("cls");
							Sleep(2000);

							admin.deleteFlight();

							cout << " Press any number to go back to Main Menu: ";
							cin >> choice3;

							if ((choice3 == 0) || (choice3 == 1) || (choice3 == 2) || (choice3 == 3) || (choice3 == 4) || (choice3 == 5) || (choice3 == 6) || (choice3 == 7) || (choice3 == 8) || (choice3 == 9))
							{
								system("cls");
								Sleep(2000);
								break;
							}
							else
							{
								throw " Invalid choice! \n\n";
							}

						}
						catch (const char* msg)
						{
							cout << " Error: Try Again! " << msg << endl;

							system("pause");
							system("cls");

							break;
						}

						break;

					case 4:
						try
						{
							system("cls");
							Sleep(2000);

							admin.displayFlightSchedule();

							cout << " Press any number to go back to Main Menu: ";
							cin >> choice3;

							if ((choice3 == 0) || (choice3 == 1) || (choice3 == 2) || (choice3 == 3) || (choice3 == 4) || (choice3 == 5) || (choice3 == 6) || (choice3 == 7) || (choice3 == 8) || (choice3 == 9))
							{
								system("cls");
								Sleep(2000);
								break;
							}
							else
							{
								throw " Invalid choice! \n\n";
							}
						}
						catch (const char* msg)
						{
							cout << " Error: Try Again! " << msg << endl;

							system("pause");
							system("cls");

							break;
						}

						break;

					case 5:
						try
						{
							system("cls");
							Sleep(2000);

							cout << " 1. Save File \n";
							cout << " 2. Load File \n";
							cin >> choice3;

							if (choice3 == 1)
							{
								admin.saveFlights();
								admin.saveSeats();
							}
							if (choice3 == 2)
							{
								admin.loadFlights();
								admin.loadSeats();
							}

							cout << " Press any number to go back to Main Menu: ";
							cin >> choice4;

							if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
							{
								system("cls");
								Sleep(2000);
								break;
							}
							else
							{
								throw " Invalid choice! \n\n";
							}

						}
						catch (const char* msg)
						{
							cout << " Error: Try Again! " << msg << endl;

							system("pause");
							system("cls");

							break;
						}

						break;

					case 6:
						cout << " Exiting from Admin Panel to Main Menu..... \n";
						Sleep(2000);
						system("cls");
						goto MainJump;
						break;

					default:
						cout << " Invalid choice! Try Again! \n";
						Sleep(2000);
						system("cls");
						break;

					}

					goto AdminJump;

				} while (true);

				break;

			}

			break;

		case 2:
			system("cls");
			Sleep(2000);

			cout << " Are you a New User or an Existing User? \n";
			cout << " 1. New User \n";
			cout << " 2. Existing User \n";
			cout << " Enter your choice: ";
			cin >> choice2;

			do
			{
				switch (choice2)
				{
				case 1:
					cout << " Before you continue to the Passenger Panel, you have to create a New Account! \n\n";

					passenger.registrationValidation();

				PassengerJump:
					cout << " ---------- Welcome to Passenger Panel ---------- \n";
					cout << " 1. Book a Seat \n";
					cout << " 2. Show Ticket Information \n";
					cout << " 3. Cancel Booking \n";
					cout << " 4. Show Flight Schedule \n";
					cout << " 5. Exit from Passenger Panel \n";
					cout << " Enter your Choice: ";
					cin >> choice3;

					do
					{
						switch (choice3)
						{
						case 1:
							try
							{
								system("cls");
								Sleep(2000);


								cout << " Following are the available Domestic and International Flights: \n\n";
								admin.displayFlightSchedule();

								cout << " Enter the Flight No to Book a Flight: ";
								cin >> flightNum;

								if (flightNum == "101" || flightNum == "102" || flightNum == "103")
								{
									cout << " Select a seat from the following columns of the Flight: \n\n";
									cout << " First Class: \t 1 \t 2 \t 3: \n\n";
									cout << " Economy Class:  4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10: \t";
									cin >> seatNum;

									cout << endl;

									cout << " You have successfully booked a seat! \n\n";
								}
								else if (flightNum == "104" || flightNum == "105" || flightNum == "106")
								{
									cout << " Do you have a VISA for International Travel? \n";
									cout << " 0. Yes \n";
									cout << " 1. No \n";
									cout << " Enter your Choice: ";
									cin >> visa;

									if (visa == 0)
									{
										cout << " You are Eligible for an International Flight! \n\n";
									}
									else if (visa == 1)
									{
										cout << " You are not Eligible for an International Flight! \n\n";
										goto PassengerJump2;
									}
									else
									{
										cout << " Invalid Choice! Try Again! \n\n";
										goto PassengerJump2;
									}

									cout << " Select a seat from the following columns of the Flight: \n\n";
									cout << " First Class: \t 1 \t 2 \t 3: \n\n";
									cout << " Economy Class:  4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10: \t";
									cin >> seatNum;

									cout << endl;

									cout << " You have successfully booked a seat! \n\n";
								}

								cout << " Press any number to go back to Main Menu: ";
								cin >> choice4;

								if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
								{
									system("cls");
									Sleep(2000);
									break;
								}
								else
								{
									throw " Invalid choice! \n\n";
								}
							}
							catch (const char* msg)
							{
								cout << " Error: Try Again! " << msg << endl;

								system("pause");
								system("cls");

								break;
							}

							break;

						case 2:
							try
							{
								system("cls");
								Sleep(2000);

								passenger.displayTicketInfo(flightNum, seatNum);

								cout << " Press any number to go back to Main Menu: ";
								cin >> choice4;

								if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
								{
									system("cls");
									Sleep(2000);
									break;
								}
								else
								{
									throw " Invalid choice! \n\n";
								}
							}
							catch (const char* msg)
							{
								cout << " Error: Try Again! " << msg << endl;

								system("pause");
								system("cls");

								break;
							}

							break;

						case 3:
							try
							{
								system("cls");
								Sleep(2000);

								cout << " ---------- Cancel Booking ---------- \n\n";
								cout << " Enter the Flight No for which you want to cancel your booking: ";
								cin >> flightNum;

								passenger.cancelBooking(flightNum);

								cout << " Press any number to go back to Main Menu: ";
								cin >> choice4;

								if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
								{
									system("cls");
									Sleep(2000);
									break;
								}
								else
								{
									throw " Invalid choice! \n\n";
								}
							}
							catch (const char* msg)
							{
								cout << " Error: Try Again! " << msg << endl;

								system("pause");
								system("cls");

								break;
							}

							break;

						case 4:
							try
							{
								system("cls");
								Sleep(2000);

								passenger.displayFlightInfo(flightNum);

								cout << " Press any number to go back to Main Menu: ";
								cin >> choice4;

								if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
								{
									system("cls");
									Sleep(2000);
									break;
								}
								else
								{
									throw " Invalid choice! \n\n";
								}
							}
							catch (const char* msg)
							{
								cout << " Error: Try Again! " << msg << endl;

								system("pause");
								system("cls");

								break;
							}

							break;

						case 5:
							cout << " Exiting from Passenger Panel to Main Menu..... \n";
							Sleep(2000);
							system("cls");

							goto MainJump;

							break;

						default:
							cout << " Invalid choice! Try Again! \n";
							Sleep(2000);
							system("cls");

							break;

						}

						goto PassengerJump;

						break;

					} while (true);

				case 2:
					cout << " Before you continue to the Passenger Panel, you have to Login to your Account! \n\n";

					if (passenger.loginValidation() == true)
					{
					PassengerJump2:
						cout << " ---------- Welcome to Passenger Panel ---------- \n";
						cout << " 1. Book a Flight \n";
						cout << " 2. Show Ticket Information \n";
						cout << " 3. Cancel Booking \n";
						cout << " 4. Show Flight Schedule \n";
						cout << " 5. Exit from Passenger Panel \n\n";
						cout << " Enter your Choice: ";
						cin >> choice3;

						do
						{
							switch (choice3)
							{
							case 1:
								try
								{

									system("cls");
									Sleep(2000);

									cout << " Following are the available Domestic and International Flights: \n\n";
									admin.displayFlightSchedule();

									cout << " Enter the Flight No to Book a Flight: ";
									cin >> flightNum;

									if (flightNum == "101" || flightNum == "102" || flightNum == "103")
									{
										cout << " Select a seat from the following columns of the Flight: \n\n";
										cout << " First Class: \t 1 \t 2 \t 3: \n\n";
										cout << " Economy Class:  4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10: \t";
										cin >> seatNum;

										cout << endl;
										cout << " You have successfully booked a seat! \n\n";
										cout << " Total Amount Deducted with Tax: " << float((0.05 * 10000) + 10000) << " PKR \n\n";
									}
									else if (flightNum == "104" || flightNum == "105" || flightNum == "106")
									{
										cout << " Do you have a VISA for International Travel? \n";
										cout << " 0. Yes \n";
										cout << " 1. No \n";
										cout << " Enter your Choice: ";
										cin >> visa;

										if (visa == 0)
										{
											cout << " You are Eligible for an International Flight! \n\n";
										}
										else if (visa == 1)
										{
											cout << " You are not Eligible for an International Flight! \n\n";
											goto PassengerJump2;
										}
										else
										{
											cout << " Invalid Choice! Try Again! \n\n";
											goto PassengerJump2;
										}

										cout << " Select a seat from the following columns of the Flight: \n\n";
										cout << " First Class: \t 1 \t 2 \t 3: \n\n";
										cout << " Economy Class:  4 \t 5 \t 6 \t 7 \t 8 \t 9 \t 10: \t";
										cin >> seatNum;

										cout << endl;
										cout << " You have successfully booked a seat! \n\n";
										cout << " Total Amount Deducted with Tax: " << float((0.1 * 20000) + 20000) << " PKR \n\n";
									}

									cout << " Press any number to go back to Main Menu: ";
									cin >> choice4;

									if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
									{
										system("cls");
										Sleep(2000);
										break;
									}
									else
									{
										throw " Invalid choice! \n\n";
									}
								}
								catch (const char* msg)
								{
									cout << " Error: Try Again! " << msg << endl;

									system("pause");
									system("cls");

									break;
								}

								break;

							case 2:
								try
								{
									system("cls");
									Sleep(2000);

									passenger.displayTicketInfo(flightNum, seatNum);

									cout << " Press any number to go back to Main Menu: ";
									cin >> choice4;

									if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
									{
										system("cls");
										Sleep(2000);
										break;
									}
									else
									{
										throw " Invalid choice! \n\n";
									}
								}
								catch (const char* msg)
								{
									cout << " Error: Try Again! " << msg << endl;

									system("pause");
									system("cls");

									break;
								}

								break;

							case 3:
								try
								{
									system("cls");
									Sleep(2000);

									cout << " ---------- Cancel Booking ---------- \n\n";
									cout << " Enter the Flight No for which you want to cancel your booking: ";
									cin >> flightNum;

									passenger.cancelBooking(flightNum);

									cout << " Press any number to go back to Main Menu: ";
									cin >> choice4;

									if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
									{
										system("cls");
										Sleep(2000);
										break;
									}
									else
									{
										throw " Invalid choice! \n\n";
									}
								}
								catch (const char* msg)
								{
									cout << " Error: Try Again! " << msg << endl;

									system("pause");
									system("cls");

									break;
								}

								break;

							case 4:
								try
								{
									system("cls");
									Sleep(2000);

									passenger.displayFlightInfo(flightNum);

									cout << " Press any number to go back to Main Menu: ";
									cin >> choice4;

									if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
									{
										system("cls");
										Sleep(2000);
										break;
									}
									else
									{
										throw " Invalid choice! \n\n";
									}
								}
								catch (const char* msg)
								{
									cout << " Error: Try Again! " << msg << endl;

									system("pause");
									system("cls");

									break;
								}

								break;

							case 5:
								cout << " Exiting from Passenger Panel to Main Menu..... \n";
								Sleep(2000);
								system("cls");

								goto MainJump;

								break;
							default:
								cout << " Invalid choice! Try Again! \n";
								Sleep(2000);
								system("cls");
								break;
							}

							goto PassengerJump2;

							break;

						} while (true);

					}

					break;

				}

			} while (true);


			if (choice2 == 1)
			{
				system("cls");
				Sleep(2000);

				break;
			}
			else
			{
				system("cls");
				Sleep(2000);
				break;
			}

			break;

		case 3:

			cout << " ---------- Ongoing Flight Sschedule ---------- \n\n";

			try
			{
				system("cls");
				Sleep(2000);

				admin.displayFlightSchedule();

				cout << " Press any number to go back to Main Menu: ";
				cin >> choice4;

				if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
				{
					system("cls");
					Sleep(2000);
					break;
				}
				else
				{
					throw " Invalid choice! \n\n";
				}
			}
			catch (const char* msg)
			{
				cout << " Error: Try Again! " << msg <<
					system("pause");
				system("cls");

				break;
			}

			break;

		case 4:
			cout << " ---------- Most Popular Flights ---------- \n\n";

			try
			{
				system("cls");
				Sleep(2000);

				cout << left << setw(20) << " Flight No ";
				cout << left << setw(20) << " Flight Name ";
				cout << left << setw(20) << " Flight From ";
				cout << left << setw(20) << " Flight Destination ";
				cout << left << setw(20) << " Departure Time ";
				cout << left << setw(20) << " Arrival Time ";
				cout << left << setw(20) << " Ticket Price " << endl << endl;
				cout << left << setw(20) << flightList[3][0];
				cout << left << setw(20) << flightList[3][1];
				cout << left << setw(20) << flightList[3][2];
				cout << left << setw(20) << flightList[3][3];
				cout << left << setw(20) << flightList[3][4];
				cout << left << setw(20) << flightList[3][5];
				cout << left << setw(20) << flightList[3][6] << endl << endl;

				cout << left << setw(20) << " Flight No ";
				cout << left << setw(20) << " Flight Name ";
				cout << left << setw(20) << " Flight From ";
				cout << left << setw(20) << " Flight Destination ";
				cout << left << setw(20) << " Departure Time ";
				cout << left << setw(20) << " Arrival Time ";
				cout << left << setw(20) << " Ticket Price " << endl << endl;
				cout << left << setw(20) << flightList[0][0];
				cout << left << setw(20) << flightList[0][1];
				cout << left << setw(20) << flightList[0][2];
				cout << left << setw(20) << flightList[0][3];
				cout << left << setw(20) << flightList[0][4];
				cout << left << setw(20) << flightList[0][5];
				cout << left << setw(20) << flightList[0][6] << endl << endl;



				cout << " Press any number to go back to Main Menu: ";
				cin >> choice4;

				if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
				{
					system("cls");
					Sleep(2000);
					break;
				}
				else
				{
					throw " Invalid choice! \n\n";
				}
			}
			catch (const char* msg)
			{
				cout << " Error: Try Again! " << msg << endl;

				system("pause");
				system("cls");

				break;
			}

			break;

		case 5:
			cout << " ---------- More About Us ---------- \n\n";

			try
			{
				cout << " Welcome to NAFS, the airline that connects you to the world! We're passionate about delivering unforgettable travel experiences and take pride in being your trusted partner in the sky. With a team of dedicated professionals and a commitment to safety, comfort, and convenience, we ensure that every journey is smooth and memorable. Whether you're traveling for business or leisure, NAFS offers a wide range of destinations, flexible booking options, and exceptional customer service that exceeds your expectations. Come fly with us and discover why NAFS is more than just an airline, it's an experience! \n\n";
				cout << " Press any number to go back to Main Menu: ";
				cin >> choice4;

				if ((choice4 == 0) || (choice4 == 1) || (choice4 == 2) || (choice4 == 3) || (choice4 == 4) || (choice4 == 5) || (choice4 == 6) || (choice4 == 7) || (choice4 == 8) || (choice4 == 9))
				{
					system("cls");
					Sleep(2000);
					break;
				}
				else
				{
					throw " Invalid choice! \n\n";
				}
			}
			catch (const char* msg)
			{
				cout << " Error: Try Again! " << msg << endl;

				system("pause");
				system("cls");

				break;
			}

			break;

		case 6:
			cout << " ---------- Thank you for using our Services! ---------- \n";
			Sleep(2000);
			exit(0);
			break;

		default:
			cout << " Invalid choice! Try Again! \n";
			Sleep(2000);
			system("cls");
			break;
		}

	} while (true);
}