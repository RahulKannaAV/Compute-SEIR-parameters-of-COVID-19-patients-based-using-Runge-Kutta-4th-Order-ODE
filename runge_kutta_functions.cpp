#include<iostream>
using namespace std;

#define A 33595 // Recruitment Rate
#define alpha 0.00001 // Rate of Interaction  between susceptible and infected individuals
#define delta 1.01 // Rate at which exposed population (E) becomes Infected population (I)
#define gamma 0.9 // Rate of Medication to Recovery
#define mew 0.143 // Natural Death Rate
#define mew1 0.1595 // Disease related Deaths
#define N0 1679754 // Initial total Population
#define S0 1661989 // Initial Susceptible Count
#define E0 16797 // Initial Exposed Count
#define I0 481 // Initial Infected Count
#define R0 487 // Initial Recovered Count
#define Vp 0.2522 // Partially Vaccinated Population Count
#define Vf 0.1517 // Fully Vaccinated Population Count

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

int k2_E(float halved_step_time) {
	int term1, term2, term3, term4;
	
	int k1S = k1_S();
	int k1I = k1_I();
	int k1E = k1_E();

	term1 = alpha * (S0 + (k1S*halved_step_time))*(I0 + (k1I * halved_step_time));
	term2 = -mew * (E0 + (k1E * halved_step_time));
	term3 = -delta * (E0 + (k1E *halved_step_time));
	term4 = Vp * (S0 + (k1S*halved_step_time));

	return term1 + term2 + term3 + term4;
}

int k2_I(float halved_step_time) {
	int term1, term2, term3, term4;
	int k1E = k1_E();
	int k1I = k1_I();

	term1 = delta * (E0 + (k1E * halved_step_time));
	term2 = -mew * (I0 + (k1I * halved_step_time));
	term3 = -mew1 * (I0 + (k1I * halved_step_time));
	term4 = -gamma * (I0 + (k1I * halved_step_time));

	return term1 + term2 + term3 + term4;
}

int k2_R(float halved_step_time) {
	int term1, term2, term3;
	int k1S = k1_S();
	int k1I = k1_I();
	int k1R = k1_R();

	term1 = Vf*(S0 + (k1S * halved_step_time));
	term2 = gamma * (I0 + (k1I * halved_step_time));
	term3 = -mew * (R0 + (k1R * halved_step_time));

	return term1 + term2 + term3;
}

int main() {
	int k1s_value = k1_S();
	int k1e_value = k1_E();
	int k1i_value = k1_I();
	int k1r_value = k1_R();
	float step_time = 0.1;
	float half_step_time = step_time/2;
	
	int k2s_value = k2_S(step_time);
	int k2e_value = k2_E(half_step_time);
	int k2i_value = k2_I(half_step_time);
	int k2r_value = k2_R(half_step_time);
	
	cout << "K1 for S: " << k1s_value << endl;
	cout << "K1 for E: " << k1e_value << endl;
	cout << "K1 for I: " << k1i_value << endl;
	cout << "K1 for R: " << k1r_value << endl;
	
	cout << "\nK2 for S: " << k2s_value << endl;
	cout << "K2 for E: " << k2e_value << endl;
	cout << "K2 for I: " << k2i_value << endl;
	cout << "K2 for R: " << k2r_value << endl;
	return 0;
}
