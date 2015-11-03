# Simple_Genetic_DSP

This Framework should provide the abitlity to envolve a "calculation-graph" from a set of input->target signals minimizing the processing error through genetic algorythms.




#DNA-Structure

The basic gene structure consists of four Types of Objects:

- Operators ( J = Join | B = Branch | M = Modify)
		J: The Join Operator joins one or more different Nodes together by an given Modificator eg. f(x,y,z)
		B: The Branch Operator branches a Data Stream into two ore more other streams. The Transterminale it branches into is given by the "~" - Adressator
		M: The Modify Operator modifies one singel Data Stream with a given Function f(x)
		
- Modificators ( + , - , * ... )
		A modificator is a general mathematic function which determines the how the given input is processed
		
- Adressators & Constants ( @# = Input | @$ = Target | @~ = Transterminal & @c=FloatNumber)
		# : The Input-Adressators refers to a given Input adressed by "#" followed by the Index of the Inputcell
		$ : The Target-Adressator refers to a given Target adressed by "$" followed by the Index of the Targetcell
		~ : The Transterminal-Adressator is a genericly generated Adress Point which is generated in runtime its weather a targetcell nor a inputcell
		c : The Constant is a floating point number envolved by the system and can be used like in normal calculations as a constant factor
		
- Allocator & Sepperator ( = & ; )
		= : The allocator links the given Adressators to the operation given on the right side of the equation
		; : The sepperator sepperates the Arguments from each other