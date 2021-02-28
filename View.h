#ifndef View_h
#define View_h

#include "Logger.h"
#include "ViewModel.h"

class View
{
    private:
        Logger* logger;

    public:
        View(Logger* aLogger);
        void backDraw();
        void fullRedraw(ViewModel* viewModel);
        void minimalRedraw(ViewModel* viewModel);
};

#endif