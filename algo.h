#ifndef NULL
#define NULL   ((void *) 0)
#endif

#define INFINITY 9999
int** matrixBuild;
int matrixSize = 0;

void functionChooser(char input[]) {
	if(input[0] == 'A') {
		CreateNewAdjancyMatrix(input);
	}
	if(input[0] == 'B') {
		expandMatrix(input);
	}
	if(input[0] == 'D') {
		DeleteVerix(input);
	}
	if(input[0] == 'S' || input[0] == 'P') {
		FindMinimalPath(input);
	}
	if(input[0] == 'T') {
		FindSalesmanPath(input);
	}
}

int** CreateNewAdjancyMatrix(char input[]) { // @suppress("No return")
	DeleteMatrix(matrixBuild);
	int inputArrSize = sizeof(input); //returns amount of chars in array
	int i = 2;
	matrixSize = atoi(input[1]); //also vertices amount in graph

	createMatrix(input, matrixSize)
	if(inputArrSize < 3){
		return matrixBuild;
	}
	//int matrixBuild[matrixSize][matrixSize] = (int **)malloc(sizeof(int)*matrixSize*matrixSize);
	for(i=2;i< inputArrSize; i++){
		if(input[i] == 'n'){
			parseEdges(matrixBuild, input, i, inputArrSize);
		}
	}
}

void createMatrix(char input[], int matrixSize){
	for(int j=0; j<matrixSize;  j++){
		matrixBuild = (int **)malloc(sizeof(int*)*matrixSize);
		for(int k=0; k<matrixSize;k++){
			matrixBuild[k]= (int *)malloc(sizeof(int)*matrixSize);
		}
	}
}

void parseEdges(int  matrix[][], char input[], i, int inputArrSize){
	int edgesSource = atoi(input[++i]);
	while(i < inputArrSize && input[i] != 'n'){
		int edgeDist = atoi(input[i++]);
		int edgeWeight = atoi(input[i++]);
		matrix[edgesSource][edgeDist] = edgeWeight;
	}
}

void DeleteVertix(char input[]){
	int v = atoi(input[1]);
	for(int i=0; i<matrixSize;i++){
		matrixBuild[v][i] = 0;
		matrixBuild[i][v] = 0;
	}

}

void DeleteMatrix(){
	if(matrixBuild != NULL){
		for(int i=0; i<matrixSize; i++){
			free(matrixBuild[i]);
		}
		free(matrixBuild);
		matrixSize = 0;
	}
}

void FindMinimalPath(char input[]){

	  int start=atoi(input[1]);
	  int finish=atoi(input[2]);
	  int cost[matrixSize][matrixSize], distance[matrixSize], pred[matrixSize];
	  int visited[matrixSize], count, mindistance, nextnode, i, j;

	  //pred[] stores the predecessor of each node
	  //count gives the number of nodes seen so far

	  //create the cost matrix
	  for (i = 0; i < n; i++){
	    for (j = 0; j < n; j++)
	      if (matrixBuild[i][j] == 0)
	        cost[i][j] = INFINITY;
	      else
	        cost[i][j] = matrixBuild[i][j];
	  }

	  //initialize pred[],distance[] and visited[]
	  int startnode = start;
	  for (i = 0; i < matrixSize; i++) {
	    distance[i] = cost[startnode][i];
	    pred[i] = startnode;
	    visited[i] = 0;
	  }
	  distance[startnode] = 0;
	  visited[startnode] = 1;
	  count = 1;
	  while (count < matrixSize - 1) {
	    mindistance = INFINITY;

	    //nextnode gives the node at minimum distance
	    for (i = 0; i < matrixSize; i++){
	      if (distance[i] < mindistance && !visited[i]) {
	        mindistance = distance[i];
	        nextnode = i;
	      }
	    }

	    //check if a better path exists through nextnode
	    visited[nextnode] = 1;
	    for (i = 0; i < matrixSize; i++)
	      if (!visited[i])
	        if (mindistance + cost[nextnode][i] < distance[i]) {
	          distance[i] = mindistance + cost[nextnode][i];
	          pred[i] = nextnode;
	        }
	    count++;
	  }

      printf("%d",distance[finish]);
}

void expandMatrix(char input[]){
	int matrixBuild2[][];
	for(int j=0; j<matrixSize+1;  j++){
		matrixBuild2 = (int **)malloc(sizeof(int*)*matrixSize+1);
		for(int k=0; k<matrixSize+1;k++){
			matrixBuild2[k]= (int *)malloc(sizeof(int)*matrixSize+1);
		}
	}
	for(int i=0; i<matrixSize; i++){
		for(int j=0; j<matrixSize; j++){
			matrixBuild2[i][j] = matrixBuild[i][j];
		}
	}
	int inputArrSize = sizeof(input); //returns amount of chars in array
	for(int i=1;i< inputArrSize; i++){
		if(input[i] == 'n'){
			parseEdges(matrixBuild, input, i, inputArrSize);
		}
	}
	DeleteMatrix();
	matrixBuild = matrixBuild2;
	matrixSize++;
}

int matrixBuild2[][];
int subMatrixSize;
int completed[], n, cost = 0;

void CreateSubMatrix(char input[]){
	subMatrixSize=atoi(input[2]);

	for(int j=0; j<subMatrixSize;  j++){
		matrixBuild2 = (int **)malloc(sizeof(int*)*subMatrixSize+1);
		for(int k=0; k<matrixSize+1;k++){
			matrixBuild2[k]= (int *)malloc(sizeof(int)*subMatrixSize+1);
		}
	}
	int indeces[subMatrixSize];
	indeces[0] = input[4];

	for(int i=1; i<subMatrixSize; i++){
		indeces[i] = input[4+2*i];
	}
	for(int i=0; i<subMatrixSize; i++){
		for(int j=0; j<subMatrixSize; j++){
			matrixBuild2[i][j] = matrixBuild[indeces[i]][indeces[j]];
		}
	}
}


void mincost(int city, int completed[]) {
  int i, ncity;

  completed[city] = 1;

  printf("%d--->", city + 1);
  ncity = least(city, completed);

  if (ncity == 999) {
    ncity = 0;
    cost += matrixBuild2[city][ncity];

    return;
  }

  mincost(ncity);
}

int least(int c,int completed[]) {
  int i, nc = 999;
  int min = 999, kmin;

  for (i = 0; i < subMatrixSize; i++) {
    if ((matrixBuild2[c][i] != 0) && (completed[i] == 0))
      if (matrixBuild2[c][i] + matrixBuild2[i][c] < min) {
        min = matrixBuild2[i][0] + matrixBuild2[c][i];
        kmin = matrixBuild2[c][i];
        nc = i;
      }
  }

  if (min != 999)
    cost += kmin;

  return nc;
}
void DeleteSubMatrix(){
	if(matrixBuild2 != NULL){
		for(int i=0; i<subMatrixSize; i++){
			free(matrixBuild2[i]);
		}
		free(matrixBuild2);
		subMatrixSize = 0;
	}
}
void FindSalesmanPath(char input[]){
	CreateSubMatrix(input);
	int toComplete[subMatrixSize];
	completed = toComplete;
	mincost(0, completed); //passing 0 because starting vertex
	printf(cost);
	DeleteSubMatrix();
}











