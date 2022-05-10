#include <iostream>
#include <unordered_map>
#include <iterator>
#include <cstring>
#include <fstream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <queue>
#include <array>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;



unordered_map<string, vector<string>> cities;

unordered_map<string, bool> visitedArray;

unordered_map<string, bool> discoveredSet;

queue<string> nodeQueue;

bool foundCycle = false;


//Looking for back edges
//if there's one back edge, return true
void DepthFirstSearchCycle(string node){
  visitedArray[node] = true;
  //check each of the node's neighbors
  for(int i = 0; i < cities[node].size(); i++){
    if(foundCycle == true){
      return;
    }
    //if the neighboring node is visited, STOP, you found a cycle
    if(visitedArray.count(cities[node][i]) > 0){
      foundCycle = true;
      return;
    }
    //mark the current node as visited
    visitedArray[cities[node][i]] = true;
    //recursive DFS call on the neighbors
    DepthFirstSearchCycle(cities[node][i]);
    if(foundCycle == true){
      return;
    }
    //remove the current node as visited in case it is part of another cycle with another node
    visitedArray.erase(cities[node][i]);
  }
}





  

/*
bool depthFirstSearchCycle(string city){
  visitedArray.push(city);
  for(int i = 0; i < cities[city].size(); i++){
    visitedArray.push()
  }
  
    
  
  return false;
}
*/




int main(){

  /*
  //tester code, comment out on Kattis
  ifstream cin("input.txt");
  ifstream textFile;
  textFile.open("input.txt");
  if(textFile.fail()){
    cout << "File Open Failed";
    return 0;
  }
*/
  
  

  int numCities = 0;

  string aString = "";
  getline(cin, aString);
  int a = std::stoi(aString);

  

  for(int i = 0; i < a; i++){
    string cityString;
    getline(cin, cityString);
    string city1 = cityString.substr(0, cityString.find(' '));
    string city2 = cityString.substr(cityString.find(' ') + 1);
    //unordered_map<string, int> local;
    //if(cities.count(city1) == 0){
      //cities.insert(make_pair(city1, local));
      cities[city1].push_back(city2);
      numCities++;
    //}
    //local.insert(make_pair(city2,0));
    //cout << city2;
    /*
*/
  }



  string city;

  while(getline(cin, city)){
    visitedArray.clear();
    discoveredSet.clear();
    foundCycle = false;
    DepthFirstSearchCycle(city);
    if(foundCycle == true){
      cout << city << " safe";
    }
    else{
      cout << city << " trapped";
    }
    cout << endl;
    //cout << city;
  }

  
/*
  cout << numCities;

  bool discoveredSet[numCities];

*/

  
  
  return 0;
}