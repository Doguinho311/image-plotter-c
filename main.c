#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include <raylib.h>

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("Uso: %s <caminho para a imagem> <rgb, hsv>.\n", argv[0]);
		exit(1);
	}

	const char* imagename = argv[1];

	int width, height, channels;
	unsigned char* img = stbi_load(imagename, &width, &height, &channels, 3);

	if (img == NULL)
	{
		printf("Não foi possível carregar a imagem.\n");
		exit(1);
	}

	printf("Imagem carregada, %d x %d, com %d canais.\n", width, height, channels);



	const int screenWidth = 800;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "Visualizador - Raylib");

	Color color = {255, 120, 0, 255};

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawCircle(screenWidth / 2, screenHeight / 2, 16, color);

		EndDrawing();
	}

	CloseWindow();

	stbi_image_free(img);

	return 0;
}
