#include <GL/glut.h>
#include "objetosescena.h"

void inicializar(){
	glClearColor(0,0,1,1);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0,50,250,0,0,0,0,1,-10);//Arriba: 0,10,1 Frente: 0,0,1------ gluLookAt(-0,10,80,0,0,0,0,1,10) *se ve al reves* 
	glMatrixMode(GL_PROJECTION);
	gluPerspective(100,2,5,500);
	//glOrtho(-250,250,-250,250,-250,250);
}
	
void luces(){
	GLfloat luzBlanca[]={0.5,0.5,0.5,1};
	GLfloat fuenteLuz[]={0.5,0.5,0.5,1.0};
	GLfloat PosicionLuz[]={1,1,1,0};
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luzBlanca);
	glLightfv(GL_LIGHT0,GL_AMBIENT,fuenteLuz);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,fuenteLuz);
	glLightfv(GL_LIGHT0,GL_POSITION,PosicionLuz);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);	
	glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE); 	
}
	
void piso(){
	glColor3f(1,0.90,0.50);
	glBegin(GL_POLYGON);
	glVertex3f(-500,0,-500);
	glVertex3f(500,0,-500);
	glVertex3f(500,0,500);
	glVertex3f(-500,0,500);
	glEnd();
}
	
void plantas(){
	luces();
	glPushMatrix();
		glTranslated(150,0,50);
		cacto();
	glPopMatrix();
	glPushMatrix();
		glTranslated(-350,0,80);
		glRotated(100,0,1,0);
		cacto();
	glPopMatrix();
	glPushMatrix();
		glScaled(0.8,0.8,0.8);
		glTranslated(-20,0,-80);
		cacto();
	glPopMatrix();
	glPushMatrix();
		glScaled(1.5,1.5,1.5);
		glTranslated(-30,0,80);
		maguey();
	glPopMatrix();
	glPushMatrix();
		glScaled(1.5,1.5,1.5);
		glTranslated(50,0,-30);
		maguey();
	glPopMatrix();
	glPushMatrix();
		glScaled(0.8,0.8,0.8);
		glTranslated(-100,0,-50);
		maguey();
	glPopMatrix();
	glPushMatrix();
		glScaled(1.2,1.2,1.2);
		glTranslated(200,0,-50);
		maguey();
	glPopMatrix();
	glPushMatrix();
		glScaled(1.2,1.2,1.2);
		glTranslated(-300,0,30);
		maguey();
	glPopMatrix();
	glPushMatrix();
		glTranslated(120,0,120);
		nopal();
	glPopMatrix();
	glPushMatrix();
		glTranslated(-200,0,-10);
		nopal();
	glPopMatrix();
		glPushMatrix();
		glTranslated(-150,0,200);
		glRotated(-95,0,1,0);
		nopal();
	glPopMatrix();
}
	
void piedras(){
	glPushMatrix();
		glTranslated(50,0,80);
		piedra();
	glPopMatrix();
	glPushMatrix();
		glTranslated(200,0,-60);
		glScaled(2,2,2);
		piedra();
	glPopMatrix();
	glPushMatrix();
		glTranslated(-200,0,120);
		glScaled(1.5,1.5,1.5);
		piedra();
	glPopMatrix();
	glPushMatrix();
		glTranslated(200,0,150);
		glScaled(1.5,1.5,1.5);
		piedra();
	glPopMatrix();
	glPushMatrix();
		glTranslated(-120,0,-30);
		piedra();
	glPopMatrix();
		glPushMatrix();
		glTranslated(-200,0,50);
		piedra();
	glPopMatrix();
	glPushMatrix();
		glTranslated(0,0,150);
		piedra();
	glPopMatrix();
	glPushMatrix();
		glTranslated(0,0,100);
		glScaled(1.3,1.3,1.3);
		piedra();
	glPopMatrix();
}
	
void nubes(float j){
	glPushMatrix();
		glTranslated(-150+j,200,-50);
		nube();
	glPopMatrix();
	glPushMatrix();
		glTranslated(-50+j,190,-50);
		nube();
	glPopMatrix();
	glPushMatrix();
		glTranslated(50-j,150,100);
		nube();
	glPopMatrix();
	glPushMatrix();
		glTranslated(150-j,160,100);
		nube();
	glPopMatrix();
	glPushMatrix();
		glTranslated(-400+j,160,-100);
		nube();
	glPopMatrix();
	glPushMatrix();
		glTranslated(-500+j,150,-100);
		nube();
	glPopMatrix();
}
	
