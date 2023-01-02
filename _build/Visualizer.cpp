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

	bool bColor = true;
	
	ScreenInfo screenInfo;
	Menu menu(50, 50);
	
	const int screenWidth = screenInfo.screenWidth;
	const int screenHeight = screenInfo.screenHeight;
	const int visualizerWidth = screenInfo.visualizerWidth;
	
	std::vector<int> dataArray{0};
	Color dataColor[MAX_DATA+1]{WHITE};
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
		}

		if(bColor)
		{
			float space{ 0 };
			for (int i = 0; i < MAX_DATA; i++)
			{
				DrawRectangle(space, screenHeight - dataArray[i], (float)visualizerWidth/ MAX_DATA, dataArray[i], WHITE);
				space += (float)visualizerWidth / MAX_DATA;
			}
		}
		else
		{
				if (cache.i != MAX_DATA - 1)
			{
				float space{ 0 };
				
				if (GetRandomValue(0, 1) == 0)
				{
					dataColor[cache.j + 1] = WHITE;
					dataColor[cache.j] = BLUE;
				}
				else
				{
					dataColor[cache.j] = WHITE;
					dataColor[cache.j + 1] = BLUE;
				}
				
				if(cache.j-1 > 0)
					dataColor[cache.j - 1] = RED;
				
				for (int i = 0; i < MAX_DATA; i++)
				{
					DrawRectangle(space, screenHeight - dataArray[i], (float)visualizerWidth/ MAX_DATA, dataArray[i], dataColor[i]);
					space += (float)visualizerWidth / MAX_DATA;
				}
			}
			else
			{
				float space{ 0 };
				for (int i = 0; i < MAX_DATA; i++)
				{
					DrawRectangle(space, screenHeight - dataArray[i], (float)visualizerWidth/ MAX_DATA, dataArray[i], WHITE);
					space += (float)visualizerWidth / MAX_DATA;
				}
			}
		}

		EndDrawing();

		dataColor[cache.j + 1] = GREEN;
		dataColor[cache.j] = GREEN;

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
