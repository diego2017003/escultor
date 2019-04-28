#include"sculptor.h"
#include<cstring>
#include<iostream>
//#include<new>
#include<cmath>
Voxel* Sculptor::AcessarElementoMatriz3D(int l,int c,int p){//Essa função auxilia no Acesso a um elemento especifico da Matriz
return (this->v+(this->nx)*(this->ny)*p + l*(this->ny)+c);////o acesso a cada elemento da matriz é dado pela estrura *((nome da matriz)+nLinha*nColunas*)Coordenada Do Plano)+nColunas*(Coordena da linha no plano) + Coordenada da coluna)
}
void Sculptor::testaEntrada(int &x,int &y,int &z){
    if(x>(this->nx - 1)){
        x=this->nx - 1;
    }
        if(y>(this->ny - 1)){
        y=this->ny - 1;
    }
        if(z>(this->nz - 1)){
        z=this->nz - 1;
    }
     if(x<0){
        x=0;
    }
        if(y<0){
        y=0;
    }
        if(z<0){
        z=0;
    }
}
Sculptor::~Sculptor(){
}
void Sculptor::setColor(float r, float g, float b, float a){
        if(r>1)
            r=1;
        if(r<0)
            r=0;
        if(g>1)
            g=1;
        if(g<0)
            g=0;
        if(b>1)
            b=1;
        if(b<0)
            b=0;

        this->r=r;
        this->g=g;
        this->b=b;
        this->a=a;
}
void Sculptor::putVoxel(int x, int y, int z){
    testaEntrada(x,y,z);
    Voxel *vo = AcessarElementoMatriz3D(x,y,z);
    (*vo).r = this->r;
    (*vo).g = this->g;
    (*vo).b = this->b;
    (*vo).t = this->a;
    (*vo).isOn = true;
}
void Sculptor::cutVoxel(int x, int y, int z){
     testaEntrada(x,y,z);
    Voxel *vo = AcessarElementoMatriz3D(x,y,z);
    (*vo).isOn = false;
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
        testaEntrada(x0,y0,z0);
        testaEntrada(x1,y1,z1);
        if(x0>x1){
                int a;
                a=x0;
                x0=x1;
                x1=a;
        }
        if(y0>y1){
                int a;
                a=y0;
                y0=y1;
                y1=a;
        }
        if(z0>z1){
                int a;
                a=z0;
                z0=z1;
                z1=a;
        }
        for(int i=x0;i<=x1;i++){
            for(int j=y0;j<=y1;j++){
                for(int k = z0;k<=z1;k++){
                    putVoxel(i,j,k);
                }
            }
        }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
        testaEntrada(x0,y0,z0);
        testaEntrada(x1,y1,z1);
        if(x0>x1){
                int a;
                a=x0;
                x0=x1;
                x1=a;
        }
        if(y0>y1){
                int a;
                a=y0;
                y0=y1;
                y1=a;
        }
        if(z0>z1){
                int a;
                a=z0;
                z0=z1;
                z1=a;
        }
        for(int i=x0;i<=x1;i++){
            for(int j=y0;j<=y1;j++){
                for(int k = z0;k<=z1;k++){
                    cutVoxel(i,j,k);
                }
            }
        }
}
Sculptor::Sculptor(int nx=1, int ny=1, int nz=1){
    this->nx=nx;
    this->ny=ny;
    this->nz=nz;
    this->v = new Voxel[nx*ny*nz];
    for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nz;k++){
                    cutVoxel(i,j,k);
                }
            }
        }
}
void Sculptor::putSphere(int xcentro, int ycentro, int zcentro, float raio){
    testaEntrada(xcentro,ycentro,zcentro);
        for(int i=0;i<this->nx;i++){
            for(int j=0;j<this->ny;j++){
                for(int k=0;k<this->nz;k++){
                    if(((i-xcentro)*(i-xcentro)+(j-ycentro)*(j-ycentro)+(k-zcentro)*(k-zcentro))<=raio*raio){
                        putVoxel(i,j,k);
                    }

                }
            }
        }
}
void Sculptor::cutSphere(int xcentro, int ycentro, int zcentro, float raio){
    testaEntrada(xcentro,ycentro,zcentro);
        for(int i=0;i<this->nx;i++){
            for(int j=0;j<this->ny;j++){
                for(int k=0;k<this->nz;k++){
                    if(sqrt((i-xcentro)*(i-xcentro)+(j-ycentro)*(j-ycentro)+(k-zcentro)*(k-zcentro))<=raio*raio){
                        cutVoxel(i,j,k);
                    }
                }
            }
        }
}
void Sculptor::putEllipsoid(int xcentro, int ycentro, int zcentro, float rx, float ry, float rz){
        testaEntrada(xcentro,ycentro,zcentro);
        for(int i=0;i<this->nx;i++){
            for(int j=0;j<this->ny;j++){
                for(int k=0;k<this->nz;k++){
                    if(sqrt(((i-xcentro)*(i-xcentro)/(rx*rx))+((j-ycentro)*(j-ycentro)/(ry*ry))+((k-zcentro)*(k-zcentro)/(rz*rz)))<=1){
                        putVoxel(i,j,k);
                    }
                }
            }
        }
}
void Sculptor::cutEllipsoid(int xcentro, int ycentro, int zcentro, float rx, float ry, float rz){
        testaEntrada(xcentro,ycentro,zcentro);
        for(int i=0;i<this->nx;i++){
            for(int j=0;j<this->ny;j++){
                for(int k=0;k<this->nz;k++){
                   if(sqrt(((i-xcentro)*(i-xcentro)/(rx*rx))+((j-ycentro)*(j-ycentro)/(ry*ry))+((k-zcentro)*(k-zcentro)/(rz*rz)))<=1){
                        cutVoxel(i,j,k);
                    }
                }
            }
        }
}
void Sculptor::writeOFF(std::string Arquivo);
void Sculptor::writeVECT(std::string Arquivo);
