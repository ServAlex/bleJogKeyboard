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

    // is in mode selection mode
    if(viewModel->isInModeSelectionMode)
    {
        tft.drawCircle(5, 5, 5, TFT_YELLOW);
    }
    else
    {
        tft.fillCircle(5, 5, 5, TFT_YELLOW);
    }

    // connection status
    if(viewModel->isConnected)
    {
        tft.fillCircle(25, 5, 5, TFT_GREEN);
    }
    else
    {
        tft.drawCircle(25, 5, 5, TFT_GREEN);
    }

    // color for battery
    uint32_t batteryColor = TFT_YELLOW;
    if(viewModel->voltage > 4.3)
    {
        batteryColor = TFT_BLUE;
    }
    else if(viewModel->voltage > 3.9)
    {
        batteryColor = TFT_GREEN;
    }
    else if(viewModel->voltage > 3.5)
    {
        batteryColor = TFT_YELLOW;
    }
    else 
    {
        batteryColor = TFT_RED;
    }

    // charge percentage bar
    tft.drawRoundRect(2, tft.height() - 7, tft.width()-2*2, 7, 4, batteryColor);
    tft.fillRoundRect(5, tft.height() - 5, 4 + (tft.width()-5*2-4)*min(viewModel->chargePortion, 1), 3, 2, batteryColor);

    // voltage text
    tft.setTextSize(1);
    tft.drawString(String(viewModel->voltage), tft.width()-30, 90);

    // draw all
    tft.setTextSize(3);
    tft.drawString(viewModel->modeName, 10, 30);
    logger->Log(viewModel->modeName);
    tft.setTextSize(2);
    tft.drawString(String(viewModel->modeIndex) + "/" + String(viewModel->modesCount), 10, 70);
    
    tft.setTextSize(1);
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
