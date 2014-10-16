from OpenGL.GL   import *
from OpenGL.GLU  import *
from OpenGL.GLUT import *
import sys


def drawCube():
    glBegin(GL_QUADS)

    glColor3f(0.0, 1.0, 0.0)
    glVertex3f(1.0, 1.0, -1.0)
    glVertex3f(-1.0, 1.0, -1.0)
    glVertex3f(-1.0, 1.0, 1.0)
    glVertex3f(1.0, 1.0, 1.0)

    glColor3f(1.0, 0.0, 0.0)
    glVertex3f(1.0, -1.0, 1.0)
    glVertex3f(-1.0, -1.0, 1.0)
    glVertex3f(-1.0, -1.0, -1.0)
    glVertex3f(1.0, -1.0, -1.0)

    glColor3f(1.0, 1.0, 1.0)
    glVertex3f(1.0, 1.0, 1.0)
    glVertex3f(-1.0, 1.0, 1.0)
    glVertex3f(-1.0, -1.0, 1.0)
    glVertex3f(1.0, -1.0, 1.0)

    glColor3f(1.0, 1.0, 0.0)
    glVertex3f(1.0, -1.0, -1.0)
    glVertex3f(-1.0, -1.0, -1.0)
    glVertex3f(-1.0, 1.0, -1.0)
    glVertex3f(1.0, 1.0, -1.0)

    glColor3f(1.0, 0.0, 1.0)
    glVertex3f(1.0, 1.0, -1.0)
    glVertex3f(1.0, 1.0, 1.0)
    glVertex3f(1.0, -1.0, 1.0)
    glVertex3f(1.0, -1.0, -1.0)

    glEnd()

def init():
    glClearColor(0.0, 0.0, 0.0, 0.0)
    glClearDepth(1.0)

def displayOrtho():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    gluLookAt(0, 0, 3, 3, 3, 3, 0, 0, 1)
    glTranslatef(3, 3, 3)
    glRotatef(45, 0, 0, 1)
    drawCube()
    glMatrixMode(GL_PROJECTION)
    glOrtho(-2, 2, -2, 2, 0, 10)
    glMatrixMode(GL_MODELVIEW)

    glutSwapBuffers()


def displayPersp1():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    gluLookAt(0, 0, 3, 3, 3, 3, 0, 0, 1)
    glTranslatef(3, 3, 3)
    glRotatef(45,0,0,1)
    drawCube()
    glMatrixMode(GL_PROJECTION)
    glFrustum(-2, 2, -2, 2, 4, 6)
    glMatrixMode(GL_MODELVIEW)
    glutSwapBuffers()

def displayPersp2():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    gluLookAt(0, 0, 3, 3, 3, 3, 0, 0, 1)
    glTranslatef(3, 3, 3)
    glRotatef(45,0,0,1)
    drawCube()
    glMatrixMode(GL_PROJECTION)
    glFrustum(-2, 2, -2, 2, 4.5, 6)
    glMatrixMode(GL_MODELVIEW)

    glutSwapBuffers()

def displayPersp3():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    gluLookAt(0, 0, 3, 3, 3, 3, 0, 0, 1)
    glTranslatef(3, 3, 3)
    glRotatef(45,0,0,1)
    drawCube()
    glMatrixMode(GL_PROJECTION)
    glFrustum(-2, 2, -2, 2, 5, 6)
    glMatrixMode(GL_MODELVIEW)

    glutSwapBuffers()

def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH)

    init()
    glutInitWindowSize(500, 500)
    glutInitWindowPosition(0, 0)
    glutCreateWindow("1")
    glutDisplayFunc(displayOrtho)
    displayOrtho()

    init()
    glutInitWindowSize(500, 500)
    glutInitWindowPosition(0, 500)
    glutCreateWindow("2")
    glutDisplayFunc(displayPersp1)
    displayPersp1()

    init()
    glutInitWindowSize(500, 500)
    glutInitWindowPosition(500, 0)
    glutCreateWindow("3")
    glutDisplayFunc(displayPersp2)
    displayPersp2()


    init()
    glutInitWindowSize(500, 500)
    glutInitWindowPosition(500, 500)
    glutCreateWindow("4")
    glutDisplayFunc(displayPersp3)
    displayPersp3()

    glutMainLoop()


# manipulate with this to get different Pictures

main()

