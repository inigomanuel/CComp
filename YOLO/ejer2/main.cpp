#include <iostream>

using namespace std;
//2
void tabla_termometro(){
    double cel;
    for (int fahr=0;fahr<=300;fahr=fahr+20){
        cel=(fahr-32)*(5.0/9.0);
        cout<<fahr<<" "<<cel<<endl;
    }
}
int main()
{
    //2.
    tabla_termometro();
    return 0;
}
