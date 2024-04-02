#include <iostream>

#include <cstdlib>

#include <ctime>



using namespace std;



bool guess_number(long int x, int& chances, long long& generatedNumber) {

    if (generatedNumber == x) {

        cout << "Yes, you guessed it!" << endl;

        return true;

    } else if (x < generatedNumber) {

        cout << "Too Low" << endl;

    } else {

        cout << "Too High" << endl;

    }



    chances++;

    return false;

}



int main() {

    srand(time(NULL));  




    long long generatedNumber;



 

        int chances = 0;  



       

        generatedNumber = rand() % 30;

        cout << "New number generated. Start guessing!" << endl;



        long int x;

        cout << "Enter your guess: ";

        cin >> x;



        while (!guess_number(x, chances, generatedNumber)) {

            cout << "Try again. Enter your guess: ";

            cin >> x;

        }



        cout << "You took " << chances << " attempts to guess the number." << endl;

       

    return 0;

}
