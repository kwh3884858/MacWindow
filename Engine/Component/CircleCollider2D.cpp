#include "CircleCollider2D.h"

namespace XenonEngine
{

    void CircleCollider2D::SetConfig(const CircleCollider2DConfig*const config)
    {
        m_radius = config->m_radius;
    }

    float CircleCollider2D::GetArea() const
    {
        return m_radius * m_radius * PI;
    }

}