#pragma once

#include <string>
#include <SDL3/SDL.h>

class MinVsgApp
{
public:
  struct Status {
    Status() {}
    Status(std::string message, int error=-1)
      : error_code{error}
      , message{message}
    {}

    bool hasSucceeded() const {return error_code == 0;}
    operator bool() const{return hasSucceeded();}

    int error_code = 0;
    const std::string message;
  };

  ~MinVsgApp();

  Status init(const std::string& title);
  Status iterate();
  Status processEvent(const SDL_Event* event);

  int width = 1024;
  int height = 768;
  std::string title;

  bool shallQuit = false;

  /*
   * VulkanSceneGraph structures.
   */

  /*
   * SDL strucutres.
   * Do we need to "destroy" them???
   */
  SDL_Window* sdlWindow = nullptr;

private:
  void initSdlVideo(const std::string& title);
  void initVsg();
};
