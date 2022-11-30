/*Mirhasan Haji Hasanli
20220702121
Labwork GraphOdd
*/


#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;
class City{
	
	private:
	int * * distanceGraph;
	int numberOfCity;
	void createCityGraph();
	
	
	public:
	
	void loadCity(string file);
	void printCityGraph();
	void isTherePath(int city1, int city2);
};


void City::createCityGraph()
{
	distanceGraph = new int*[numberOfCity];
	for(int i=0; i<numberOfCity;i++)
	distanceGraph[i] = new int[numberOfCity];
		for(int i=0; i<numberOfCity;i++)
			for(int j=0; j<numberOfCity; j++)
				distanceGraph[i][j]=0;
}

void City::printCityGraph()
{
	cout<<"city\t";
	for(int i=0; i<numberOfCity; i++)
	cout<<i<<"\t";
	cout<<endl;
	for(int i=0; i<numberOfCity; i++)
	cout<<"-\t";
	cout<<endl;
	for(int i=0; i<numberOfCity; i++){
		cout<<i<<"\t";
		for(int j=0; j<numberOfCity; j++){
			cout<<distanceGraph[i][j]<<"\t";
		}
		cout<<endl;
		}
		
	cout<<"------------------------------------\n\n";
		
	}
	

void City::isTherePath(int city1, int city2)
{
	if(city1<0 || city1>=numberOfCity || city2<0 || city2>=numberOfCity){
		cout<<"Invalid city index " <<endl;
		return;
	}
	if (city1 == city2){
		cout<<"Yes there is a path from " <<city1<<" to "<<city2<<endl;
		return;
	}
	bool *visited = new bool[numberOfCity];
	for (int i=0; i<numberOfCity; i++)
		visited[i]=false;
	queue<int>myQueue;
	visited[city1]=true;
	myQueue.push(city1);
	while (!myQueue.empty()){
		int s = myQueue.front();
		myQueue.pop();
		for(int j=0; j<numberOfCity; j++){
			if(distanceGraph[s][j]>0){
				if(j==city2){
					cout<<"Yes there is a path from "<<city1<<" to "<<city2<<endl;
					return;
					
				}
				if (!visited[j]){
					visited[j] = true;
					myQueue.push(j);
				}
			}
		}
	}
	cout<<"NO, there is no path from "<<city1<<" to "<<city2<<endl;
}

void City::loadCity(string filename)
{
	ifstream file;
	file.open(filename.c_str());
	int city1,city2,distance;
	
	file>>numberOfCity;
	createCityGraph();
	
	while(file>>city1)
	{
		file>>city2;
		file>>distance;
		distanceGraph[city1][city2] = distance;
		
	}
	file.close();
}
