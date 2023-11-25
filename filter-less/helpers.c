#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // Calculate average of red, green, and blue values
            int rgbg = round((image[i][k].rgbtRed + image[i][k].rgbtGreen + image[i][k].rgbtBlue) / 3.0);

            // Set red, green, and blue values to the average value
            image[i][k].rgbtRed = image[i][k].rgbtGreen = image[i][k].rgbtBlue = rgbg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // Calculate sepia values for red, green, and blue
            int sepiaRed = round(.393 * image[i][k].rgbtRed + .769 * image[i][k].rgbtGreen + .189 * image[i][k].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][k].rgbtRed + .686 * image[i][k].rgbtGreen + .168 * image[i][k].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][k].rgbtRed + .534 * image[i][k].rgbtGreen + .131 * image[i][k].rgbtBlue);

            // Cap values at 255 if they exceed it
            image[i][k].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][k].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][k].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            // Reflect each pixel until the middle
            for (int k = 0; k < width / 2; k++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][k] = image[i][k];
                image[i][k] = image[i][width - (k + 1)];
                image[i][width - (k + 1)] = temp[i][k];
            }
        }
        else if (width % 2 != 0)
        {
            // Reflect each pixel until the middle (for odd width)
            for (int k = 0; k < (width - 1) / 2; k++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][k] = image[i][k];
                image[i][k] = image[i][width - (k + 1)];
                image[i][width - (k + 1)] = temp[i][k];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image to store blurred values
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // Initialize variables to store sum of RGB values and the counter for neighboring pixels
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float counter = 0;

            // Iterate over neighboring pixels in a 3x3 grid centered around the current pixel
            for (int x = -1; x < 2; x++)
            {
                for (int z = -1; z < 2; z++)
                {
                    // Skip pixels that are outside the image boundaries
                    if (i + x < 0 || i + x > height - 1)
                    {
                        continue;
                    }

                    if (k + z < 0 || k + z > width - 1)
                    {
                        continue;
                    }

                    // Accumulate the RGB values of neighboring pixels
                    sumRed += image[i + x][k + z].rgbtRed;
                    sumGreen += image[i + x][k + z].rgbtGreen;
                    sumBlue += image[i + x][k + z].rgbtBlue;
                    counter++;
                }
            }

            // Calculate the average RGB values for the current pixel
            temp[i][k].rgbtRed = round(sumRed / counter);
            temp[i][k].rgbtGreen = round(sumGreen / counter);
            temp[i][k].rgbtBlue = round(sumBlue / counter);
        }
    }

    // Update the original image with the blurred values from the temporary image
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            image[i][k].rgbtRed = temp[i][k].rgbtRed;
            image[i][k].rgbtGreen = temp[i][k].rgbtGreen;
            image[i][k].rgbtBlue = temp[i][k].rgbtBlue;
        }
    }

    return;
}