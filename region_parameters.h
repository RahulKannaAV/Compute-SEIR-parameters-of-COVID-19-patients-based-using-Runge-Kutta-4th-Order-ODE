#include<iostream>
#include<unordered_map>
using namespace std;

// g++ test.cpp -DREGION=\"TAMIL_NADU\"

	unordered_map<string, float> parameter_trivandrum = {
		{"A", 33595},
		{"alpha", 0.00001},
		{"delta", 1.01},
		{"gamma", 0.9},
		{"mew", 0.143},
		{"mew1", 0.1595},
		{"N0", 1679754},
		{"S0", 1661989},
		{"E0", 16797},
		{"I0", 481},
		{"R0", 487},
		{"Vp", 0.2522},
		{"Vf", 0.1517}
	};
	
	unordered_map<string, float> parameter_tamilnadu = {
		{"A", 1500000},
		{"alpha", 0.00001},
		{"delta", 1.2},
		{"gamma", 0.85},
		{"mew", 0.14},
		{"mew1", 0.16},
		{"N0", 77000000},
		{"S0", 76002000},
		{"E0", 35000},
		{"I0", 68000},
		{"R0", 895000},
		{"Vp", 0.20},
		{"Vf", 0.10}
	};
	
	unordered_map<string, float> parameter_maharashtra = {
		{"A", 2500000},
		{"alpha", 0.00001},
		{"delta", 1.35},
		{"gamma", 0.82},
		{"mew", 0.15},
		{"mew1", 0.17},
		{"N0", 123000000},
		{"S0", 118830000},
		{"E0", 300000},
		{"I0", 670000},
		{"R0", 3200000},
		{"Vp", 0.18},
		{"Vf", 0.09}
	};

	unordered_map<string, float> parameter_gujarat = {
    	{"A", 1100000},
    	{"alpha", 0.00001},
		{"delta", 1.25},
		{"gamma", 0.84},
		{"mew", 0.145},
		{"mew1", 0.162},
		{"N0", 64000000},
		{"S0", 63385000},
		{"E0", 55000},
		{"I0", 110000},
		{"R0", 450000},
		{"Vp", 0.19},
		{"Vf", 0.095}
	};
	
	unordered_map<string, float> parameter_delhi = {
    {"A", 900000},
    {"alpha", 0.00001},
    {"delta", 1.4},
    {"gamma", 0.80},
    {"mew", 0.155},
    {"mew1", 0.17},
    {"N0", 20000000},
    {"S0", 18965000},
    {"E0", 120000},
    {"I0", 95000},
    {"R0", 820000},
    {"Vp", 0.22},
    {"Vf", 0.11}
	};

	inline unordered_map<string, unordered_map<string, float>> seir_params = {
		{"TAMIL_NADU", parameter_tamilnadu},
		{"MAHARASHTRA", parameter_maharashtra},
		{"GUJARAT", parameter_gujarat},
		{"KERALA", parameter_trivandrum},
		{"DELHI", parameter_delhi}
	};
	
