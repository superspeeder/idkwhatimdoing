#pragma once

#include "kat/engine.hpp"

namespace kat {

    class Monitor;

    using GamepadState = GLFWgamepadstate;
    using VideoMode = GLFWvidmode;
    using GammaRamp = GLFWgammaramp;

    enum class InputMode {
        StickyKeys = GLFW_STICKY_KEYS,
        StickyMouseButtons = GLFW_STICKY_MOUSE_BUTTONS,
        LockKeyMods = GLFW_LOCK_KEY_MODS,
        RawMouseMotion = GLFW_RAW_MOUSE_MOTION
    };

    enum class CursorMode {
        Normal = GLFW_CURSOR_NORMAL,
        Hidden = GLFW_CURSOR_HIDDEN,
        Disabled = GLFW_CURSOR_DISABLED
    };

    enum class SystemCursorShape {
        Arrow = GLFW_ARROW_CURSOR,
        IBeam = GLFW_IBEAM_CURSOR,
        Crosshair = GLFW_CROSSHAIR_CURSOR,
        Hand = GLFW_HAND_CURSOR,
        HResize = GLFW_HRESIZE_CURSOR,
        VResize = GLFW_VRESIZE_CURSOR
    };

    enum class ClientAPI {
        OpenGL = GLFW_OPENGL_API,
        OpenGLES = GLFW_OPENGL_ES_API,
        NoAPI = GLFW_NO_API
    };

    enum class ContextCreationAPI {
        Native = GLFW_NATIVE_CONTEXT_API,
        EGL = GLFW_EGL_CONTEXT_API,
        OSMesa = GLFW_OSMESA_CONTEXT_API
    };

    enum class ContextRobustness {
        None = GLFW_NO_ROBUSTNESS,
        NoResetNotification = GLFW_NO_RESET_NOTIFICATION,
        LoseContextOnReset = GLFW_LOSE_CONTEXT_ON_RESET
    };

    enum class ContextReleaseBehavior {
        Any = GLFW_ANY_RELEASE_BEHAVIOR,
        Flush = GLFW_RELEASE_BEHAVIOR_FLUSH,
        None = GLFW_RELEASE_BEHAVIOR_NONE
    };

    enum class OpenGLProfile {
        Core = GLFW_OPENGL_CORE_PROFILE,
        Compat = GLFW_OPENGL_COMPAT_PROFILE,
        Any = GLFW_OPENGL_ANY_PROFILE
    };

    struct CursorConfig {
        const GLFWimage* m_Image;
        glm::ivec2 m_Hotspot;
    };

