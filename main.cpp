#include <GL/freeglut.h>
#include <iostream>

float escala = 1.0;
float velocidade = 0.005;

// Cores do fundo
float vermelho = 1.0;
float verde = 0.5;
float azul = 0.7;

void desenha(void) {

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Aumenta e diminui a palavra
    glScalef(escala, escala, 1.0);

    // Letras brancas
    glColor3f(1, 1, 1);

    glLineWidth(3.0);

    glBegin(GL_LINES);

        // Letra C
        glVertex2f(-1.6, 1);
        glVertex2f(-2.6, 1);

        glVertex2f(-2.6, 1);
        glVertex2f(-2.6, -1);

        glVertex2f(-2.6, -1);
        glVertex2f(-1.6, -1);

        // Letra A
        glVertex2f(-1.2, -1);
        glVertex2f(-0.7, 1);

        glVertex2f(-0.7, 1);
        glVertex2f(-0.2, -1);

        glVertex2f(-1.0, 0);
        glVertex2f(-0.4, 0);

        // Letra M
        glVertex2f(0.2, -1);
        glVertex2f(0.2, 1);

        glVertex2f(0.2, 1);
        glVertex2f(0.7, 0);

        glVertex2f(0.7, 0);
        glVertex2f(1.2, 1);

        glVertex2f(1.2, 1);
        glVertex2f(1.2, -1);

        // Letra I
        glVertex2f(1.6, 1);
        glVertex2f(2.6, 1);

        glVertex2f(2.1, 1);
        glVertex2f(2.1, -1);

        glVertex2f(1.6, -1);
        glVertex2f(2.6, -1);

    glEnd();

    glFlush();
}


// FUNÇÃO DE ANIMAÇÃO
void animacao(int valor) {

    // Aumenta a palavra
    escala += velocidade;

    // Quando chegar no tamanho máximo,
    // começa a diminuir
    if (escala >= 1.5) {
        velocidade =- 0.01;
    }

    // Quando chegar no tamanho mínimo,
    // começa a aumentar novamente
    if (escala <= 0.07) {
        velocidade = 0.01;
    }


    // Muda a cor do FUNDO

    vermelho += 0.01;

    if (vermelho >= 1.0) {
        vermelho = 0.0;
        verde += 0.01;
    }

    if (verde >= 1.0) {
        verde = 0.0;
        azul += 0.01;
    }

    if (azul >= 1.0) {
        azul = 0.0;
    }

    // Define a nova cor do fundo
    glClearColor(vermelho, verde, azul, 1.0);

    // Redesenha a tela
    glutPostRedisplay();

    glutTimerFunc(30, animacao, 0);
}


// FUNÇÃO DO TECLADO
void listeningKey(unsigned char tecla, int x, int y) {

    switch(tecla) {

        case '+':
            escala += 0.1;
            break;

        case '-':
            escala -= 0.1;
            break;

    }

    desenha();
}


int main(int argc, char* argv[]) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("CAMI");

    // Fundo inicial rosa
    glClearColor(1.0, 0.5, 0.7, 1.0);

    glutDisplayFunc(desenha);

    glutKeyboardFunc(listeningKey);

    // Faz a animação automaticamente
    glutTimerFunc(30, animacao, 0);

    glutMainLoop();

    return 0;
}
