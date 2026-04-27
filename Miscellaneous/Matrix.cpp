template<typename T>
struct Matrix {
    int n, m;
    vector<vector<T>> mat;

    // Constructor
    Matrix(int n, int m, bool ident = false) : n(n), m(m) {
        mat.assign(n, vector<T>(m, T(0)));
        if (ident) {
            for (int i = 0; i < min(n, m); i++)
                mat[i][i] = T(1);
        }
    }

    // Access (A[i][j])
    vector<T>& operator[](int i) { return mat[i]; }
    const vector<T>& operator[](int i) const { return mat[i]; }

    // Identity
    static Matrix identity(int n) {
        return Matrix(n, n, true);
    }

    // Addition
    Matrix operator + (const Matrix &o) const {
        Matrix res(n, m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                res[i][j] = mat[i][j] + o[i][j];
               // UPDATE NEEDED FOR MOD  
            }
        }
        return res;
    }

    // Subtraction
    Matrix operator - (const Matrix &o) const {
        Matrix res(n, m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                res[i][j] = mat[i][j] - o[i][j];
               // UPDATE NEEDED FOR MOD  
            }
        }
        return res;
    }

    // Multiplication
    Matrix operator * (const Matrix &o) const {
        Matrix res(n, o.m);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if (mat[i][k] == T(0)) continue;
                for (int j = 0; j < o.m; j++) {
                    res[i][j] += mat[i][k] * o[k][j];
                    // UPDATE NEEDED FOR MOD  
                }
            }
        }
        return res;
    }

    // Transpose
    Matrix transpose() const {
        Matrix res(m, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res[j][i] = mat[i][j];
        return res;
    }

    // Fast Exponentiation (ONLY square matrices) 
    // T.C. O(n³log(k))
    Matrix power(long long exp) const {
        assert(n == m);
        Matrix base = *this;
        Matrix res = identity(n); 

        while (exp > 0) {
            if (exp & 1) res = res * base;
            base = base * base;
            exp >>= 1;
        }
        return res;
    }
};
