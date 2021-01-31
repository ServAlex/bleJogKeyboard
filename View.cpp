#include "View.h"

#include "parts/display_part.h"

View::View(Logger* aLogger)
{
    this->logger = aLogger;

    displaySetup();

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextDatum(TL_DATUM);
}

void View::backDraw()
{
    //tft.drawCircle(10, 10, 5, TFT_YELLOW);
    clearScreen();
}

bool flag = false;

void View::fullRedraw(ViewModel* viewModel)
{
    logger->Log("full redraw method start");
    // clear all
    backDraw();

    if(viewModel->isInModeSelectionMode)
    {
        tft.drawCircle(5, 5, 5, TFT_YELLOW);
    }
    else
    {
        tft.fillCircle (5, 5, 5, TFT_YELLOW);
    }

    // draw all
    tft.setTextSize(3);
    tft.drawString(viewModel->modeName, 10, 30);
    logger->Log(viewModel->modeName);
    tft.setTextSize(2);
    tft.drawString(String(viewModel->modeIndex) + "/" + String(viewModel->modesCount), 10, 70);
    
    tft.drawString(String(viewModel->encoderValue), 10, 90);
}

void View::minimalRedraw(ViewModel* viewModel)
{
    // clear only updated part
    clearRect(tft.width() - 40, 80, 80, 40);

    // draw updated part
    tft.setTextSize(2);
    tft.drawString(String(viewModel->encoderValue), tft.width(), 80);
}

/////
/*
bool report_needed = false;

void reportSetup()
{
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextDatum(TL_DATUM);

    int d = 25;

    drawLeftAlignedStringWithOffset("connect",      20, 5 + 0*d);
    drawLeftAlignedStringWithOffset("mode",         20, 5 + 1*d);
    drawLeftAlignedStringWithOffset("encoder",      20, 5 + 2*d);
}

void report_on_demand()
{
    int d = 25;
    int secondColumnStart = 140;
    //clearScreen();
    clearRect(0, 0, 10, tft.height());
    clearRect(secondColumnStart, 0, tft.width() - secondColumnStart, tft.height());
    
    drawLeftAlignedStringWithOffset(String(Keyboard.isConnected()),        secondColumnStart, 5 + 0*d);
    drawLeftAlignedStringWithOffset(modes[activeMode].modeShortName(),     secondColumnStart, 5 + 1*d);
    drawLeftAlignedStringWithOffset(String(encoderValue),                  secondColumnStart, 5 + 2*d);

    //tft.fillCircle(5, tft.height()/2-d*2 + currentMenu*d, 3, TFT_GREEN);
    tft.fillCircle(5, 15 + currentMenu*d, 3, TFT_GREEN);

    report_needed = false;
}

void report_regular()
{
    int d = 25;
    int secondColumnStart = 140;
    clearRect(secondColumnStart, 0, tft.width() - secondColumnStart, 20);
    drawLeftAlignedStringWithOffset(String(Keyboard.isConnected()),        secondColumnStart, 5 + 0*d);
}
*/
