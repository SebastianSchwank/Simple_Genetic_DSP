/* 
	Project Name (@Param "-ProjName:"):
				The ProjName specifies the Name of the Project or determines the Path to a already existing Project.
				The suffix for the Project files is ".dspg"
				
				Syntax : DSPGen.out -ProjName: myProjects/myProject.dspg
				
	Basic IO (@Param: "-Files:" ):
				Basic acess is given by passing pairs of .wav Files to the Application via Commandline:
					
					- The first one is the given INPUT File which is the "source"-Signal for the "calculation-graphs" beeing generaterated
					- The second one is the giiven TARGET File which is the target-Signal for the "calculation-graphs" the Mean-Error per Sample is defined as fittness funcion
					
					Syntax: DSPGen.out -Files: [Path to the INPUT-File ; Path to the Target File][Path to the INPUT-File ; Path to the Target File] ... 
					
					Note:	- Multible access to the same File is possible
							- only .wav-Files are supported
							- All Input Files must have the same length !!!
							- All Target Files must have the same length !!!
							
*/


#include <iostream>
#include "DSPGen.h"

int main(int argc, char *argv[]){
	
	std::cout << "Hallo Cloud ! \n";
	
}