
#include <iostream>
#include <string>


using namespace std;

int knapsack(int weight[], int value[], int n, int W){
	int K[n+1][W+1];
	for(int i =0;i<=n;i++){
		for(int w = 0; w<=W;w++){
			if(i ==0 || w == 0){
				K[i][w]=0;
			}
			else if (weight[i-1] <= w){
				K[i][w]=(value[i-1]+K[i-1][w-weight[i-1]]> K[i-1][w])?value[i-1]+K[i-1][w-weight[i-1]]:K[i-1][w];
			}
			else {
				K[i][w] = K[i-1][w];
			}
		}

	}
return K[n][W];
}


int main(){
	//How many rupees is each treasure worth
	int value [] = {210, 220, 180, 120, 160, 170,90,40,60,10};
	int weight [] = {15,12,10,9,8,7,5,4,3,1};
	//How Strong are you?
	//i.e how much weight can you carry?
	int W = 26;
	//How many items are there?
	int n = 10;

	//Output the value in ruppees of what you're able to carry
	//Your output for this example should be 520
	std::cout << knapsack (weight, value, n, W) << std::endl;

	return 0;

}
