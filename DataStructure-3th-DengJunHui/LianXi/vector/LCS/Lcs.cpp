#include"Lcs.h"
int main()
{
    string a="ABCBDAB";
    string b="BDCABAB";
    // string a="A";
    // string b="AB";
    cout<<lcsSimpleRe(a,b,a.size()-1,b.size()-1)<<endl;
    Lcs(a,b);
    // 昨夜西风凋碧树，独上高楼，望尽天涯路
    //衣带渐宽终不悔，为伊消得人憔悴
    //众里寻他千百度，蓦然回首，那人却在灯火阑珊处
    system("pause");
}