    enum class Key {
        kUnknown = GLFW_KEY_UNKNOWN,
        kSpace = GLFW_KEY_SPACE,
        kApostrophe = GLFW_KEY_APOSTROPHE,
        kComma = GLFW_KEY_COMMA,
        kMinus = GLFW_KEY_MINUS,
        kPeriod = GLFW_KEY_PERIOD,
        kSlash = GLFW_KEY_SLASH,
        k0 = GLFW_KEY_0,
        k1 = GLFW_KEY_1,
        k2 = GLFW_KEY_2,
        k3 = GLFW_KEY_3,
        k4 = GLFW_KEY_4,
        k5 = GLFW_KEY_5,
        k6 = GLFW_KEY_6,
        k7 = GLFW_KEY_7,
        k8 = GLFW_KEY_8,
        k9 = GLFW_KEY_9,
        kSemicolon = GLFW_KEY_SEMICOLON,
        kEqual = GLFW_KEY_EQUAL,
        kA = GLFW_KEY_A,
        kB = GLFW_KEY_B,
        kC = GLFW_KEY_C,
        kD = GLFW_KEY_D,
        kE = GLFW_KEY_E,
        kF = GLFW_KEY_F,
        kG = GLFW_KEY_G,
        kH = GLFW_KEY_H,
        kI = GLFW_KEY_I,
        kJ = GLFW_KEY_J,
        kK = GLFW_KEY_K,
        kL = GLFW_KEY_L,
        kM = GLFW_KEY_M,
        kN = GLFW_KEY_N,
        kO = GLFW_KEY_O,
        kP = GLFW_KEY_P,
        kQ = GLFW_KEY_Q,
        kR = GLFW_KEY_R,
        kS = GLFW_KEY_S,
        kT = GLFW_KEY_T,
        kU = GLFW_KEY_U,
        kV = GLFW_KEY_V,
        kW = GLFW_KEY_W,
        kX = GLFW_KEY_X,
        kY = GLFW_KEY_Y,
        kZ = GLFW_KEY_Z,
        kLeftBracket = GLFW_KEY_LEFT_BRACKET,
        kBackslash = GLFW_KEY_BACKSLASH,
        kRightBracket = GLFW_KEY_RIGHT_BRACKET,
        kGraveAccent = GLFW_KEY_GRAVE_ACCENT,
        kWorld1 = GLFW_KEY_WORLD_1,
        kWorld2 = GLFW_KEY_WORLD_2,
        kEscape = GLFW_KEY_ESCAPE,
        kEnter = GLFW_KEY_ENTER,
        kTab = GLFW_KEY_TAB,
        kBackspace = GLFW_KEY_BACKSPACE,
        kInsert = GLFW_KEY_INSERT,
        kDelete = GLFW_KEY_DELETE,
        kRight = GLFW_KEY_RIGHT,
        kLeft = GLFW_KEY_LEFT,
        kUp = GLFW_KEY_UP,
        kDown = GLFW_KEY_DOWN,
        kPageUp = GLFW_KEY_PAGE_UP,
        kPageDown = GLFW_KEY_PAGE_DOWN,
        kHome = GLFW_KEY_HOME,
        kEnd = GLFW_KEY_END,
        kCapsLock = GLFW_KEY_CAPS_LOCK,
        kScrollLock = GLFW_KEY_SCROLL_LOCK,
        kNumLock = GLFW_KEY_NUM_LOCK,
        kPrintScreen = GLFW_KEY_PRINT_SCREEN,
        kPause = GLFW_KEY_PAUSE,
        kF1 = GLFW_KEY_F1,
        kF2 = GLFW_KEY_F2,
        kF3 = GLFW_KEY_F3,
        kF4 = GLFW_KEY_F4,
        kF5 = GLFW_KEY_F5,
        kF6 = GLFW_KEY_F6,
        kF7 = GLFW_KEY_F7,
        kF8 = GLFW_KEY_F8,
        kF9 = GLFW_KEY_F9,
        kF10 = GLFW_KEY_F10,
        kF11 = GLFW_KEY_F11,
        kF12 = GLFW_KEY_F12,
        kF13 = GLFW_KEY_F13,
        kF14 = GLFW_KEY_F14,
        kF15 = GLFW_KEY_F15,
        kF16 = GLFW_KEY_F16,
        kF17 = GLFW_KEY_F17,
        kF18 = GLFW_KEY_F18,
        kF19 = GLFW_KEY_F19,
        kF20 = GLFW_KEY_F20,
        kF21 = GLFW_KEY_F21,
        kF22 = GLFW_KEY_F22,
        kF23 = GLFW_KEY_F23,
        kF24 = GLFW_KEY_F24,
        kF25 = GLFW_KEY_F25,
        kKP0 = GLFW_KEY_KP_0,
        kKP1 = GLFW_KEY_KP_1,
        kKP2 = GLFW_KEY_KP_2,
        kKP3 = GLFW_KEY_KP_3,
        kKP4 = GLFW_KEY_KP_4,
        kKP5 = GLFW_KEY_KP_5,
        kKP6 = GLFW_KEY_KP_6,
        kKP7 = GLFW_KEY_KP_7,
        kKP8 = GLFW_KEY_KP_8,
        kKP9 = GLFW_KEY_KP_9,
        kKPDecimal = GLFW_KEY_KP_DECIMAL,
        kKPDivide = GLFW_KEY_KP_DIVIDE,
        kKPMultiply = GLFW_KEY_KP_MULTIPLY,
        kKPSubtract = GLFW_KEY_KP_SUBTRACT,
        kKPAdd = GLFW_KEY_KP_ADD,
        kKPEnter = GLFW_KEY_KP_ENTER,
        kKPEqual = GLFW_KEY_KP_EQUAL,
        kLeftShift = GLFW_KEY_LEFT_SHIFT,
        kLeftControl = GLFW_KEY_LEFT_CONTROL,
        kLeftAlt = GLFW_KEY_LEFT_ALT,
        kLeftSuper = GLFW_KEY_LEFT_SUPER,
        kRightShift = GLFW_KEY_RIGHT_SHIFT,
        kRightControl = GLFW_KEY_RIGHT_CONTROL,
        kRightAlt = GLFW_KEY_RIGHT_ALT,
        kRightSuper = GLFW_KEY_RIGHT_SUPER,
        kMenu = GLFW_KEY_MENU
    };

