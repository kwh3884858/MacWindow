//  IDrawerSurface.h
//  MacWindow
//
//  Created by whkong on 2021-3-22.
//  Copyright (c) 2018 whkong. All rights reserved.
#pragma once

#include "CrossPlatform/SColorRGBA.h"

namespace CrossPlatform {
    class IDrawerSurface
    {
    public:
        virtual ~IDrawerSurface() {};

        virtual void lock() = 0;
        virtual void DrawPixel(unsigned int x, unsigned int y, SColorRGBA rgba) = 0;
        virtual SColorRGBA GetPixel(unsigned int x, unsigned int y) = 0;
        virtual void Unlock() = 0;

    };
}