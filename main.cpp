
#include "graph.h"


int main()
{
	
	City cse;
	
	cse.loadCity("input.txt");
	cse.printCityGraph();
	cse.isTherePath(2,4);
	cse.isTherePath(0,4);
	cse.isTherePath(1,2);
	cse.isTherePath(0,5);
}
