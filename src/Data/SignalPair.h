/*  This calss should realize the structured acess on a single Input-/Target-Pair.
	It also gives the Programm access to the .wav-Files on the disk by the subclass "IO_wav"
	Warning: It also normalizes the input to [-1.0;1.0]
*/

#include <string>

class SignalPair 
{
	SignalPair(string pathToInput,string pathToTarget);
	
	//This function gives basic access to the Target Signal by index
	float getT(int index);
	//This function gives basic access to the Input Signal by index
	float getI(int index);
	
	//This function provides rotation of both vectors by "rot"-steps
	void rotate(int rot);
	
	//This function calculates the quadratic average error for the genSignal against the target signal
	//The return value is calculated as following: ret = sqrt{ sum(i = 0; i < #i; i++)[(targetSignal[i]-genSignal[i])²]/(#i) }
	float getAvgQuadErrToTgt(vector<float> signal);
	
	private:
		vector<float> 		Input;
		vector<float> 		Target;
		int					len;
}