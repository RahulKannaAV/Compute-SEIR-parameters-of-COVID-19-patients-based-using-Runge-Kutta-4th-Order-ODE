#include<iostream>
#include<iomanip>
#include "region_parameters.h"
using namespace std;

/*
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
*/
// First order RK
int k1_S(string region) {
	float A = seir_params[region]["A"];
	float alpha = seir_params[region]["alpha"];
	float S0 = seir_params[region]["S0"];
	float I0 = seir_params[region]["I0"];
	float mew = seir_params[region]["mew"];
	float Vp = seir_params[region]["Vp"];
	float Vf = seir_params[region]["Vf"];

	return (A - (alpha * S0 * I0) - (mew * S0) - (Vp * S0) - (Vf * S0));
}

int k1_E(string region) {
	float A = seir_params[region]["A"];
	float alpha = seir_params[region]["alpha"];
	float S0 = seir_params[region]["S0"];
	float I0 = seir_params[region]["I0"];
	float mew = seir_params[region]["mew"];
	float E0 = seir_params[region]["E0"];
	float delta = seir_params[region]["delta"];
	float Vp = seir_params[region]["Vp"];

	return ((alpha * S0 * I0) - (mew * E0) - (delta * E0) + (Vp * S0));
}


int k1_I(string region) {
	float I0 = seir_params[region]["I0"];
	float mew = seir_params[region]["mew"];
	float mew1 = seir_params[region]["mew1"];
	float E0 = seir_params[region]["E0"];
	float delta = seir_params[region]["delta"];
	float gamma = seir_params[region]["gamma"];

	return ((delta * E0) - (mew * I0) - (mew1 * I0) - (gamma * I0));
}

int k1_R(string region) {
	float S0 = seir_params[region]["S0"];
	float I0 = seir_params[region]["I0"];
	float R0 = seir_params[region]["R0"];
	float Vf = seir_params[region]["Vf"];
	float mew = seir_params[region]["mew"];
	float gamma = seir_params[region]["gamma"];

	return ((Vf * S0) + (gamma * I0) - (mew * R0));
}

// Second Order RK
int k2_S(string region, float delT_by2) {
	int term1_2, term3, term4_5;

	int k1s_val = k1_S(region);
	int k1i_val = k1_I(region);

	float A = seir_params[region]["A"];
	float alpha = seir_params[region]["alpha"];
	float S0 = seir_params[region]["S0"];
	float I0 = seir_params[region]["I0"];
	float mew = seir_params[region]["mew"];
	float Vp = seir_params[region]["Vp"];
	float Vf = seir_params[region]["Vf"];

	// float delT_by2 = step_time / 2; 
	term1_2 = A - (alpha * (S0 + (k1s_val * delT_by2)) * (I0 + (k1i_val * delT_by2)));
	term3 = -mew * (S0 + (k1s_val * delT_by2));
	term4_5 = (-Vp * (S0 + (k1s_val * delT_by2))) - (Vf * (S0 + (k1s_val * delT_by2)));
	
	return term1_2 + term3 + term4_5;
}

