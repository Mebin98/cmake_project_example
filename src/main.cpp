#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv)
{
    SPDLOG_INFO("Start Program");

    // glfw 라이브러리 초기화, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit()) { // glfw초기화에 실패하면?
        const char* description = nullptr;
        glfwGetError(&description);
        SPDLOG_ERROR("failed to initialize glfw: {}", description);
        // same as -> printf("failed to initialize glfw: %s\n", description);
        return -1;
    }

    // glfw 윈도우 생성, 실패하면 에러 출력후 종료
    SPDLOG_INFO("Create glfw window");
    // auto가 GLFWwindow*로 자동 인지
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME,
      nullptr, nullptr); // 4(모니터 어떤?),5(다른 window랑 context share 할 것인지?)
      // nullptr-> C++에서 제공 널포인터
    if (!window) {
        SPDLOG_ERROR("failed to create glfw window");
        glfwTerminate();
        return -1;
    }

    // glfw 루프 실행, 윈도우 close 버튼을 누르면 정상 종료
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)) { // 닫혀야 되나요? -> !false(==true)-> 계속 반복
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}