#include "ClosenessDist.h"

void ClosenessDist::RunSim(Config &config, RegionAreas &areas)
{
	//gets the adjacency list
	vector<vector <int> > adj = areas.getList();
	
	//creates an updatable list of the areas
	vector <RegionArea> currentState;// creates an area list that can be updated
	for (int i = 1; i < areas.size() + 1; i++){
		currentState.push_back(areas.getArea(i));
	}
	
	calcClosenessVals(adj, currentState);
	
	//Run Simulation
	allocateVaccines(currentState, config.getNumOfVaccines());
	vector <RegionArea> previousState;
	
	cout << "CLOSENESS DISTRIBUTION\n";
	do{
		int day = 0;
		printDay(currentState, day);
		previousState = currentState;
		day++;
	}while(previousState != currentState);
	
	return;
}
void ClosenessDist::printDay(vector <RegionArea> &areas, int day){
	cout << "Day " << day << endl;
	for (int i = 0; i < areas.size(); i++){
		cout << i + 1 << "\tCvalue: " << setprecision(3) << areas[i].getCValue() << "\tPOP: " << areas[i].getPopulation();
		cout << "\tS: " << areas[i].getSusceptible();
		cout << "\tI: " << areas[i].getInfected();
		cout << "\tR: " << areas[i].getRecovered();
		cout << "\tV: " << areas[i].getVaccinated() << endl;
	}
	cout << endl;
	return;
}
bool ClosenessDist::BFS(vector <vector<int> > adj, int src, int dest, int v, int pred[], int dist[]){ // Standard BFS search
    list<int> queue;
    bool* visited = new bool[v];
	
    for (int i = 0; i < v; i++){
		visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
	
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty()){
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++){
            if (visited[adj[u][i]] == false){
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
				
				if (adj[u][i] == dest){
					delete[] visited;
                   return true;
				}
            } 
        } 
    } 
	delete[] visited;
    return false; 
}
int ClosenessDist::shortestDist(vector <vector<int> >adj, int s, int dest, int v){ 
	int* pred = new int[v];
	int* dist = new int[v];
  
    if (BFS(adj, s, dest, v, pred, dist) == false){// returns a distance of 0 since the nodes are not connected
        return 0;
    }
 
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
	
    while (pred[crawl] != -1){// runs through and adds up the paths
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
	
	delete[] pred;
	delete[] dist;
	return dist[dest];
}
void ClosenessDist::calcClosenessVals(vector<vector <int> > adj, vector <RegionArea> &areas){
	//calculates Closeness Values
	float length = 0;// stores length of shortest path from source to destination
	for(int i = 0; i < adj.size(); i++){//loops through all nodes for start nodes
		int source = i;
		for(int j = 0; j < adj.size(); j++){// loops through all nodes for dest nodes
			if(i != j){// skips itself
				int dest = j;
				length += shortestDist(adj, source, dest, adj.size());// gets shortest path
			}
		}
		float cValue = length/static_cast<float>(adj.size());//calculates closeness value
		length = 0;
		areas[i].setCValue(cValue);
	}
	return;
}
void ClosenessDist::allocateVaccines(vector <RegionArea> &areas, int vaccines){
	
	struct A { float areaData[2]; };// creates a struct to sort easier [areaID][cValue]
	A* arr = new A[areas.size()];
	for (int i = 0; i < areas.size(); i++){
		arr[i].areaData[0] = i;
		arr[i].areaData[1] = areas[i].getCValue();
	}
	
	//bubble sort for cValues
	for(int i = 0; i < areas.size() - 1; i++){
		for (int j = 0; j < areas.size() - i - 1; j++){
			if(arr[j].areaData[1] > arr[j+1].areaData[1]){// compares cValues
				A tempArea = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tempArea;
				
			}
		}
	}
	for(int i = 0; i < areas.size(); i++){
		//cout << arr[i].areaData[0] + 1 << ":" << arr[i].areaData[1] << endl;
		if(vaccines > 0){
			if(vaccines - areas[arr[i].areaData[0]].getPopulation() > 0){// enough vaccines for the pop
				areas[arr[i].areaData[0]].setVaccinated(areas[arr[i].areaData[0]].getPopulation());
				vaccines = vaccines - areas[arr[i].areaData[0]].getPopulation();
			}else{// allocates remaining vaccines to the area
				areas[arr[i].areaData[0]].setVaccinated(vaccines);
				vaccines = 0;
			}
		}else{
			delete[] arr;
			return;
		}
	}

	delete[] arr;
}

