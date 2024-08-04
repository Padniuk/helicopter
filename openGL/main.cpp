#include <GL/freeglut.h>
#include <cmath>
//initial scale
double scaleX = 0.1;
double scaleY = 0.1;
//scale step
#define scaleStep 0.02

void DrawAxis(double angle=0) {
    //size of arrows
    static double d = 0.02;
    //possible rotation on angle alpha in deg 
    glPushMatrix();
    glRotatef(angle,0,0,1);
    //definition of axes arrow
    glBegin(GL_LINES);
        glVertex2f(-1,0);
        glVertex2f(1,0);
        glVertex2f(1,0);
        glVertex2f(1-d,0+d);
        glVertex2f(1,0);
        glVertex2f(1-d,0-d);
    glEnd();
    glPopMatrix();
}

void DrawGraph(int n=100/*number of graph points, more points - better graph look*/) {
    //graph scalling
    glScalef(scaleX,scaleY,1);
    glBegin(GL_LINE_STRIP);
    for(int i =0; i<=n; i++) {
        double t = 4*M_PI/n*i;// i - integer in loop, t is continuous parameterization
        glVertex2f((2+cos(5/2.*t))*cos(t),(2+cos(5/2.*t))*sin(t));
    }
    glEnd();
}

void DrawDivisions(double angle=0) {
    //size of individual division
    static double d = 0.05;
    //possible rotation on angle alpha in deg 
    glPushMatrix();
    glRotatef(angle,0,0,1);
    glBegin(GL_LINES);
    //definition of each line
    for(int i=-10;i<=10;i+=2) {
        glVertex2f(scaleX*i,-1*d);
        glVertex2f(scaleX*i,d);
    }
    glEnd();
    glPopMatrix();
}

void display() {
    //background color black
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    //definition of axes, them divisions
    glLineWidth(2);
    glColor3f(1,1,1);//white
    DrawAxis();
    DrawDivisions();
    DrawAxis(90);
    DrawDivisions(90);
    glColor3f(0,0,1);//blue RGB
    //drawing a graph
    DrawGraph();

    glutSwapBuffers();//swap buffers
}

void mouseFunc(int button, int state, int x, int y) {
    //here we check 3 or 4 mouse buttons which correspond to scroll up or down
    if (state == GLUT_DOWN) {
        switch(button) {
            case 3:
                scaleX += scaleStep;
                scaleY += scaleStep;
                break;
            case 4:
                scaleX -= scaleStep;
                scaleY -= scaleStep;
                break;
            default:
                break;
        }
    } 
    glutPostRedisplay();//update
}

int main(int argc, char *argv[]) {
    //standart glut initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    //sizes of app window, his initial position and name
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Graph of function");
    // display and mouse functions
    glutDisplayFunc(display);
    glutMouseFunc(mouseFunc);
    //run main loop
    glutMainLoop();
    return 0;
}
