#include "BoxCollider2D.h"

namespace XenonEngine
{
    
    void BoxCollider2D::SetConfig(const BoxCollider2DConfig*const config)
    {
        mIsTrigger = config->m_isTrigger;
        m_size = config->m_size;
    }

    float BoxCollider2D::GetArea() const
    {
        return m_size.x * m_size.y;
    }

}