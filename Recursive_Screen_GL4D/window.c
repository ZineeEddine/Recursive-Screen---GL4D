/*
HADJ RABAH
ZINE EDDINE
UNIVERSITE PARIS 8

Recursive Screen

GL4D
Voici l'implementation d'une petite
démo donant l'impression que l'écran
du PC affiche un PC qui affiche un PC

GL4D.
https://github.com/noalien/GL4Dummies
*/

#include <assert.h>
#include <GL4D/gl4dp.h>
#include "rasterize.h"
#include <GL4D/gl4duw_SDL2.h>

static void init(void);
static void draw(void);
static void key(int keycode);
static void sortie(void);

//declaration des differentes surfaces
static surface_t * _cube = NULL;
static surface_t * _cube_table = NULL;
static surface_t * _cube_clavier = NULL;
static surface_t * _cube_iphone_front = NULL;
static surface_t * _fresque = NULL;
static surface_t * _cube_logo_xcode = NULL;
static surface_t * _cube_logo_androidstudio = NULL;
static surface_t * _cube_logo_swift = NULL;
static surface_t * _cube_logo_java = NULL;
static surface_t * _cube_logo_apple = NULL;
static surface_t * _cube_logo_android = NULL;
static surface_t * _sphere_ball = NULL;


//variables pour la camera
static float _ycam = 3.0f;
static float _lcam = 3.0f;
//variables pour le pc et l'iphone
//pour les deplacer touche Z,Q,S,D,E,F
static float _z = 0.0f;
static float _e = 0.0f;
static float _r = 0.0f;

int main(int argc, char ** argv) {
  if(!gl4duwCreateWindow(argc, argv, 
			 "Recursive Screen Mob Dev - Hadj Rabah Zine Eddine - GL4D", 
			 10, 10, 800, 600, 
			 GL4DW_SHOWN) ) {   
    return 1;
  }
  init();
  gl4duwKeyDownFunc(key);
  gl4duwDisplayFunc(draw);
  gl4duwMainLoop();
  return 0;
}