void zorro(int i, int *bandera, int *angulo){
	glPushMatrix();
	glTranslated(300-i,0,0);
	cuerpo();
	cabeza();
	cola();
	ojos();
	glPopMatrix();
	//MOVER PIERNA1
	glPushMatrix();
	glTranslated(-11.77,21.10,6.03);
	glTranslated(300-i,0,0);
	if(*bandera==1){
		glRotated(*angulo,0,0,1);
		glTranslated(11.77,-21.10,-6.03);
		pierna1();
		glRotated(-*angulo,0,0,1);
		if(*angulo>65){
			*bandera=0;
			*angulo=0;
		}
	}else{
		glRotated(-*angulo,0,0,1);
		glTranslated(11.77,-21.10,-6.03);
		pierna1();
		glTranslated(-11.77,21.10,6.03);
		glRotated(*angulo,0,0,1);
		if(*angulo>65){
			*bandera=1;
			*angulo=0;
		}
	}
	glPopMatrix();
	//FIN MOVER PIERNA1
	//MOVER PIERNA2
	glPushMatrix();
	glTranslated(-11.77,21.10,-6.03);
	glTranslated(300-i,0,0);
	if(*bandera==0){
		glRotated(*angulo,0,0,1);
		glTranslated(11.77,-21.10,6.03);
		pierna2();
		glRotated(-*angulo,0,0,1);
		if(*angulo>65){
			*bandera=1;
			*angulo=0;
		}
	}else{
		glRotated(-*angulo,0,0,1);
		glTranslated(11.77,-21.10,6.03);
		pierna2();
		glTranslated(-11.77,21.10,-6.03);
		glRotated(*angulo,0,0,1);
		if(*angulo>65){
			*bandera=0;
			*angulo=0;
		}
	}
	glPopMatrix();
	//FIN MOVER PIERNA2
	//MOVER PIERNA4
	glPushMatrix();
	glTranslated(10.52,22.06,-5.99);
	glTranslated(300-i,0,0);
	if(*bandera==1){
		glRotated(*angulo,0,0,1);
		glTranslated(-10.52,-22.06,5.99);
		pierna4();
		glRotated(-*angulo,0,0,1);
		if(*angulo>65){
			*bandera=1;
			*angulo=0;
		}
	}else{
		glRotated(-*angulo,0,0,1);
		glTranslated(-10.52,-22.06,5.99);
		pierna4();
		glTranslated(10.52,22.06,-5.99);
		glRotated(*angulo,0,0,1);
		if(*angulo>65){
			*bandera=0;
			*angulo=0;
		}
	}
	glPopMatrix();
	//FIN MOVER PIERNA3
	//MOVER PIERNA3
	glPushMatrix();
	glTranslated(10.52,22.06,5.99);
	glTranslated(300-i,0,0);
	if(*bandera==0){
		glRotated(*angulo,0,0,1);
		glTranslated(-10.52,-22.06,-5.99);
		pierna3();
		glRotated(-*angulo,0,0,1);
		if(*angulo>65){
			*bandera=1;
			*angulo=0;
		}
	}else{
		glRotated(-*angulo,0,0,1);
		glTranslated(-10.52,-22.06,-5.99);
		pierna3();
		glTranslated(10.52,22.06,5.99);
		glRotated(*angulo,0,0,1);
		if(*angulo>65){
			*bandera=0;
			*angulo=0;
		}
	}
	glPopMatrix();
	//FIN MOVER PIERNA4
}

void escena(){	
	glutInitDisplayMode(GL_DEPTH);
	glMatrixMode(GL_MODELVIEW);
	glutInitDisplayMode(GL_DEPTH);
	int i=0,bandera=1,angulo=0;
	float j=0;
	while(i<750){
		glClear(GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT);
		luces();
		zorro(i,&bandera,&angulo);
		glPushMatrix();
			glTranslated(-200,0,80);
			glRotated(150,0,1,0);
			zorro(i,&bandera,&angulo);
		glPopMatrix();
		glPushMatrix();
			glTranslated(0,0,-100);
			montanas();
		glPopMatrix();
		glPushMatrix();
			glTranslated(-250,0,-100);
			montanas();
		glPopMatrix();
		piso();
		plantas();
		piedras();
		nubes(j);
		glFlush();
		glDisable(GL_DEPTH_TEST);
		i++;
		j+=0.2;
		angulo++;
	}
}

int main (int argc, char **argv) {
	glutInitWindowSize(1000,600);
	glutInit(&argc, argv);
	glutCreateWindow("Escenario 3D");
	inicializar();
	glutDisplayFunc(escena);
	glutMainLoop();
	return 0;
}

