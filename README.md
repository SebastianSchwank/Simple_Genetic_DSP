# Simple_Genetic_DSP

This Framework should provide the abitlity to envolve a "calculation-graph" from a set of input->target signals minimizing the processing error through genetic algorythms.

#DNA-Structure

The basic gene structure consists of four Types of Objects:

- Operators ( J = Join | M = Modify)
		J: The Join Operator joins one or more different Nodes together by an given Modificator eg. f(x,y)
		M: The Modify Operator modifies one singel Data Stream with a given Function f(x)
		
- Weighted Arethmetics ( + , - , * , < , > , exp, sin )
		A Weighted Aretmetic should provide the possibility to calculatate an Error for a Aretmetic operation.
		The generall arethmetic is described as following:
		
			- f(x,y) = w(+)*(x+y) + w(*)*(x*y) + w(<)*(x<y) + w(>)*(x>y)
			... for the J Operator
			and
			- f(x) =  w(+)*(+x) + w(-)*(-x) + w(sig)*(sigmoid(x)) + w(exp)*(exp(x))
			... for the M Operator
			
			So each node is described by an weighted operation defined by a weight-vector v4b which will be modiefied later by evaluation and correction.
			Note that the v4 - weight vector is normed after each modification to the length 1 so that the maximal amount of one arethmetic is limited to 1
			whereas the other arethmetics fall to 0.
		
- Adressators & Constants ( # = Input | $ = Target | ~ = Transterminal & c = ConstantFloatNumber)
		# : The Input-Adressators refers to a given Input adressed by "#" followed by the Index of the Inputcell
		$ : The Target-Adressator refers to a given Target adressed by "$" followed by the Index of the Targetcell
		~ : The Transterminal-Adressator is a genericly generated Adress Point which is generated in runtime its weather a targetcell nor a inputcell
		c : The Constant is a floating point number envolved by the system and can be used like in normal calculations as a constant factor
		
- Allocator & Sepperator ( = & ; )
		= : The allocator links the given Adressators to the operation given on the right side of the equation
		; : The sepperator sepperates the Arguments from each other
		
	Example:
		The input length is given as two cells, The output length is defined as one cell so here's a code-example describing a process:
		
		~0		= J(0.32;...)[#0;#1]
		~1 		= M(...)[~0]
		~2		= J(...)[#0;c=3.1415]
		~3		= J(...)[~1;~0]
		~4		= J(...)[~2;~1]
		$0		= J(...)[~3;~4]
		
	Notes:
			- Every line of code represents a node in the graph
			- Branching is made by using the same ~/Transterminal multible times
			- The order of the Nodes is determined by the Transterminals which are already declared
			- Only TWO (2) Transterminals can be joined at the same time
			- Branching is not restricted
			
#Random Inital Population Generation

The inital population is generated as following:
	
	1st:	Generate a empty Input Target Graph.
	2nd:	Generate several Transterminals wheras the number of Transterminals is limited by a PARAMETER defined by the user.
	3rd:	Generate a varying number of lines of Code wheras the Adressators are choosen randomly from the pool of existing Adressators
			and the Operats and Modificators are choosen randomly.
			The maximal number of codelines is limited by a user-choosen PARAMETER.



#Selection Algorythm (Global Selection)

Two selection algorythms are provided by the programm both are determined by the parameter "n" which is the number of individuals which remain in the DNA-Pool for population:

	1st: Russian Roulett elemination till "n" GraphIs' remain. Higher error causes higher probability to be eleminated.
	2nd: Take the "n" top GraphIs' with the lowerst error.
	
#Crossing (Local Selection)

The crossing is basically done by local error evaluation whereas we have one dominating DNA which is ---more likely--- to push trough is a part of the graph with the lower error.
The error is calculated backwards through the graph whereas each node of the Graph gets a Error-Quantifier depending on input and the error to the target.
The Error-Quantifiers are accumulated over the several Input Target exercises the Graph has to solve for survial.
The exact process is described below:

(Prenote: Mutations are not included at this point !!)
(4Me_PapesToRead: http://www.math.drexel.edu/~tolya/propagationarithmetic.pdf)
		
	1st: Evaluationg an Error-Quantifier for each Node
			
			!!! Warning !!! Experimental - Theory : 
							In this approach i'll use a stocatical iterative algorythm to get the Error-Quantifier for each symbol in the DNA Code
							For that we'll have to make some experimental hypotheses which could be emphasize as wrong. So note that from this point the Programm could be completly false.
							It's just a coding experiment so join me on this journey if you want to.
							
							1.0 The "everything is any before it's prooven wrong"-hypotheses:
										The problem you could see when try to backpropagate the calculated error through the Graph is how to distribute it "correctly" in the graph.
										So what is "correctly" ? In my case the correctness of the number behind the equation is not so important.
										It's more important that the propotions between the numbers are approximated fast and these numbers are meaningful and compareable to each other and between
										different Graphs.
										
										So lets make a weired try to get these numbers:
										
										$0 = J(0.32;...)[#0;#1]
										The target is defined as:
										$0 = J(1.0;0.0;0.0;0.0)[#0;#1]
										
										So here the first approach is to modifie the weighted arethmetic correctly (or as best as we get it).
										So the equations we've now is:
										
										Error = Output - Target
										whereas:
										Output = w(+)*(x+y) + w(*)*(x*y) + w(<)*(x<y) + w(>)*(x>y)
										
										So if we suppose that Error(y) = 0.0 and Error(x) = 0.0 but Error(Output) = E(xoy) we have to adjust the weights in a way we get less error.
										But how we can find that "way" ?
										Let's try it with a random momentum driven error weighted approach we already know from neural networks. Basically it works like:
										
										If my next random step is better in error than the last one was add him highly to the new weights. If not so add him less high to the new weights.
										
										The "highness" or "lowness" of the random step is basically defined a function over the current Error (@Me_search4theBestFittingFunction).
										So in general the random momentum error minimasation looks like:
										
										weights_n+1 = normalize( weights_n + momentum )
										
										whereas the momentum is defined recursivly as:
										
										momentum = momentum + sigmoid(Error_n) * normalize( randomChoosenVector[0..1] )
										
										For the evaluation of the "completness" of the graph we need another variable determine the JITTERING of the momentum. Lower jittering indicates that the nod is stable
										higher jittering indicates that we have to change something "around" the node for that we introduce a fluctuation factor flux.
										
										flux = flux + momentum + sigmoid(Error_n) *
										
										
										For that we trace ONE Path of the error backwards assuming that the other Path is already calculated correctly (what we can assume bcs. the other branch is linked to the input).
							
							
							
							
							
	
#Mutation (Local Modifications)