void init(void) {
  GLuint id;
  gl4dpInitScreen();
  SDL_GL_SetSwapInterval(0);



  _cube   =   mk_quad();
  _cube_table = mk_cube();
  _cube_clavier = mk_cube();  
  _cube_iphone_front =  mk_cube();
  _fresque = mk_quad();
  _cube_logo_xcode = mk_cube();
  _cube_logo_androidstudio = mk_cube();
  _cube_logo_swift = mk_cube();
  _cube_logo_java =  mk_cube();
  _cube_logo_apple = mk_cube();
  _cube_logo_android = mk_cube();
  _sphere_ball = mk_sphere(32,32);

  //mise en place des differentes textures
  //peut etre optimiser avec une boucle
  id = get_texture_from_BMP("images/screen_web.bmp");
  set_texture_id(  _cube_table, id);
  id = get_texture_from_BMP("images/iphone_front.bmp");
  set_texture_id(  _cube_iphone_front, id);
  id = get_texture_from_BMP("images/screen_recursive.bmp");
  set_texture_id(  _cube, id);
  id = get_texture_from_BMP("images/screen_clavier.bmp");
  set_texture_id(  _cube_clavier, id);
  id = get_texture_from_BMP("images/andst.bmp");
  set_texture_id(  _cube_logo_androidstudio, id);
  id = get_texture_from_BMP("images/1200x630bb.bmp");
  set_texture_id(  _cube_logo_xcode, id);
  id = get_texture_from_BMP("images/swift-logo.bmp");
  set_texture_id(  _cube_logo_swift, id);
  id = get_texture_from_BMP("images/java-logo.bmp");
  set_texture_id(  _cube_logo_java, id);
  id = get_texture_from_BMP("images/fresque.bmp");
  set_texture_id(  _fresque, id);
  id = get_texture_from_BMP("images/Android_robot.bmp");
  set_texture_id(  _cube_logo_android, id);
  id = get_texture_from_BMP("images/logo-apple.bmp");
  set_texture_id(  _cube_logo_apple, id);
  id = get_texture_from_BMP("images/NewTennisBallColor.bmp");
  set_texture_id(  _sphere_ball, id);

  //Pour la texture, la couleur et la lumière
  enable_surface_option(  _cube, SO_USE_TEXTURE);
  enable_surface_option(  _cube_logo_androidstudio, SO_USE_TEXTURE);
  enable_surface_option(  _cube_logo_java, SO_USE_TEXTURE);
  enable_surface_option(  _cube_logo_xcode, SO_USE_TEXTURE);
  enable_surface_option(  _cube_logo_swift, SO_USE_TEXTURE);
  enable_surface_option(  _cube_table, SO_USE_TEXTURE);
  enable_surface_option(  _fresque, SO_USE_TEXTURE);
  enable_surface_option(  _cube_clavier, SO_USE_TEXTURE);
  enable_surface_option(  _cube_iphone_front, SO_USE_TEXTURE);;
  enable_surface_option(  _cube_logo_android, SO_USE_TEXTURE);
  enable_surface_option( _cube_logo_apple,SO_USE_TEXTURE);
  enable_surface_option( _sphere_ball,SO_USE_TEXTURE);
  disable_surface_option(  _cube, SO_USE_COLOR);
  disable_surface_option(  _cube_logo_androidstudio, SO_USE_COLOR);
  disable_surface_option(  _cube_logo_swift, SO_USE_COLOR);
  disable_surface_option(  _cube_logo_xcode, SO_USE_COLOR);
  disable_surface_option(  _cube_logo_java, SO_USE_COLOR);
  disable_surface_option(  _cube_table, SO_USE_COLOR);
  disable_surface_option(  _fresque, SO_USE_COLOR);
  disable_surface_option( _cube_clavier,SO_USE_COLOR);
  disable_surface_option(  _cube_iphone_front, SO_USE_COLOR);
  disable_surface_option(  _cube_logo_apple, SO_USE_COLOR);
  disable_surface_option(  _cube_logo_android, SO_USE_COLOR);
  disable_surface_option(  _sphere_ball, SO_USE_COLOR);
  enable_surface_option(  _fresque, SO_USE_LIGHTING);
  enable_surface_option(  _cube, SO_USE_LIGHTING);
  enable_surface_option(  _cube_logo_androidstudio, SO_USE_LIGHTING);
  enable_surface_option(  _cube_logo_java, SO_USE_LIGHTING);
  enable_surface_option(  _cube_logo_xcode, SO_USE_LIGHTING);
  enable_surface_option(  _cube_logo_swift, SO_USE_LIGHTING);
  enable_surface_option(  _cube_table, SO_USE_LIGHTING);
  enable_surface_option(  _cube_clavier, SO_USE_LIGHTING);
  enable_surface_option(  _cube_iphone_front, SO_USE_LIGHTING);
  enable_surface_option(  _cube_logo_android, SO_USE_LIGHTING);
  enable_surface_option(  _cube_logo_apple, SO_USE_LIGHTING);
  enable_surface_option(  _sphere_ball, SO_USE_LIGHTING);

 
  atexit(sortie);
}
int c=1;

