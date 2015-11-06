//This source code shoud demonstrate a way to use a divergent iterations to evaluate/qualify the Error of a given Node in the Graph

#include <iostream>
#include <random>

using namespace std;

float mean(float x,float y){
	return (x+y)/2.0;
}
	
	
int main(){
	
	float accErrorI0  = 0.0
	float accErrorI1  = 0.0
	float accErrorTT1 = 0.0
	float accErrorTT2 = 0.0
	float accErrorTT3 = 0.0
	float accErrorO0  = 0.0
		
	for(int iterations = 0; iterations < 128; iterations++){
	
			float i0 = (double)random()/(0.5*RAND_MAX)-1.0;
			float i1 = (double)random()/(0.5*RAND_MAX)-1.0;

			float t0 = i0 + i1;
			float t1 = i0 * i1 + i1;

			//Calculate forward with a wrong choosen set of mathematical operators
			float transTerm1 = i0 * 0.24;
			float transTerm2 = i1 + transTerm1;
			float transTerm3 = transTerm2 * i1;
			
			float o0		 = transTerm3 + i0;
			float o1		 = transTerm2 * transTerm3;
			
			float e0		 = o0 - t0;
			float e1		 = o1 - t1;
			cout << "Resulting Error of the current graph: " << e0 << "\n";


			//Backpropagate the error through the Graph and forward propagate the resulting error forward again
			int maxIt = 32;
			for(int i = 0; i < maxIt; i++){
				
			}
		
	}
	
}