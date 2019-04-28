#ifndef SCULPTOR_H
#define SCULPTOR_H
#include<iostream>
#include<cstring>
#include<cmath>
struct Voxel {
  float r,g,b; // Cores r=red g=green b=blue
  float t;//transparencia
  bool isOn; // Aparece ou nao
};
class Sculptor
{
    public:
        Voxel *v;
        int nx,ny,nz;
        float r,g,b,a;
    public:
        Sculptor(int _nx, int _ny, int _nz);
        virtual ~Sculptor();
        Voxel* AcessarElementoMatriz3D(int l,int c,int p);
        void testaEntrada(int &x,int &y,int &z);
        void setColor(float r, float g, float b, float alpha);
        void putVoxel(int x, int y, int z);
        void cutVoxel(int x, int y, int z);
        void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
        void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
        void putSphere(int xcentro, int ycentro, int zcentro, float raio);
        void cutSphere(int xcentro, int ycentro, int zcentro, float raio);
        void putEllipsoid(int xcentro, int ycentro, int zcentro, float rx, float ry, float rz);
        void cutEllipsoid(int xcentro, int ycentro, int zcentro, float rx, float ry, float rz);
        void writeOFF(std::string Arquivo);
        void writeVECT(std::string Arquivo);

};

#endif // SCULPTOR_H
