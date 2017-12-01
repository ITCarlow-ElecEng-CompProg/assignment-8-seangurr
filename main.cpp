/** Sean Gurr
 *  C00221886
 *  Ex. 8
 *  Operation Amplifier Circuits
 *  05/11/2017
 */

/**< Preprocessor directives */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <windows.h>

using namespace std;


/**< Main function */
 int main()
{

    /**< Function prototypes */
    char userChoice;
    void Inverting(void);
    void NonInverting(void);
    char menu(void);

    /**< Do while loop criteria */
    do
    {
        userChoice = menu();

        switch (userChoice)
        {
            case 'a': Inverting();
                      break;

            case 'b': NonInverting();
                      break;

            case 'q': cout << "\nGoodbye!!" << endl;
                      break;

            default : cout << "\nError" << endl;
                      break;
        }
    }
    while (userChoice != 'q');

return 0;
}

/**< Menu function */
char menu(void)
{
    char choice;

    /**< Prompt user to enter an option */
    cout << "\nEnter one of the following options" <<
            "\nEnter a for an Inverting Op Amp: " <<
            "\nEnter b for a Non-Inverting Op Amp: " <<
            "\nEnter q to quit" << endl;

    cin >> choice;

return choice;
}

/**< Inverting function */
void Inverting(void)
{
    /**< variable declarations */
    double Vcc, Vee, Vin, Rin=0, Rf=0, Av, Vout;
    double *Av_ptr, *Vout_ptr;

    Av_ptr = &Av;
    Vout_ptr = &Vout;

    void InvertingCalculations(double, double, double, double, double, double*, double*);

    /**< Prompt user to enter values */
    cout << "\n\nEnter value for Vcc: ";
    cin >> Vcc;
    cout << "\n\nEnter value for Vee: ";
    cin >> Vee;
    cout << "\n\nEnter value for Vin: ";
    cin >> Vin;

    /**< While loop criteria */
    while ((Rin <=0 )||(Rf <=0 ))
    {
        cout << "\nEnter value greater than zero for Rin: ";
        cin >> Rin;
        cout << "\nEnter value greater than zero for Rf: ";
        cin >> Rf;
    }


    InvertingCalculations(Vcc, Vee, Vin, Rf, Rin, Av_ptr, Vout_ptr);

    /**< Display result */
    cout << "\nGain = " << Av << endl;
    cout << "\nVout = "<<Vout<<"V"<< endl;

return;
}


/**< Inverting calculations function */
void InvertingCalculations(double Vcc, double Vee, double Vin, double Rf, double Rin, double *Av_ptr, double *Vout_ptr)
{

*Av_ptr = -Rf / Rin;

*Vout_ptr = *Av_ptr * Vin;

    if(*Vout_ptr > Vcc)
    {
       *Vout_ptr = Vcc;
    }

    else if (*Vout_ptr < Vee)
    {
       *Vout_ptr = Vee;
    }

    else
    {
        *Vout_ptr = *Vout_ptr;
    }

return;
}


/**< Non-Inverting function */
void NonInverting(void)
{
    /**< variable declarations */
    double Vcc, Vee, Vin, R1=0, R2=0, Av, Vout;
    double *Av_ptr, *Vout_ptr;

    Av_ptr = &Av;
    Vout_ptr = &Vout;


    void NonInvertingCalculations(double, double, double, double, double, double*, double*);

     /**< Prompt user to enter values */
    cout << "\nEnter value for Vcc: ";
    cin >> Vcc;
    cout << "\nEnter value for Vee: ";
    cin >> Vee;
    cout << "\nEnter value for Vin: ";
    cin >> Vin;

    /**< While loop criteria */
    while ((R1 <=0 )||(R2 <=0 ))
    {
        cout << "\nEnter R1 value greater than zero: ";
        cin >> R1;
        cout << "\nEnter R2 value greater than zero: ";
        cin >> R2;
    }


    NonInvertingCalculations(Vcc, Vee, Vin, R1, R2, Av_ptr, Vout_ptr);

    /**< Display results */
    cout << "\nGain = " << Av << endl;
    cout << "\nVout = " <<Vout<<"V"<< endl;

return;
}


/**< Non-Inverting calculations function */
void NonInvertingCalculations(double Vcc,double Vee,double Vin,double R1,double R2,double *Av_ptr,double *Vout_ptr)
{
    *Av_ptr = 1 + (R2/R1);

    *Vout_ptr = *Av_ptr * Vin;

    if(*Vout_ptr > Vcc)
    {
       *Vout_ptr = Vcc;
    }

    else if (*Vout_ptr < Vee)
    {
       *Vout_ptr = Vee;
    }

    else
    {
        *Vout_ptr = *Vout_ptr;
    }

return;

}






