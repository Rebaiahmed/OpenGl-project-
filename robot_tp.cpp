#include <GL/glut.h>
#include <stdlib.h>

static int epaule = 0, coude = 0;
void init(void) 
{
   glClearColor (1.0, 0.0, 0.5, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glTranslatef (-2.0, 0.0, 0.0);
   glRotatef ((GLfloat) epaule, 0.0, 0.0, 1.0);
   glTranslatef (2.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (2.0);
   glPopMatrix();

   glTranslatef (2.0, 0.0, 0.0);
   glRotatef ((GLfloat) coude, 0.0, 0.0, 1.0);
   glTranslatef (2.0, 0.0, 0.0);
 
   glPushMatrix();
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (2.0);
   glPopMatrix();

   glPopMatrix();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -6.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'r':
         epaule = (epaule + 7) % 360;
         glutPostRedisplay();
         break;
      case 'R':
         epaule = (epaule - 7) % 360;
         glutPostRedisplay();
         break;
      case 'a':
         coude = (coude + 7) % 360;
         glutPostRedisplay();
         break;
      case 'A':
         coude = (coude - 7) % 360;
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (1300, 650); 
   glutInitWindowPosition (0, 0);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
