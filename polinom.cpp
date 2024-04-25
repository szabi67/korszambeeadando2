#include "polinom_header.h" 
   


polinom::polinom() {}                      // default konstruktor

polinom::polinom(const vector<double>& a) : egyutthatok(a) {}  //vektor konstruktor

polinom::polinom(const polinom& cpy): egyutthatok{cpy.egyutthatok}{}     //copy konstruktor

polinom::polinom(const int& x): egyutthatok(x, 0.0) {}    //sima számos kontsruktor

    //Kiírás
void polinom::iras(){
        for(int i = 0; i < egyutthatok.size(); ++i){
            if(i != 0){
                cout << " + ";
            }
            cout << egyutthatok[i] << "x^"<< i;
        }
    }

    //összeadás
polinom polinom::operator+(const polinom& p) const {
        int meret = max(egyutthatok.size(), p.egyutthatok.size());

        polinom eredmeny(meret);

        for(int i = 0; i < meret; ++i){
            double e1 = (i < egyutthatok.size()) ? egyutthatok[i] : 0;
            double e2 = (i < p.egyutthatok.size()) ? p.egyutthatok[i] : 0;

            eredmeny.egyutthatok[i] = e1 + e2;
        }

        return eredmeny;
    }

//kivonás
polinom polinom::operator-(const polinom& p) const {
        int meret = max(egyutthatok.size(), p.egyutthatok.size());

        polinom eredmeny(meret);

        for(int i = 0; i < meret; ++i){
            double e1 = (i < egyutthatok.size()) ? egyutthatok[i] : 0;
            double e2 = (i < p.egyutthatok.size()) ? p.egyutthatok[i] : 0;

            eredmeny.egyutthatok[i] = e1 - e2;
        }

        return eredmeny;
    }

    //Szorzás
polinom polinom::operator*(const polinom& p) const{

        polinom eredmeny(egyutthatok.size() + p.egyutthatok.size() - 1);

        for(int i = 0; i < egyutthatok.size(); ++i){
            for(int j = 0; j < p.egyutthatok.size(); ++j){
                eredmeny.egyutthatok[i+j] += egyutthatok[i] * p.egyutthatok[j];
            }
        }

        return eredmeny;
    }

    //deriválás
polinom polinom::diff() const {
        polinom eredmeny(egyutthatok.size()-1);

        for(int i = 1; i < egyutthatok.size(); ++i){
            eredmeny.egyutthatok[i-1] = i * egyutthatok[i];
        }

        return eredmeny;
    }

//Ezt csak funból csináltam, hogy lehessen szépen parancsssorból futtatni
polinom beolvaso(){
    vector<double> v;
    double k;
    string sor;

    cout << "Adja meg a polinom egyutthatoit: \n";
    getline(cin, sor);

    istringstream iss(sor);

    while(iss >> k){
        v.push_back(k);
    }
    polinom p(v);
    return p;
}

//És végül a futtatás és sok kiíratás
int main(){
    polinom p1 = beolvaso();
    cout << "Az elso polinom: \n" ;
    p1.iras();

    cout << endl;
    cout << endl;

    polinom p2 = beolvaso();
    cout << "A masodik polinom: \n";
    p2.iras();

    cout << endl;
    cout << endl;

    cout << "A ket polinom osszege: \n";
    polinom po = p1+p2;
    po.iras();

    cout << endl;
    cout << endl;

    cout << "A ket polinom kulonbsege:\n ";
    polinom pk = p1-p2;
    pk.iras();

    cout << endl;
    cout << endl;

    cout << "A ket polinom szorzata:\n ";
    polinom psz = p1 * p2;
    psz.iras();

    cout << endl;
    cout << endl;

    cout << "A ket polinom derivaltja:\n";
    cout << "dp1/dx = ";
    polinom dp1 = p1.diff();
    dp1.iras();

    cout << endl;

    cout << "dp2/dx = ";
    polinom dp2 = p2.diff();
    dp2.iras();
}

