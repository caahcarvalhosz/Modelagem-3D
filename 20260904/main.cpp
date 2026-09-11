#include<GL/freeglut.h>
#include<iostream>

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1); // cor branca para as letras
    glLineWidth(3.0);

    glBegin(GL_LINES);
        // Letra C
        glVertex2f(-1.6, 1);
        glVertex2f(-2.6, 1);   // topo

        glVertex2f(-2.6, 1);
        glVertex2f(-2.6, -1);  // lateral esquerda

        glVertex2f(-2.6, -1);
        glVertex2f(-1.6, -1);  // base

        // Letra A
        glVertex2f(-1.2, -1);
        glVertex2f(-0.7, 1);   // diagonal esquerda

        glVertex2f(-0.7, 1);
        glVertex2f(-0.2, -1);  // diagonal direita

        glVertex2f(-1.0, 0);
        glVertex2f(-0.4, 0);   // travessa

        // Letra M
        glVertex2f(0.2, -1);
        glVertex2f(0.2, 1);    // vertical esquerda

        glVertex2f(0.2, 1);
        glVertex2f(0.7, 0);    // diagonal descendo

        glVertex2f(0.7, 0);
        glVertex2f(1.2, 1);    // diagonal subindo

        glVertex2f(1.2, 1);
        glVertex2f(1.2, -1);   // vertical direita

        // Letra I
        glVertex2f(1.6, 1);
        glVertex2f(2.6, 1);    // topo

        glVertex2f(2.1, 1);
        glVertex2f(2.1, -1);   // haste central

        glVertex2f(1.6, -1);
        glVertex2f(2.6, -1);   // base
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800,600);
    glutCreateWindow("cacaca");
    glutDisplayFunc(desenha);
    glClearColor( 1.0, 0.4, 0.7, 1.0); // fundo rosa
    glutMainLoop();
return 0;
}