    class Cursor {
    public:

        explicit Cursor(const CursorConfig& cfg);
        explicit Cursor(SystemCursorShape shape);

        ~Cursor();

        GLFWcursor* getHandle() const noexcept;

    private:
        GLFWcursor* m_Cursor;

    };

    class Monitor {
    public:
        static std::vector<Monitor> getMonitors();
        Monitor getPrimaryMonitor();


        explicit Monitor(int i);
        explicit Monitor(GLFWmonitor* handle);

        [[nodiscard]] glm::ivec2 getPos() const;
        [[nodiscard]] glm::ivec4 getWorkarea() const;
        [[nodiscard]] glm::ivec2 getPhysicalSize() const;
        [[nodiscard]] glm::vec2 getContentScale() const;
        [[nodiscard]] std::string getName() const;
        [[nodiscard]] std::vector<VideoMode> getVideoModes() const;
        [[nodiscard]] const VideoMode* getVideoMode() const;

        void setGamma(float gamma) const;

        [[nodiscard]] const GammaRamp* getGammaRamp() const;
        void setGammaRamp(const GammaRamp& ramp) const;
        void setGammaRamp(const GammaRamp* ramp) const;

        [[nodiscard]] GLFWmonitor* getHandle() const noexcept;

    private:

        GLFWmonitor* m_Handle;
    };

    // must be defined after Monitor to prevent compiler errors due to optional
    struct WindowConfig {
        bool resizable = true;
        bool visible = true;
        bool decorated = true;
        bool focused = true;
        bool autoIconify = true;
        bool floating = false;
        bool maximized = false;
        bool centerCursor = true;
        bool transparentFrambuffer = false;
        bool focusOnShow = true;
        bool scaleToMonitor = false;
        std::array<int, 4> colorBits{ 8,8,8,8 }; // r,g,b,a
        int depthBits = 24;
        int stencilBits = 8;
        std::array<int, 4> accumColorBits{ 0,0,0,0 }; // r,g,b,a
        int auxBuffers = 0;
        int refreshRate = GLFW_DONT_CARE;
        bool stereo = false;
        bool srgbCapable = false;
        bool doublebuffer = true;
        ClientAPI clientApi = ClientAPI::OpenGL;
        ContextCreationAPI contextCreationApi = ContextCreationAPI::Native;
        std::array<int, 2> contextVersion{ 4,5 }; // major, minor
        ContextRobustness contextRobustness = ContextRobustness::None;
        ContextReleaseBehavior contextReleaseBehavior = ContextReleaseBehavior::Any;
        bool openglForwardCompat = false;
        bool openglDebugContext = false;
        OpenGLProfile openglProfile = OpenGLProfile::Core;
        bool cocoaRetinaFramebuffer = true;
        std::string cocoaFrameName = "";
        bool cocoaGraphicsSwitching = false;
        std::string x11ClassName = "";
        std::string x11InstanceName = "";

