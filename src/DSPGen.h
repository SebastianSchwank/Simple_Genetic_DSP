/* This class should provide basic acess to the capability of generating "calculation graphs" from given signals by minimizing the error with a evolutionary-strategy */


#include <string>
#include <vector>

#include "GraphIndividual/GraphI.h"
#include "Data/SignalPair.h"

class DSPGen
{
	public:
		//@Constructor_DSPGen:
		//To create the DSPGen pass EQUAL NUMBER of Source/Target - SignalPaths to the constructor
		//Note that ALL signals must have the same length !
		//Set the Project-Name by hand over the last Parameter to a NAME for the Project
		DSPGen(vector<string> PathsToSourceSignals, vector<string> PathsToTargetSignals, string ProjName);
		
		//@InitRandom:
		//To initalise the DSPGen with random population use this function.
		//DSPGen will initalise with the default values (see @DefaultVal for details)
		//Parameters are:
		/*		- minimizeGraph : says if the "size"/length of a Graph influences the fittness of the Graph negatively (shorter Graphs are fitter)
									@DefaultVal = false
									
				- populationSize : sets a fix number of Graphs which determine the number of individual Graphs we're working on 
									@DefaultVal = 128
									
				- maxInitalStringLength: sets the max length of the randomly generated strings which describe the populating Graphs
									@DefaultVal = -1 : This means this number will be calculated later (auto)
									
									WARNING: Setting this Number to low in terms of the Input-/Target-Signals will cause problems within the optimisation Process
		*/
		void initRandom(bool minimizeGraph = false,int populationSize = 128, int maxInitalStringLength = -1);
		
		//@Run:
		//To run the DSP-Code-Generation by genetic algorythms use this function.
		//Parameters are:
		/*
				- avgErrBreak: This Number determine which Avg-Quad-Error per Sample will cause the stopping of the whole process
									@DefaultVal = 0.0 : This default value will cause that the programm never stops
									
				- autoSaveBest: This param determines if the Best-GraphIndividual from each generation will be saved as a .txt-File to the disk (consecutive numbered Files)
									@DefaultVal = true
									
									Note: This files could be loaded later again for reprocessing
									
				- autoSavePop: Here we can choose if we want to save the whole Population after each Generation to disk (consecutive numbered Files)
									@DefaultVal = true
									
									Note: This files could be loaded later again for reprocessing
									
		*/
		//Retrun Value is:
		//The return value represents the Graph as String with the lowerst error in terms of the given Input/Target-Signals
		string run(float avgErrBreak = 0.0, bool autoSaveBest = true, bool autoSavePop = true);
		
		//@Destructor_DSPGen
		~DSPGen();
	private:
	
		bool	mMinimizeGraph;
		int		mPopulationSize;
		int		mMaxStringlength;
		float	mAvgErrBreak;
		bool	mAutoSaveBest;
		bool	mAutoSavePop;
		
		vector<GraphI>		mPopulation;
		vector<SignalPair>	mInputTargetPair;
	
	
	
}