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

	const int x = 10;
	const int y = 10;

	int tab[x][y];
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			tab[i][j] = 0;
		}
	}

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			cout << tab[i][j];
		}
		cout << endl;
	}
	
	
	while (1) //For all of time
	{


		NuiSkeletonGetNextFrame(0, &ourframe); //Get a frame and stuff it into ourframe
		for (int i = 0; i < 6; i++) //Six times, because the Kinect has space to track six people
		{
			if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){ //See more on this line below
				system("cls");//Clear the screen
				tab[10 -(int)((ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y * 10))][(int)((ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x * 10))] = 1;

				for (int i = 0; i < x; i++){
					for (int j = 0; j < y; j++){
						cout << tab[i][j];
					}
					cout << endl;
				}
			
			}
		}
		
	}

	NuiShutdown();
	return 0;
}

