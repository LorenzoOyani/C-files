#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
for(int i =0; i<height;i++)
{
    for(int j = 0;  j < width; i++)
    {
        float blue = image[i][j].rgbtBlue;
        float green = image[i][j].rgbtGreen;
        float red = image[i][j].rgbtRed;

        int average = round((red + blue + green) / 3);

        image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed =average;
    }

}

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    int sepiaRed, sepiaBlue, sepiaBlue;
    for(int i = 0 ; i < height; i++){
        for(int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            //calculate for sepiaColor and assign a new value;
            sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            if(sepiaRed > 255){
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            sepiaGreen  = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * 0riginalBlue );
            if(sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen
            }
             sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i =0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[height][width] = image[i][j];
        }


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float  sum_red;
            float sum_ blue;
            float sum_green;
            int counter = 0;


            sum_red = sum_blue = sum_green =counter = 0;
        }
         for(int k = -1; k<2;k++)
    {
        for (int I = -1; I<2; I++)
        {
            // check if pixel is outside rows
            if(i =k < 0 || i + k >= height)
            {
                continue;
            }

            // check if pixel is outside column;
            if(j = I < 0 || j + I >= width)
            {
                continue;
            }

            //otherwise add to sums

            sum_red += temp[i + k] [j + I].rgbtRed;
            sum_blue += temp[i + k] [j + I].rgbtBlue;
            sum_green += temp[ i + k] [j + I]. rgbtGreen;
            counter ++;
        }
    }

    image[i][j].rgbtRed = round(sum_red / counter);
    image[i][j].rgbtGreen = round(sum_green / counter);
    image[i][j].rgbtBlue = round(sum_blue / counter);
    }

    }

    return;
}
