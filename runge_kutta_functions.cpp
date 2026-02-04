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

// First order RK
int k1_S() {
	return (A - (alpha * S0 * I0) - (mew * S0) - (Vp * S0) - (Vf * S0));
}

int k1_E() {
	return ((alpha * S0 * I0) - (mew * E0) - (delta * E0) + (Vp * S0));
}

int k1_I() {
	return ((delta * E0) - (mew * I0) - (mew1 * I0) - (gamma * I0));
}

int k1_R() {
	return ((Vf * S0) + (gamma * I0) - (mew * R0));
}

// Second Order RK
int k2_S(float step_time) {
	int term1_2, term3, term4_5;

	int k1s_val = k1_S();
	int k1i_val = k1_I();
	
	float delT_by2 = step_time / 2; 
	term1_2 = A - (alpha * (S0 + (k1s_val * delT_by2)) * (I0 + (k1i_val * delT_by2)));
	term3 = -mew * (S0 + (k1s_val * delT_by2));
	term4_5 = (-Vp * (S0 + (k1s_val * delT_by2))) - (Vf * (S0 + (k1s_val * delT_by2)));
	
	return term1_2 + term3 + term4_5;
}

int main() {
	int k1s_value = k1_S();
	int k1e_value = k1_E();
	int k1i_value = k1_I();
	int k1r_value = k1_R();
	float step_time = 0.1;
	
	int k2s_value = k2_S(step_time);
	
	cout << "K1 for S: " << k1s_value << endl;
	cout << "K1 for E: " << k1e_value << endl;
	cout << "K1 for I: " << k1i_value << endl;
	cout << "K1 for R: " << k1r_value << endl;
	
	cout << "\nK2 for S: " << k2s_value << endl;
	return 0;
}
