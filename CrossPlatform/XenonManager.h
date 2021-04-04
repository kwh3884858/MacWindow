//  XenonManager.h
//  XenonEngine
//
//  Created by whkong on 2021-4-4.
//  Copyright (c) 2018 whkong. All rights reserved.
#pragma once
#include "CrossPlatform/XenonSingleton.h"

namespace CrossPlatform {

    template<typename T>
    class XenonManager: public XenonSingleton<T>
    {
    public:
        virtual ~XenonManager() override = default;

        //initilize function, take the place of constructor
        virtual bool initialize() = 0;

        //destroy function, take the  place of deconstructor
        virtual bool shutdown() = 0;

        protected:
            XenonManager() = default;
    };

}