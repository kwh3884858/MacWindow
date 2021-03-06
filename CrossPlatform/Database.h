//  Database.h
//  MacWindow
//
//  Created by whkong on 2021-3-31.
//  Copyright (c) 2018 whkong. All rights reserved.
#pragma once
#include "CrossPlatform/EngineConfig.h"
#include "CrossPlatform/XenonSingleton.h"
namespace CrossPlatform
{
    class Database :public XenonSingleton<Database>{
    public:
        Database() {
            engineConfig.m_isFullScreen = false;
            engineConfig.m_width = 800;
            engineConfig.m_height = 600;
            engineConfig.m_isPerspectiveProjection = true;
        }

        EngineConfig engineConfig;
    };

    
}