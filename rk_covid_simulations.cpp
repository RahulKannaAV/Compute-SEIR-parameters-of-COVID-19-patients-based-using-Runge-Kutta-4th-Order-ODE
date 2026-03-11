#include<iostream>
#include<iomanip>
#include<chrono>
#include"runge_kutta_functions.h"
using namespace std;
#define NUM_STATES 100

int main() {
	
	float currentS, currentE, currentI, currentR, updatedS, updatedE, updatedI, updatedR;
	
	float step_time = 0.1;
	
	currentS = S0;
	currentE = E0;
	currentI = I0;
	currentR = R0;
	cout << setprecision(8) << fixed;
	auto startTime = chrono::high_resolution_clock::now();
	for(int i=0; i<NUM_STATES; i++) {
		float updatedS = nextS(currentS, step_time);
		float updatedE = nextE(currentE, step_time);
		float updatedI = nextI(currentI, step_time);
		float updatedR = nextR(currentR, step_time);
		
		cout << "\nSTATE " << i+1 << endl;
		cout << "S: " << updatedS << endl;
		cout << "E: " << updatedE << endl;
		cout << "I: " << updatedI << endl;
		cout << "R: " << updatedR << endl;
		
		currentS = updatedS;
		currentE = updatedE;
		currentI = updatedI;
		currentR = updatedR;
	}
	auto endTime = chrono::high_resolution_clock::now();
	
	chrono::duration<double> executionTime = endTime - startTime;
	
	cout << "For States: " << NUM_STATES << " Execution Time: " << executionTime.count() << endl;
	
	return 0;
}
