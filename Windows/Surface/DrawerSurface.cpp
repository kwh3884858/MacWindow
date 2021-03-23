namespace WindowSurface 
{

    DrawerSurface::DrawerSurface(unsigned int width, unsigned int height)
    {
        m_width = width;
        m_height = height;

        if (!IsResolutionValid()) { return false; }

        m_buffer = new SColorRGB[m_width * m_height];
    }

    DrawerSurface::~DrawerSurface()
    {
        delete m_buffer;
        m_buffer = nullptr;
    }

    void DrawerSurface::lock()
    {
        m_lock = true;
    }

    void DrawerSurface::DrawPixel(unsigned int x, unsigned int y, SColorRGBA rgba)
    {
        if (m_lock == false)
        {
            return;
        }

        *(m_buffer[y *m_width + x]) = rgba;
    }

    CrossPlatform::SColorRGBA DrawerSurface::GetPixel(unsigned int x, unsigned int y)
    {
        return *(m_buffer[y *m_width + x]);
    }

    void DrawerSurface::Unlock()
    {
        m_lock = false;
    }

    bool DrawerSurface::IsResolutionValid() const
    {
        if (m_width == UNINITIALUZE_VALUE || m_height == UNINITIALUZE_VALUE)
        {
            return false;
        }
        return true;
    }

    bool DrawerSurface::IsBufferValid() const
    {
        if (m_buffer == nullptr)
        {
            return false;
        }

        return true;
    }

    bool DrawerSurface::IsPositionValid(unsigned int x, unsigned int y) const
    {
        if (x < 0 || x >= m_width || y < 0 || y >= m_height)
        {
            return false;
        }
        return true;
    }

}