void draw(void) {
  static float a = 0.0f;
  float model_view_matrix[16], projection_matrix[16], nmv[16];
  gl4dpClearScreen();
  clear_depth_map();
  MFRUSTUM(projection_matrix, -0.05f, 0.05f, -0.05f, 0.05f, 0.1f, 1000.0f);
  MIDENTITY(model_view_matrix);
  lookAt(model_view_matrix, 8.0f +_lcam, 10.0f+_ycam, 30, 0, 0, 0, 0, 1, 0);
  //fresque 
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, 0.0f, 10.0f, -40.0f);
  scale(nmv,40.0f,15.0f,40.0f);
  transform_n_rasterize(_fresque, nmv, projection_matrix);
 //balle de tennis
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, 10.0f, -8.5f, 9.0f);
  rotate(nmv, a*1.2, 0.0f, 0.0f, 1.0f);
  transform_n_rasterize(_sphere_ball, nmv, projection_matrix);
  //cube logo apple
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, 10.0f, -7.0f, -3.0f );
  rotate(nmv, a, 0.0f, 0.0f, 0.0f);
  transform_n_rasterize(_cube_logo_apple, nmv, projection_matrix);
  //cube logandroid
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, -10.0f, -7.0f, -3.0f );
  rotate(nmv, a, 0.0f, 0.0f, 0.0f);
  transform_n_rasterize(_cube_logo_android, nmv, projection_matrix);
  //cube logo swift
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  rotate(nmv, a, 2.0f, 1.0f,0.0f);
  translate(nmv, 12.0f, -0.5f, 0.0f);
  rotate(nmv, a, 1.0f, 0.0f,0.0f);
  transform_n_rasterize(_cube_logo_swift, nmv, projection_matrix);
  //cube logo java
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  rotate(nmv, a, 1.0f, 1.0f,0.0f);
  translate(nmv, 12.0f, -2.5f, 0.0f);
  rotate(nmv, a, 1.0f, 0.0f, 0.0f);
  transform_n_rasterize(_cube_logo_java, nmv, projection_matrix);
  //cube logo xcode
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  rotate(nmv, a, 0.5f, 1.0f,0.0f);
  translate(nmv, 12.0f, -4.5f, 0.0f);
  rotate(nmv, a, 1.0f, 0.0f, 0.0f);
  transform_n_rasterize(_cube_logo_xcode, nmv, projection_matrix);
  //cube logo android studio
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  rotate(nmv, a, 0.2f, 1.0f,0.0f);
  translate(nmv, 12.0f, -7.0, 0.0f);
  rotate(nmv, a, 1.0f, 0.0f, 0.0f);
  transform_n_rasterize(_cube_logo_androidstudio, nmv, projection_matrix);
  //table
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, 0.0f, -32.0f, 0.0f);
  scale(nmv,4.0f,20.0f,2.0f);
  transform_n_rasterize(_cube_table, nmv, projection_matrix);
  //table
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, 0.0f, -10.0f, -3.0f);
  scale(nmv,20.0f,1.0f,20.0f);
  transform_n_rasterize(_cube_table, nmv, projection_matrix);
  //iphone
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, -10.0f + _z,  _e, +1.0f+_r);
  scale(nmv,1.0f,3.0f,1.0f);
  rotate(nmv, a, 0.0f, 1.0f, 0.0f);
  transform_n_rasterize(_cube_iphone_front, nmv, projection_matrix);
  //clavier
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, 0.0f + _z , -9.0f +  _e,   _r );
  scale(nmv,8.5f,0.5f,6.0f);
  transform_n_rasterize(_cube_clavier, nmv, projection_matrix);
  //ecran
  memcpy(nmv, model_view_matrix, sizeof nmv); 
  translate(nmv, 0.0f + _z, 0.0f + _e , -6.5f+  _r );
  scale(nmv,8.5f,8.0f,1.0f);
  transform_n_rasterize(_cube, nmv, projection_matrix);
  
  gl4dpScreenHasChanged();
  gl4dpUpdateScreen(NULL);
  a += 0.5f;
}

/*
gestion du clavier
z,q,s,d - deplacement
e,f deplacement
p - quitter
haut,droite,gauche,bas - camera
*/
void key(int keycode) {
  switch(keycode) {
  case GL4DK_UP:
    _ycam += 1.05f;
    break;
  case GL4DK_DOWN:
    _ycam -= 1.05f;
    break;
  case GL4DK_LEFT:
    _lcam += 1.05f;    
    break;
  case GL4DK_RIGHT:
    _lcam -= 1.05f;
    break;
  case GL4DK_q:
    _z -= 1.05f;
    break;
  case GL4DK_d:
    _z += 1.05f;
    break;
  case GL4DK_z:
    _r -= 1.05f;
    break;
  case GL4DK_e:
    _e += 1.05f;
    break;
  case GL4DK_f:
    _e -= 1.05f;
    break;
  case GL4DK_s:
    _r += 0.3f;
    break;
  case GL4DK_p: // pour quitter
    exit(0);
    break;
  default: break;
  }
}

//liberation des differentes surfaces
void sortie(void) {

  if(_cube) {
    free_surface(_cube);
    _cube = NULL;
  }
  if(_cube_table) {
    free_surface(_cube_table);
    _cube_table = NULL;
  }
  if(_cube_clavier) {
    free_surface(_cube_clavier);
    _cube_clavier = NULL;
  }
  if(_cube_iphone_front) {
    free_surface(_cube_iphone_front);
    _cube_iphone_front = NULL;
  }
  if(_fresque ) {
    free_surface(_fresque);
    _fresque  = NULL;
  }
  if(_cube_logo_xcode ) {
    free_surface(_cube_logo_xcode );
    _cube_logo_xcode  = NULL;
  }
  if(_cube_logo_androidstudio ) {
    free_surface(_cube_logo_androidstudio );
    _cube_logo_androidstudio = NULL;
  }
  if(_cube_logo_java) {
    free_surface(_cube_logo_java);
    _cube_logo_java = NULL;
  }
  if(_cube_logo_apple) {
    free_surface(_cube_logo_apple);
    _cube_logo_apple= NULL;
  }
  if(_cube_logo_swift) {
    free_surface(_cube_logo_swift);
    _cube_logo_swift = NULL;
  }
  if(_sphere_ball) {
    free_surface(_sphere_ball);
    _sphere_ball = NULL;
  }
  if(_cube_logo_android ) {
    free_surface(_cube_logo_android );
    _cube_logo_android = NULL;
  }
  gl4duClean(GL4DU_ALL);
}
