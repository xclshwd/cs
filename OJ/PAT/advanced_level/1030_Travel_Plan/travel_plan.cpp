#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000
#define MAXV 504
using namespace std;

int cntV, cntE, srcID, destID;
int minCost = INF;
int G[MAXV][MAXV], cost[MAXV][MAXV];
int dist[MAXV];
bool marked[MAXV];
vector<int> preV[MAXV];
vector<int> tmpPath, path;

int init(){
	fill( G[0], G[0] + MAXV*MAXV, INF );
	fill( cost[0], cost[0] + MAXV*MAXV, INF );
	fill( dist, dist + MAXV, INF );
	fill( marked, marked + MAXV, false);
	return 0;
}

int Dijkstra(){
	dist[srcID] = 0;
	int midID = srcID;
	while( marked[destID] == false ){
		int minWeight = INF;
		for( int i=0; i<cntV; ++i ){
			if( marked[i] == false ){
				if( dist[i] < minWeight ){
					minWeight = dist[i];
					midID = i;
				}
			}
		}
		marked[midID] = true;

		for( int i=0; i<cntV; ++i ){
			if( G[midID][i] != INF ){
				if( marked[i] == false ){
					if( dist[midID] + G[midID][i] < dist[i] ){
						dist[i] = dist[midID] + G[midID][i];
						preV[i].clear();
						preV[i].push_back(midID);
					}else if( dist[midID] + G[midID][i] == dist[i] ){
						preV[i].push_back(midID);
					}
				}
			}
		}
	}
	return 0;
}

int DFS(int cur){
	if( cur == srcID ){
		tmpPath.push_back(cur);
		int tmpCost = 0;
		for( int i = tmpPath.size() - 1; i > 0; --i ){
			int id = tmpPath[i];
			int nextID = tmpPath[i-1];
			tmpCost += cost[id][nextID];
		}
		if( tmpCost < minCost ){
			minCost = tmpCost;
			path = tmpPath;
		}
		tmpPath.pop_back();
		return 0;
	}

	tmpPath.push_back(cur);
	for( int i = 0; i < preV[cur].size(); ++i ){
		DFS( preV[cur][i] );
	}
	tmpPath.pop_back();
	return 0;
}

int main(){
	int A, B, distAB, costAB, i;
	init();

	cin>>cntV>>cntE>>srcID>>destID;	
	for( i = 0; i < cntE; ++i ){
		cin>>A>>B>>distAB>>costAB;
		G[A][B] = G[B][A] = distAB;
		cost[A][B] = cost[B][A] = costAB;
	}

	Dijkstra();

	DFS(destID);
	for( i = path.size() - 1; i >= 0; --i ){
		cout<<path[i]<<' ';
	}

	cout<<dist[destID]<<' '<<minCost<<'\n';

	return 0;
}