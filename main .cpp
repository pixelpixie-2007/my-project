#include "report.cpp"
#include "storage.cpp"
#include "library.cpp"
#include "utils.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
int main() {

     LibraryState state;
    string dbPath = "library_data.txt";
    loadDatabase(state, "library_data.txt");
    saveDatabase(state, "library_data.txt");

    int choice;
    while (true) {
         try{
            cout <<BLUE<< "\n  ====== Library Management System ======" <<RESET<< endl;
            cout <<BLUE<< "Current Day: " << state.currentDay <<RESET<< endl;
            cout <<BLUE<< "1. Add Book (Member A)" <<RESET<< endl;
            cout <<BLUE<< "2. Checkout Book (Member A)" <<RESET<< endl;
            cout <<BLUE<< "3. Generate Overdue Report (Member B)" <<RESET<< endl;
            cout <<BLUE<< "4. Export Overdue List (Member B)" <<RESET<< endl;
            cout <<BLUE<< "5. Advance to Next Day" <<RESET<< endl;
            cout <<BLUE<< "6. Save and Exit" <<RESET<< endl;
            cout << "Enter choice: ";


            if (!(cin >> choice))
                cout << RED << "Error!! Invalid input! Please enter a number." << RESET << endl;

            switch (choice) {
                 case 1:
                     cout << "[Waiting for Member A's addBook function...]" << endl;
                     break;
                 case 2:
                     cout << "[Waiting for Member A's checkoutBook function...]" << endl;
                     break;
                 case 3:
                     generateOverdueReport(state);
                    break;
                 case 4:
                      exportOverdueBooks(state, "overdue_report.txt");
                      break;
                 case 5:
                      state.currentDay++;
                     cout << GREEN << "Advanced to next day: " << state.currentDay << RESET << endl;
                     break;
                      case 6:
                      saveDatabase(state, dbPath);
                      cout << GREEN << "Data saved successfully. Exiting..." << RESET << endl;
                     return 0;
                 default:
                cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }
}

        catch (const exception& e) {
            cout << RED << " Error!! " << e.what() << RESET << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    return 0;
}
