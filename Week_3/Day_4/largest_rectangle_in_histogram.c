#include <stdbool.h>

static bool shouldCloseBar(int currentHeight, int lastOpenHeight) {
	return lastOpenHeight > currentHeight;
}

int largestRectangleArea(int* heights, int heightsSize) {
	int openBars[heightsSize + 1];
	int topOpenBar = -1;
	int largestArea = 0;

	for (int currentBar = 0; currentBar <= heightsSize; currentBar++) {
		int currentHeight = currentBar == heightsSize ? 0 : heights[currentBar];

		while (topOpenBar != -1 &&
		       shouldCloseBar(currentHeight, heights[openBars[topOpenBar]])) {
			int closedBar = openBars[topOpenBar--];
			int height = heights[closedBar];
			int leftBoundary = topOpenBar == -1 ? -1 : openBars[topOpenBar];
			int width = currentBar - leftBoundary - 1;
			int rectangleArea = height * width;

			if (rectangleArea > largestArea)
				largestArea = rectangleArea;
		}

		openBars[++topOpenBar] = currentBar;
	}

	return largestArea;
}
