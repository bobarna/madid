// Math
#include <glm/glm.hpp>

#include <iostream>
#include <memory>

#include "utility/application.h"

int main(int argc, char **argv) {
    /* Creating a GLFW application */
    std::shared_ptr<Application> application = std::make_shared<Application>()

    glutInit( &argc, argv );

    OpenTissue::glut::instance_pointer application = init_glut_application(argc,argv);

    OpenTissue::glut::set_application_instance(application);

    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( application->width(), application->height() );
    glutInitWindowPosition( 50, 50 );
    application->main_window() = glutCreateWindow( application->get_title() );

    application->init_gl_state();

    int main_menu = glutCreateMenu( &OpenTissue::glut::menu );

    application->init_right_click_menu( main_menu, &OpenTissue::glut::menu );

    glutSetMenu( main_menu );
    glutAttachMenu( GLUT_RIGHT_BUTTON );

    application->init();

    glutDisplayFunc ( &OpenTissue::glut::display );
    glutReshapeFunc ( &OpenTissue::glut::reshape );
    glutMouseFunc   ( &OpenTissue::glut::mouse   );
    glutMotionFunc  ( &OpenTissue::glut::motion  );
    glutPassiveMotionFunc( &OpenTissue::glut::motion  );
    glutKeyboardFunc( &OpenTissue::glut::key     );
    glutSpecialFunc ( &OpenTissue::glut::specialkey );

    glutMainLoop();

    application->shutdown();

}
