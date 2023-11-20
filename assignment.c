#define MAX_POINTS 100 // max points
#define MAX_DISTANCE 1000000000 // max distance
#define INF 987654321
#include <stdio.h>
#include <stdbool.h>
//colorMapping must be a global variable
/*explanation function & variables
1. point = the location of point(x, y)
2. calculate = calcualte the distance of point1 and point2. return distance.
			 = it will help comparing the distance of red patches and current location. 
3. findshortestDistance = to find the shortest distance among redponits. 
						its parameters are 1) current location x, y 2) red patches location x, y 3) the number of red patches.
4. first current poisition will be (4, 4)
5. isPointzero is to check whether robot is on (0, 0) or not. 
6. bell_ford = to find weights between verteces and edges
7. redpoint[max_point] is the location of red patches. it will help to compare distance between red patches and current position
*/

// not reversed, same order array for now. 

/*operate
1. When robot go to first red patch, drop the that red patch in redpoint[], and redcount--;*/


typedef struct Point {
	int r;
	int c;
} Point;
Point currentPosition = {4, 4}; // start point. 
int score = 0; // the number of red patches that robot gets.

float Calculate(Point point1, Point point2){ //calculate the distance of point1 and point2. 
	return abs((point1.r + point1.c) - (point2.r + point2.c));
}

Point findShortestDistance(Point currentPosition, Point redPoint[], int redPointCount){ // send redPoint array. compare each elements
	float shortestDistance = MAX_DISTANCE;
	Point shortest_redPatch;

	for (int i = 0; i < redPointCount; i++){
		float distance = Calculate(currentPosition, redPoint[i]);
		if (distance < shortestDistance) {
			shortestDistance = distance;
			shortest_redPatch.r = redPoint[i].r;
			shortest_redPatch.c = redPoint[i].c;
		}
	}

	return shortest_redPatch; // it returns shortest_redPatch location x, y
}

bool isPointZero(Point point){
	return (point.r == 0 && point.c == 0);
}


void bell_ford(Point start, Point end, int array[5][5]){ // Pointer memory ? ?? 
	for (int i = 0; i< 5; i++){
		for (int j = 0; j < 5; j++){
			array[i][j] = INF; // give initial values 
		}
	}

	int offset_r, offset_c, limit_r, limit_c;

	if (start.r > end.r){limit_r = start.r; offset_r = end.r;}
	else{limit_r = end.r; offset_r = start.r;}

	if (start.c > end.c){limit_c = start.c; offset_c = end.c;}
	else{limit_c = end.c; offset_c = start.c;}
	// to copy array 


	// copy array 
	for (int r = offset_r; r <= limit_r; r++){
		for (int c = offset_c; c <= limit_c; c++){
			array[r][c] = colorMapping[r][c];
		}
	}

	return array;
}

void weight(Point start, Point end){
	int weight_array[5][5];

	bell_ford(start, end, weight_array);
	// find weight / use lecture reference
	 

}
task main()
{
	Point redPoint[MAX_POINTS];
	int redPointCount = 0; //add points
	int r, g, b;
	if (getcolorRGB(r, g, b) == 2) {score++;} // add to LineTracing.c

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (colorMapping[i][j] == 2){ // if red;
				redPoint[redPointCount].x = i;
				redPoint[redPointCount].y = j;
				redPointCount++;}
		}
	}

	//redPoint location store.
	Point togo = findShortestDistance(currentPosition, redPoint, redPointCount); // first
	bell_ford(currentPosition, togo);
	


	
}
