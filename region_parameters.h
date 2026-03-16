#include <unordered_map>
#include <string>
using namespace std;

// ---------------- PARAMETER SETS ----------------

unordered_map<string,double> parameter_trivandrum={
	{"A",33595},
	{"alpha",0.00001},
	{"delta",1.01},
	{"gamma",0.9},
	{"mew",0.143},
	{"mew1",0.1595},
	{"N0",1679754},
	{"S0",1661989},
	{"E0",16797},
	{"I0",481},
	{"R0",487},
	{"Vp",0.2522},
	{"Vf",0.1517}};

unordered_map<string,double> parameter_chennai={
	{"A",71600},
	{"alpha",0.000012},
	{"delta",1.01},
	{"gamma",0.9},
	{"mew",0.143},
	{"mew1",0.1595},
	{"N0",7090000},
	{"S0",7009000},
	{"E0",65000},
	{"I0",8200},
	{"R0",17800},
	{"Vp",0.21},
	{"Vf",0.11}};

unordered_map<string,double> parameter_delhi={
	{"A",82000},
	{"alpha",0.000014},
	{"delta",1.02},
	{"gamma",0.91},
	{"mew",0.143},
	{"mew1",0.162},
	{"N0",19000000},
	{"S0",18740000},
	{"E0",170000},
	{"I0",28000},
	{"R0",150000},
	{"Vp",0.19},
	{"Vf",0.09}};

unordered_map<string,double> parameter_mumbai={
	{"A",95000},
	{"alpha",0.000013},
	{"delta",1.01},
	{"gamma",0.92},
	{"mew",0.143},
	{"mew1",0.158},
	{"N0",12400000},
	{"S0",12260000},
	{"E0",90000},
	{"I0",12000},
	{"R0",78000},
	{"Vp",0.23},
	{"Vf",0.12}};