        std::optional<Monitor> monitor;
    };

    class Window {
    public:
        static bool isRawMouseMotionSupported();
        static void setSystemClipboard(const std::string& contents);
        [[nodiscard]] std::string getSystemClipboard();

        static double getTime();
        static void setTime(double t);
        static uint64_t getTimerValue();
        static uint64_t getTimerFrequency();

        static void pollEvents();
        static void waitEvents();
        static void waitEventsTimeout(double timeout);
        static void postEmptyEvent();

        Window(const std::string& title, glm::ivec2 size, const WindowConfig& cfg = {});
        ~Window();

        void makeContextCurrent() const;

        [[nodiscard]] bool isOpen() const;
        void setTitle(const std::string& title) const;
        void setIcon(std::vector<GLFWimage> images) const;
        [[nodiscard]] glm::ivec2 getPos() const;
        void setPos(const glm::ivec2& pos) const;
        [[nodiscard]] glm::ivec2 getSize() const;
        void setSize(const glm::ivec2& size) const;
        void setSizeLimits(const glm::ivec2& minSize, const glm::ivec2& maxSize) const;
        void setAspectRatio(int numer, int denom) const;
        [[nodiscard]] glm::ivec2 getFramebufferSize() const;
        [[nodiscard]] glm::vec2 getContentScale() const;
        [[nodiscard]] float getOpacity() const;
        void setOpacity(float opacity) const;
        void iconify() const;
        void restore() const;
        void maximize() const;
        void show() const;
        void hide() const;
        void focus() const;
        void requestAttention() const;
        Monitor getMonitor() const;
        void setFullscreen(Monitor monitor) const;
        void setWindowed(glm::ivec2 size, glm::ivec2 position = { 0,0 }) const;
        [[nodiscard]] bool isFocused() const;
        [[nodiscard]] bool isIconified() const;
        [[nodiscard]] bool isMaximized() const;
        [[nodiscard]] bool isHovered() const;
        [[nodiscard]] bool isVisible() const;
        [[nodiscard]] bool isResizable() const;
        [[nodiscard]] bool isDecorated() const;
        [[nodiscard]] bool willAutoIconify() const;
        [[nodiscard]] bool isFloating() const;
        [[nodiscard]] bool hasTransparentFramebuffer() const;
        [[nodiscard]] bool willFocusOnShow() const;

        void makeDecorated(bool decorated = true) const;
        void makeResizable(bool resizable = true) const;
        void makeFloating(bool floating = true) const;
        void makeAutoIconify(bool autoIconify = true) const;
        void makeFocusOnShow(bool makeFocusOnShow = true) const;

        [[nodiscard]] ClientAPI getClientAPI() const;
        [[nodiscard]] ContextCreationAPI getContextCreationAPI() const;
        [[nodiscard]] std::array<int, 3> getContextVersion() const;
        [[nodiscard]] bool isOpenGLForwardCompat() const;
        [[nodiscard]] bool hasOpenGLDebugContext() const;
        [[nodiscard]] OpenGLProfile getOpenGLProfile() const;
        [[nodiscard]] ContextReleaseBehavior getContextReleaseBehavior() const;
        [[nodiscard]] bool willContextGenerateErrors() const; //GLFW_CONTEXT_NO_ERROR attrib
        [[nodiscard]] ContextRobustness getContextRobustness() const;

        void swapBuffers();

        [[nodiscard]] bool getKey(Key key) const;
        [[nodiscard]] bool getMouseButton(int button) const;
        [[nodiscard]] glm::dvec2 getMousePos() const;
        void setMousePos(const glm::dvec2& pos) const;

        void setCursor(const Cursor& cursor) const;
        void setCursor(const Cursor* cursor) const;
        void setCursor(const std::shared_ptr<Cursor>& cursor) const;

        void setClipboard(const std::string& contents) const;
        [[nodiscard]] std::string getClipboard() const;

