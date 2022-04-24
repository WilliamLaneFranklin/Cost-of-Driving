#include <iostream>
#include <iomanip>


using namespace std;


//function prototypes
void   welcomeMessage();
char   getInput();
double getMilesPerGallon();
double getDollarsPerGallon();
double getMiles();
double calcDrivingCost(double userMpg, double userMiles, double gasPrice);


int main() {
  welcomeMessage();

  cout << fixed << setprecision(2);
  
  double userMpg = 0.00;
  double userMiles = 0.00;
  double gasPrice = 0.00;
  double totalCost = 0.00;

  cout << '\n' << "Would you like to calculate your driving cost? Enter 'y' or 'n': ";
  char userInput = '\0';
  userInput = getInput();
  while (userInput == 'y'){
  
    userMpg = getMilesPerGallon();
    userMiles = getMiles();
    gasPrice = getDollarsPerGallon();
  
    totalCost = calcDrivingCost(userMpg, userMiles, gasPrice);
  
    cout << '\n' << "Total cost of driving: $" << totalCost << endl;
    cout << '\n' << "Would you like to calculate another driving cost? Enter 'y' or 'n': ";
    userInput = getInput();
  }
  
  cout << '\n' << "Thanks for using my program!" << endl;

  return 0;
}


void welcomeMessage() {
  cout << '\n' << "Welcome to my program." << endl;
  cout << "This program will calculate the cost of driving!" << endl;
}


char getInput(){
  char userInput = '\0';
  cin >> userInput;
  userInput = tolower(userInput);
  while (userInput != 'y' && userInput != 'n'){
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter a valid choice: ";
    cin >> userInput;
    userInput = tolower(userInput);
  }
  return userInput;
}  


double getMilesPerGallon() {
  double userMpg = 0.00;
  cout << '\n' << "Enter your car's miles per gallon: ";
  cin  >> userMpg;
  while (!cin || userMpg < 0.00)
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid. Please enter a valid number of miles per gallon: ";
      cin  >> userMpg;
    }
  return userMpg;
}


double getMiles() {

  double userMiles = 0.00;

  cout << "Enter miles driven: ";
  cin  >> userMiles;

  while (!cin || userMiles < 0.00)
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid. Please enter a valid number of miles driven: ";
      cin  >> userMiles;
    }
  return userMiles;
}


double getDollarsPerGallon() {

  double gasPrice = 0.00;

  cout << "Enter gas price per gallon: $";
  cin  >> gasPrice;
  while (!cin || gasPrice < 0.00)
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid. Please enter a valid gas price per gallon: ";
      cin  >> gasPrice;
    }
  return gasPrice;
}


double calcDrivingCost(double userMpg, double userMiles, double gasPrice) {
  return (userMiles / userMpg) * gasPrice;
}
