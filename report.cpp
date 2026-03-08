#include "reports.h"
#include "utils.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

void generateOverdueReport(const LibraryState& state) {
    bool found = false;
    cout << "\n--- Overdue Report ---" << endl;
    for (const auto& record : state.loans) {
        
        if (state.currentDay > record.dueDay) {
            found = true;
            int DaysOverdue = state.currentDay - record.dueDay;
            int fine = DaysOverdue * 5;

            
            cout << "Overdue Book ISBN: " << record.isbn
                 << " | borrowed by member: " << record.memberId 
                 << " is overdue by " << DaysOverdue 
                 << " days. Fine: " << fine << " pounds." << endl;
        }
    }
    if (!found) {
        cout << "No overdue books found." << endl;
    }
}

void exportOverdueBooks(const LibraryState& state, const string& filename) {
    ofstream myFile(filename);
    if (myFile.is_open()) {
        myFile << "MemberID|ISBN|DaysOverdue|Fine\n";
        for (const auto& record : state.loans) {
            int DaysOverdue = state.currentDay - record.dueDay;
            int fine = DaysOverdue * 5;
            if (DaysOverdue > 14) {
                int fine = (DaysOverdue - 14) * 5;
                myFile << record.memberId << "|"
                       << record.isbn << "|"
                       << DaysOverdue << "|"
                       << fine << "\n";
            }
        }
        myFile.close();
        cout << GREEN << "Overdue report exported successfully to " << filename << RESET << endl;
    } else {
        cout << RED << "Error!! Could not open file for exporting!" << RESET << endl;
    }

}