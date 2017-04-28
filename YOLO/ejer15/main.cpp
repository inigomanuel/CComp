#include <iostream>

using namespace std;
//15
string palindromo(string pal)
{
    string palabra1;
    for(int i = pal.size()-1; i>=0; i--)
        palabra1 += pal[i];
    return palabra1;
}
int main()
{
    //15
    string palabra,invertido;
    cout<<"Ingrese una palabra: "<<endl;
    cin >> palabra;
    invertido = palindromo(palabra);
    cout<<invertido<<endl;
    if (palabra==invertido)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