unordered_map<string,double> parameter_kolkata={{"A",62000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.156},{"N0",4500000},{"S0",4456000},{"E0",32000},{"I0",4200},{"R0",7800},{"Vp",0.18},{"Vf",0.08}};
unordered_map<string,double> parameter_bengaluru={{"A",88000},{"alpha",0.000013},{"delta",1.02},{"gamma",0.91},{"mew",0.143},{"mew1",0.161},{"N0",12000000},{"S0",11870000},{"E0",85000},{"I0",11000},{"R0",44000},{"Vp",0.22},{"Vf",0.10}};
unordered_map<string,double> parameter_hyderabad={{"A",65000},{"alpha",0.000012},{"delta",1.01},{"gamma",0.90},{"mew",0.143},{"mew1",0.158},{"N0",6800000},{"S0",6732000},{"E0",48000},{"I0",5200},{"R0",14800},{"Vp",0.20},{"Vf",0.10}};
unordered_map<string,double> parameter_ahmedabad={{"A",52000},{"alpha",0.000011},{"delta",1.01},{"gamma",0.90},{"mew",0.143},{"mew1",0.157},{"N0",5600000},{"S0",5544000},{"E0",39000},{"I0",4500},{"R0",12500},{"Vp",0.19},{"Vf",0.09}};
unordered_map<string,double> parameter_gurgaon={{"A",21000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.155},{"N0",1500000},{"S0",1479000},{"E0",12000},{"I0",1500},{"R0",7500},{"Vp",0.18},{"Vf",0.09}};
unordered_map<string,double> parameter_pune={{"A",58000},{"alpha",0.000012},{"delta",1.01},{"gamma",0.91},{"mew",0.143},{"mew1",0.159},{"N0",6000000},{"S0",5930000},{"E0",52000},{"I0",7000},{"R0",11000},{"Vp",0.22},{"Vf",0.11}};
unordered_map<string,double> parameter_trichy={{"A",15000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",1000000},{"S0",988000},{"E0",8000},{"I0",1000},{"R0",3000},{"Vp",0.20},{"Vf",0.09}};
unordered_map<string,double> parameter_madurai={{"A",18000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",1200000},{"S0",1186000},{"E0",9000},{"I0",1200},{"R0",2800},{"Vp",0.19},{"Vf",0.08}};
unordered_map<string,double> parameter_indore={{"A",24000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.156},{"N0",2000000},{"S0",1976000},{"E0",15000},{"I0",2200},{"R0",7800},{"Vp",0.18},{"Vf",0.08}};
unordered_map<string,double> parameter_chandigarh={{"A",9000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",1050000},{"S0",1037000},{"E0",7000},{"I0",900},{"R0",4100},{"Vp",0.21},{"Vf",0.10}};
unordered_map<string,double> parameter_patna={{"A",30000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",2000000},{"S0",1976000},{"E0",15000},{"I0",1800},{"R0",7200},{"Vp",0.15},{"Vf",0.06}};
unordered_map<string,double> parameter_lucknow={{"A",45000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.155},{"N0",3500000},{"S0",3460000},{"E0",28000},{"I0",3000},{"R0",9000},{"Vp",0.16},{"Vf",0.07}};
unordered_map<string,double> parameter_ranchi={{"A",12000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",1100000},{"S0",1088000},{"E0",8000},{"I0",900},{"R0",2100},{"Vp",0.14},{"Vf",0.05}};
unordered_map<string,double> parameter_imphal={{"A",8000},{"alpha",0.000009},{"delta",1.00},{"gamma",0.87},{"mew",0.143},{"mew1",0.153},{"N0",800000},{"S0",792000},{"E0",5000},{"I0",600},{"R0",2400},{"Vp",0.13},{"Vf",0.05}};
unordered_map<string,double> parameter_bhopal={{"A",20000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.155},{"N0",1800000},{"S0",1779000},{"E0",12000},{"I0",1800},{"R0",7200},{"Vp",0.17},{"Vf",0.07}};
unordered_map<string,double> parameter_jaipur={{"A",42000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.156},{"N0",3100000},{"S0",3060000},{"E0",25000},{"I0",3500},{"R0",11500},{"Vp",0.18},{"Vf",0.08}};
unordered_map<string,double> parameter_surat={{"A",41000},{"alpha",0.000012},{"delta",1.01},{"gamma",0.90},{"mew",0.143},{"mew1",0.157},{"N0",4500000},{"S0",4440000},{"E0",30000},{"I0",4000},{"R0",20000},{"Vp",0.20},{"Vf",0.09}};
unordered_map<string,double> parameter_vadodara={{"A",19000},{"alpha",0.000011},{"delta",1.01},{"gamma",0.90},{"mew",0.143},{"mew1",0.156},{"N0",1700000},{"S0",1679000},{"E0",11000},{"I0",1500},{"R0",6500},{"Vp",0.18},{"Vf",0.08}};
unordered_map<string,double> parameter_nagpur={{"A",25000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.156},{"N0",2400000},{"S0",2368000},{"E0",18000},{"I0",2600},{"R0",12600},{"Vp",0.19},{"Vf",0.09}};
unordered_map<string,double> parameter_coimbatore={{"A",26000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.155},{"N0",2100000},{"S0",2075000},{"E0",15000},{"I0",1800},{"R0",8700},{"Vp",0.21},{"Vf",0.10}};
unordered_map<string,double> parameter_kochi={{"A",22000},{"alpha",0.000011},{"delta",1.01},{"gamma",0.90},{"mew",0.143},{"mew1",0.155},{"N0",1800000},{"S0",1779000},{"E0",12000},{"I0",1500},{"R0",7500},{"Vp",0.23},{"Vf",0.12}};
unordered_map<string,double> parameter_visakhapatnam={{"A",23000},{"alpha",0.000011},{"delta",1.00},{"gamma",0.89},{"mew",0.143},{"mew1",0.155},{"N0",2000000},{"S0",1974000},{"E0",14000},{"I0",2000},{"R0",9600},{"Vp",0.19},{"Vf",0.09}};
unordered_map<string,double> parameter_guwahati={{"A",15000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",1100000},{"S0",1088000},{"E0",8000},{"I0",900},{"R0",2100},{"Vp",0.16},{"Vf",0.06}};
unordered_map<string,double> parameter_bhubaneswar={{"A",16000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",1200000},{"S0",1186000},{"E0",9000},{"I0",1100},{"R0",2900},{"Vp",0.17},{"Vf",0.07}};
unordered_map<string,double> parameter_dehradun={{"A",12000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",1000000},{"S0",988000},{"E0",7000},{"I0",900},{"R0",3100},{"Vp",0.18},{"Vf",0.08}};
unordered_map<string,double> parameter_srinagar={{"A",13000},{"alpha",0.000010},{"delta",1.00},{"gamma",0.88},{"mew",0.143},{"mew1",0.154},{"N0",1200000},{"S0",1186000},{"E0",9000},{"I0",1100},{"R0",2900},{"Vp",0.17},{"Vf",0.07}};


	unordered_map<string, double> parameter_tamilnadu = {
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
	
	unordered_map<string, double> parameter_maharashtra = {
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

	unordered_map<string, double> parameter_gujarat = {
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
	


	unordered_map<string, double> parameter_karnataka = {
    {"A", 1800000},
    {"alpha", 0.00001},
    {"delta", 1.30},
    {"gamma", 0.83},
    {"mew", 0.148},
    {"mew1", 0.165},
    {"N0", 67500000},
    {"S0", 66000000},
    {"E0", 120000},
    {"I0", 210000},
    {"R0", 1180000},
    {"Vp", 0.21},
    {"Vf", 0.11}
};

unordered_map<string, double> parameter_uttarpradesh = {
    {"A", 3500000},
    {"alpha", 0.00001},
    {"delta", 1.28},
    {"gamma", 0.82},
    {"mew", 0.152},
    {"mew1", 0.168},
    {"N0", 230000000},
    {"S0", 226000000},
    {"E0", 300000},
    {"I0", 450000},
    {"R0", 2400000},
    {"Vp", 0.17},
    {"Vf", 0.08}
};

unordered_map<string, double> parameter_westbengal = {
    {"A", 1600000},
    {"alpha", 0.00001},
    {"delta", 1.27},
    {"gamma", 0.83},
    {"mew", 0.146},
    {"mew1", 0.163},
    {"N0", 100000000},
    {"S0", 98500000},
    {"E0", 150000},
    {"I0", 220000},
    {"R0", 980000},
    {"Vp", 0.19},
    {"Vf", 0.10}
};

unordered_map<string, double> parameter_rajasthan = {
    {"A", 1400000},
    {"alpha", 0.00001},
    {"delta", 1.24},
    {"gamma", 0.84},
    {"mew", 0.144},
    {"mew1", 0.160},
    {"N0", 81000000},
    {"S0", 79800000},
    {"E0", 80000},
    {"I0", 150000},
    {"R0", 850000},
    {"Vp", 0.20},
    {"Vf", 0.10}
};

unordered_map<string, double> parameter_madhyapradesh = {
    {"A", 1300000},
    {"alpha", 0.00001},
    {"delta", 1.26},
    {"gamma", 0.83},
    {"mew", 0.147},
    {"mew1", 0.162},
    {"N0", 85000000},
    {"S0", 83500000},
    {"E0", 90000},
    {"I0", 170000},
    {"R0", 750000},
    {"Vp", 0.18},
    {"Vf", 0.09}
};

unordered_map<string, double> parameter_andhrapradesh = {
    {"A", 1500000},
    {"alpha", 0.00001},
    {"delta", 1.29},
    {"gamma", 0.84},
    {"mew", 0.145},
    {"mew1", 0.160},
    {"N0", 54000000},
    {"S0", 52500000},
    {"E0", 85000},
    {"I0", 160000},
    {"R0", 720000},
    {"Vp", 0.21},
    {"Vf", 0.11}
};

unordered_map<string, double> parameter_telangana = {
    {"A", 900000},
    {"alpha", 0.00001},
    {"delta", 1.28},
    {"gamma", 0.84},
    {"mew", 0.146},
    {"mew1", 0.162},
    {"N0", 40000000},
    {"S0", 38900000},
    {"E0", 65000},
    {"I0", 120000},
    {"R0", 500000},
    {"Vp", 0.22},
    {"Vf", 0.12}
};

unordered_map<string,double> parameter_bihar = {
	{"A",2400000},{"alpha",0.00001},{"delta",1.28},{"gamma",0.83},{"mew",0.148},{"mew1",0.166},
	{"N0",124000000},{"S0",122000000},{"E0",140000},{"I0",210000},{"R0",820000},{"Vp",0.15},{"Vf",0.07}
};

unordered_map<string,double> parameter_odisha = {
	{"A",700000},{"alpha",0.00001},{"delta",1.22},{"gamma",0.85},{"mew",0.142},{"mew1",0.158},
	{"N0",46000000},{"S0",45000000},{"E0",42000},{"I0",95000},{"R0",410000},{"Vp",0.19},{"Vf",0.10}
};

unordered_map<string,double> parameter_punjab = {
	{"A",600000},{"alpha",0.00001},{"delta",1.26},{"gamma",0.84},{"mew",0.147},{"mew1",0.161},
	{"N0",30000000},{"S0",29300000},{"E0",35000},{"I0",70000},{"R0",310000},{"Vp",0.22},{"Vf",0.12}
};

unordered_map<string,double> parameter_haryana = {
	{"A",550000},{"alpha",0.00001},{"delta",1.27},{"gamma",0.84},{"mew",0.146},{"mew1",0.160},
	{"N0",29000000},{"S0",28300000},{"E0",31000},{"I0",65000},{"R0",280000},{"Vp",0.23},{"Vf",0.12}
};

unordered_map<string,double> parameter_assam = {
	{"A",500000},{"alpha",0.00001},{"delta",1.20},{"gamma",0.86},{"mew",0.140},{"mew1",0.156},
	{"N0",35000000},{"S0",34400000},{"E0",20000},{"I0",45000},{"R0",150000},{"Vp",0.17},{"Vf",0.09}
};

unordered_map<string,double> parameter_jharkhand = {
{"A",520000},{"alpha",0.00001},{"delta",1.23},{"gamma",0.85},{"mew",0.143},{"mew1",0.158},
{"N0",39000000},{"S0",38200000},{"E0",28000},{"I0",56000},{"R0",210000},{"Vp",0.18},{"Vf",0.09}
};


unordered_map<string,double> parameter_chhattisgarh = {
	{"A",480000},{"alpha",0.00001},{"delta",1.24},{"gamma",0.85},{"mew",0.144},{"mew1",0.159},
	{"N0",30000000},{"S0",29200000},{"E0",32000},{"I0",61000},{"R0",170000},{"Vp",0.18},{"Vf",0.09}
};

unordered_map<string,double> parameter_himachal = {
{"A",120000},{"alpha",0.00001},{"delta",1.15},{"gamma",0.88},{"mew",0.135},{"mew1",0.150},
{"N0",7400000},{"S0",7200000},{"E0",4000},{"I0",9000},{"R0",28000},{"Vp",0.21},{"Vf",0.12}
};

unordered_map<string,double> parameter_uttarakhand = {
	{"A",150000},{"alpha",0.00001},{"delta",1.18},{"gamma",0.87},{"mew",0.137},{"mew1",0.152},
	{"N0",11200000},{"S0",10800000},{"E0",6000},{"I0",12000},{"R0",42000},{"Vp",0.22},{"Vf",0.12}
};


unordered_map<string,double> parameter_usa = {
	{"A",8000000},{"alpha",0.00001},{"delta",1.35},{"gamma",0.82},{"mew",0.155},{"mew1",0.170},
	{"N0",331000000},{"S0",320000000},{"E0",800000},{"I0",1200000},{"R0",8000000},{"Vp",0.45},{"Vf",0.35}
};

unordered_map<string,double> parameter_uk = {
	{"A",1500000},{"alpha",0.00001},{"delta",1.30},{"gamma",0.84},{"mew",0.150},{"mew1",0.165},
	{"N0",67000000},{"S0",63000000},{"E0",90000},{"I0",180000},{"R0",1500000},{"Vp",0.50},{"Vf",0.40}
};

unordered_map<string,double> parameter_germany = {
	{"A",1200000},{"alpha",0.00001},{"delta",1.28},{"gamma",0.84},{"mew",0.148},{"mew1",0.163},
	{"N0",83000000},{"S0",79000000},{"E0",110000},{"I0",210000},{"R0",1400000},{"Vp",0.48},{"Vf",0.38}
};

unordered_map<string,double> parameter_france = {
	{"A",1100000},{"alpha",0.00001},{"delta",1.27},{"gamma",0.84},{"mew",0.148},{"mew1",0.163},
	{"N0",67000000},{"S0",64000000},{"E0",95000},{"I0",180000},{"R0",1200000},{"Vp",0.46},{"Vf",0.36}
};

unordered_map<string,double> parameter_brazil = {
	{"A",4000000},{"alpha",0.00001},{"delta",1.33},{"gamma",0.83},{"mew",0.152},{"mew1",0.168},
	{"N0",213000000},{"S0",205000000},{"E0",420000},{"I0",780000},{"R0",3500000},{"Vp",0.30},{"Vf",0.20}
};

unordered_map<string,double> parameter_russia = {
	{"A",2500000},{"alpha",0.00001},{"delta",1.29},{"gamma",0.83},{"mew",0.150},{"mew1",0.165},
	{"N0",146000000},{"S0",140000000},{"E0",250000},{"I0",420000},{"R0",1800000},{"Vp",0.28},{"Vf",0.18}
};

unordered_map<string,double> parameter_china = {
	{"A",10000000},{"alpha",0.00001},{"delta",1.10},{"gamma",0.90},{"mew",0.120},{"mew1",0.140},
	{"N0",1440000000},{"S0",1430000000},{"E0",20000},{"I0",35000},{"R0",600000},{"Vp",0.60},{"Vf",0.50}
};

unordered_map<string,double> parameter_japan = {
	{"A",1800000},{"alpha",0.00001},{"delta",1.20},{"gamma",0.88},{"mew",0.135},{"mew1",0.150},
	{"N0",125000000},{"S0",120000000},{"E0",80000},{"I0",150000},{"R0",900000},{"Vp",0.52},{"Vf",0.40}
};

unordered_map<string,double> parameter_australia = {
	{"A",500000},{"alpha",0.00001},{"delta",1.05},{"gamma",0.92},{"mew",0.110},{"mew1",0.130},
	{"N0",25600000},{"S0",25200000},{"E0",5000},{"I0",9000},{"R0",45000},{"Vp",0.55},{"Vf",0.45}
};

unordered_map<string,double> parameter_canada = {
    {"A",700000},{"alpha",0.00001},{"delta",1.22},{"gamma",0.86},{"mew",0.140},{"mew1",0.155},
    {"N0",38000000},{"S0",37000000},{"E0",25000},{"I0",45000},{"R0",320000},{"Vp",0.55},{"Vf",0.45}
};

unordered_map<string,double> parameter_italy = {
    {"A",1200000},{"alpha",0.00001},{"delta",1.28},{"gamma",0.84},{"mew",0.148},{"mew1",0.162},
    {"N0",60000000},{"S0",57000000},{"E0",85000},{"I0",160000},{"R0",1200000},{"Vp",0.50},{"Vf",0.38}
};

unordered_map<string,double> parameter_southafrica = {
    {"A",1000000},{"alpha",0.00001},{"delta",1.30},{"gamma",0.83},{"mew",0.150},{"mew1",0.165},
    {"N0",60000000},{"S0",57500000},{"E0",90000},{"I0",150000},{"R0",850000},{"Vp",0.28},{"Vf",0.18}
};


inline unordered_map<string, unordered_map<string, double>> seir_params = {

    {"TRIVANDRUM", parameter_trivandrum},
    {"CHENNAI", parameter_chennai},
    {"DELHI", parameter_delhi},
    {"MUMBAI", parameter_mumbai},
    {"KOLKATA", parameter_kolkata},
    {"BENGALURU", parameter_bengaluru},
    {"HYDERABAD", parameter_hyderabad},
    {"AHMEDABAD", parameter_ahmedabad},
    {"GURGAON", parameter_gurgaon},
    {"PUNE", parameter_pune},
    {"TRICHY", parameter_trichy},
    {"MADURAI", parameter_madurai},
    {"INDORE", parameter_indore},
    {"CHANDIGARH", parameter_chandigarh},
    {"PATNA", parameter_patna},
    {"LUCKNOW", parameter_lucknow},
    {"RANCHI", parameter_ranchi},
    {"IMPHAL", parameter_imphal},
    {"BHOPAL", parameter_bhopal},
    {"JAIPUR", parameter_jaipur},
    {"SURAT", parameter_surat},
    {"VADODARA", parameter_vadodara},
    {"NAGPUR", parameter_nagpur},
    {"COIMBATORE", parameter_coimbatore},
    {"KOCHI", parameter_kochi},
    {"VISAKHAPATNAM", parameter_visakhapatnam},
    {"GUWAHATI", parameter_guwahati},
    {"BHUBANESWAR", parameter_bhubaneswar},
    {"DEHRADUN", parameter_dehradun},
    {"SRINAGAR", parameter_srinagar},
	{"TAMIL_NADU", parameter_tamilnadu},
	{"MAHARASHTRA", parameter_maharashtra},
	{"GUJARAT", parameter_gujarat},
	{"DELHI", parameter_delhi},
	{"KARNATAKA", parameter_karnataka},
	{"UTTAR_PRADESH", parameter_uttarpradesh},
	{"WEST_BENGAL", parameter_westbengal},
	{"RAJASTHAN", parameter_rajasthan},
	{"MADHYA_PRADESH", parameter_madhyapradesh},
	{"ANDHRA_PRADESH", parameter_andhrapradesh},
	{"TELANGANA", parameter_telangana},
	{"BIHAR", parameter_bihar},
	{"ODISHA", parameter_odisha},
	{"PUNJAB", parameter_punjab},
	{"HARYANA", parameter_haryana},
	{"ASSAM", parameter_assam},
	{"JHARKHAND", parameter_jharkhand},
	{"USA", parameter_usa},
	{"UK", parameter_uk},
	{"GERMANY", parameter_germany},
	{"FRANCE", parameter_france},
	{"BRAZIL", parameter_brazil},
	{"RUSSIA", parameter_russia},
	{"CHINA", parameter_china},
	{"JAPAN", parameter_japan},
	{"AUSTRALIA", parameter_australia},
	{"CANADA", parameter_canada},
	{"ITALY", parameter_italy},
	{"SOUTH_AFRICA", parameter_southafrica},
};
	

