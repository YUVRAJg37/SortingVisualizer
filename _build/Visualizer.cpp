#include <iostream>

#include "Sort/BubbleSort/BubbleSort.h"
#include "Sort/SelectionSort/SelectionSort.h"
#include "Screen.h"
#include "Menu.h"
#include "vector"

#define MAX_DATA 1000

void InitializeData(std::vector<int> &data, int min, int max);

int main()
{
	BubbleSort bubbleSort;
	SelectionSort selectionSort;
	
	ScreenInfo screenInfo;
	Menu menu(50, 50);
	
	const int screenWidth = screenInfo.screenWidth;
	const int screenHeight = screenInfo.screenHeight;
	const int visualizerWidth = screenInfo.visualizerWidth;
	
	std::vector<int> dataArray{0};
	Cache cache;

	InitializeData(dataArray, 1, screenHeight);
	
	InitWindow(screenWidth, screenHeight, "Sort");

	int PreviousButtonIndex = -1;

	SetTargetFPS(60.0f);
	
	while (!WindowShouldClose())
	{
		ClearBackground(BLACK);
		BeginDrawing();

		menu.PushButton();
		
		menu.AddButton("Bubble");
		menu.AddButton("Selection");
		menu.AddButton("Quick");
		menu.AddButton("Heap");
		menu.AddButton("GNome");
		
		menu.PopButton();
		
		int CurrentButtonIndex = menu.getCurrentPressedButtonIndex();

		if(CurrentButtonIndex != PreviousButtonIndex)
		{
			std::cout<<"Reset";
			InitializeData(dataArray, 1, screenHeight);
			cache.Reset();
		}

		switch (CurrentButtonIndex)
		{
		case 0 :
			{
				bubbleSort.SortData(dataArray, MAX_DATA,cache);
				break;
			}
		case 1 :
			{
				selectionSort.SortData(dataArray, MAX_DATA, cache);
				break;
			}
		default: break;
		}

		float space{ 0 };
		for (int i = 0; i < MAX_DATA; i++)
		{
			DrawRectangle(space, screenHeight - dataArray[i], (float)visualizerWidth/ MAX_DATA, dataArray[i], WHITE);
			space += (float)visualizerWidth / MAX_DATA;
		}

		EndDrawing();

		PreviousButtonIndex = CurrentButtonIndex;
	}

	CloseWindow();
}

void InitializeData(std::vector<int> &data, int min, int max)
{
	data.clear();
	for (int i = 0; i < MAX_DATA; i++)
		data.push_back(GetRandomValue(min, max));
}
