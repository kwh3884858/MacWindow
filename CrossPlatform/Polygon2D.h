//  Polygon2D.h
//  XenonEngine
//
//  Created by whkong on 2021-4-11.
//  Copyright (c) 2018 whkong. All rights reserved.
#pragma once

#include "MathLab/Vector2f.h"
#include "CrossPlatform/SColorRGBA.h"
namespace CrossPlatform {
    //class Vertex2Df
    //{
    //public:
    //    float x = 0;
    //    float y = 0;

    //};

    //class Vertex2Di {
    //public:
    //    int x = 0;
    //    int y = 0;
    //};

    class Polygon2D 
    {

    public:
        enum EState {
            Disable,
            Enable,
        };

        Polygon2D();
        Polygon2D(EState state, MathLab::Vector2f position, MathLab::Vector2f velocity, SColorRGBA color, int numberOfVertex, MathLab::Vector2f* vertexList);
        ~Polygon2D();

        EState m_state = EState::Enable;
        MathLab::Vector2f m_position;
        MathLab::Vector2f m_velocity;
        SColorRGBA m_color;
        int m_numberOfVertex;
        MathLab::Vector2f* m_vertexList;
    };
}