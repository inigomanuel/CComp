#include <iostream>
#define TAMa 2
#define TAMb 3
using namespace std;
//11
void producto(int matriz[TAMa][TAMb], int matrizb[TAMb][TAMa], int matrizc[TAMa][TAMa]){
	for (int i = 0; i < TAMa;i++){
		for (int j = 0; j < TAMa; j++){
			matrizc[i][j] = 0;
			for (int h =0; h < TAMb; h++){
				matrizc[i][j] += matriz[j][h] * matrizb[h][j];
			}
			cout << matrizc[i][j] <<"";
		}
		cout << "\n";
	}
}
int main()
{
//11
    int matriz[TAMa][TAMb] = {{2,2,2},{2,2,2}};
	int matrizb[TAMb][TAMa] = {{2,2},{2,2},{2,2}};
	int matrizc[TAMa][TAMa];
    producto(matriz, matrizb, matrizc);
    return 0;
}
