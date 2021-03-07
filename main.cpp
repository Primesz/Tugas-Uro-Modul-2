#include <bits/stdc++.h>

using namespace std;

double x,y;
long a,b;
int k,p;
double x0,xt;
const double kons = 1e4;

vector<int> pangkatintegral;
vector<int> koefintegral;

void init(){
    pangkatintegral.clear();
    koefintegral.clear();
}

void input(){
    cout << "Masukkan x : ";
    cin >> x;
    cout << "Masukkan y : ";
    cin>>y;
}

double power(double a,int b){
    if(b == 0){
        return 1;
    }else{
        return a*power(a,b-1);
    }
}

long long power(long a,long b){
    if(b == 0){
        return 1;
    }else{
        return a*power(a,b-1);
    }
}

void pangkat(){
    cout << "Menghitung nilai a^b" <<endl;
    cout << "Masukkan a : ";
    cin >> a;
    cout << "Masukkan b : ";
    cin>>b;
    cout << power(a,b) <<endl;
}


void countintegral(){
    init();
    int counter = 0;
    cout << "Masukkan batas bawah dan atas integral : ";
    cin >> x0 >> xt;
    cout << "Masukkan koefisien dan pangkat dari variabel : " <<endl;
    while (true){
        cin>>k>>p;
        if (k == 0 && p == 0){
            break; // loop input akan berhenti bila masukan koefisien dan pangkat adalah 0
        }
        koefintegral.push_back(k);
        pangkatintegral.push_back(p);
        counter++;
    }
    double res = 0;
    for(int j=0;j<kons;j++){ // jumlah partisi integral sebesar kons
        for(int l=0;l<counter;l++){
            if (j == 0 || j == kons-1){
                res+=0.5*(double)koefintegral[l]*power((x0+(double)j*((xt-x0)/kons)),pangkatintegral[l])*(xt-x0)/kons;
            }else{
                res+=(double)koefintegral[l]*power((x0+(double)j*((xt-x0)/kons)),pangkatintegral[l])*(xt-x0)/kons;
            }
        }
    }
    cout << "Hasil integral : " << res <<endl;
}

int main()
{
    cout << "List of command" <<endl;
    cout << "'+' = Penjumlahan, '-' = Pengurangan '*' = Perkalian , ':' = Pembagian, '^' = Pangkat, 'integrate' = integral" <<endl;
    while(true){
        string c;
        cout << "Masukkan operator : ";
        cin>>c; // memilih operasi yang ingin digunakan
        if(c == "+"){
            cout << "Menghitung nilai x+y" <<endl;
            input();
            cout << "x + y = " << x+y <<endl;
        }else if (c == "-"){
            cout << "Menghitung nilai x-y" <<endl;
            input();
            cout << "x - y = " << x-y <<endl;
        }else if(c == "*"){
            cout << "Menghitung nilai x*y" <<endl;
            input();
            cout << "x * y = " << x*y <<endl;
        }else if(c == ":"){
            cout << "Menghitung nilai x/y" <<endl;
            input();
            cout << "x / y = " << x/y <<endl;
        }else if(c == "^"){
            pangkat();
        }else if(c[0] == 'i'){
            countintegral();
        }else{
            break;
        }
    }


    cin.get();
    return 0;
}

/* Testcase
integrate
2 10
1 2
2 3
3 4
4 5
0 0
*/
// testcase tersebut merupakan integral dari fungsi y = x^2 + 2x^3 + 3x^4 +4x^5 dengan batas bawah 2 dan batas atas 10
