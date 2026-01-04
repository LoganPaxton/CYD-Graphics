#pragma once

#include "CONFIG.hpp"
#include <TFT_eSPI.h>

class ezgraphics {
    private:
        TFT_eSPI tft;
    public:
        ezgraphics();
        void init();
};