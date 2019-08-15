#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

	int nums[99];
	int x;
	int numBadNums = 0;		// count of the numbers not considered
	int numLeft = 54;
	int numOfLottoNums = 0;

int main(){
	
	int pool[numLeft];
	int noGoodNums[numLeft];
	int findLastNum[numLeft];
	int numOfTimesPerNum[numLeft];
	// pool[] will hold all the numbers available to be selected from
	for(int a = 0; a < numLeft; a++){
		pool[a] = (a + 1);
	}
	
	ifstream inFile;
	inFile.open("pastNumbers.txt");
	if(!inFile){
		cout << "Unable to open file";
		return 0;
	}
	//int c = 0;
	while(inFile >> x){
		nums[numOfLottoNums] = x;  	// nums[] holds previously selected numbers
		numOfLottoNums++;
	}
	
	// We don't want to consider any of the 6 numbers which were last selected
	for(int i = 0; i < 6; i++){
		noGoodNums[i] = nums[i];
		numBadNums++;
	}
	
	for(int i = 0; i < numBadNums; i++){
		cout << noGoodNums[i] << " ";
	}
	cout << endl;
	
	int fTemp;
	int difference;
	// take away future multiples
	for(int i = 0; i < 6; i++){
		for(int j = 6; j < 12; j++){
			difference = abs(nums[i] - nums[j]);
			if(difference <= 7){
				if(nums[i] > nums[j]){
					fTemp = nums[i] + difference;
					if(fTemp <= 54){
						noGoodNums[numBadNums] = fTemp;
						numBadNums++;
					}
				}else{
					fTemp = nums[i] - difference;
					if(fTemp > 0){
					noGoodNums[numBadNums] = fTemp;
					numBadNums++;
					}
				}
			}
		}
	}
	
	// same thing as before, just remove future mults from rows 4 to 2
	for(int i = 6; i < 12; i++){
		for(int j = 18; j < 24; j++){
			difference = abs(nums[i] - nums[j]);
			if(difference <= 7){
				if(nums[i] > nums[j]){
					fTemp = nums[i] + difference;
					if(fTemp <= 54){
						noGoodNums[numBadNums] = fTemp;
						numBadNums++;
					}
				}else{
					fTemp = nums[i] - difference;
					if(fTemp > 0){
					noGoodNums[numBadNums] = fTemp;
					numBadNums++;
					}
				}
			}
		}
	}
	
	// Find the number which was selected the longest time from present
	for(int i = 0; i < 54; i++){
		findLastNum[i] = i + 1;
	}
	// If a number has recently been used, mark it with a 0
	for(int x = 0; x < numOfLottoNums; x++){
		int temp = nums[x];
		findLastNum[temp - 1] = 0;  // number recently used, we don't want
	}
	// Just seeing if it works...
	for(int a = 0; a < 54; a++){
		cout << findLastNum[a] << " ";
	}
	cout << endl;
	
	// Find the 10's range which was last selected...
	int zero10s, ten10s, twenty10s, thirty10s, forty10s, fifty10s = 0;
	for(int x = 0; x < numOfLottoNums; x++){
		int temp = nums[x] / 10;
		if(temp < 1)
			zero10s++;
		else if(temp < 2)
			ten10s++;
		else if(temp < 3)
			twenty10s++;
		else if(temp < 4)
			thirty10s++;
		else if(temp < 5)
			forty10s++;
		else
			fifty10s++;
	}
		cout << "0's: " << zero10s << endl;
		cout << "10's: " << ten10s << endl;
		cout << "20's: " << twenty10s << endl;
		cout << "30's: " << thirty10s << endl;
		cout << "40's: " << forty10s << endl;
		cout << "50's: " << (fifty10s * 2) << endl;  // since only 5 #'s in 50 range
	
	// How many times have each numbers been picked recently
	for(int i = 0; i < 54; i++){
		numOfTimesPerNum[i] = 0;
	}
	
	for(int x = 0; x < numOfLottoNums; x++){
		int temp = nums[x];
		numOfTimesPerNum[temp - 1] = numOfTimesPerNum[temp - 1] + 1;
	}
	
	for(int x = 0; x < 54; x++){
		cout << (x + 1) << ":  " << numOfTimesPerNum[x] << endl;
	}
	
	// Just to print out the bad numbers, currently having duplicates 
	for(int i = 0; i < numBadNums; i++){
		cout << noGoodNums[i] << " ";
	}
	
	
	cout << endl;
	
	inFile.close();
	
	return 0;
}
