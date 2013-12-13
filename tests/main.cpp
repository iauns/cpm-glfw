#include <iostream>
#include <gtest/gtest.h>
#include <GLFW/glfw3.h>

static void error_callback(int error, const char* description)
{
  FAIL() << "GLFW Failed (" << error << "): " << description;
}

TEST(GLFWTests, BuildInvisibleWindow)
{
  GLFWwindow* window;
  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
    FAIL() << "GLFW failed to initialize";

  glfwWindowHint(GLFW_VISIBLE, 0);
  window = glfwCreateWindow(640, 480, "Invisible Example", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    FAIL() << "Failed to create glfw window";
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);


  return RUN_ALL_TESTS();
}
