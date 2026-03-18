#include<iostream>
#include<omp.h>
#include<vector>
#include<cmath>
#include<fstream>
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
double k1_S(string region) {
	double A = seir_params[region]["A"];
	double alpha = seir_params[region]["alpha"];
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double Vp = seir_params[region]["Vp"];
	double Vf = seir_params[region]["Vf"];

	return (A - (alpha * S0 * I0 ) - (mew * S0) - (Vp * S0) - (Vf * S0));
}

double k1_E(string region) {
	double A = seir_params[region]["A"];
	double alpha = seir_params[region]["alpha"];
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double E0 = seir_params[region]["E0"];
	double delta = seir_params[region]["delta"];
	double Vp = seir_params[region]["Vp"];

	return ((alpha * S0 * I0 ) - (mew * E0) - (delta * E0) + (Vp * S0));
}


double k1_I(string region) {
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double mew1 = seir_params[region]["mew1"];
	double E0 = seir_params[region]["E0"];
	double delta = seir_params[region]["delta"];
	double gamma = seir_params[region]["gamma"];

	return ((delta * E0) - (mew * I0) - (mew1 * I0) - (gamma * I0));
}

double k1_R(string region) {
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double R0 = seir_params[region]["R0"];
	double Vf = seir_params[region]["Vf"];
	double mew = seir_params[region]["mew"];
	double gamma = seir_params[region]["gamma"];

	return ((Vf * S0) + (gamma * I0) - (mew * R0));
}

// Second Order RK
double k2_S(string region, float delT_by2) {
	double term1_2, term3, term4_5;

	double k1s_val = k1_S(region);
	double k1i_val = k1_I(region);

	double A = seir_params[region]["A"];
	double alpha = seir_params[region]["alpha"] ;
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double Vp = seir_params[region]["Vp"];
	double Vf = seir_params[region]["Vf"];

	// float delT_by2 = step_time / 2; 
	term1_2 = A - (alpha * (S0 + (k1s_val * delT_by2)) * (I0 + (k1i_val * delT_by2)));
	term3 = -mew * (S0 + (k1s_val * delT_by2));
	term4_5 = (-Vp * (S0 + (k1s_val * delT_by2))) - (Vf * (S0 + (k1s_val * delT_by2)));
	
	return term1_2 + term3 + term4_5;
}

double k2_E(string region, double halved_step_time) {
	double term1, term2, term3, term4;
	
	double alpha = seir_params[region]["alpha"];
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double E0 = seir_params[region]["E0"];
	double mew = seir_params[region]["mew"];
	double delta = seir_params[region]["delta"];
	double Vp = seir_params[region]["Vp"];
	
	double k1S = k1_S(region);
	double k1I = k1_I(region);
	double k1E = k1_E(region);

	term1 = alpha * (S0 + (k1S*halved_step_time))*(I0 + (k1I * halved_step_time));
	term2 = -mew * (E0 + (k1E * halved_step_time));
	term3 = -delta * (E0 + (k1E *halved_step_time));
	term4 = Vp * (S0 + (k1S*halved_step_time));

	return term1 + term2 + term3 + term4;
}

double k2_I(string region, double halved_step_time) {
	double term1, term2, term3, term4;
	double delta = seir_params[region]["delta"];
	double E0 = seir_params[region]["E0"];
	double mew = seir_params[region]["mew"];
	double I0 = seir_params[region]["I0"];
	double mew1 = seir_params[region]["mew1"];
	double gamma = seir_params[region]["gamma"];
	
	double k1E = k1_E(region);
	double k1I = k1_I(region);

	term1 = delta * (E0 + (k1E * halved_step_time));
	term2 = -mew * (I0 + (k1I * halved_step_time));
	term3 = -mew1 * (I0 + (k1I * halved_step_time));
	term4 = -gamma * (I0 + (k1I * halved_step_time));

	return term1 + term2 + term3 + term4;
}

