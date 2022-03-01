#include "kat/window.hpp"

namespace kat {

    Cursor::Cursor(const CursorConfig& cfg) {
        m_Cursor = glfwCreateCursor(cfg.m_Image, cfg.m_Hotspot.x, cfg.m_Hotspot.y);
    }

    Cursor::Cursor(SystemCursorShape shape) {
        m_Cursor = glfwCreateStandardCursor(static_cast<int>(shape));
    }

    Cursor::~Cursor() {
        glfwDestroyCursor(m_Cursor);
    }

    GLFWcursor* Cursor::getHandle() const noexcept {
        return m_Cursor;
    }

    std::vector<Monitor> Monitor::getMonitors() {
        int i;
        GLFWmonitor** mons = glfwGetMonitors(&i);
        std::vector<Monitor> monits;
        for (int e = 0; e < i; e++) {
            monits.emplace_back(mons[e]);
        }
        return monits;
    }

    Monitor Monitor::getPrimaryMonitor() {
        return Monitor(glfwGetPrimaryMonitor());
    }

    Monitor::Monitor(int i) {
        int i_;
        GLFWmonitor** mons = glfwGetMonitors(&i);
        if (i < i_) {
            m_Handle = mons[i];
        }
        else {
            spdlog::error("Failed to find monitor {}, using primary", i);
            m_Handle = glfwGetPrimaryMonitor();
        }
    }

    Monitor::Monitor(GLFWmonitor* hndle) : m_Handle{ hndle } {
    }

    glm::ivec2 Monitor::getPos() const {
        glm::ivec2 p{};
        glfwGetMonitorPos(m_Handle, &p.x, &p.y);
        return p;
    }

    glm::ivec4 Monitor::getWorkarea() const {
        glm::ivec4 p{};
        glfwGetMonitorWorkarea(m_Handle, &p.x, &p.y, &p.z, &p.w);
        return p;
    }

    glm::ivec2 Monitor::getPhysicalSize() const {
        glm::ivec2 p{};
        glfwGetMonitorPhysicalSize(m_Handle, &p.x, &p.y);
        return p;
    }

    glm::vec2 Monitor::getContentScale() const {
        glm::vec2 p{};
        glfwGetMonitorContentScale(m_Handle, &p.x, &p.y);
        return p;
    }

    std::string Monitor::getName() const {
        return glfwGetMonitorName(m_Handle);
    }

    std::vector<VideoMode> Monitor::getVideoModes() const {
        int i;
        const VideoMode* vms = glfwGetVideoModes(m_Handle, &i);
        std::vector<VideoMode> vmods;
        for (int e = 0; e < i; e++) {
            vmods.push_back(vms[e]);
        }

        return vmods;
    }

    const VideoMode* Monitor::getVideoMode() const {
        return glfwGetVideoMode(m_Handle);
    }

    void Monitor::setGamma(float gamma) const {
        glfwSetGamma(m_Handle, gamma);
    }

    const GammaRamp* Monitor::getGammaRamp() const {
        return glfwGetGammaRamp(m_Handle);
    }

    void Monitor::setGammaRamp(const GammaRamp& ramp) const {
        glfwSetGammaRamp(m_Handle, &ramp);
    }

    void Monitor::setGammaRamp(const GammaRamp* ramp) const {
        glfwSetGammaRamp(m_Handle, ramp);
    }

    GLFWmonitor* Monitor::getHandle() const noexcept {
        return m_Handle;
    }

    bool Window::isRawMouseMotionSupported() {
        return glfwRawMouseMotionSupported();
    }

    void Window::setSystemClipboard(const std::string& contents) {
        glfwSetClipboardString(NULL, contents.c_str());
    }

    std::string Window::getSystemClipboard() {
        return glfwGetClipboardString(NULL);
    }

    double Window::getTime() {
        return glfwGetTime();
    }

