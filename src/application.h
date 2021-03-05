#ifndef MADID_APPLICATION_H
#define MADID_APPLICATION_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <memory>

#include "constants.h"
#include "scene.h"
#include "rendering/camera.h"

// TODO make this class a singleton
class Application {
    int keyArr[350];
    int width = WIDTH;
    int height = HEIGHT;

    static bool dragging;
    // Callback functions
    static void error_callback(int error, const char* description);
    static void resize_callback(GLFWwindow *window, int w, int h);
    static void key_callback(GLFWwindow *window, int key, int scancode, 
            int action, int mods);
    static void mouse_click_callback(GLFWwindow *window, int button, int action,
            int mods);
    static void mouse_motion_callback(GLFWwindow *window, double x, double y);

    std::shared_ptr<Scene> scene = std::make_shared<Scene>();

    void run();
    double time_since_last_frame;

    std::shared_ptr<Camera> camera = std::make_shared<Camera>();

    // TODO
    //boolean flag, indicates whether a screen capture event should be performed
    //on the next display event.
    /* bool screen_capture; */ 
    /* bool zoom_mode; */ 
    /* bool pan_mode; */
    /* bool trackball_mode; */
public:
    Application();
    ~Application();
    
    GLFWwindow *window; 
    
    GLFWwindow *get_window();
    void init();
    void set_callbacks();

    void start();
};


#endif //MADID_APPLICATION_H
