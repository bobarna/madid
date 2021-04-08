#include "application.h"

InputHandler *Application::inputHandler = InputHandler::GetInstance();
bool Application::dragging = false;

Application::Application() {
    window = glfwCreateWindow(WIDTH, HEIGHT, NAME, NULL, NULL);
}

Application::~Application() {
    glfwDestroyWindow(window);
}

GLFWwindow *Application::get_window() {
    return window;
}

void Application::init() {
    this->set_callbacks();

    glViewport(0, 0, this->width, this->height);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glLoadIdentity();
    glClearColor(255.0f / 255.0f, 25.0f / 255.0f, 25.0f / 255.0f, 1.0f);

    camera->glSetupCamera();
}

void Application::error_callback(int error, const char *description) {
    std::cerr << "Error: " << description << "." << std::endl;
}

void Application::resize_callback(GLFWwindow *window, int w, int h) {
    // TODO set application's width and height
    if (h < 1)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) w / (float) h, 0.1f, 1000.0f);
    gluLookAt(0.0f, 0.0f, 30, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Application::key_callback(GLFWwindow *window,
                               int key,
                               int scancode,
                               int action,
                               int mods) {
//    std::cout << key << " was pressed" << std::endl;
    if (key == GLFW_KEY_ESCAPE)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if (action == GLFW_RELEASE)
        InputHandler::KeyRelease(key);
    else
        InputHandler::KeyPress(key);

    InputHandler::SetModifiers(mods);
}


void Application::mouse_click_callback(GLFWwindow *window,
                                       int button,
                                       int action,
                                       int mods) {
    switch (button) {
        case GLFW_MOUSE_BUTTON_1:
            dragging = (action == GLFW_PRESS);
            break;
    }
}


void Application::mouse_motion_callback(GLFWwindow *window,
                                        double x,
                                        double y) {
    printf("mouse");
}

void Application::set_callbacks() {
    glfwSetErrorCallback(error_callback);
    glfwSetWindowSizeCallback(window, resize_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_click_callback);
    glfwSetCursorPosCallback(window, mouse_motion_callback);
}

void Application::start() {
    while (!glfwWindowShouldClose(this->window)) {
        this->run();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void Application::run() {
    // ticking every 24 FPS
    bool tick = false;

    double delta_time = glfwGetTime() - time_since_last_frame;
    time_since_last_frame = glfwGetTime();

    if (time_since_last_frame >= 1.0 / 24.0) {
        glfwSetTime(0.0f);
        time_since_last_frame = 0.0f;
        tick = true;
    }

    // TODO think about rendering only in 24 FPS
    // TODO guarantee delta_time to be infinitesimal
    scene->update(delta_time);
    camera->control(delta_time);

    //clear color and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); //load identity matrix
    camera->glSetupCamera();
    scene->render();
}


