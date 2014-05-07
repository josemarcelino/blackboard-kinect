// KingofKinect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <NuiApi.h>

using namespace std;


int main(){

	NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	NUI_SKELETON_FRAME ourframe;

	const int x = 45;
	const int y = 45;

	int tab[x][y];
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			tab[i][j] = 0;
		}
	}

	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			cout << tab[i][j];
		}
		cout << endl;
	}
	
	
	while (1) //For all of time
	{
		NuiSkeletonGetNextFrame(0, &ourframe); //Get a frame and stuff it into ourframe
		for (int i = 0; i < 6; i++) //Six times, because the Kinect has space to track six people
		{

			int position_y = y - (int)((ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y +1.6) *9.375*1.5);
			int position_x = (int)((ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x+2.2) *6.8*1.5);

			if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED && tab[position_y][position_x] != 1){ //See more on this line below
				system("cls");//Clear the screen
				tab[position_y][position_x] = 1;
				
				for (int i = 0; i < y; i++){
					for (int j = 0; j < x; j++){
						cout << tab[i][j];
					}
					cout << endl;
				}

				cout << position_x << endl;
				cout << position_y << endl;
			}
		}
		
	}

	NuiShutdown();
	return 0;
}

