#include "../Image/Image.hpp"
#include <iostream>

int main()
{
    /* Create image */
    ImageManager::Image img1 = ImageManager::create(2, 2);
    std::cout << "Pixel (0, 0) of Image 1: ";
    img1.printPixel(0, 0);

    /* Copy Constructor */
    ImageManager::Image img2(img1);
    img2.setPixel(1, 1, 255, 0, 0);
    std::cout << "Pixel (1, 1) of Image 2 after set new color: ";
    img2.printPixel(1, 1);
    std::cout << "Pixel (1, 1) of Image 1: ";
    img1.printPixel(1, 1);

    /* Copy Assignment */
    ImageManager::Image img3;
    img3 = img1;
    img3.invertColors();
    std::cout << "Pixel (0, 1) of Image 3 after invert: ";
    img3.printPixel(0, 1);
    std::cout << "Pixel (0, 1) of Image 1: ";
    img1.printPixel(0, 1);

    /* Move assignment */
    ImageManager::Image img4;
    img4 = std::move(img1);
    std::cout << "Pixel (0, 0) of Image 4 after move assignment: ";
    img4.printPixel(0, 0);

    /* Move constructor */
    ImageManager::Image img5(std::move(img4));
    std::cout << "Pixel (0, 0) of Image 5 after moveconstructor: ";
    img5.printPixel(0, 0);
    img5.toGrayScale();
    std::cout << "Pixel(0, 0) of Image 5 after grayscale: ";
    img5.printPixel(0, 0);

    return 0;
}