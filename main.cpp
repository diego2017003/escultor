#include<iostream>
#include"sculptor.h"
#include<cstring>;
void mostrarMatriz(Voxel *v,int nl,int nc,int np){
    for(int k=0;k<np;k++){
        for(int i=0;i<nl;i++){
            for(int j=0;j<nc;j++){
                std::cout<<(*(v + nl*(nc)*k + i*(nc)+j)).isOn <<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }

}
int main(){
   /*Voxel *v;
   Sculptor s = Sculptor(2,2,2);
   s.setColor(0.5,0.2,0,1);
   s.putVoxel(0,1,0);
   v = s.AcessarElementoMatriz3D(1,0,1);
   std::cout<<(*v).isOn<<" "<<(*v).r<<" "<<(*v).g<<" "<<(*v).b<<std::endl;
   s.cutVoxel(0,1,0);
    v = s.AcessarElementoMatriz3D(0,1,0);
   std::cout<<(*v).isOn<<" "<<(*v).r<<" "<<(*v).g<<" "<<(*v).b<<std::endl;
   mostrarMatriz(s.v,s.nx,s.ny,s.nz);
    Sculptor s1 = Sculptor(4,4,4);
    s1.putBox(0,2,0,2,0,2);
    s1.cutBox(1,2,1,2,1,2);
   mostrarMatriz(s1.v,s1.nx,s1.ny,s1.nz);
    Sculptor s2 = Sculptor(9,9,9);
    s2.putSphere(3,3,3,3);
    s2.cutSphere(4,4,4,1);
   //mostrarMatriz(s2.v,s2.nx,s2.ny,s2.nz);
    Sculptor s3 = Sculptor(9,12,10);
    s3.putEllipsoid(4,6,5,5,5,5);
    s3.cutEllipsoid(4,6,2,3,3,3);
   mostrarMatriz(s3.v,s3.nx,s3.ny,s3.nz);*/

return 0;
}
