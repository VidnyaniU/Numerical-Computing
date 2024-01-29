class Function
{
public:
    int degree;
    int *coefficients;
    double func(int degree, int *coefficients, double x);

    void printFunction(int, int *);
};
