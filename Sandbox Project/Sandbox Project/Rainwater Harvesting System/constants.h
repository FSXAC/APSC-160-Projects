// necessary imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// math
#define PI cos(-1)

// global satisfaction index position reference
const int
S_CONSUMP = 0,
S_COST = 1,
S_ENV = 2,
S_MAINTEN = 3,
S_ODF = 4,
S_RELIAB = 5;

// global satisfaction obejectives / requirements
const int SATISFACTION_MIN[] = {
	150,
	30,
	0,
	8,
	15,
	250
};

const int SATISFACTION_MAX[] = {
	625,
	170,
	1,
	95,
	30,
	360
};

// satisfaction weightings
const double SATISFACTION_WEIGHT[] = {
	0.2,
	0.25,
	0.1,
	0.15,
	0.15,
	0.15
};

// global specification value positions
const int SPEC_COMSUMPTION = 0;
const int SPEC_ROOF = 1;
const int SPEC_HAS_ADDITIONAL = 2;
const int SPEC_ADDITIONAL_AREA = 3;
const int SPEC_ADDITIONAL_X = 4;
const int SPEC_ADDITIONAL_Y = 5;
const int SPEC_HAS_CATCHMENT_TANK = 6;
const int SPEC_CATCHMENT_TANK = 7;
const int SPEC_STORAGE_TANK = 8;
const int SPEC_STORAGE_X = 9;
const int SPEC_STORAGE_Y = 10;
const int SPEC_HAS_TOWER = 11;
const int SPEC_TOWER_HEIGHT = 12;
const int SPEC_PUMP = 13;
const int SPEC_FILTER_DIR = 14;
const int SPEC_FILER_1 = 15;
const int SPEC_FILTER_5 = 16;
const int SPEC_FILTER_200 = 17;
const int SPEC_UV = 18;
const int SPEC_POWERGEN = 19;
const int SPEC_SOLAR_PANEL = 20;
const int SPEC_SOLAR_PANELS = 21;
const int SPEC_INVENTER = 22;
const int SPEC_BATTERIES = 23;

// global component costs
const int COST_ROOF_HALF = 0;
const int COST_ROOF_FULL = 350;
const int COST_ADDITIONAL = 100;
const int COST_COLLECTION_TANK_400 = 200;
const int COST_COLLECTION_TANK_1500 = 500;
const int COST_COLLECTION_TANK_2500 = 900;
const int COST_COLLECTION_TANK_10000 = 2000;
const int COST_STORAGE_TANK = 250;
const int COST_TOWER_A = 45;
const int COST_TOWER_B = 200;
const int COST_PIPING = 40;
const int COST_FILTER_1 = 125;
const int COST_FILTER_1_REPLACEMENT = 75;
const int COST_FILTER_5 = 110;
const int COST_FILTER_5_REPLACEMENT = 60;
const int COST_FILTER_200 = 100;
const int COST_FILTER_200_REPLACEMENT = 50;
const int COST_UV_36 = 500;
const int COST_UV_36_REPLACEMENT = 90;
const int COST_UV_50 = 750;
const int COST_UV_50_REPLACEMENT = 110;
const int COST_PUMP_A = 580;
const int COST_PUMP_B = 1400;
const int COST_PUMP_C = 3500;
const int COST_SOLAR_A = 500;
const int COST_SOLAR_B = 205;
const int COST_SOLAR_C = 450;
const int COST_BATTERY = 390;
const int COST_INVERTER = 2369;
const int COST_GENERATOR = 3500;
const int COST_GENERATOR_FUEL = 50;
const int COST_WATER_IMPORT = 75;