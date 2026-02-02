#include "SSD1306.hpp"
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
SSD1306 OLED(SCREEN_ADDRESS);
void SSD1306::command(uint8_t cmd)
{
    Wire.beginTransmission(addr); // or 0x3D if that's your address
    Wire.write(0x00);             // command mode
    Wire.write(cmd);
    Wire.endTransmission();
}
void SSD1306::data(uint8_t dat)
{
    Wire.beginTransmission(addr);
    Wire.write(0x40); // data
    Wire.write(dat);
    Wire.endTransmission();
}

void SSD1306::printChar(int x, int y, char c)
{
    const int tune_offset = 0;
    uint16_t offset = uint8_t(c) * 5;
    for (uint8_t col = 0; col < 5; col++)
    {
        uint8_t bitmap = pgm_read_byte(&font[offset + col]);

        // LSB at bottom (most common for this font style)
        for (uint8_t row = 0; row < 8; row++)
        {
            bool pixelOn = (bitmap & (1 << row)) != 0;
            putPixel(x + col, y + row, pixelOn);
        }
    }
}
void SSD1306::print(String s)
{
    int i;
    for (size_t i = 0; i < s.length(); i++)
    {
        printChar(x + i * 6 + 5, y, s.c_str()[i]);
    }
}

void SSD1306::println(String s)
{
    print(s);
    x = 0;                      // reset horizontal too
    y = min(y + 8, HEIGHT - 8); // prevent overflow
}
void SSD1306::setCursor(int X, int Y)
{
    x = X;
    y = Y;
}
void SSD1306::putPixel(int x, int y, bool on)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    uint16_t byteIndex = (y / 8) * WIDTH + x;
    uint8_t bit = y % 8;
    uint8_t mask = (1 << bit);

    if (on)
    {
        frameBuffer[byteIndex] |= mask;
    }
    else
    {
        frameBuffer[byteIndex] &= ~mask;
    }
}

// Clear buffer (RAM only)
void SSD1306::clear()
{
    memset(frameBuffer, 0x00, BUFFER_SIZE);
}
void SSD1306::update()
{
    command(0x20);
    command(0x00);
    command(0x21);
    command(0x00);
    command(0x7F);
    command(0x22);
    command(0x00);
    command(0x07);
    for (uint16_t i = 0; i < BUFFER_SIZE;)
    {
        Wire.beginTransmission(addr);
        Wire.write(0x40);
        for (uint8_t chunk = 0; chunk < 30 && i < BUFFER_SIZE; chunk++, i++)
        {
            Wire.write(frameBuffer[i]);
        }
        Wire.endTransmission();
    }
}
void SSD1306::putBitmap(int x, int y, const uint8_t *bitmap, int w, int h, bool invert)
{
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            // Assuming common horizontal format: each row padded to byte boundary
            uint8_t bits = pgm_read_byte(&bitmap[(row * ((w + 7) / 8)) + (col / 8)]);
            bool pixel = (bits & (0x80 >> (col % 8))) != 0; // MSB left

            if (invert)
                pixel = !pixel;
            if (pixel)
            {
                putPixel(x + col, y + row, true);
            }
        }
    }
}

void SSD1306::init()
{
    // Typical init sequence using the command() function
    command(0xAE); // Display OFF

    command(0xD5); // Set display clock divide ratio / oscillator frequency
    command(0x80);

    command(0xA8); // Set multiplex ratio
    command(0x3F); // 64 mux for 128×64 display (use 0x1F for 128×32)

    command(0xD3); // Set display offset
    command(0x00);

    command(0x40); // Set display start line = 0

    command(0x8D); // Charge pump
    command(0x14); // Enable charge pump (required for most modules!)

    command(0x20); // Memory addressing mode
    command(0x00); // Horizontal addressing

    command(0xA1); // Segment remap (A1 = column address reversed)
    command(0xC8); // COM output scan direction (C8 = reversed)

    command(0xDA); // COM pins hardware configuration
    command(0x12); // Alternative COM pin config

    command(0x81); // Contrast control
    command(0xCF); // Higher = brighter

    command(0xD9); // Set pre-charge period
    command(0xF1);

    command(0xDB); // Set VCOMH deselect level
    command(0x40);

    command(0xA4); // Entire display ON = output follows RAM
    command(0xA6); // Normal (not inverted) display

    command(0xAF); // Display ON
}

SSD1306::SSD1306(uint8_t i2cAddress) : addr(i2cAddress)
{
    Wire.begin();
    Wire.setClock(40000);
}
