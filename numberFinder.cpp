#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

	int nums[99];
	int x;
	int numBadNums = 0;		// count of the numbers not considered
	int numLeft = 54;

int main(){
	
	int pool[numLeft];
	int noGoodNums[numLeft];
	
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
	int c = 0;
	while(inFile >> x){
		nums[c] = x;  	// nums[] holds previously selected numbers
		c++;
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
					noGoodNums[numBadNums] = fTemp;
					numBadNums++;
				}else{
					fTemp = nums[i] - difference;
					noGoodNums[numBadNums] = fTemp;
					numBadNums++;
				}
			}
		}
	}
	
	for(int i = 0; i < numBadNums; i++){
		cout << noGoodNums[i] << " ";
	}
	cout << endl;
	
	inFile.close();
	
	return 0;
}
