#include<iostream>
using namespace std;

#define A 33595 // Recruitment Rate
#define alpha 0.00001 // Rate of Interaction  between susceptible and infected individuals
#define mew 0.143 // Natural Death Rate
#define Vp 0.2522 // Partially Vaccinated Population Count
#define Vf 0.1517 // Fully Vaccinated Population Count
#define delta 1.01 // Rate at which exposed population (E) becomes Infected population (I)
#define mew1 0.1595 // Disease related Deaths
#define gamma 0.9 // Rate of Medication to Recovery
#define N0 1679754 // Initial total Population
#define S0 1661989 // Initial Susceptible Count
#define E0 16797 // Initial Exposed Count
#define I0 481 // Initial Infected Count
#define R0 487 // Initial Recovered Count


int k1_S() {
	return (A - (alpha * S0 * I0) - (mew * S0) - (Vp * S0) - (Vf * S0));
}

int main() {
	int k1s_value = k1_S();
	cout << k1s_value << endl;
	return 0;
}