    private:

        GLFWwindow* m_Window;
    };

    class Joystick {
    public:
        explicit Joystick(int jid);

        [[nodiscard]] std::vector<float> getAxes() const;
        [[nodiscard]] std::vector<bool> getButtons() const;
        [[nodiscard]] std::vector<unsigned char> getHats() const;
        [[nodiscard]] std::string getName() const;
        [[nodiscard]] const char* getGUID() const;

        [[nodiscard]] bool isGamepad() const;
        [[nodiscard]] std::string getGamepadName() const;
        [[nodiscard]] GamepadState getGamepadState() const;


    private:
        int m_JID;
    };

    std::string getKeyNameFromKeyID(Key key);
    std::string getKeyNameFromScancode(int scancode);
    int getScancode(Key key);
    bool isJoystickPresent(int jid);


    // Events

    class WindowEvent : public BaseEvent {
    public:

        WindowEvent(Window* window);

        [[nodiscard]] Window* getWindow() const noexcept;

    private:

        Window* m_Window;
    };

    class MouseButtonEvent : public WindowEvent {
    public:
        MouseButtonEvent(Window* window, int button, int mods);

        [[nodiscard]] int getButton() const noexcept;
        [[nodiscard]] int getMods() const noexcept;

    private:
        int m_Button, m_Mods;
    };

    class MouseButtonDownEvent : public MouseButtonEvent {
    public:
        MouseButtonDownEvent(Window* window, int button, int mods);
    };

    class MouseButtonUpEvent : public MouseButtonEvent {
    public:
        MouseButtonUpEvent(Window* window, int button, int mods);
    };

    class CursorMoveEvent : public WindowEvent {
    public:
        CursorMoveEvent(Window* window, glm::dvec2 position);

        [[nodiscard]] const glm::dvec2& getPosition() const noexcept;

    private:
        glm::dvec2 m_Position;
    };


    class CursorEnterEvent : public WindowEvent {
    public:
        CursorEnterEvent(Window* window);
    private:
    };

    class CursorLeaveEvent : public WindowEvent {
    public:
        CursorLeaveEvent(Window* window);
    private:
    };

    class ScrollEvent : public WindowEvent {
    public:
        ScrollEvent(Window* window, glm::dvec2 offset);

        [[nodiscard]] const glm::dvec2& getOffset() const noexcept;

    private:
        glm::dvec2 m_Offset;
    };


    class KeyEvent : public WindowEvent {
    public:
        KeyEvent(Window* window, Key key, int scancode, int mods);

        [[nodiscard]] Key getKey() const noexcept;
        [[nodiscard]] int getScancode() const noexcept;
        [[nodiscard]] int getMods() const noexcept;

    private:
        Key m_Key;
        int m_Scancode, m_Mods;
    };

    class KeyDownEvent : public KeyEvent {
    public:
        KeyDownEvent(Window* window, Key key, int scancode, int mods);
    };

    class KeyUpEvent : public KeyEvent {
    public:
        KeyUpEvent(Window* window, Key key, int scancode, int mods);
    };

    class CharEvent : public WindowEvent {
    public:
        CharEvent(Window* window, uint32_t codepoint);

        [[nodiscard]] uint32_t getCodepoint() const noexcept;

    private:
        uint32_t m_Codepoint;
    };


    class PathDropEvent : public WindowEvent {
    public:
        PathDropEvent(Window* window, std::vector<std::string> paths);

        [[nodiscard]] const std::vector<std::string>& getPaths() const noexcept;

    private:

        std::vector<std::string> m_Paths;
    };

    class WindowMoveEvent : public WindowEvent {
    public:
        WindowMoveEvent(Window* window, glm::ivec2 position);

        [[nodiscard]] const glm::ivec2& getPosition() const noexcept;

    private:
        glm::ivec2 m_Position;
    };

    class WindowResizeEvent : public WindowEvent {
    public:
        WindowResizeEvent(Window* window, glm::ivec2 size);

