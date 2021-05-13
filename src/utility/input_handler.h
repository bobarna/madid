#ifndef MADID_INPUT_HANDLER_H
#define MADID_INPUT_HANDLER_H

#include "gl.h"

/**
 * The inputHandler class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over. (Singleton pattern)
 */
class InputHandler {
    // Input handling
    bool aKeyWasPressed;
    static bool keyPressed[348];
    static int modifiers;

    /**
     * The inputHandler's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
    InputHandler() {
        aKeyWasPressed = false;
        modifiers = 0;
        for (bool &k : keyPressed)
            k = false;

    }

    static InputHandler *singleton_;

public:

    /**
     * Singletons should not be cloneable.
     */
    InputHandler(InputHandler &other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const InputHandler &) = delete;

    static InputHandler *GetInstance();

    static void KeyPress(int key);

    static void SetModifiers(int m);

    static void KeyRelease(int key);

    static bool IsPressed(int key);

    static bool IsShiftPressed();

    static bool IsControlPressed();

    static bool IsAltPressed();

    static bool IsSuperPressed();

    static bool IsCapsLock();

    static bool IsNumLock();

};

#endif //MADID_INPUT_HANDLER_H
