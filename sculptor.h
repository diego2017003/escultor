#ifndef SCULPTOR_H
#define SCULPTOR_H
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
/**
*Voxel uma estrutura que armazena valores de
*cor (r)ed (g)reen (b)lue, e tambem valores de
*transparencia e validade de uma estrutura componente
*do desenho
*/
struct Voxel {
  float r,g,b; // Cores r=red g=green b=blue
  float t;//transparencia
  bool isOn; // Aparece ou nao
};

/**
*Sculptor uma classe que projeta um conjunto de
*Voxels organizando-os para "esulpir" uma imagem.
*a classe pode esculpir caixas, esferas e elipsses
*a partir de voxels representados como cubos. bem como
*escrever as estruturas em arquivos '.off' ou '.vect'.
*/
class Sculptor
{
    private:
/**
*os parametros da classe são uma matriz de estruturas "voxel",
*os parametros dessa matriz nx, ny, nz
*Os níveis de cores red, green, blue no intervelo de (0,1);
*'a' eh a tranparencia do voxel
*/
        Voxel *v;
        int nx,ny,nz;
        float r,g,b,a;
    public:
/**
*Construtor de objetos da classe sculptor,
*inicializa a matriz de voxels com todos desabilitados
*os valores de nx,ny,nz sao todos inicialmente 1 para caso
*algum valor não seja dado ao construtor.
*/
        Sculptor(int nx, int ny, int nz);
/**
*destrutor de objetos da classe sculptor
*apaga a colecao de voxels
*/
        virtual ~Sculptor();
  /**
*metodo auxiliar para acessar um elemento especifico da matriz,z
*recebe como parametros a linha, coluna e plano e retorna um ponteiro
*para o voxel que está na coordenada.
*/
        Voxel* AcessarElementoMatriz3D(int l,int c,int p);
/**
*metodo auxiliar para testar se as entradas dos demais metodos sao validas
*no contexto, se nao forem validas o metodos da o ultimo valor valido para
*a entrada que extrapola o limite e da zero para valores negativos.
*/
        void testaEntrada(int &x,int &y,int &z);
/**
*o metodo recebe valores rgbe tranparencia para atualizar as cores e tranparencia
*que serao utilizadas posteriormente para os voxels manipulados pelas demais funcoes
*/
        void setColor(float r, float g, float b, float alpha);
/**
*o metodo Recebe os valores de coordenadas x,y,z e habilita o voxel nessa coordenada
* da matriz 'v' atribuindo-lhe tbm os valores das cores e tranparencia atuais
*do objeto sculptor.
*/
        void putVoxel(int x, int y, int z);
/**
*o metodo Recebe os valores de coordenadas x,y,z e desabilita o voxel nessa coordenada
* da matriz 'v'.
*/
        void cutVoxel(int x, int y, int z);
/**
*o metodo Recebe os valores de coordenadas x0,x1,y0,y1,z0,z1 e habilita os voxels da matriz 'v'
*que estao localizados nos intervalos [x0,x1], [y0,y1], [z0,z1]
*atribuindo-lhe tbm os valores das cores e tranparencia atuais do objeto sculptor.
*/
        void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
/**
*o metodo Recebe os valores de coordenadas x0,x1,y0,y1,z0,z1 e desabilita os voxels da matriz 'v'
*que estao localizados nos intervalos [x0,x1], [y0,y1], [z0,z1].
*/
        void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
/**o metodo Recebe o raio os valores de coordenadas xcentro,ycntro,zcentro representando o centro de uma esfera
*e habilita todos os voxels da matriz 'v' que respeitam a equacao da esfera "x*x + y*y+ z*z<= raio*raio" onde x,y,z
*sao coordenadas em relacao a xcentro, ycentro, zcentro. o metodo tbm atribui aos voxels os valores das cores e
*tranparencia atuais do objeto sculptor.
*/
        void putSphere(int xcentro, int ycentro, int zcentro, float raio);
/**o metodo Recebe o raio os valores de coordenadas xcentro,ycntro,zcentro representando o centro de uma esfera
*e desabilita todos os voxels da matriz 'v' que respeitam a equacao da esfera "x*x + y*y+ z*z<= raio*raio" onde x,y,z
*sao coordenadas em relacao a xcentro, ycentro, zcentro.
*/
        void cutSphere(int xcentro, int ycentro, int zcentro, float raio);
/**o metodo Recebe o raio na direcao x(rx), o raio na direcao y(ry), o raio na direcao z(rz) os valores
*de coordenadas xcentro,ycntro,zcentro representando o centro de uma elipsoide e habilita todos os voxels
*da matriz 'v' que respeitam a equacao da elipsoide "(x/rx)*(x/rx) + (y/ry)*(y/ry)+ (z/rz)*(z/rz)<= 1" onde x,y,z
*sao coordenadas em relacao a xcentro, ycentro, zcentro.
*/
        void putEllipsoid(int xcentro, int ycentro, int zcentro, float rx, float ry, float rz);
/**o metodo Recebe o raio na direcao x(rx), o raio na direcao y(ry), o raio na direcao z(rz) os valores
*de coordenadas xcentro,ycntro,zcentro representando o centro de uma elipsoide e desabilita todos os voxels
*da matriz 'v' que respeitam a equacao da elipsoide "(x/rx)*(x/rx) + (y/ry)*(y/ry)+ (z/rz)*(z/rz)<= 1" onde x,y,z
*sao coordenadas em relacao a xcentro, ycentro, zcentro.
*/
        void cutEllipsoid(int xcentro, int ycentro, int zcentro, float rx, float ry, float rz);
/**o metodo Recebe um diretorio e grava um arquivo .off que descreve a imagem formada pela matriz de voxels
*/
        void writeOFF(std::string A);
/**o metodo Recebe um diretorio e grava um arquivo .vect que descreve a imagem formada pela matriz de voxels
*/
        void writeVECT(std::string A);

};

#endif // SCULPTOR_H
