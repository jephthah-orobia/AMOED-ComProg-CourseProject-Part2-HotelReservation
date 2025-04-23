/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: Hotel Reservation
 * @app desc: Ask user to input reservation details and display calculations
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "text_style.h"
#include "validation.h"

using namespace std;
using namespace style;

const int RATES[5] = {
  1000,
  1800,
  2700,
  3600,
  4500
};

double total_payments(double ndays, int nguest){
  if(nguest >= 5)
    nguest = 5;
  int rate = RATES[nguest-1];
  return rate*ndays;
}

double down_payment(double total){
  return 0.4*total;
}

double balance(double total){
  return total - down_payment(total);
}

void display_slip(ostream &out, string name, int age, int n_guests, int n_days){
  double total = total_payments(n_days, n_guests);
  double dp = down_payment(total);
  double bal = balance(total);
  out << faded << "=======================================" << reset << endl
    << bold << fg::cyan << "\tHOTEL RESERVATION SLIP" << reset << endl
    << "Consumer Name \t: " << bold << fg::green << name << reset << endl
    << "Age \t\t: " << bold << fg::green <<  age << reset << endl
    << "Number of Guests: " << bold << fg::green << n_guests << reset << endl
    << "Number of Days \t: " << bold << fg::green << n_days << reset << endl
    << "Total Payment \t: " << bold << fg::green << total << reset << endl
    << "Down Payment \t: " << bold << fg::green << dp << reset << endl
    << "Balance \t: " << bold << fg::green << bal << reset << endl
    << faded << "=======================================" << reset << endl;
}

void new_reservation(istream &in, ostream &out)
{
  /* Get name */
  string name;
  cout << endl << "Consumer Name: ";
  getline(cin, name);
  
  /* Get age */
  function<bool(int)> isLegalAge = [](int a){return a > 17;};
  int age = validation::getValidInput(
    cin, cout, 
    "Age: ",
    "You must be of legal age (18+). Please try again.\n",
    isLegalAge
  );

  function<bool(int)> is_more_than_zero_int = [](int n){return n > 0;};
  /* Get number of guest */
  int number_of_guest = validation::getValidInput(
    cin, cout,
    "Number of guests: ",
    "Invalid value. Please try again.\n",
    is_more_than_zero_int
  );

  function<bool(double)> is_more_than_zero_double = [](double n){return n > 0;};
  /* Get number of days */
  double number_of_days = validation::getValidInput(
    cin, cout,
    "Number of days: ",
    "Invalid value. Please try again.\n",
    is_more_than_zero_double
  );

  display_slip(out, name, age, number_of_guest, number_of_days);
  cout << endl << endl;
}

void display_rates(ostream &out)
{
  out << endl << inv << "Number of guests   | Daily Rate" << reset << endl;

  for(int i = 0; i < 5; i++){
    if(i == 4)
      cout << " 5 and above       | " << RATES[4] << endl << endl;
    else
      out << " " << (i+1) << "                 | " << RATES[i] << endl;
  }
}

int main()
{
  char o;

  cout << fg::yellow << bold << "*** H O T E L  R E S E R V A T I O N ***" << reset << endl
       << "Options:" << endl
       << "\t" << bold << "N" << reset << " or " << bold << "n" << reset << " - New Reservation" << endl
       << "\t" << bold << "R" << reset << " or " << bold << "r" << reset << " - to display rates" << endl
       << "\t" << bold << "C" << reset << " or " << bold << "c" << reset << " - Clear the screen" << endl
       << "\tAny other character - Quit or exit program" << endl
       << "Choose: ";

  cin >> o;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  switch (o)
  {
  case 'N':
  case 'n':
    new_reservation(cin, cout);
    break;
  case 'R':
  case 'r':
    display_rates(cout);
    break;
  case 'C':
  case 'c':
    system("clear");
    break;
  default:
    return EXIT_SUCCESS;
  }
  return main();
}
