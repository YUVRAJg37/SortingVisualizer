#include <iostream>

#include "Sort/BubbleSort/BubbleSort.h"
#include "Sort/SelectionSort/SelectionSort.h"
#include "Screen.h"
#include "Menu.h"
#include "vector"

#define MAX_DATA 1000

#define Lock_FPS 0

void InitializeData(std::vector<int> &data, int min, int max);

int main()
{
	BubbleSort bubbleSort;
	SelectionSort selectionSort;
	
	ScreenInfo screenInfo;
	Menu menu(50, 50);
	
	const int ScreenWidth = screenInfo.screenWidth;
	const int ScreenHeight = screenInfo.screenHeight;
	const int VisualizerWidth = screenInfo.visualizerWidth;
	
	std::vector<int> DataArray{0};
	Cache cache;

	InitializeData(DataArray, 1, ScreenHeight);
	
	InitWindow(ScreenWidth, ScreenHeight, "Sort");

	int PreviousButtonIndex = -1;

#if Lock_FPS
	SetTargetFPS(60.0f);
#endif

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
			InitializeData(DataArray, 1, ScreenHeight);
			cache.Reset();
		}

		switch (CurrentButtonIndex)
		{
		case 0 :
			{
				bubbleSort.SortData(DataArray, MAX_DATA,cache);
				break;
			}
		case 1 :
			{
				selectionSort.SortData(DataArray, MAX_DATA, cache);
				break;
			}
		default: break;
		}

		float space{ 0 };
		for (int i = 0; i < MAX_DATA; i++)
		{
			DrawRectangle(space, ScreenHeight - DataArray[i], (float)VisualizerWidth/ MAX_DATA, DataArray[i], WHITE);
			space += (float)VisualizerWidth / MAX_DATA;
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
