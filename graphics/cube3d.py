from OpenGL.GL   import *
from OpenGL.GLU  import *
from OpenGL.GLUT import *
import sys


def drawCube():
    glBegin(GL_QUADS)

    glColor3f(0.0,1.0, 0.0)
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

def init ():
    glClearColor(0.0, 0.0, 0.0, 0.0)
    glClearDepth(1.0)
    glDepthFunc(GL_LEQUAL)
    glEnable(GL_DEPTH_TEST)
    glEnable(GL_TEXTURE_2D)
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST)
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)

def reshape(width, height):
    glViewport(0, 0, width, height )
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(60.0, float(width)/float (height), 1.0, 60.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()

def displayOrtho():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glMatrixMode(GL_MODELVIEW )
    glLoadIdentity()
    gluLookAt(0, 0, 3, 3, 3, 3, 0, 0, 1)
    glTranslatef(3, 3, 3)
    glRotatef(45,0,0,1)
    drawCube()
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(-2, 2, -2, 2, 0, 10)
    glMatrixMode(GL_MODELVIEW)
    glutSwapBuffers()


def displayPersp1():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    gluLookAt(0, 0, 3, 3, 3, 3, 0, 0, 1)
    glTranslatef(3, 3, 3)
    glRotatef(45,0,0,1)
    drawCube()

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glFrustum(-2, 2, -2, 2, 4, 6)
    glMatrixMode(GL_MODELVIEW)

    glutSwapBuffers()

def displayPersp2():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    gluLookAt(0, 0, 3, 3, 3, 3, 0, 0, 1)
    glTranslatef(3, 3, 3)
    glRotatef(45,0,0,1)
    drawCube()

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glFrustum(-2, 2, -2, 2, 4.5, 6)
    glMatrixMode(GL_MODELVIEW)

    glutSwapBuffers()

def displayPersp3():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    gluLookAt(0, 0, 3, 3, 3, 3, 0, 0, 1)
    glTranslatef(3, 3, 3)
    glRotatef(45,0,0,1)
    drawCube()

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glFrustum(-2, 2, -2, 2, 5, 6)
    glMatrixMode(GL_MODELVIEW)

    glutSwapBuffers()

def main(mDisplay):
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH)
    glutInitWindowSize(500, 500)
    glutInitWindowPosition(0, 0)
    glutCreateWindow("Cube")
    glutDisplayFunc(mDisplay)
    glutReshapeFunc(reshape)
    init()
    glutMainLoop()

# manipulate with this to get different Pictures

#main(displayOrtho)

#main(displayPersp1)

#main(displayPersp2)

main(displayPersp3)