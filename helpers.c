#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float tempRed = 0;
    float tempGreen = 0;
    float tempBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempRed = image[i][j].rgbtRed;
            tempGreen = image[i][j].rgbtGreen;
            tempBlue = image[i][j].rgbtBlue;
            float ave = (tempRed + tempGreen + tempBlue) / 3.00;
            image[i][j].rgbtRed = roundf(ave);
            image[i][j].rgbtGreen = roundf(ave);
            image[i][j].rgbtBlue = roundf(ave);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float orgRed = 0;
    float orgGreen = 0;
    float orgBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            orgRed = image[i][j].rgbtRed;
            orgGreen = image[i][j].rgbtGreen;
            orgBlue = image[i][j].rgbtBlue;

            // Calculate Sepia Red
            float sepRed = (0.393 * orgRed) + (0.769 * orgGreen) + (0.189 * orgBlue);
            if (sepRed > 255.0)
                sepRed = 255.0;
            // Calculate Sepia Green
            float sepGreen = (0.349 * orgRed) + (0.686 * orgGreen) + (0.168 * orgBlue);
            if (sepGreen > 255.0)
                sepGreen = 255.0;
            // Calculate Sepia Blue
            float sepBlue = (0.272 * orgRed) + (0.534 * orgGreen) + (0.131 * orgBlue);
            if (sepBlue > 255.0)
                sepBlue = 255.0;

            image[i][j].rgbtRed = roundf(sepRed);
            image[i][j].rgbtGreen = roundf(sepGreen);
            image[i][j].rgbtBlue = roundf(sepBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            float pixelR = image[i][j].rgbtRed;
            float pixelG = image[i][j].rgbtGreen;
            float pixelB = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed; // Swap 1
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = pixelR;
            image[i][width - j - 1].rgbtGreen = pixelG;
            image[i][width - j - 1].rgbtBlue = pixelB;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
