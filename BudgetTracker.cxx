#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Data Structures
map<string, double> incomes;
vector<pair<string, double>> expenses;

void startUp() {
       cout << "  Log Your Spending in Seconds!\n" << endl;
}

string displayMenu() {
	  string choice;
	  
	  cout << "  =============================" << endl;
      cout << "      Personal Budget Menu" << endl;
      cout << "  =============================" << endl;
      cout << "        1. Add Income" << endl;
      cout << "        2. Add Expense" << endl;
      cout << "        3. View Expenses" << endl;
      cout << "        4. Check Budget" << endl;
      cout << "        5. Exit" << endl;
     
      cout << "  -----------------------------" << endl;
      cout << "       Enter your choice:  ";
      cin >> choice;
      return choice;
      
}

void addIncome() {
        string source;
        double amount;
        
	  cout << "  =============================" << endl;
      cout << "  Enter source income(Allowance): ";
      cin >> source;
      
      cout << "  Enter income amount: ";
      cin >> amount;
      cout << "  =============================\n" << endl;
      
      if (amount > 0) {
              incomes[source] += amount;
      
      cout << "     ===Source of Income===" << endl;  
      cout << "         [ " << source << " | ₱" << amount << " ]" << endl; 
      cout << "    Income added successfully!\n" << endl;
     }
     else {
     	cout << "      Invalid income amount.\n" << endl;
  }
}

void addExpense() {
      string category;
      double amount;
      
      cout << "  =============================" << endl;
      cout << "          CHOOSE CATEGORY" << endl;
      cout << " [Food] [Transport] [Entertainment]" << endl;
      cout << "      [School Project] [Other]\n" << endl;
      
      cout << "     Enter expense category: ";  
      cin >> category;
      
      cout << "     Enter expense amount: ";
      cin >> amount;
      cout << "  =============================\n" << endl;
      
      if (amount > 0) {
           expenses.push_back({category, amount});
           
      cout << "         ===Expenses===" << endl;
      cout << "          [ " << category << " | ₱" << amount << " ]"<< endl;    
      cout << "   Expenses added successfully!\n" << endl;
   } 
      else {
     	cout << "      Invalid income amount.\n" << endl;
  }
}

void viewExpenses() {
	map<string, double> summary;
	
	for (auto &expense : expenses) {
	 	summary[expense.first] += expense.second;
	}
	cout << "  =============================\n" << endl;
    cout << "   ===Expenses by Category===" << endl;
    
    for (auto &expense : summary) {
    	cout << "         [ " << expense.first << " | ₱" << expense.second << " ]\n" << endl;
    }

}

void checkBudget() {
	double total_income = 0;
	double total_expense = 0;
	
	for (auto &income : incomes) {
		total_income += income.second;
	}
	
	for (auto &expense : expenses) {
		total_expense += expense.second;
	}
	
	double remaining = total_income - total_expense;
	
    cout << "  =============================\n" << endl;
	cout << "        ---Total Income---" << endl;
	
	for (auto &income : incomes) {
		cout <<"             " << income.first << " | ₱" << income.second << endl;
	}
	
	cout << "       ---Total Expenses---" << endl;
	cout << "              ₱" << total_expense << endl;	
	cout << "         ---Remaining---" << endl;
	cout << "               ₱" << remaining << endl;
    cout << "  =============================\n" << endl;
}

int main() {
    startUp();
     
    while (true) {	
    	string choice = displayMenu();
    	
    	if (choice == "1") {
    		addIncome();
    	}   	
    	else if (choice == "2") {
    		addExpense();
    	}    	
    	else if (choice == "3") {
    		viewExpenses();
    	}   	
    	else if (choice == "4") {
    		checkBudget();
    	}    	
    	else if (choice == "5") {
    		cout << "\nThank you for using.....Keep going!\n" << endl;
    	}    	
    	else {
    		cout << "Invalid input. Try again.\n" << endl;
    		break;   	
    	}
    }  	
    return 0;  
}
              