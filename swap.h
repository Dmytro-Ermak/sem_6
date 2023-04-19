#pragma once
#define SWAP(var_1, var_2) ({typeof(var_1) var_temp = var_1; var_1 = var_2; var_2 = var_temp;})