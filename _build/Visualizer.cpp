#include <iostream>
#include <string>

#include "Sort/BubbleSort/BubbleSort.h"
#include "Screen.h"
#include "Menu.h"
#include "vector"

#define MAX_DATA 1000

int main()
{
	BubbleSort q_bubble_sort;
	ScreenInfo screenInfo;
	Menu menu(50, 50);
	
	const int screenWidth = screenInfo.screenWidth;
	const int screenHeight = screenInfo.screenHeight;
	const int visualizerWidth = screenInfo.visualizerWidth;
	
	std::vector<int> dataArray{0};
	Color dataColor[MAX_DATA+1]{WHITE};
	Cache cache;

	for (int i = 0; i < MAX_DATA; i++)
		dataArray.push_back(GetRandomValue(1, screenHeight));
	
	InitWindow(screenWidth, screenHeight, "Sort");

	SetTargetFPS(60.0f);
	
	while (!WindowShouldClose())
	{
		ClearBackground(BLACK);
		BeginDrawing();

		menu.PushButton();
		
		menu.AddButton("Bubble");
		menu.AddButton("Quick");
		menu.AddButton("Merge");
		menu.AddButton("Heap");
		menu.AddButton("GNome");
		
		menu.PopButton();
		
		int x = menu.getCurrentPressedButtonIndex();

		switch (x)
		{
		case 0 :
			{
				q_bubble_sort.SortData(dataArray, MAX_DATA,cache);
			}
		}
		
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

		EndDrawing();

		dataColor[cache.j + 1] = GREEN;
		dataColor[cache.j] = GREEN;
	}

	CloseWindow();
}

