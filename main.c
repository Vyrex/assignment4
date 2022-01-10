#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <dijkstra.h>
#include <salesmanPath.h>
#include <algo.h>


int main() {

	char *userInput;
	scanf("%s", userInput);
	takeInput();
	printf("\n\nThe Path is:\n");
	mincost(0); //passing 0 because starting vertex
	printf("\n\nMinimum cost is %d\n ", cost);
	return 0;
}

