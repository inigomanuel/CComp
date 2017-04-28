#include <iostream>

using namespace std;
//1
float convertir_millas(float milla){
    float KM;
    KM = milla*1.60934;
    return KM;
}
int main()
{
    //1.
    int milla;
    cout<<"Ingrese el numero de millas que desee convertir: "<<endl;
    cin >> milla;
    cout<<"La conversion de "<< milla << " millas a kilometros es: " << convertir_millas(milla) <<endl;
    return 0;
}