/*
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

// Third order RK
int k3_S(float halved_step_time) {
	int term1, term2, term3, term4;
	
	int k2S = k2_S(halved_step_time);
	int k2I = k2_I(halved_step_time);
	term1 = -alpha*(S0+(k2S * halved_step_time)) * (I0 + (k2I * halved_step_time));
	term2 = -mew * (S0 + (k2S * halved_step_time));
	term3 = -Vp * (S0 + (k2S * halved_step_time));
	term4 = -Vf * (S0 + (k2S * halved_step_time));
	
	
	return A + term1 + term2 + term3 + term4;
}

int k3_E(float halved_step_time) {
	int term1, term2, term3, term4;
	
	int k2S = k2_S(halved_step_time);
	int k2I = k2_I(halved_step_time);
	int k2E = k2_E(halved_step_time);
	
	term1 = alpha * (S0 + (k2S * halved_step_time)) * (I0 + (k2I * halved_step_time));
	term2 = -mew * (E0 + (k2E * halved_step_time));
	term3 = -delta * (E0 + (k2E * halved_step_time));
	term4 = Vp * (S0 + (k2S * halved_step_time));
	
	return term1 + term2 + term3 + term4;
}

int k3_I(float halved_step_time) {
	int term1, term2, term3, term4;
	
	int k2E = k2_E(halved_step_time);
	int k2I = k2_I(halved_step_time);
	
	term1 = delta * (E0 + (k2E * halved_step_time));
	term2 = -mew * (I0 + (k2I * halved_step_time));
	term3 = -mew1 * (I0 + (k2I * halved_step_time));
	term4 = -gamma * (I0 + (k2I * halved_step_time));
	
	return term1 + term2 + term3 + term4;
}


int k3_R(float halved_step_time) {
	int term1, term2, term3;
	
	int k2S = k2_S(halved_step_time);
	int k2I = k2_I(halved_step_time);
	int k2R = k2_R(halved_step_time);
	
	term1 = Vf * (S0 + (k2S * halved_step_time));
	term2 = gamma * (I0 + (k2I * halved_step_time));
	term3 = -mew * (R0 + (k2R * halved_step_time));
	
	return term1 + term2 + term3;
}

// Fourth Order RK
int k4_S(float step_time) {
	int term1, term2, term3, term4;
	
	int k3S = k3_S(step_time/2);
	int k3I = k3_I(step_time/2);
	
	term1 = -alpha * (S0 + (k3S * step_time)) * (I0 + (k3I * step_time));
	term2 = -mew * (S0 + (k3S * step_time));
	term3 = -Vp * (S0 + (k3S * step_time));
	term4 = -Vf * (S0 + (k3S * step_time));
	
	
	return A + term1 + term2 + term3 + term4;
}

int k4_E(float step_time) {
	int term1, term2, term3, term4;
	
	float halved_step_time = step_time/2; 
	int k3S = k3_S(halved_step_time);
	int k3I = k3_I(halved_step_time);
	int k3E = k3_E(halved_step_time);
	
	term1 = alpha * (S0 + (k3S * step_time)) * (I0 + (k3I * step_time));
	term2 = -mew * (E0 + (k3E * step_time));
	term3 = -delta * (E0 + (k3E * step_time));
	term4 = Vp * (S0 + (k3S * step_time));
	
	return term1 + term2 + term3 + term4;
}

int k4_I(float step_time) {
	int term1, term2, term3, term4;
	
	float halved_step_time = step_time / 2;
	int k3E = k3_E(halved_step_time);
	int k3I = k3_I(halved_step_time);
	
	term1 = delta * (E0 + (k3E * step_time));
	term2 = -mew * (I0 + (k3I * step_time));
	term3 = -mew1 * (I0 + (k3I * step_time));
	term4 = -gamma * (I0 + (k3I * step_time));
	
	return term1 + term2 + term3 + term4;
}

int k4_R(float step_time) {
	int term1, term2, term3;
	float halved_step_time = step_time / 2;
	
	int k3S = k3_S(halved_step_time);
	int k3I = k3_I(halved_step_time);
	int k3R = k3_R(halved_step_time);
	
	term1 = Vf * (S0 + (k3S * step_time));
	term2 = gamma * (I0 + (k3I * step_time));
	term3 = -mew * (R0 + (k3R * step_time));
	
	return term1 + term2 + term3;
}

// Computing next state
float nextS(int currentS, float step_time) {
	float halved_step_time = step_time / 2;
	
	int k1S = k1_S();
	int k2S = k2_S(halved_step_time);
	int k3S = k3_S(halved_step_time);
	int k4S = k4_S(step_time);	
	
	float S1 = currentS + ((step_time/6) * (k1S + (2 * k2S) + (2 * k3S) + k4S));
	
	return S1;
}

float nextE(int currentE, float step_time) {
	float halved_step_time = step_time / 2;
	
	int k1E = k1_E();
	int k2E = k2_E(halved_step_time);
	int k3E = k3_E(halved_step_time);
	int k4E = k4_E(step_time);
	
	float E1 = currentE + ((step_time/6) * (k1E + (2*k2E) + (2*k3E) + k4E));
	
	return E1;
}

float nextI(int currentI, float step_time) {
	float halved_step_time = step_time / 2;
	
	int k1I = k1_I();
	int k2I = k2_I(halved_step_time);
	int k3I = k3_I(halved_step_time);
	int k4I = k4_I(step_time);
	
	float I1 = currentI + ((step_time/6) * (k1I + (2*k2I) + (2*k3I) + k4I));
	
	return I1;
}

float nextR(int currentR, float step_time) {
	float halved_step_time = step_time / 2;
	
	int k1R = k1_R();
	int k2R = k2_R(halved_step_time);
	int k3R = k3_R(halved_step_time);
	int k4R = k4_R(step_time);
	
	float R1 = currentR + ((step_time/6) * (k1R + (2*k2R) + (2*k3R) + k4R));
	
	return R1;
}
*/

int main() {

	string region = "TAMIL_NADU";
	int k1s_value = k1_S(region);
	int k1e_value = k1_E(region);
	int k1i_value = k1_I(region);
	int k1r_value = k1_R(region);
	float step_time = 0.1;
	float half_step_time = step_time/2;
	
	int k2s_value = k2_S(region, step_time);
	/*
	int k2e_value = k2_E(half_step_time);
	int k2i_value = k2_I(half_step_time);
	int k2r_value = k2_R(half_step_time);
	*/
	cout << setprecision(6) << fixed;
	
	cout << "K1 for S: " << k1s_value << endl;
	cout << "K1 for E: " << k1e_value << endl;
	cout << "K1 for I: " << k1i_value << endl;
	cout << "K1 for R: " << k1r_value << endl;
	
	cout << "\nK2 for S: " << k2s_value << endl;
	/*
	cout << "K2 for E: " << k2e_value << endl;
	cout << "K2 for I: " << k2i_value << endl;
	cout << "K2 for R: " << k2r_value << endl;
	
	int k3s_value = k3_S(half_step_time);
	int k3e_value = k3_E(half_step_time);
	int k3i_value = k3_I(half_step_time);
	int k3r_value = k3_R(half_step_time);
	
	cout << "\nK3 for S: " << k3s_value << endl;
	cout << "K3 for E: " << k3e_value << endl;
	cout << "K3 for I: "  << k3i_value << endl;
	cout << "K3 for R: " << k3r_value << endl;
	
	int k4s_value = k4_S(step_time);
	int k4e_value = k4_E(step_time);
	int k4i_value = k4_I(step_time);
	int k4r_value = k4_R(step_time);
	
	cout << "\nK4 for S: " << k4s_value << endl;
	cout << "K4 for E: " << k4e_value << endl;
	cout << "K4 for I: " << k4i_value << endl;
	cout << "K4 for R: " << k4r_value << endl;
	
	cout << "\nNext States " << endl;
	
	float s1 = nextS(S0, step_time);
	float e1 = nextE(E0, step_time);
	float i1 = nextI(I0, step_time);
	float r1 = nextR(R0, step_time);
	
	cout << "S1: " << s1 << endl;
	cout << "E1: " << e1 << endl;
	cout << "I1: " << i1 << endl;
	cout << "R1: " << r1 << endl;
	*/
	return 0;
}

