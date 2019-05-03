#include<iostream>
#include"sculptor.h"
#include<cstring>;
/*void mostrarMatriz(Voxel *v,int nl,int nc,int np){
    for(int k=0;k<np;k++){
        for(int i=0;i<nl;i++){
            for(int j=0;j<nc;j++){
                std::cout<<(*(v + nl*(nc)*k + i*(nc)+j)).isOn <<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }

}*/
int main(){
    Sculptor spc = Sculptor(2,2,2);//objeto escultor para testar o put e o cut
    spc.setColor(0.5,0.2,0.4,1);
    spc.putVoxel(1,0,1);
    spc.cutVoxel(0,1,0);
    spc.writeVECT("C:/Users/Cliente/Desktop/offs/EscultorPCve.vect");
    spc.writeOFF("C:/Users/Cliente/Desktop/offs/EscultorPCOFF.off");
    Sculptor sbox = Sculptor(4,4,4);//objeto escultor para testar o putbox e o cutbox
    sbox.putBox(0,2,0,2,0,2);
    sbox.cutBox(1,2,1,2,1,2);
    sbox.writeVECT("C:/Users/Cliente/Desktop/offs/EscultorBoxve.vect");
    sbox.writeOFF("C:/Users/Cliente/Desktop/offs/EscultorBoxOFF.off");
    Sculptor ses = Sculptor(9,9,9);//objeto escultor para testar o putsphere e o cutsphere
    ses.putSphere(3,3,3,3);
    ses.cutSphere(4,4,4,1);
    ses.writeVECT("C:/Users/Cliente/Desktop/offs/EscultorEsfve.vect");
    ses.writeOFF("C:/Users/Cliente/Desktop/offs/EscultorEsfOFF.off");
    Sculptor seli = Sculptor(9,12,10);
    seli.setColor(0.6,0.1,0.1,0.2);
    seli.putEllipsoid(4,5,4,5,6,7);
    seli.cutEllipsoid(4,6,2,3,3,3);
    seli.writeVECT("C:/Users/Cliente/Desktop/offs/EscultorElive.vect");
    seli.writeOFF("C:/Users/Cliente/Desktop/offs/EscultorEliOFF.off");

return 0;
}