double k2_R(string region, double halved_step_time) {
	double term1, term2, term3;
	double k1S = k1_S(region);
	double k1I = k1_I(region);
	double k1R = k1_R(region);
	
	double Vf = seir_params[region]["Vf"];
	double S0 = seir_params[region]["S0"];
	double gamma = seir_params[region]["gamma"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double R0 = seir_params[region]["R0"];

	term1 = Vf*(S0 + (k1S * halved_step_time));
	term2 = gamma * (I0 + (k1I * halved_step_time));
	term3 = -mew * (R0 + (k1R * halved_step_time));

	return term1 + term2 + term3;
}

// Third order RK
double k3_S(string region, double halved_step_time) {
	double term1, term2, term3, term4;
	
	double k2S = k2_S(region, halved_step_time);
	double k2I = k2_I(region, halved_step_time);
	
	double A = seir_params[region]["A"];
	double alpha = seir_params[region]["alpha"];
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double Vp = seir_params[region]["Vp"];
	double Vf = seir_params[region]["Vf"];
	
	term1 = -alpha*(S0+(k2S * halved_step_time)) * (I0 + (k2I * halved_step_time));
	term2 = -mew * (S0 + (k2S * halved_step_time));
	term3 = -Vp * (S0 + (k2S * halved_step_time));
	term4 = -Vf * (S0 + (k2S * halved_step_time));
	
	
	return A + term1 + term2 + term3 + term4;
}

double k3_E(string region, double halved_step_time) {
	double term1, term2, term3, term4;
	
	double k2S = k2_S(region, halved_step_time);
	double k2I = k2_I(region, halved_step_time);
	double k2E = k2_E(region, halved_step_time);
	
	double alpha = seir_params[region]["alpha"];
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double E0 = seir_params[region]["E0"];
	double delta = seir_params[region]["delta"];
	double Vp = seir_params[region]["Vp"];
	
	term1 = alpha * (S0 + (k2S * halved_step_time)) * (I0 + (k2I * halved_step_time));
	term2 = -mew * (E0 + (k2E * halved_step_time));
	term3 = -delta * (E0 + (k2E * halved_step_time));
	term4 = Vp * (S0 + (k2S * halved_step_time));
	
	return term1 + term2 + term3 + term4;
}

double k3_I(string region, double halved_step_time) {
	double term1, term2, term3, term4;
	
	double k2E = k2_E(region, halved_step_time);
	double k2I = k2_I(region, halved_step_time);
	
	double delta = seir_params[region]["delta"];
	double E0 = seir_params[region]["E0"];
	double mew = seir_params[region]["mew"];
	double I0 = seir_params[region]["I0"];
	double mew1 = seir_params[region]["mew1"];
	double gamma = seir_params[region]["gamma"];
	
	term1 = delta * (E0 + (k2E * halved_step_time));
	term2 = -mew * (I0 + (k2I * halved_step_time));
	term3 = -mew1 * (I0 + (k2I * halved_step_time));
	term4 = -gamma * (I0 + (k2I * halved_step_time));
	
	return term1 + term2 + term3 + term4;
}


double k3_R(string region, double halved_step_time) {
	double term1, term2, term3;
	
	double k2S = k2_S(region, halved_step_time);
	double k2I = k2_I(region, halved_step_time);
	double k2R = k2_R(region, halved_step_time);
	
	double Vf = seir_params[region]["Vf"];
	double S0 = seir_params[region]["S0"];
	double gamma = seir_params[region]["gamma"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double R0 = seir_params[region]["R0"];
	
	
	term1 = Vf * (S0 + (k2S * halved_step_time));
	term2 = gamma * (I0 + (k2I * halved_step_time));
	term3 = -mew * (R0 + (k2R * halved_step_time));
	
	return term1 + term2 + term3;
}

// Fourth Order RK
double k4_S(string region, double step_time) {
	double term1, term2, term3, term4;
	
	double k3S = k3_S(region, step_time/2);
	double k3I = k3_I(region, step_time/2);
	
	double A = seir_params[region]["A"];
	double alpha = seir_params[region]["alpha"];
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double Vp = seir_params[region]["Vp"];
	double Vf = seir_params[region]["Vf"]; 

	term1 = -alpha * (S0 + (k3S * step_time)) * (I0 + (k3I * step_time));
	term2 = -mew * (S0 + (k3S * step_time));
	term3 = -Vp * (S0 + (k3S * step_time));
	term4 = -Vf * (S0 + (k3S * step_time));
	
	
	return A + term1 + term2 + term3 + term4;
}

double k4_E(string region, double step_time) {
	double term1, term2, term3, term4;
	
	double halved_step_time = step_time/2; 
	double k3S = k3_S(region, halved_step_time);
	double k3I = k3_I(region, halved_step_time);
	double k3E = k3_E(region, halved_step_time);
	
	double alpha = seir_params[region]["alpha"];
	double S0 = seir_params[region]["S0"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double E0 = seir_params[region]["E0"];
	double delta = seir_params[region]["delta"];
	double Vp = seir_params[region]["Vp"];

	term1 = alpha * (S0 + (k3S * step_time)) * (I0 + (k3I * step_time));
	term2 = -mew * (E0 + (k3E * step_time));
	term3 = -delta * (E0 + (k3E * step_time));
	term4 = Vp * (S0 + (k3S * step_time));
	
	return term1 + term2 + term3 + term4;
}

double k4_I(string region, double step_time) {
	double term1, term2, term3, term4;
	
	double halved_step_time = step_time / 2;
	double k3E = k3_E(region, halved_step_time);
	double k3I = k3_I(region, halved_step_time);

	double delta = seir_params[region]["delta"];
	double E0 = seir_params[region]["E0"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double mew1 = seir_params[region]["mew1"];
	double gamma = seir_params[region]["gamma"];
	
	term1 = delta * (E0 + (k3E * step_time));
	term2 = -mew * (I0 + (k3I * step_time));
	term3 = -mew1 * (I0 + (k3I * step_time));
	term4 = -gamma * (I0 + (k3I * step_time));
	
	return term1 + term2 + term3 + term4;
}

double k4_R(string region, double step_time) {
	double term1, term2, term3;
	double halved_step_time = step_time / 2;
	
	double k3S = k3_S(region, halved_step_time);
	double k3I = k3_I(region, halved_step_time);
	double k3R = k3_R(region, halved_step_time);

	double Vf = seir_params[region]["Vf"];
	double S0 = seir_params[region]["S0"];
	double gamma = seir_params[region]["gamma"];
	double I0 = seir_params[region]["I0"];
	double mew = seir_params[region]["mew"];
	double R0 = seir_params[region]["R0"];
	
	term1 = Vf * (S0 + (k3S * step_time));
	term2 = gamma * (I0 + (k3I * step_time));
	term3 = -mew * (R0 + (k3R * step_time));
	
	return term1 + term2 + term3;
}

// Computing next state
double nextS(string region, double step_time) {
	double halved_step_time = step_time / 2;
	double currentS = seir_params[region]["S0"];
	
	double k1S = k1_S(region);
	double k2S = k2_S(region, halved_step_time);
	double k3S = k3_S(region, halved_step_time);
	double k4S = k4_S(region, step_time);	
	
	double S1 = currentS + ((step_time/6) * (k1S + (2 * k2S) + (2 * k3S) + k4S));
	
	return S1;
}

double nextE(string region, double step_time) {
	double halved_step_time = step_time / 2;
	double currentE = seir_params[region]["E0"];

	double k1E = k1_E(region);
	double k2E = k2_E(region, halved_step_time);
	double k3E = k3_E(region, halved_step_time);
	double k4E = k4_E(region, step_time);
	
	double E1 = currentE + ((step_time/6) * (k1E + (2*k2E) + (2*k3E) + k4E));
	
	return E1;
}

double nextI(string region, double step_time) {
	double halved_step_time = step_time / 2;
	double currentI = seir_params[region]["I0"];
	
	double k1I = k1_I(region);
	double k2I = k2_I(region, halved_step_time);
	double k3I = k3_I(region, halved_step_time);
	double k4I = k4_I(region, step_time);
	
	double I1 = currentI + ((step_time/6) * (k1I + (2*k2I) + (2*k3I) + k4I));
	
	return I1;
}

double nextR(string region, float step_time) {
	double halved_step_time = step_time / 2;
	double currentR = seir_params[region]["R0"];

	double k1R = k1_R(region);
	double k2R = k2_R(region, halved_step_time);
	double k3R = k3_R(region, halved_step_time);
	double k4R = k4_R(region, step_time);
	
	double R1 = currentR + ((step_time/6) * (k1R + (2*k2R) + (2*k3R) + k4R));
	
	return R1;
}


void computeSEIR(string region, double STEP_TIME) {
	double S0, E0, I0, N0, R0;

	S0 = seir_params[region]["S0"];
	E0 = seir_params[region]["E0"];
	I0 = seir_params[region]["I0"];
	R0 = seir_params[region]["R0"];

	double s1 = nextS(region, STEP_TIME);
	double e1 = nextE(region,  STEP_TIME);
	double i1 = nextI(region,  STEP_TIME);
	double r1 = nextR(region, STEP_TIME);

	seir_params[region]["S0"] = s1;
	seir_params[region]["E0"] = e1;
	seir_params[region]["I0"] = i1;
	seir_params[region]["R0"] = r1;
	seir_params[region]["N0"] = s1 + e1 + i1 + r1;
}

void writeDataToCSV(ofstream &file, string region, int day) {
	const double A = seir_params[region]["A"];
	const double alpha = seir_params[region]["alpha"];
	const double delta = seir_params[region]["delta"];
	const double gamma = seir_params[region]["gamma"];
	const double mew = seir_params[region]["mew"];
	const double mew1 = seir_params[region]["mew1"];
	const double N = seir_params[region]["N0"];
	const double Vp = seir_params[region]["Vp"];
	const double Vf = seir_params[region]["Vf"];

	const double currentSuspected = round(seir_params[region]["S0"]);
	const double currentExposed = round(seir_params[region]["E0"]);
	const double currentInfected = round(seir_params[region]["I0"]);
	const double currentRecovered = round(seir_params[region]["R0"]);

	file << region << "," << A << "," << alpha << "," << delta << ",";
	file << gamma << "," << mew << "," << mew1 << "," << N << ",";
	file << Vp << "," << Vf << "," << currentSuspected << "," << currentExposed << ",";
	file << currentInfected << "," << currentRecovered << "\n";
}

int main() {
	cout << setprecision(0) << fixed;
	ofstream file;
	double S0, E0, I0, R0;
	string region;
	
	vector<string> allRegions;
	auto startTime = omp_get_wtime();
	for(auto region_name: seir_params) {
		allRegions.push_back(region_name.first);
	}
	
	for(string regions: allRegions) {
		cout << regions << " ";
	}
	cout << endl << endl;

file.open("seir_dataset_omp.csv", ios::app);
int reg_idx = 0;
int threadID;
int dayCount = 0; // Number of days simulated
double iterDiff = 0.0; // Difference between checkpoint and current iteration
double pastCheckpoint = 0.0; // Checkpoint iteration (it finished a Day)
const int NUM_DAYS = 1095; // Total days to simulate SEIR model
int N_INIT; // Initial Population count
double STEP_TIME; // Time difference between current states and next states
int NUM_STEPS; // Number of steps of iterations (will be with magnitudes of total days)
double ITERATIONS_PER_DAY;
int numThreads = 1;

#pragma omp parallel
{   
    #pragma omp single
    {
        numThreads = omp_get_num_threads();
    }
}

#pragma omp parallel for shared(file, allRegions, NUM_DAYS, seir_params) \
private(reg_idx, dayCount, iterDiff, pastCheckpoint, N_INIT, STEP_TIME, NUM_STEPS, ITERATIONS_PER_DAY, S0, E0, I0, R0, region, threadID)
for(reg_idx = 0; reg_idx < allRegions.size(); reg_idx++) {

    threadID = omp_get_thread_num();
    region = allRegions[reg_idx];

    // 🔥 LOCAL COPY (KEY FIX)
    auto local_params = seir_params[region];

    dayCount = 0;
    pastCheckpoint = 0.0;

    N_INIT = local_params["N0"];
    STEP_TIME = 0.1 * (1679754.0 / N_INIT);
    NUM_STEPS = (int)(1.0 / STEP_TIME);
    ITERATIONS_PER_DAY = (1.0 / (STEP_TIME * 10.0));

    cout << "SEIR of region " << region 
         << " on Thread " << threadID << endl;

    for(int i = 1; i <= ((NUM_DAYS/10)*(NUM_STEPS+1)); i++) {

        seir_params[region] = local_params;

        computeSEIR(region, STEP_TIME);

        local_params = seir_params[region];

        iterDiff = i - pastCheckpoint;

        if(iterDiff >= ITERATIONS_PER_DAY) {
            dayCount++;
            pastCheckpoint = ITERATIONS_PER_DAY * dayCount;

            #pragma omp critical
            {
                double A = local_params["A"];
                double alpha = local_params["alpha"];
                double delta = local_params["delta"];
                double gamma = local_params["gamma"];
                double mew = local_params["mew"];
                double mew1 = local_params["mew1"];
                double N = local_params["N0"];
                double Vp = local_params["Vp"];
                double Vf = local_params["Vf"];

                file << region << "," << dayCount << "," << A << "," << alpha << "," << delta << ",";
                file << gamma << "," << mew << "," << mew1 << "," << N << ",";
                file << Vp << "," << Vf << "," << round(local_params["S0"]) << ",";
                file << round(local_params["E0"]) << ",";
                file << round(local_params["I0"]) << ",";
                file << round(local_params["R0"]) << "\n";
            }
        }

        if(dayCount == NUM_DAYS) break;
    }

    // 🔥 write back final result (optional)
    #pragma omp critical
    {
        seir_params[region] = local_params;
    }
}
	file.close();	
    auto endTime = omp_get_wtime();

    cout << endl << endl;
    cout << "Available Threads: " << numThreads << endl;
    cout << "Execution Time: " << endTime - startTime << endl;
	return 0;
}