    void Window::setTime(double t) {
        glfwSetTime(t);
    }

    uint64_t Window::getTimerValue() {
        return glfwGetTimerValue();
    }

    uint64_t Window::getTimerFrequency() {
        return glfwGetTimerFrequency();
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

    void Window::waitEvents() {
        glfwWaitEvents();
    }

    void Window::waitEventsTimeout(double timeout) {
        glfwWaitEventsTimeout(timeout);
    }

    void Window::postEmptyEvent() {
        glfwPostEmptyEvent();
    }

    namespace glfwcbks {
        void windowpos(GLFWwindow* window, int xpos, int ypos) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(WindowMoveEvent(reinterpret_cast<Window*>(uptr), { xpos, ypos }));
            }
        }

        void windowsize(GLFWwindow* window, int width, int height) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(WindowResizeEvent(reinterpret_cast<Window*>(uptr), { width, height }));
            }
        }

        void windowclose(GLFWwindow* window) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(WindowCloseEvent(reinterpret_cast<Window*>(uptr)));
            }
        }

        void windowrefresh(GLFWwindow* window) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(WindowRefreshEvent(reinterpret_cast<Window*>(uptr)));
            }
        }

        void windowfocus(GLFWwindow* window, int focused) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                if (focused) {
                    kat::engine().dispatch(WindowGainedFocusEvent(reinterpret_cast<Window*>(uptr)));
                }
                else {
                    kat::engine().dispatch(WindowLostFocusEvent(reinterpret_cast<Window*>(uptr)));
                }
            }
        }

        void windowiconify(GLFWwindow* window, int iconified) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                if (iconified) {
                    kat::engine().dispatch(WindowIconfiedEvent(reinterpret_cast<Window*>(uptr)));
                }
                else {
                    kat::engine().dispatch(WindowDeiconfiedEvent(reinterpret_cast<Window*>(uptr)));
                }
            }
        }

        void windowmaximize(GLFWwindow* window, int maximized) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                if (maximized) {
                    kat::engine().dispatch(WindowMaximizedEvent(reinterpret_cast<Window*>(uptr)));
                }
                else {
                    kat::engine().dispatch(WindowDemaximizedEvent(reinterpret_cast<Window*>(uptr)));
                }
            }
        }

        void windowframebuffersize(GLFWwindow* window, int width, int height) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(WindowFramebufferResizeEvent(reinterpret_cast<Window*>(uptr), { width, height }));
            }
        }

        void windowcontentscale(GLFWwindow* window, float xscale, float yscale) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(WindowContentScaleEvent(reinterpret_cast<Window*>(uptr), { xscale, yscale }));
            }
        }

        void mousebutton(GLFWwindow* window, int button, int action, int mods) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                if (action == GLFW_PRESS) {
                    kat::engine().dispatch(MouseButtonDownEvent(reinterpret_cast<Window*>(uptr), button, mods));
                }
                else {
                    kat::engine().dispatch(MouseButtonUpEvent(reinterpret_cast<Window*>(uptr), button, mods));
                }
            }
        }

        void cursorpos(GLFWwindow* window, double xpos, double ypos) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(CursorMoveEvent(reinterpret_cast<Window*>(uptr), { xpos, ypos }));
            }
        }

        void cursorenter(GLFWwindow* window, int entered) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                if (entered) {
                    kat::engine().dispatch(CursorEnterEvent(reinterpret_cast<Window*>(uptr)));
                }
                else {
                    kat::engine().dispatch(CursorLeaveEvent(reinterpret_cast<Window*>(uptr)));
                }
            }
        }

        void scroll(GLFWwindow* window, double xoffset, double yoffset) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(ScrollEvent(reinterpret_cast<Window*>(uptr), { xoffset, yoffset }));
            }
        }

        void key(GLFWwindow* window, int key, int scancode, int action, int mods) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                if (action == GLFW_PRESS) {
                    kat::engine().dispatch(KeyDownEvent(reinterpret_cast<Window*>(uptr), static_cast<Key>(key), scancode, mods));
                }
                else if (action == GLFW_RELEASE) {
                    kat::engine().dispatch(KeyUpEvent(reinterpret_cast<Window*>(uptr), static_cast<Key>(key), scancode, mods));
                }
            }
        }

        void chart(GLFWwindow* window, uint32_t codepoint) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                kat::engine().dispatch(CharEvent(reinterpret_cast<Window*>(uptr), codepoint));
            }
        }

        void drop(GLFWwindow* window, int path_count, const char** paths) {
            void* uptr = glfwGetWindowUserPointer(window);
            if (uptr) {
                std::vector<std::string> paths_;
                paths_.reserve(path_count);
                for (int i = 0; i < path_count; i++) {
                    paths_.emplace_back(paths[i]);
                }

                kat::engine().dispatch(PathDropEvent(reinterpret_cast<Window*>(uptr), paths_));
            }
        }

        void joystick(int jid, int event) {
            if (event == GLFW_CONNECTED) {
                kat::engine().dispatch(JoystickConnectedEvent(Joystick(jid)));
            }
            else if (event == GLFW_DISCONNECTED) {
                kat::engine().dispatch(JoystickDisconnectedEvent(Joystick(jid)));
            }
        }

        void monitor(GLFWmonitor* monitor, int event) {
            if (event == GLFW_CONNECTED) {
                kat::engine().dispatch(MonitorConnectedEvent(Monitor(monitor)));
            }
            else if (event == GLFW_DISCONNECTED) {
                kat::engine().dispatch(MonitorDisconnectedEvent(Monitor(monitor)));
            }
        }
    }

    Window::Window(const std::string& title, glm::ivec2 size, const WindowConfig& cfg) {
        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_RESIZABLE, cfg.resizable);
        glfwWindowHint(GLFW_VISIBLE, cfg.visible);
        glfwWindowHint(GLFW_DECORATED, cfg.decorated);
        glfwWindowHint(GLFW_AUTO_ICONIFY, cfg.autoIconify);
        glfwWindowHint(GLFW_FLOATING, cfg.floating);
        glfwWindowHint(GLFW_MAXIMIZED, cfg.maximized);
        glfwWindowHint(GLFW_CENTER_CURSOR, cfg.centerCursor);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, cfg.transparentFrambuffer);
        glfwWindowHint(GLFW_FOCUS_ON_SHOW, cfg.focusOnShow);
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, cfg.scaleToMonitor);
        glfwWindowHint(GLFW_ALPHA_BITS, cfg.colorBits[3]);
        glfwWindowHint(GLFW_DEPTH_BITS, cfg.depthBits);
        glfwWindowHint(GLFW_STENCIL_BITS, cfg.stencilBits);
        glfwWindowHint(GLFW_ACCUM_RED_BITS, cfg.accumColorBits[0]);
        glfwWindowHint(GLFW_ACCUM_GREEN_BITS, cfg.accumColorBits[1]);
        glfwWindowHint(GLFW_ACCUM_BLUE_BITS, cfg.accumColorBits[2]);
        glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, cfg.accumColorBits[3]);
        glfwWindowHint(GLFW_AUX_BUFFERS, cfg.auxBuffers);
        glfwWindowHint(GLFW_STEREO, cfg.stereo);
        glfwWindowHint(GLFW_SRGB_CAPABLE, cfg.srgbCapable);
        glfwWindowHint(GLFW_DOUBLEBUFFER, cfg.doublebuffer);
        glfwWindowHint(GLFW_CLIENT_API, static_cast<int>(cfg.clientApi));
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, static_cast<int>(cfg.contextCreationApi));
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, cfg.contextVersion[0]);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, cfg.contextVersion[1]);
        glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, static_cast<int>(cfg.contextReleaseBehavior));
        glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, static_cast<int>(cfg.contextRobustness));
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, cfg.openglForwardCompat);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, cfg.openglDebugContext);
        glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(cfg.openglProfile));
        glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, cfg.cocoaRetinaFramebuffer);
        glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, cfg.cocoaGraphicsSwitching);
        glfwWindowHintString(GLFW_COCOA_FRAME_NAME, cfg.cocoaFrameName.c_str());
        glfwWindowHintString(GLFW_X11_CLASS_NAME, cfg.x11ClassName.c_str());
        glfwWindowHintString(GLFW_X11_INSTANCE_NAME, cfg.x11InstanceName.c_str());


        if (cfg.monitor.has_value()) {
            // fullscreen
            const VideoMode* vmode = cfg.monitor.value().getVideoMode();
            glfwWindowHint(GLFW_RED_BITS, vmode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, vmode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, vmode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, vmode->refreshRate);

            m_Window = glfwCreateWindow(vmode->width, vmode->height, title.c_str(), cfg.monitor.value().getHandle(), NULL);
        }
        else {

            glfwWindowHint(GLFW_RED_BITS, cfg.colorBits[0]);
            glfwWindowHint(GLFW_GREEN_BITS, cfg.colorBits[1]);
            glfwWindowHint(GLFW_BLUE_BITS, cfg.colorBits[2]);
            glfwWindowHint(GLFW_REFRESH_RATE, cfg.refreshRate);
            m_Window = glfwCreateWindow(size.x, size.y, title.c_str(), NULL, NULL);
        }

        glfwSetWindowUserPointer(m_Window, this);
        glfwSetWindowPosCallback(m_Window, glfwcbks::windowpos);
        glfwSetWindowSizeCallback(m_Window, glfwcbks::windowsize);
        glfwSetWindowCloseCallback(m_Window, glfwcbks::windowclose);
        glfwSetWindowRefreshCallback(m_Window, glfwcbks::windowrefresh);
        glfwSetWindowFocusCallback(m_Window, glfwcbks::windowfocus);
        glfwSetWindowIconifyCallback(m_Window, glfwcbks::windowiconify);
        glfwSetWindowMaximizeCallback(m_Window, glfwcbks::windowmaximize);
        glfwSetFramebufferSizeCallback(m_Window, glfwcbks::windowframebuffersize);
        glfwSetWindowContentScaleCallback(m_Window, glfwcbks::windowcontentscale);
    }


    Window::~Window() {
        glfwDestroyWindow(m_Window);
    }

    void Window::makeContextCurrent() const {
        glfwMakeContextCurrent(m_Window);
    }

    bool Window::isOpen() const {
        return !glfwWindowShouldClose(m_Window);
    }

    void Window::setTitle(const std::string& title) const {
        glfwSetWindowTitle(m_Window, title.c_str());
    }

    void Window::setIcon(std::vector<GLFWimage> images) const {
        glfwSetWindowIcon(m_Window, images.size(), images.data());
    }

    glm::ivec2 Window::getPos() const {
        glm::ivec2 v{};
        glfwGetWindowPos(m_Window, &v.x, &v.y);
        return v;
    }
    
    void Window::setPos(const glm::ivec2& pos) const {
        glfwSetWindowPos(m_Window, pos.x, pos.y);
    }
    
    glm::ivec2 Window::getSize() const {
        glm::ivec2 v{};
        glfwGetWindowSize(m_Window, &v.x, &v.y);
        return v;
    }
    
    void Window::setSize(const glm::ivec2& size) const {
        glfwSetWindowSize(m_Window, size.x, size.y);
    }
    
    void Window::setSizeLimits(const glm::ivec2& minSize, const glm::ivec2& maxSize) const {
        glfwSetWindowSizeLimits(m_Window, minSize.x, minSize.y, maxSize.x, maxSize.y);
    }
    
    void Window::setAspectRatio(int numer, int denom) const {
        glfwSetWindowAspectRatio(m_Window, numer, denom);
    }
    
    glm::ivec2 Window::getFramebufferSize() const {
        glm::ivec2 v{};
        glfwGetFramebufferSize(m_Window, &v.x, &v.y);
        return v;
    }
    
    glm::vec2 Window::getContentScale() const {
        glm::vec2 v{};
        glfwGetWindowContentScale(m_Window, &v.x, &v.y);
        return v;
    }
    
    float Window::getOpacity() const {
        return glfwGetWindowOpacity(m_Window);
    }
    
    void Window::setOpacity(float opacity) const {
        glfwSetWindowOpacity(m_Window, opacity);
    }

    void Window::iconify() const {
        glfwIconifyWindow(m_Window);
    }

    void Window::restore() const {
        glfwRestoreWindow(m_Window);
    }

    void Window::maximize() const {
        glfwMaximizeWindow(m_Window);
    }

    void Window::show() const {
        glfwShowWindow(m_Window);
    }

    void Window::hide() const {
        glfwHideWindow(m_Window);
    }

    void Window::focus() const {
        glfwFocusWindow(m_Window);
    }

    void Window::requestAttention() const {
        glfwRequestWindowAttention(m_Window);
    }

    Monitor Window::getMonitor() const {
        return Monitor(glfwGetWindowMonitor(m_Window));
    }

    void Window::setFullscreen(Monitor monitor) const {
        const VideoMode* vm = monitor.getVideoMode();

        glfwSetWindowMonitor(m_Window, monitor.getHandle(), 0, 0, vm->width, vm->height, vm->refreshRate);
    }

    void Window::setWindowed(glm::ivec2 size, glm::ivec2 position) const {
        glfwSetWindowMonitor(m_Window, NULL, position.x, position.y, size.x, size.y, GLFW_DONT_CARE);
    }

    bool Window::isFocused() const {
        return glfwGetWindowAttrib(m_Window, GLFW_FOCUSED);
    }

    bool Window::isIconified() const {
        return glfwGetWindowAttrib(m_Window, GLFW_ICONIFIED);
    }

    bool Window::isMaximized() const {
        return glfwGetWindowAttrib(m_Window, GLFW_MAXIMIZED);
    }

    bool Window::isHovered() const {
        return glfwGetWindowAttrib(m_Window, GLFW_HOVERED);
    }

    bool Window::isVisible() const {
        return glfwGetWindowAttrib(m_Window, GLFW_VISIBLE);
    }

    bool Window::isResizable() const {
        return glfwGetWindowAttrib(m_Window, GLFW_RESIZABLE);
    }

    bool Window::isDecorated() const {
        return glfwGetWindowAttrib(m_Window, GLFW_DECORATED);
    }

    bool Window::willAutoIconify() const {
        return glfwGetWindowAttrib(m_Window, GLFW_AUTO_ICONIFY);
    }

    bool Window::isFloating() const {
        return glfwGetWindowAttrib(m_Window, GLFW_FLOATING);
    }

    bool Window::hasTransparentFramebuffer() const {
        return glfwGetWindowAttrib(m_Window, GLFW_TRANSPARENT_FRAMEBUFFER);
    }

    bool Window::willFocusOnShow() const {
        return glfwGetWindowAttrib(m_Window, GLFW_FOCUS_ON_SHOW);
    }

    void Window::makeDecorated(bool decorated) const {
        glfwSetWindowAttrib(m_Window, GLFW_DECORATED, decorated);
    }

    void Window::makeResizable(bool resizable) const {
        glfwSetWindowAttrib(m_Window, GLFW_RESIZABLE, resizable);
    }

    void Window::makeFloating(bool floating) const {
        glfwSetWindowAttrib(m_Window, GLFW_FLOATING, floating);
    }

    void Window::makeAutoIconify(bool autoIconify) const {
        glfwSetWindowAttrib(m_Window, GLFW_AUTO_ICONIFY, autoIconify);
    }

    void Window::makeFocusOnShow(bool makeFocusOnShow) const {
        glfwSetWindowAttrib(m_Window, GLFW_FOCUS_ON_SHOW, makeFocusOnShow);
    }

    ClientAPI Window::getClientAPI() const {
        return static_cast<ClientAPI>(glfwGetWindowAttrib(m_Window, GLFW_CLIENT_API));
    }

    ContextCreationAPI Window::getContextCreationAPI() const {
        return static_cast<ContextCreationAPI>(glfwGetWindowAttrib(m_Window, GLFW_CONTEXT_CREATION_API));
    }

    std::array<int, 3> Window::getContextVersion() const {
        return {
            glfwGetWindowAttrib(m_Window, GLFW_CONTEXT_VERSION_MAJOR),
            glfwGetWindowAttrib(m_Window, GLFW_CONTEXT_VERSION_MAJOR),
            glfwGetWindowAttrib(m_Window, GLFW_CONTEXT_REVISION)
        };
    }

    bool Window::isOpenGLForwardCompat() const {
        return glfwGetWindowAttrib(m_Window, GLFW_OPENGL_FORWARD_COMPAT);

    }

    bool Window::hasOpenGLDebugContext() const {
        return glfwGetWindowAttrib(m_Window, GLFW_OPENGL_DEBUG_CONTEXT);

    }

    OpenGLProfile Window::getOpenGLProfile() const {
        return static_cast<OpenGLProfile>(glfwGetWindowAttrib(m_Window, GLFW_OPENGL_PROFILE));
    }

    ContextReleaseBehavior Window::getContextReleaseBehavior() const {
        return static_cast<ContextReleaseBehavior>(glfwGetWindowAttrib(m_Window, GLFW_CONTEXT_RELEASE_BEHAVIOR));
    }

    bool Window::willContextGenerateErrors() const {
        return glfwGetWindowAttrib(m_Window, GLFW_CONTEXT_NO_ERROR);
    }

    ContextRobustness Window::getContextRobustness() const {
        return static_cast<ContextRobustness>(glfwGetWindowAttrib(m_Window, GLFW_CONTEXT_ROBUSTNESS));
    }

    void Window::swapBuffers() {
        glfwSwapBuffers(m_Window);
    }

    bool Window::getKey(Key key) const {
        return glfwGetKey(m_Window, static_cast<int>(key));
    }

    bool Window::getMouseButton(int button) const {
        return glfwGetMouseButton(m_Window, button);
    }

    glm::dvec2 Window::getMousePos() const {
        glm::dvec2 p{};
        glfwGetCursorPos(m_Window, &p.x, &p.y);
        return p;
    }

    void Window::setMousePos(const glm::dvec2& pos) const {
        glfwSetCursorPos(m_Window, pos.x, pos.y);
    }

    void Window::setCursor(const Cursor& cursor) const {
        glfwSetCursor(m_Window, cursor.getHandle());
    }

    void Window::setCursor(const Cursor* cursor) const {
        glfwSetCursor(m_Window, cursor->getHandle());
    }

    void Window::setCursor(const std::shared_ptr<Cursor>& cursor) const {
        glfwSetCursor(m_Window, cursor->getHandle());
    }

    void Window::setClipboard(const std::string& contents) const {
        glfwSetClipboardString(m_Window, contents.c_str());
    }

    std::string Window::getClipboard() const {
        return glfwGetClipboardString(m_Window);
    }

    Joystick::Joystick(int jid) : m_JID(jid) {
    }

    std::vector<float> Joystick::getAxes() const {
        int c;
        const float* axes_ = glfwGetJoystickAxes(m_JID, &c);
        std::vector<float> axes(c);
        std::memcpy(axes.data(), axes_, c * sizeof(float));
        return axes;
    }
    
    std::vector<bool> Joystick::getButtons() const {
        int c;
        const unsigned char* buttons_ = glfwGetJoystickButtons(m_JID, &c);

        std::vector<bool> buttons(c);
        for (int i = 0; i < c; i++) {
            buttons[i] = buttons_[i];
        }

        return buttons;
    }
    
    std::vector<unsigned char> Joystick::getHats() const {
        int c;
        const unsigned char* hats_ = glfwGetJoystickHats(m_JID, &c);
        std::vector<unsigned char> hats(c);
        std::memcpy(hats.data(), hats_, c * sizeof(unsigned char));
        return hats;
    }
    
    std::string Joystick::getName() const {
        return glfwGetJoystickName(m_JID);
    }
    
    const char* Joystick::getGUID() const {
        return glfwGetJoystickGUID(m_JID);
    }
    
    bool Joystick::isGamepad() const {
        return glfwJoystickIsGamepad(m_JID);
    }
    
    std::string Joystick::getGamepadName() const {
        return glfwGetGamepadName(m_JID);
    }
    
    GamepadState Joystick::getGamepadState() const {
        GamepadState gs;
        if (glfwGetGamepadState(m_JID, &gs)) {
            return gs;
        }
        else {
            spdlog::error("Cannot load gamepad state from joystick {} since it is either not present or does not have a gamepad mapping", m_JID);
            return {};
        }
    }    

    std::string getKeyNameFromKeyID(Key key) {
        return glfwGetKeyName(static_cast<int>(key), 0);
    }
    
    std::string getKeyNameFromScancode(int scancode) {
        return glfwGetKeyName(GLFW_KEY_UNKNOWN, scancode);
    }
    
    int getScancode(Key key) {
        return glfwGetKeyScancode(static_cast<int>(key));
    }
    
    bool isJoystickPresent(int jid) {
        return glfwJoystickPresent(jid);
    }
    
    WindowEvent::WindowEvent(Window* window) : m_Window(window) {
    }

    Window* WindowEvent::getWindow() const noexcept {
        return m_Window;
    }

    MouseButtonEvent::MouseButtonEvent(Window* window, int button, int mods) : WindowEvent(window), m_Button(button), m_Mods(mods) {
    }

    int MouseButtonEvent::getButton() const noexcept {
        return m_Button;
    }

    int MouseButtonEvent::getMods() const noexcept {
        return m_Mods;
    }

    MouseButtonDownEvent::MouseButtonDownEvent(Window* window, int button, int mods) : MouseButtonEvent(window, button, mods) {
    }

    MouseButtonUpEvent::MouseButtonUpEvent(Window* window, int button, int mods) : MouseButtonEvent(window, button, mods) {
    }

    KeyEvent::KeyEvent(Window* window, Key key, int scancode, int mods) : WindowEvent(window), m_Key(key), m_Scancode(scancode), m_Mods(mods) {
    }

    Key KeyEvent::getKey() const noexcept {
        return m_Key;
    }

    int KeyEvent::getScancode() const noexcept {
        return m_Scancode;
    }

    int KeyEvent::getMods() const noexcept {
        return m_Mods;
    }

    KeyDownEvent::KeyDownEvent(Window* window, Key key, int scancode, int mods) : KeyEvent(window, key, scancode, mods) {
    }

    KeyUpEvent::KeyUpEvent(Window* window, Key key, int scancode, int mods) : KeyEvent(window, key, scancode, mods) {
    }

    CursorMoveEvent::CursorMoveEvent(Window* window, glm::dvec2 position) : WindowEvent(window), m_Position(position) {
    }

    const glm::dvec2& CursorMoveEvent::getPosition() const noexcept {
        return m_Position;
    }

    CursorEnterEvent::CursorEnterEvent(Window* window) : WindowEvent(window) {
    }

    CursorLeaveEvent::CursorLeaveEvent(Window* window) : WindowEvent(window) {
    }

    ScrollEvent::ScrollEvent(Window* window, glm::dvec2 offset) : WindowEvent(window), m_Offset(offset) {
    }

    const glm::dvec2& ScrollEvent::getOffset() const noexcept {
        return m_Offset;
    }

    CharEvent::CharEvent(Window* window, uint32_t codepoint) : WindowEvent(window), m_Codepoint(codepoint) {
    }

    uint32_t CharEvent::getCodepoint() const noexcept {
        return m_Codepoint;
    }

    PathDropEvent::PathDropEvent(Window* window, std::vector<std::string> paths) : WindowEvent(window), m_Paths(paths) {
    }

    const std::vector<std::string>& PathDropEvent::getPaths() const noexcept {
        return m_Paths;
    }

    WindowMoveEvent::WindowMoveEvent(Window* window, glm::ivec2 position) : WindowEvent(window), m_Position(position) {
    }

    const glm::ivec2& WindowMoveEvent::getPosition() const noexcept {
        return m_Position;
    }

    WindowResizeEvent::WindowResizeEvent(Window* window, glm::ivec2 size) : WindowEvent(window), m_Size(size) {
    }

    const glm::ivec2& WindowResizeEvent::getSize() const noexcept {
        return m_Size;
    }

    WindowCloseEvent::WindowCloseEvent(Window* window) : WindowEvent(window) {
    }

    WindowRefreshEvent::WindowRefreshEvent(Window* window) : WindowEvent(window) {
    }

    WindowGainedFocusEvent::WindowGainedFocusEvent(Window* window) : WindowEvent(window) {
    }

    WindowLostFocusEvent::WindowLostFocusEvent(Window* window) : WindowEvent(window) {
    }

    WindowIconfiedEvent::WindowIconfiedEvent(Window* window) : WindowEvent(window) {
    }

    WindowDeiconfiedEvent::WindowDeiconfiedEvent(Window* window) : WindowEvent(window) {
    }

    WindowMaximizedEvent::WindowMaximizedEvent(Window* window) : WindowEvent(window) {
    }

    WindowDemaximizedEvent::WindowDemaximizedEvent(Window* window) : WindowEvent(window) {
    }

    WindowFramebufferResizeEvent::WindowFramebufferResizeEvent(Window* window, glm::ivec2 framebufferSize) : WindowEvent(window), m_FramebufferSize(framebufferSize) {
    }

    const glm::ivec2& WindowFramebufferResizeEvent::getFramebufferSize() const noexcept {
        return m_FramebufferSize;
    }

    WindowContentScaleEvent::WindowContentScaleEvent(Window* window, glm::vec2 contentScale) : WindowEvent(window), m_ContentScale(contentScale) {
    }

    const glm::vec2& WindowContentScaleEvent::getContentScale() const noexcept {
        return m_ContentScale;
    }

    JoystickConnectedEvent::JoystickConnectedEvent(const Joystick& joy) : m_Joystick(joy) {
    }

    const Joystick& JoystickConnectedEvent::getJoystick() const noexcept {
        return m_Joystick;
    }

    JoystickDisconnectedEvent::JoystickDisconnectedEvent(const Joystick& joy) : m_Joystick(joy) {
    }

    const Joystick& JoystickDisconnectedEvent::getJoystick() const noexcept {
        return m_Joystick;
    }

    MonitorConnectedEvent::MonitorConnectedEvent(const Monitor& monitor) : m_Monitor(monitor) {
    }

    const Monitor& MonitorConnectedEvent::getMonitor() const noexcept {
        return m_Monitor;
    }

    MonitorDisconnectedEvent::MonitorDisconnectedEvent(const Monitor& monitor) : m_Monitor(monitor) {
    }

    const Monitor& MonitorDisconnectedEvent::getMonitor() const noexcept {
        return m_Monitor;
    }
}