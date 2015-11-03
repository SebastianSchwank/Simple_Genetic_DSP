/* This class should provide basic acess to the capability of generating "calculation graphs" from given signals by minimizing the error with a evolutionary-strategy */


#include <string>
#include <vector>

class DSPGen{
	
	public:
		//@Constructor_DSPGen:
		//To create the DSPGen pass EQUAL NUMBER of Source/Target - SignalPaths to the constructor
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
									
				- maxInitalPopulationStringLength: sets the max length of the randomly generated strings which describe the populating Graphs
									@DefaultVal = -1 : This means this number will be calculated later (auto)
									
									WARNING: Setting this Number to low in terms of the Input-/Target-Signals will cause problems within the optimisation Process
									
				- avgErrBreak: This Number determine which Avg-Quad-Error per Sample will cause the stopping of the whole process
									@DefaultVal = 0.0 : This default value will cause that the programm never stops
									
				- autoSaveBest: This param determines if the Best-GraphIndividual from each generation will be saved as a .txt-File to the disk (consecutive numbered Files)
									@DefaultVal = true
									
				- autoSavePop: Here we can choose if we want to save the whole Population after each Generation to disk (consecutive numbered Files)
									@DefaultVal = true
									
									Note: This files could be loaded later again for reprocessing
		*/
		initRandom(bool minimizeGraph = false,int populationSize = 128, int maxInitalPopulationStringLength = -1, float avgErrBreak = 0.0, bool autoSaveBest = true, bool autoSavePop = true);
	

	
	
	
	
}