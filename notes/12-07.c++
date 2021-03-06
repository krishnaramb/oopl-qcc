typedef int foo;

using foo = int;

int (*)(int, int) same as int (int, int)

int    a[] = {2, 3, 4};
double x[10];
double* p = copy(a, a + 3, x);

template <typename II, typename OI>
OI copy (II b, II e, OI o)  {
    while (b != e) {
        *o = *b;
        ++b;
        ++o;}
    return o;}

const list<int> y(...);
list<int>::const_iterator p = begin(y);
++p;
equal(..., p);

int x[3];
fill(x, x + 3, 2.34);

template <typename FI, typename T>
void fill (FI b, FI e, T v) {
    while (b != e) {
        *b = v;
        ++b;}}

      int i  = 2; // initialization optional
const int ci = 3; // initialization required
++ci; // not ok

int* p = &i; // ok
++*p;
p = &ci;     // not ok
++*p;

const int* pc;       // ok
const int* pc = &ci;
++*pc;               // not ok
++pc;                // ok
pc = &i;             // ok
int* tmp = pc;       // not ok

int* const cp;       // not ok
int* const cp = &ci; // not ok
int* const cp = &i;  // ok
++*cp;               // ok
++cp;                // not ok

int* const p = new int[1000];
...
++p; // not ok
...
delete [] p;

const int* const cpc;       // not ok
const int* const cpc = &ci;
const int* const cqc = &i;
++cpc;                      // not ok
++*cpc;                     // not ok

      int a[] = {2, 3, 4}; //       int* const a
const int a[] = {2, 3, 4}; // const int* const a

struct A {
    int i;

    void f () {
                         // A* const this;
        i = (3 * i) + 1;
        g();}

    void g () const {
                      // const A* const this;
        f();          // not ok
        i = 0;}};     // not ok

void h (const A& r) {
    r.f();  // not ok
    r.g();}

int main () {
    A x;
    x.i = 2;
    x.f();       // this is a pointer to x
    cout << x.i; // 7

    A y;
    y.f();       // this is a pointer to y
    h(y);

    const A z;
    z.f();       // not ok
    z.g();       // ok

struct A {};

//  A(),  default constructor
//  A(A), copy    constructor
// ~A(),  destructor
//  =(A), copy    assignment operator

int main () {
    {
    A x;     //  A()
    A y(x);  //  A(A)
    A y = x; //  A(A)
    y = x;   //  =(A)
    }        // ~A()

    return 0;}

int i = 2;
T   j = 3;
int i;
int i = int();

int i = 2;  /* is not the same as */ i = 2;

T x = v; // T constructor of type v
x = v;   // T assignment operator of type v

// things I can do wrong with delete
// 1. forget to call it
// 2. call it more than once on the same address
// 3. call it with or without [], incorrectly
// 4. call it early
// 5. the wrong address

T v = ...;
T* a = new T[s];   // T(), s times
fill(a, a + s, v); // =(T), s times

vector<T> x(s, v); // T(T), s times
vector<T> y(x);    // T(T), s times


vector<int>::iterator begin (vector<int>& r) {
    return r.begin();}

template <typename T>
class vector {
    private:
        int s;
        T*  a;
    public:
        vector (int s = 0, T v = T())
            ...

        T& operator [] (int i)
            ...
        T operator [] (int i) const
            ...

int main () {
     vector<int> x(10, 2);
    cout << x[3];
    cout << x.operator[](3);
    x[3] = 4; // not ok

template <typename T>
class vector {
    private:
        int _s;
        T*  _a;
    public:
        vector (int s = 0, const T& v = T()) {
            _s = s;
            _a = new T[s];
            fill(_a, _a + s, v);}
        ~vector () {
            delete [] _a;}
        int size () const {
            return _s;}
        T* begin () {
            return _a;}
        const T* begin () const {
            return _a;}
        T* end () {
            return _a + _s;}
        const T* end () const {
            return _a + _s;}
        T& operator [] (int i) {
            return _a[i];}
        const T& operator [] (int i) const {
            return _a[i];}

const int i = 2;

const int i;     // not ok
i = 2;
