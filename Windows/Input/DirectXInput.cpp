
#define INITGUI

#include "DirectXInput.h"
#include <cassert>
namespace WindowInput {
    DirectXInput::DirectXInput()
    {
    }

    DirectXInput::~DirectXInput()
    {
    }

    void DirectXInput::SetConfig(const DirectXInputConfig* const config)
    {
        m_hwnd = config;
    }

    void DirectXInput::Initialize()
    {
        HRESULT result;
        result = DirectInput8Create(m_hwnd, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&lpdi, nullptr);
        assert(result == DI_OK);
       
        //Keybroad
        result = lpdi->CreateDevice(GUID_SysKeyboard, &lpdikey, nullptr);
        assert(result == DI_OK);

        result = lpdikey->SetCooperativeLevel(m_hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
        assert(result == DI_OK);

        result = lpdikey->SetDataFormat(&c_dfDIKeyboard);
        assert(result == DI_OK);

        //Mouse
        result = lpdi->CreateDevice(GUID_SysMouse, &lpdiMouse, nullptr);
        assert(result == DI_OK);

        result = lpdiMouse->SetCooperativeLevel(m_hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
        assert(result == DI_OK);

        result = lpdiMouse->SetDataFormat(&c_dfDIMouse);
        assert(result == DI_OK);

        result = lpdiMouse->Acquire();
        assert(result == DI_OK);

        //Joystick
        result = lpdi->EnumDevices(DI8DEVTYPE_JOYSTICK, DirectInputEnumJoystick, &m_joyStickGUID, DIEDFL_ATTACHEDONLY);
        assert(result == DI_OK);

        result = lpdi->CreateDevice(m_joyStickGUID, &lpdiJoystick,nullptr);
        assert(result == DI_OK);

        lpdiJoystick->SetCooperativeLevel(m_hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
        assert(result == DI_OK);

        lpdiJoystick->SetDataFormat(&c_dfDIJoystick);
        assert(result == DI_OK);

        result = lpdiJoystick->Acquire();
        assert(result == DI_OK);
    }

    void DirectXInput::Update()
    {
        HRESULT result;
        result = lpdikey->GetDeviceData(sizeof(m_keyState), (LPVOID)m_keyState);
        //assert(result == DI_OK);
        while(result == DIERR_INPUTLOST)
        {
            HRESULT state = lpdi->Acquire();
            if (state != DI_OK)
            {
                break;
            }
        }

        lpdiMouse->GetDeviceState(sizeof(m_mouseState), &m_mouseState);
        assert(result == DI_OK);

        result = lpdiJoystick->Poll();
        assert(result == DI_OK);

        lpdiJoystick->GetDeviceData(sizeof(m_joystickState), &m_joystickState);
        assert(result == DI_OK);

    }

    void DirectXInput::ShutDown()
    {
        if (lpdiJoystick)
        {
            lpdiJoystick->Unacquire();
        }
        if (lpdiJoystick)
        {
            lpdiJoystick->Release();
        }
        if (lpdimouse)
        {
            lpdiMouse->Unacquire();
        }
        if (lpdiMouse)
        {
            lpdiMouse->Release();
        }
        if (lpdikey)
        {
            lpdikey->Unacquire();
        }
        if (lpdikey)
        {
            lpdikey->Release();
        }
        if (lpdi)
        {
            lpdi->Release();
        }
    }

    bool DirectXInput::GetKeyDown(unsigned char keyCode) const
    {
        return m_keyState[keyCode] & 0x80;
    }

    Vector2f DirectXInput::GetMouseMove() const
    {
        return Vector2f(m_mouseState.lX, m_mouseState.lY);
    }

    bool DirectXInput::GetMouseButton(unsigned char mouseCode) const
    {
        return m_mouseState.rgbButtons[mouseCode] & 0x80;
    }

    bool DirectXInput::DirectInputEnumJoystick(LPCDIDEVICEINSTANCE lpddi, LPVOID guidPointer)
    {
        *(GUID*)guidPointer = lpddi->guidInstance;
        strcpy(m_joyStickName, (char*)lpddi->tszProductName);
        return (DIENUM_STOP);
    }

}