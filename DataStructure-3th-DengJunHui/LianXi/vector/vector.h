#define DEFAULT_CAPACITY 3
class vector
{
private:
    int _size;int _capacity;int *_elem;
protected:
    void copyFrom(const int*,int,int);
    void expand();
    void shrink();
    int binSearch1(const int*,int,int,int);
    int binSearch2(const int*,int,int,int);
    int binSearch3(const int*,int,int,int);
    int fibSearch(const int*,int,int,int);
public:
    int ssize;
    vector(int c=DEFAULT_CAPACITY)
    {_elem=new int[_capacity=c];_size=0;}
    vector(const int* a,int lo,int hi)
    {copyFrom(a,lo,hi);}
    vector(const vector &v,int lo,int hi)
    {copyFrom(v._elem,lo,hi);}
    vector(const vector &v)
    {copyFrom(v._elem,0,v._size);}
    ~vector()
    {delete []_elem;_elem=nullptr;}
    int &operator[](int);
    int size()const
    {return _size;}
    int get(int)const; 
    void put(int,int);
    int insert(int,const int&);
    int remove(int,int);
    int remove(int);
    int disordered()const;//返回逆序对的数目
    void sort();
    int find(const int &,int lo,int hi)const;
    int search(const int,int,int);
    int deduplicate();
    int uniquify(); 
    void traverse();

};