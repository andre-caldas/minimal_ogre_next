// You should include this only when a directory name is needed.
#include "config_dir.h"

#include "MinVsgApp.h"

#include <format>
#include <SDL3/SDL.h>

MinVsgApp::Status MinVsgApp::init(const std::string& title)
{
  try {
    initSdlVideo(title);
    initVsg();
  } catch(Status status) {
    return status;
  }

  return {};
}


void MinVsgApp::initSdlVideo(const std::string& title)
{
  if(SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
    throw Status{SDL_GetError()};
  }

  SDL_WindowFlags wflags = SDL_WINDOW_RESIZABLE;
  sdlWindow = SDL_CreateWindow(title.c_str(), width, height, wflags);
  if(!sdlWindow) {
    throw Status{SDL_GetError()};
  }
}


void MinVsgApp::initVsg()
{
}


MinVsgApp::Status MinVsgApp::processEvent(const SDL_Event* event)
{
  switch(event->type) {
  case SDL_EVENT_QUIT:
    shallQuit = true;
  }

  return {};
}

MinVsgApp::Status MinVsgApp::iterate()
{
  return {};
}

MinVsgApp::~MinVsgApp()
{
  if(sdlWindow) {
    SDL_DestroyWindow(sdlWindow);
    sdlWindow = nullptr;
  }
}
