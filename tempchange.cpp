#include<iostream>

using namespace std;

void calculate_from_celsius(float c)

{

    float fh,ke;

    fh=((c*9)/5)+32;

    ke= c + 273.15;

    cout<<"Fahrenheit :"<<fh<<endl;

    cout<<"Kelvin :"<<ke<<endl;

}



void calculate_from_fahrenheit(float f)

{

    float ce,ke;

    ce = ((f-32)*5)/9;

    ke = ce + 273.15;

    cout<<"Celsius :"<<ce<<endl;

    cout<<"Kelvin :"<<ke<<endl;



}



void calculate_from_kelvin(int k)

{

    float fh,ce;



    ce = k - 273.15;

    fh = (ce*9)/5 + 32;

    cout<<"Fahrenheit :"<<fh<<endl;

    cout<<"Celsius :"<<ce<<endl;

}



int main()

{

    float x;

   

    char unit;

    cout<<"Enter temperature :"<<endl;

    cin>>x;

    cout<<"Enter the unit of measurement :";

    cin>>unit;

   

    switch(unit)

    {

        case 'C' :

        case 'c':

        calculate_from_celsius(x);

        break;



        case 'F':

        case 'f':

        calculate_from_fahrenheit(x);

        break;



        case 'K':

        case 'k':

       calculate_from_kelvin(x);

        break;





    }

}