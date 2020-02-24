#pragma once

#include "GLView.h"
#include "irrKlang.h"
#include "NetMessengerClient.h"
#include "../cwin64/WObanana.h"
#include "WO.h"

using namespace irrklang;
namespace Aftr
{
   class Camera;


class GLViewNewModule : public GLView
{
public:
   WObanana* banana;
   static GLViewNewModule* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewNewModule();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createNewModuleWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );
   float move = 0;
   void adjust(const Vector& x) { banana->moveRelative(x); };
   Vector getLookDirection() { return banana->getLookDirection(); };

protected:
   
   GLViewNewModule( const std::vector< std::string >& args );
   virtual void onCreate();   
   ISoundEngine* Engine = nullptr;
private:
    bool isMoving();
    NetMessengerClient* net;
};

} //namespace Aftr