        [[nodiscard]] const glm::ivec2& getSize() const noexcept;

    private:
        glm::ivec2 m_Size;
    };

    class WindowCloseEvent : public WindowEvent {
    public:
        WindowCloseEvent(Window* window);
    };

    class WindowRefreshEvent : public WindowEvent {
    public:
        WindowRefreshEvent(Window* window);
    };

    class WindowGainedFocusEvent : public WindowEvent {
    public:
        WindowGainedFocusEvent(Window* window);
    };

    class WindowLostFocusEvent : public WindowEvent {
    public:
        WindowLostFocusEvent(Window* window);
    };

    class WindowIconfiedEvent : public WindowEvent {
    public:
        WindowIconfiedEvent(Window* window);
    };

    class WindowDeiconfiedEvent : public WindowEvent {
    public:
        WindowDeiconfiedEvent(Window* window);
    };

    class WindowMaximizedEvent : public WindowEvent {
    public:
        WindowMaximizedEvent(Window* window);
    };

    class WindowDemaximizedEvent : public WindowEvent {
    public:
        WindowDemaximizedEvent(Window* window);
    };

    class WindowFramebufferResizeEvent : public WindowEvent {
    public:
        WindowFramebufferResizeEvent(Window* window, glm::ivec2 framebufferSize);

        [[nodiscard]] const glm::ivec2& getFramebufferSize() const noexcept;

    private:
        glm::ivec2 m_FramebufferSize;
    };

    class WindowContentScaleEvent : public WindowEvent {
    public:
        WindowContentScaleEvent(Window* window, glm::vec2 contentScale);

        [[nodiscard]] const glm::vec2& getContentScale() const noexcept;

    private:
        glm::vec2 m_ContentScale;
    };

    class JoystickConnectedEvent : public BaseEvent {
    public:
        JoystickConnectedEvent(const Joystick& joy);

        [[nodiscard]] const Joystick& getJoystick() const noexcept;

    private:
        Joystick m_Joystick;
    };

    class JoystickDisconnectedEvent : public BaseEvent {
    public:
        JoystickDisconnectedEvent(const Joystick& joy);

        [[nodiscard]] const Joystick& getJoystick() const noexcept;

    private:
        Joystick m_Joystick;
    };

    class MonitorConnectedEvent : public BaseEvent {
    public:
        MonitorConnectedEvent(const Monitor& monitor);

        [[nodiscard]] const Monitor& getMonitor() const noexcept;

    private:
        Monitor m_Monitor;
    };

    class MonitorDisconnectedEvent : public BaseEvent {
    public:
        MonitorDisconnectedEvent(const Monitor& monitor);

        [[nodiscard]] const Monitor& getMonitor() const noexcept;

    private:
        Monitor m_Monitor;
    };

    namespace glfwcbks {
        void windowpos(GLFWwindow* window, int xpos, int ypos);
        void windowsize(GLFWwindow* window, int width, int height);
        void windowclose(GLFWwindow* window);
        void windowrefresh(GLFWwindow* window);
        void windowfocus(GLFWwindow* window, int focused);
        void windowiconify(GLFWwindow* window, int iconfied);
        void windowmaximize(GLFWwindow* window, int maximized);
        void windowframebuffersize(GLFWwindow* window, int width, int height);
        void windowcontentscale(GLFWwindow* window, float xscale, float yscale);
        void mousebutton(GLFWwindow* window, int button, int action, int mods);
        void cursorpos(GLFWwindow* window, double xpos, double ypos);
        void cursorenter(GLFWwindow* window, int entered);
        void scroll(GLFWwindow* window, double xoffset, double yoffset);
        void key(GLFWwindow* window, int key, int scancode, int action, int mods);
        void chart(GLFWwindow* window, uint32_t codepoint);
        void drop(GLFWwindow* window, int path_count, const char** paths);
        void joystick(int jid, int event);
        void monitor(GLFWmonitor* monitor, int event);
    }
}