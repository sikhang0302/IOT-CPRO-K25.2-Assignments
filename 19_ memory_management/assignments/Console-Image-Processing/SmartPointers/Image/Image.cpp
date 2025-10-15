#include "../Image/Image.hpp"
#include <iostream>

namespace ImageManager
{
    /* Default Constructor */
    Image::Image() : width(0), height(0), pixel(nullptr) {};

    /* Constructor */
    Image::Image(int width, int height)
        : width(width), height(height), pixel(std::make_unique<unsigned char[]>(width * height * 3))
    {
        int i;
        for (i = 0; i < width * height * 3; i++)
        {
            pixel[i] = 0;
        }
    }

    /* Copy Constructor */
    Image::Image(const Image &other_image)
    {
        std::cout << "Copy Constructor called!\n";

        width = other_image.width;
        height = other_image.height;
        pixel = std::make_unique<unsigned char[]>(width * height * 3);
        int i;
        for (i = 0; i < width * height * 3; i++)
        {
            pixel[i] = other_image.pixel[i];
        }
    }

    /* Copy Assignment Operator */
    Image &Image::operator=(const Image &other_image)
    {
        std::cout << "Copy Assignment called!\n";

        // Check self assignment
        if (this == &other_image)
        {
            return *this;
        }

        // Allocate new memory based on other object
        width = other_image.width;
        height = other_image.height;
        pixel = std::make_unique<unsigned char[]>(width * height * 3);

        // Copy data from other object
        int i;
        for (i = 0; i < width * height * 3; i++)
        {
            pixel[i] = other_image.pixel[i];
        }

        // Return reference to current object
        return *this;
    }

    /* Move Constructor */
    Image::Image(Image &&other_image) noexcept
    {
        std::cout << "Move Constructor called!\n";

        width = other_image.width;
        height = other_image.height;
        pixel = std::move(other_image.pixel);

        other_image.width = 0;
        other_image.height = 0;
    }

    /* Move Assignment Operator */
    Image &Image::operator=(Image &&other_image) noexcept
    {
        std::cout << "Move Assignment called!\n";

        // Check self asssigment
        if (this == &other_image)
        {
            return *this;
        }

        // Move ownership
        width = other_image.width;
        height = other_image.height;
        pixel = std::move(other_image.pixel);

        other_image.width = 0;
        other_image.height = 0;

        return *this;
    }

    /* Destructor */
    Image::~Image()
    {
        std::cout << "Destructor called!\n";
    }

    /* Methods */
    void Image::invertColors()
    {
        int i;
        for (i = 0; i < width * height * 3; i++)
        {
            pixel[i] = 255 - pixel[i];
        }
    }

    void Image::toGrayScale()
    {
        int i;
        for (i = 0; i < width * height * 3; i += 3)
        {
            int r = pixel[i];
            int g = pixel[i + 1];
            int b = pixel[i + 2];

            // Weighted formula
            unsigned char gray = static_cast<unsigned char>(0.299 * r + 0.587 * g + 0.114 * b);

            pixel[i] = gray;     // R
            pixel[i + 1] = gray; // G
            pixel[i + 2] = gray; // B
        }
    }

    void Image::setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
    {
        if (x < 0 || x >= width || y < 0 || y >= height)
        {
            return;
        }

        int pixel_idx = (y * width + x) * 3;
        pixel[pixel_idx] = r;
        pixel[pixel_idx + 1] = g;
        pixel[pixel_idx + 2] = b;
    }

    void Image::printPixel(int x, int y)
    {
        if (x < 0 || x >= width || y < 0 || y >= height)
        {
            return;
        }

        int pixel_idx = (y * width + x) * 3;
        std::cout << "("
                  << "R: " << static_cast<int>(pixel[pixel_idx]) << ", "
                  << "G: " << static_cast<int>(pixel[pixel_idx + 1]) << ", "
                  << "B: " << static_cast<int>(pixel[pixel_idx + 2]) << ")\n";
    }

    Image create(int width, int height)
    {
        Image img(width, height);

        // Initialize with blue color (0, 128, 255)
        int i, j;
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                img.setPixel(j, i, 0, 128, 255);
            }
        }

        return img;
    }
} // namespace ImageManager