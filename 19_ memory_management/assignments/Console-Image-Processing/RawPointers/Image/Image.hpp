#ifndef __IMAGE_H__
#define __IMAGE_H__

namespace ImageManager
{
    class Image
    {
    private:
        int width;
        int height;
        unsigned char *pixel; // Each pixel: RGB 3 byte

    public:
        /* Default Constructor */
        Image();

        /* Constructor */
        Image(int width, int height);

        /* Copy Constructor */
        Image(const Image &other_image);

        /* Copy Assignment Operator */
        Image &operator=(const Image &other_image);

        /* Move Constructor */
        Image(Image &&other_image) noexcept;

        /* Move Assignment Operator */
        Image &operator=(Image &&other_image) noexcept;

        /* Destructor */
        ~Image();

        /* Methods */
        void invertColors();
        void toGrayScale();
        void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
        void printPixel(int x, int y);
    };

    Image create(int width, int height);
} // namespace ImageManager

#endif // !__IMAGE_H__