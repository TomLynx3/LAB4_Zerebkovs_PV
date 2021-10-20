// LAB4_Zerebkovs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>




void printResult(char result[], int size,int exponent) {

	printf("2^%d = ",exponent);
	for (int i = size; i >= 0; i--) {
		std::cout << result[i];
	}
	std::cout << "\n";
}

void pow(int exponent) {
	int finalResultSize = 0;
	char result[10000] = { '2' };
	int partialResultSize = 0;
	int mod = 0;

	for (int i = 0; i < exponent - 1; i++) {

		for (int j = 0; result[j] != 0; j++) {
			int mul = (result[j] - '0') * 2 + mod;

			result[j] = mul % 10 + '0';

			mod = mul / 10;

			partialResultSize++;
		}

		while (mod) {
			result[partialResultSize] = mod % 10 + '0';
			mod = mod / 10;
		}

		finalResultSize = partialResultSize;
		partialResultSize = 0;
	
	}
	printResult(result, finalResultSize,exponent);
}


int main()
{
	int exponent = 0;

	int choice = 1;


	while (choice == 1) {

		printf("Enter exponent = "); scanf("%d", &exponent);

		if (exponent > 0 && exponent < 256) {
			pow(exponent);
		}
		else {
			printf("Please enter number from 1 to 255\n");
		}

		
		printf("Try one more time? - 1 \nExit from program - 0\n"); scanf("%d", &choice);
		
	}


	

	
}

