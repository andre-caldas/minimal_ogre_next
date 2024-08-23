#include "MinVsgApp.h"

#include <iostream>
#include <memory>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>

namespace {
  std::unique_ptr<MinVsgApp> app;
}

SDL_AppResult SDL_AppInit(void** /*appstate*/, int /*argc*/, char** /*argv*/)
{
  app = std::make_unique<MinVsgApp>();
  auto status
    = app->init("(Not so) minimal (yet complete) VulkanSceneGraph application");
  if(!status) {
    // Use your error logging facility, here! (SDL_LogError, for example)
    std::cerr << status.message << std::endl;
    return SDL_APP_FAILURE;
  }
  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* /*appstate*/)
{
  app->iterate();
  if(app->shallQuit) {
    // TODO: report errors.
    return SDL_APP_SUCCESS;
  }
  return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* /*appstate*/, const SDL_Event* event)
{
  app->processEvent(event);
  if(app->shallQuit) {
    // TODO: report errors.
    return SDL_APP_SUCCESS;
  }
  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* /*appstate*/)
{
  app = nullptr;
}
